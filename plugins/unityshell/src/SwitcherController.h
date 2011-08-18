// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2011 Canonical Ltd
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

#ifndef SWITCHERCONTROLLER_H
#define SWITCHERCONTROLLER_H

#include "SwitcherModel.h"
#include "SwitcherView.h"

#include <boost/shared_ptr.hpp>
#include <sigc++/sigc++.h>

#include <Nux/Nux.h>
#include <Nux/BaseWindow.h>
#include <Nux/WindowCompositor.h>

namespace unity
{
namespace switcher
{

class SwitcherController : public sigc::trackable
{

public:
  enum SortMode
  {
    LAUNCHER_ORDER,
    FOCUS_ORDER,
  };

  enum ShowMode
  {
    ALL,
    CURRENT_VIEWPORT,
  };

  SwitcherController();
  virtual ~SwitcherController();

  nux::Property<int> timeout_length;

  nux::Property<bool> detail_on_timeout;
  nux::Property<int>  detail_timeout_length;

  void Show(ShowMode show, SortMode sort, bool reverse, std::vector<AbstractLauncherIcon*> results);
  void Hide(bool accept_state=true);

  bool Visible();

  void Next();
  void Prev();

  void NextDetail();
  void PrevDetail();

  void SetDetail(bool detail);

  void SelectFirstItem();

  void SetWorkspace(nux::Geometry geo);

  SwitcherView * GetView ();

  LayoutWindowList ExternalRenderTargets ();

private:
  enum DetailMode
  {
    TAB_NEXT_WINDOW,
    TAB_NEXT_WINDOW_LOOP,
    TAB_NEXT_TILE,
  };

  void ConstructView();

  void OnModelSelectionChanged(AbstractLauncherIcon *icon);

  int WindowsRelatedToSelection();

  static void OnBackgroundUpdate (GVariant *data, SwitcherController *self);

  SwitcherModel::Ptr model_;
  SwitcherView* view_;

  nux::Geometry workarea_;

  nux::BaseWindow* view_window_;

  bool visible_;
  guint show_timer_;
  guint detail_timer_;
  nux::Color bg_color_;
  DetailMode detail_mode_;

  static gboolean OnShowTimer(gpointer data);
  static gboolean OnDetailTimer(gpointer data);

  static bool CompareSwitcherItemsPriority(AbstractLauncherIcon* first, AbstractLauncherIcon* second);

};

}
}

#endif // SWITCHERCONTROLLER_H

