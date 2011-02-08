// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2010 Canonical Ltd
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored by: Jason Smith <jason.smith@canonical.com>
 */
 
#include <glib.h>
#include "PluginAdapter.h"

PluginAdapter * PluginAdapter::_default = 0;

#define MAXIMIZABLE (CompWindowActionMaximizeHorzMask & CompWindowActionMaximizeVertMask & CompWindowActionResizeMask)
#define COVERAGE_AREA_BEFORE_AUTOMAXIMIZE 0.75

/* static */
PluginAdapter *
PluginAdapter::Default ()
{
  if (!_default)
      return 0;
  return _default;
}

/* static */
void
PluginAdapter::Initialize (CompScreen *screen)
{
  _default = new PluginAdapter (screen);
}

PluginAdapter::PluginAdapter(CompScreen *screen) :
    m_Screen (screen),
    m_ExpoActionList (0),
    m_ScaleActionList (0),
    m_focussed(NULL)
{
}

PluginAdapter::~PluginAdapter()
{
}

/* A No-op for now, but could be useful later */
void
PluginAdapter::OnScreenGrabbed ()
{
}

void
PluginAdapter::OnScreenUngrabbed ()
{
  if (m_SpreadedWindows.size () && !screen->grabExist ("scale"))
    terminate_spread.emit (m_SpreadedWindows);
}

void
PluginAdapter::NotifyResized (CompWindow *window, int x, int y, int w, int h)
{
  window_resized.emit (window->id ());
}

void 
PluginAdapter::NotifyMoved (CompWindow *window, int x, int y)
{
  window_moved.emit (window->id ());
}

void
PluginAdapter::NotifyStateChange (CompWindow *window, unsigned int state, unsigned int last_state)
{
  if (!((last_state & MAXIMIZE_STATE) == MAXIMIZE_STATE)
      && ((state & MAXIMIZE_STATE) == MAXIMIZE_STATE))
  {
    WindowManager::window_maximized.emit (window->id ());
  }
  else if (((last_state & MAXIMIZE_STATE) == MAXIMIZE_STATE)
           && !((state & MAXIMIZE_STATE) == MAXIMIZE_STATE))
  {
    WindowManager::window_restored.emit (window->id ());
  }
}

void 
PluginAdapter::Notify (CompWindow *window, CompWindowNotify notify)
{
  switch (notify)
  {
    case CompWindowNotifyMinimize:
      window_minimized.emit (window->id ());
      break;
    case CompWindowNotifyUnminimize:
      window_unminimized.emit (window->id ());
      break;
    case CompWindowNotifyShade:
      window_shaded.emit (window->id ());
      break;
    case CompWindowNotifyUnshade:
      window_unshaded.emit (window->id ());
      break;
    case CompWindowNotifyHide:
      window_hidden.emit (window->id ());
      break;
    case CompWindowNotifyShow:
      window_shown.emit (window->id ());
      break;
    case CompWindowNotifyFocusChange:
      m_focussed = window;
      window_focussed.emit (window->id ());
      break;
    case CompWindowNotifyMap:
      WindowManager::window_mapped.emit (window->id ());
      break;
    case CompWindowNotifyUnmap:
      WindowManager::window_unmapped.emit (window->id ());
      break;
    case CompWindowNotifyReparent:
      MaximizeIfBigEnough (window);
      break;
    default:
      break;
  }
}

void
MultiActionList::AddNewAction (CompAction *a, bool primary)
{
  if (std::find (m_ActionList.begin (), m_ActionList.end (), a)  == m_ActionList.end ())
    m_ActionList.push_back (a);

  if (primary)
    _primary_action = a;
}

void
MultiActionList::RemoveAction (CompAction *a)
{
  m_ActionList.remove (a);
}

void
MultiActionList::InitiateAll (CompOption::Vector &extraArgs)
{
  CompOption::Vector argument;
  if (!m_ActionList.size ())
    return;

  argument.resize (1);
  argument[0].setName ("root", CompOption::TypeInt);
  argument[0].value ().set ((int) screen->root ());
  foreach (CompOption &arg, extraArgs)
  {
    argument.push_back (arg);
  }

  CompAction *a;
  
  if (_primary_action)
    a = _primary_action;
  else
    a = m_ActionList.front ();
  
  /* Initiate the first available action with the arguments */
  a->initiate () (a, 0, argument);
}

void
MultiActionList::TerminateAll (CompOption::Vector &extraArgs)
{
  CompOption::Vector argument;
  CompOption::Value  value;
  if (!m_ActionList.size ())
    return;

  argument.resize (1);
  argument[0].setName ("root", CompOption::TypeInt);
  argument[0].value ().set ((int) screen->root ());

  foreach (CompOption &a, extraArgs)
    argument.push_back (a);
    
  if (_primary_action)
  {
    _primary_action->terminate () (_primary_action, 0, argument);
    return;
  }
  
  foreach (CompAction *action, m_ActionList)
  {
    if (action->state () & (CompAction::StateTermKey |
                            CompAction::StateTermButton |
                            CompAction::StateTermEdge |
                            CompAction::StateTermEdgeDnd))
    {
      action->terminate () (action, 0, argument);
    }
  }
}

