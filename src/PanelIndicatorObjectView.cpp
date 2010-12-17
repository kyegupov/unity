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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "Nux/Nux.h"
#include "Nux/HLayout.h"
#include "Nux/VLayout.h"

#include "NuxGraphics/GLThread.h"
#include "Nux/BaseWindow.h"
#include "Nux/WindowCompositor.h"

#include "PanelIndicatorObjectView.h"

#include "IndicatorObjectEntryProxy.h"

#include <glib.h>

PanelIndicatorObjectView::PanelIndicatorObjectView ()
: View (NUX_TRACKER_LOCATION),
  _proxy (NULL),
  _entries ()
{
}

PanelIndicatorObjectView::PanelIndicatorObjectView (IndicatorObjectProxy *proxy)
: View (NUX_TRACKER_LOCATION),
  _proxy (proxy),
  _entries ()
{
  printf ("IndicatorAdded: %s\n", _proxy->GetName ().c_str ());
  _layout = new nux::HLayout ("", NUX_TRACKER_LOCATION);

  SetCompositionLayout (_layout);
 
  _proxy->OnEntryAdded.connect (sigc::mem_fun (this, &PanelIndicatorObjectView::OnEntryAdded));
  _proxy->OnEntryMoved.connect (sigc::mem_fun (this, &PanelIndicatorObjectView::OnEntryMoved));
  _proxy->OnEntryRemoved.connect (sigc::mem_fun (this, &PanelIndicatorObjectView::OnEntryRemoved));
}

PanelIndicatorObjectView::~PanelIndicatorObjectView ()
{
}

long
PanelIndicatorObjectView::ProcessEvent (nux::IEvent &ievent, long TraverseInfo, long ProcessEventInfo)
{
  long ret = TraverseInfo;
  ret = _layout->ProcessEvent (ievent, ret, ProcessEventInfo);
  return ret;
}

void
PanelIndicatorObjectView::Draw (nux::GraphicsEngine& GfxContext, bool force_draw)
{

}

void
PanelIndicatorObjectView::DrawContent (nux::GraphicsEngine &GfxContext, bool force_draw)
{
  GfxContext.PushClippingRectangle (GetGeometry() );
  _layout->ProcessDraw (GfxContext, force_draw);
  GfxContext.PopClippingRectangle();
}

void
PanelIndicatorObjectView::OnEntryAdded (IndicatorObjectEntryProxy *proxy)
{
  PanelIndicatorObjectEntryView *view = new PanelIndicatorObjectEntryView (proxy);
  _layout->AddView (view, 0, nux::eCenter, nux::eFull);
  _layout->SetContentDistribution (nux::eStackLeft);

  _entries.push_back (view);

  AddChild (view);

  this->ComputeChildLayout ();
  NeedRedraw ();  
}

void
PanelIndicatorObjectView::OnEntryMoved (IndicatorObjectEntryProxy *proxy)
{
  printf ("ERROR: Moving IndicatorObjectEntry not supported\n");
}

void
PanelIndicatorObjectView::OnEntryRemoved(IndicatorObjectEntryProxy *proxy)
{
  std::vector<PanelIndicatorObjectEntryView *>::iterator it;
  
  for (it = _entries.begin(); it != _entries.end(); it++)
  {
    PanelIndicatorObjectEntryView *view = static_cast<PanelIndicatorObjectEntryView *> (*it);
    if (view->_proxy == proxy)
      {
        RemoveChild (view);
        _entries.erase (it);
        _layout->RemoveChildObject (view);

        break;
      }
  }

  this->ComputeChildLayout (); 
  NeedRedraw ();
}

const gchar *
PanelIndicatorObjectView::GetName ()
{
  return _proxy->GetName ().c_str ();
}

const gchar *
PanelIndicatorObjectView::GetChildsName ()
{
  return "entries";
}

void
PanelIndicatorObjectView::AddProperties (GVariantBuilder *builder)
{
  nux::Geometry geo = GetGeometry ();

  /* Now some props from ourselves */
  g_variant_builder_add (builder, "{sv}", "x", g_variant_new_int32 (geo.x));
  g_variant_builder_add (builder, "{sv}", "y", g_variant_new_int32 (geo.y));
  g_variant_builder_add (builder, "{sv}", "width", g_variant_new_int32 (geo.width));
  g_variant_builder_add (builder, "{sv}", "height", g_variant_new_int32 (geo.height));
}
