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
* Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
*/

#include "PlacesGroupController.h"

#include <Nux/GridHLayout.h>

#include "PlacesStyle.h"
#include "PlacesSimpleTile.h"

static const guint kPadding = 4;

PlacesGroupController::PlacesGroupController (PlaceEntryGroup& group)
: _group (NULL)
{
  PlacesStyle *style = PlacesStyle::GetDefault ();

  _id = group.GetId ();

  _group = new PlacesGroup (NUX_TRACKER_LOCATION);
  _group->SetName(group.GetName ());
  _group->SetIcon (group.GetIcon ());
  _group->SetChildUnexpandHeight (style->GetTileHeight () + kPadding * 3);

  nux::GridHLayout *layout = new nux::GridHLayout (NUX_TRACKER_LOCATION);
  layout->ForceChildrenSize (true);
  layout->SetChildrenSize (style->GetTileWidth (), style->GetTileHeight ());
  layout->EnablePartialVisibility (false);

  layout->SetVerticalExternalMargin (kPadding);
  layout->SetHorizontalExternalMargin (kPadding);
  layout->SetVerticalInternalMargin (kPadding);
  layout->SetHorizontalInternalMargin (kPadding);
  layout->SetHeightMatchContent (true);

  _group->SetChildLayout (layout);
  _group->SetVisible (false);
  _group->SetExpanded (false);
}

PlacesGroupController::~PlacesGroupController ()
{
}

const void *
PlacesGroupController::GetId ()
{
  return _id;
}

PlacesGroup *
PlacesGroupController::GetGroup ()
{
  return _group;
}

void
PlacesGroupController::AddResult (PlaceEntryGroup& group, PlaceEntryResult& result)
{
  gchar            *result_name;
  const gchar      *result_icon;
  PlacesSimpleTile *tile;
  
  result_name = g_markup_escape_text (result.GetName (), -1);
  result_icon = result.GetIcon ();

  tile = new PlacesSimpleTile (result_icon, result_name, PlacesStyle::GetDefault ()->GetTileIconSize ());
  tile->SetURI (result.GetURI ());
  tile->QueueRelayout ();

  _id_to_tile[result.GetId ()] = tile;
  
  _group->GetChildLayout ()->AddView (tile);
  _group->Relayout ();
  _group->SetVisible (true);
  _group->SetCounts (6, _id_to_tile.size ());

  g_free (result_name);
}

void
PlacesGroupController::RemoveResult (PlaceEntryGroup& group, PlaceEntryResult& result)
{
  PlacesTile  *tile;

  tile = _id_to_tile[result.GetId ()];
  if (!tile)
    return;
  
  _id_to_tile.erase (result.GetId ());

  _group->GetChildLayout ()->RemoveChildObject (tile);
  _group->Relayout ();
  _group->SetCounts (6, _id_to_tile.size ());
  _group->SetVisible (_id_to_tile.size ());
}

void
PlacesGroupController::Clear ()
{

}

//
// Introspectable
//
const gchar *
PlacesGroupController::GetName ()
{
  return "PlacesGroupController";
}

void
PlacesGroupController::AddProperties (GVariantBuilder *builder)
{

}
