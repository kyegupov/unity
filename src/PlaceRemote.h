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

#ifndef PLACE_REMOTE_H
#define PLACE_REMOTE_H

#include <glib.h>
#include <gio/gio.h>

#include <string>
#include <vector>
#include <sigc++/signal.h>
#include <sigc++/trackable.h>

#include "Place.h"

class PlaceRemote : public Place
{
public:
  PlaceRemote (const char *path);
  ~PlaceRemote ();

  std::vector<PlaceEntry *>& GetEntries ();
  guint32                    GetNEntries ();

private:
  void LoadKeyFileEntries (GKeyFile *key_file);

private:
  char *_path;
  char *_dbus_name;
  char *_dbus_path;

  GRegex *_uri_regex;
  GRegex *_mime_regex;
};

#endif // PLACE_REMOTE_H