void
PluginAdapter::SetExpoAction (MultiActionList &expo)
{
  m_ExpoActionList = expo;
}

void
PluginAdapter::SetScaleAction (MultiActionList &scale)
{
  m_ScaleActionList = scale;
}
    
std::string *
PluginAdapter::MatchStringForXids (std::list<Window> *windows)
{
  char *string;
  std::string *result = new std::string ("any & (");
    
  std::list<Window>::iterator it;
    
  for (it = windows->begin (); it != windows->end (); it++)
  {
    string = g_strdup_printf ("| xid=%i ", (int) *it);
    result->append (string);
    g_free (string);
  }
    
  result->append (")");
    
  return result;
}
    
void 
PluginAdapter::InitiateScale (std::string *match)
{
  CompOption::Vector argument;
  CompMatch	     m (*match);
  std::list <guint32> xids;

  argument.resize (1);
  argument[0].setName ("match", CompOption::TypeMatch);
  argument[0].value ().set (m);

  /* FIXME: Lame */
  foreach (CompWindow *w, screen->windows ())
  {
    if (m.evaluate (w))
    {
      if (std::find (m_SpreadedWindows.begin (), m_SpreadedWindows.end (), w->id ()) ==
                     m_SpreadedWindows.end ())
        m_SpreadedWindows.push_back (w->id ());
      xids.push_back (w->id ());
    }
  }

  initiate_spread.emit (xids);
  m_ScaleActionList.InitiateAll (argument);
}

void 
PluginAdapter::TerminateScale ()
{
  CompOption::Vector argument (0);

  terminate_spread.emit (m_SpreadedWindows);
  m_SpreadedWindows.clear ();
  m_ScaleActionList.TerminateAll (argument);
}

bool
PluginAdapter::IsScaleActive ()
{
  return m_Screen->grabExist ("scale");
}

void 
PluginAdapter::InitiateExpo ()
{
    CompOption::Vector argument (0);
    
    m_ExpoActionList.InitiateAll (argument);
}

// WindowManager implementation
bool
PluginAdapter::IsWindowMaximized (guint xid)
{
  Window win = (Window)xid;
  CompWindow *window;

  window = m_Screen->findWindow (win);
  if (window)
  {
    return ((window->state () & MAXIMIZE_STATE) == MAXIMIZE_STATE);
  }

  return false;
}

bool
PluginAdapter::IsWindowDecorated (guint32 xid)
{
  Window win = (Window)xid;
  CompWindow *window;

  window = m_Screen->findWindow (win);
  if (window)
  {
    unsigned int decor = window->mwmDecor ();

    return decor & (MwmDecorAll | MwmDecorTitle);
  }
  return true;
}

bool
PluginAdapter::IsWindowFocussed (guint32 xid)
{
  Window win = (Window)xid;
  CompWindow *window;

  if (window != NULL && xid == window->id())
    return true;

  return false;
}

void
PluginAdapter::Restore (guint32 xid)
{
  Window win = (Window)xid;
  CompWindow *window;

  window = m_Screen->findWindow (win);
  if (window)
    window->maximize (0);
}

void
PluginAdapter::Minimize (guint32 xid)
{
  Window win = (Window)xid;
  CompWindow *window;

  window = m_Screen->findWindow (win);
  if (window)
    window->minimize ();
}

void
PluginAdapter::Close (guint32 xid)
{
  Window win = (Window)xid;
  CompWindow *window;

  window = m_Screen->findWindow (win);
  if (window)
    window->close (CurrentTime);
}

void PluginAdapter::MaximizeIfBigEnough (CompWindow *window)
{
  XClassHint   classHint;
  Status       status;
  char*        win_wmclass = NULL;
  int          num_monitor;
  CompOutput   screen;
  int          screen_width;
  int          screen_height;
  float        covering_part;

  if (!window)
    return;

  if (window->type () != CompWindowTypeNormalMask
      || (window->actions () & MAXIMIZABLE) != MAXIMIZABLE)
    return;

  status = XGetClassHint (m_Screen->dpy (), window->id (), &classHint);
  if (status && classHint.res_class)
  {
    win_wmclass = strdup (classHint.res_class);
    XFree (classHint.res_class);
  }
  else
    return;

  num_monitor = window->outputDevice();
  screen = m_Screen->outputDevs().at(num_monitor);

  screen_height = screen.workArea().height ();
  screen_width = screen.workArea().width ();

  if ((window->state () & MAXIMIZE_STATE) == MAXIMIZE_STATE) {
    g_debug ("MaximizeIfBigEnough: window mapped and already maximized, just undecorate");
    Undecorate (window->id ());
    return;
  }

  // use server<parameter> because the window won't show the real parameter as
  // not mapped yet
  covering_part = (float)(window->serverWidth () * window->serverHeight ()) / (float)(screen_width * screen_height);
  if ((covering_part < COVERAGE_AREA_BEFORE_AUTOMAXIMIZE) || (covering_part > 1.0))
  {
    g_debug ("MaximizeIfBigEnough: %s window size doesn't fit", win_wmclass);
    return;
  }

  Undecorate (window->id ());
  window->maximize (MAXIMIZE_STATE);

  if (win_wmclass)
    free (win_wmclass);
}
