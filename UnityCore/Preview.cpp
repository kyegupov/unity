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
 * Authored by: Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include "Preview.h"

#include "MusicPreviews.h"

namespace unity
{
namespace dash
{

Preview::Ptr Preview::PreviewForProperties(std::string const& renderer_name,
                                           Properties& properties)
{
  if (renderer_name == "preview-track")
  {
    return Preview::Ptr(new TrackPreview(properties));
  }
  
  return Preview::Ptr(new NoPreview());
}

Preview::~Preview()
{}

unsigned int Preview::PropertyToUnsignedInt (Properties& properties, const char* key)
{
  return g_variant_get_uint32(properties[key]);
}

std::string Preview::PropertyToString(Properties& properties, const char *key)
{
  return g_variant_get_string(properties[key], NULL);
}

std::vector<std::string> Preview::PropertyToStringVector(Properties& properties, const char *key)
{
  GVariantIter* iter = NULL;
  char* value = NULL;

  g_variant_get(properties[key], "as", &iter);

  std::vector<std::string> property;
  while (g_variant_iter_loop(iter, "s", &value))
    property.push_back(value);    

  g_variant_iter_free(iter);

  return property;
}


NoPreview::NoPreview()
{
  renderer_name = "preview-none";
}

}
}
