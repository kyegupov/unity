// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2015 Canonical Ltd
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
 * Authored by: Marco Trevisan <marco.trevisan@canonical.com>
 */

#include "FileManagerLauncherIcon.h"

#include <boost/algorithm/string.hpp>
#include <NuxCore/Logger.h>
#include <UnityCore/DesktopUtilities.h>

#include "unity-shared/GnomeFileManager.h"

namespace unity
{
namespace launcher
{
namespace
{
DECLARE_LOGGER(logger, "unity.launcher.icon.filemanager");
const std::string TRASH_URI = "trash:";
const std::string TRASH_PATH = "file://" + DesktopUtilities::GetUserTrashDirectory();
const std::string DEFAULT_ICON = "system-file-manager";
}

FileManagerLauncherIcon::FileManagerLauncherIcon(ApplicationPtr const& app, FileManager::Ptr const& fm)
  : WindowedLauncherIcon(IconType::APPLICATION)
  , ApplicationLauncherIcon(app)
  , StorageLauncherIcon(GetIconType(), fm ? fm : GnomeFileManager::Get())
{
  // We disconnect from ApplicationLauncherIcon app signals, as we manage them manually
  signals_conn_.Clear();

  signals_conn_.Add(app_->desktop_file.changed.connect([this](std::string const& desktop_file) {
    LOG_DEBUG(logger) << tooltip_text() << " desktop_file now " << desktop_file;
    UpdateDesktopFile();
  }));

  signals_conn_.Add(app_->closed.connect([this] {
    LOG_DEBUG(logger) << tooltip_text() << " closed";
    OnApplicationClosed();
  }));

  signals_conn_.Add(app_->title.changed.connect([this](std::string const& name) {
    LOG_DEBUG(logger) << tooltip_text() << " name now " << name;
    _menu_items.clear();
    tooltip_text = name;
  }));

  signals_conn_.Add(app_->icon.changed.connect([this](std::string const& icon) {
    LOG_DEBUG(logger) << tooltip_text() << " icon now " << icon;
    icon_name = (icon.empty() ? DEFAULT_ICON : icon);
  }));
}

void FileManagerLauncherIcon::Focus(ActionArg arg)
{
  WindowedLauncherIcon::Focus(arg);
}

bool FileManagerLauncherIcon::IsLocationManaged(std::string const& location) const
{
  if (boost::algorithm::starts_with(location, TRASH_URI))
    return false;

  if (boost::algorithm::starts_with(location, TRASH_PATH))
    return false;

  // FIXME: get paths from devices manager
  if (boost::algorithm::starts_with(location, "file:///media/"+std::string(g_get_user_name())))
    return false;

  return true;
}

WindowList FileManagerLauncherIcon::GetManagedWindows() const
{
  return StorageLauncherIcon::GetManagedWindows();
}

WindowList FileManagerLauncherIcon::GetStorageWindows() const
{
  WindowList fm_windows;

  for (auto const& app_win : ApplicationLauncherIcon::GetManagedWindows())
  {
    auto const& locations = file_manager_->LocationsForWindow(app_win);

    if (!locations.empty() && IsLocationManaged(locations.front()))
      fm_windows.push_back(app_win);
  }

  return fm_windows;
}

} // namespace launcher
} // namespace unity
