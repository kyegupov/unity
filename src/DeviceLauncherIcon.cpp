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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "DeviceLauncherIcon.h"

#include "ubus-server.h"
#include "UBusMessages.h"

#define DEFAULT_ICON "drive-removable-media"

DeviceLauncherIcon::DeviceLauncherIcon (Launcher *launcher, GVolume *volume)
: SimpleLauncherIcon(launcher),
  _volume (volume)
{
  g_signal_connect (_volume, "removed",
                    G_CALLBACK (&DeviceLauncherIcon::OnRemoved), this);

  UpdateDeviceIcon ();

}

DeviceLauncherIcon::~DeviceLauncherIcon()
{

}

void
DeviceLauncherIcon::UpdateDeviceIcon ()
{
  {
    gchar *name;
    gchar *escape;

    name = g_volume_get_name (_volume);
    escape = g_markup_escape_text (name, -1);

    SetTooltipText (escape);

    g_free (escape);
    g_free (name);
  }
  
  {
    GIcon *icon;

    icon = g_volume_get_icon (_volume);
    if (G_IS_THEMED_ICON (icon))
    {
      const gchar * const *names;

      names = g_themed_icon_get_names (G_THEMED_ICON (icon));

      if (names)
        SetIconName (names[0]);
      else
        SetIconName (DEFAULT_ICON);

      g_debug ("ICON: %s", names[0]);
    }
    else if (G_IS_FILE_ICON (icon))
    {
      GFile *file;

      file = g_file_icon_get_file (G_FILE_ICON (icon));
      if (file)
      {
        gchar *path;

        path = g_file_get_path (file);
        SetIconName (path);

        g_debug ("ICON: %s", path);

        g_free (path);
      }
      else
        SetIconName (DEFAULT_ICON);
    }
    else
    {
      SetIconName (DEFAULT_ICON);
    }
  }
  
  
  SetQuirk (QUIRK_VISIBLE, true);
  SetQuirk (QUIRK_RUNNING, false);
  SetIconType (TYPE_DEVICE);

}

nux::Color 
DeviceLauncherIcon::BackgroundColor ()
{
  return nux::Color (0xFF333333);
}

nux::Color 
DeviceLauncherIcon::GlowColor ()
{
  return nux::Color (0xFF333333);
}

void
DeviceLauncherIcon::OnMouseClick (int button)
{
  SimpleLauncherIcon::OnMouseClick (button);

  if (button == 1)
  {
    Activate ();
  }
}

std::list<DbusmenuMenuitem *>
DeviceLauncherIcon::GetMenus ()
{
  std::list<DbusmenuMenuitem *>  result;
  DbusmenuMenuitem              *menu_item;

  menu_item = dbusmenu_menuitem_new ();

  dbusmenu_menuitem_property_set (menu_item, DBUSMENU_MENUITEM_PROP_LABEL, "Open");
  dbusmenu_menuitem_property_set_bool (menu_item, DBUSMENU_MENUITEM_PROP_ENABLED, true);
  dbusmenu_menuitem_property_set_bool (menu_item, DBUSMENU_MENUITEM_PROP_VISIBLE, true);

  g_signal_connect (menu_item, DBUSMENU_MENUITEM_SIGNAL_ITEM_ACTIVATED,
                    G_CALLBACK (&DeviceLauncherIcon::OnOpen), this);

  result.push_back (menu_item);

  return result;
}

void
DeviceLauncherIcon::Activate ()
{
}

void
DeviceLauncherIcon::OnOpen (DbusmenuMenuitem *item, int time, DeviceLauncherIcon *self)
{
  self->Activate ();
}

void
DeviceLauncherIcon::OnRemoved (GVolume *volume, DeviceLauncherIcon *self)
{
  self->Remove ();
}
