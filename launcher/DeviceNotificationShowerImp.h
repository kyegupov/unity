// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright (C) 2012 Canonical Ltd
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
 * Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
 */

#ifndef UNITYSHELL_DEVICE_NOTIFICATION_SHOWER_IMP_H
#define UNITYSHELL_DEVICE_NOTIFICATION_SHOWER_IMP_H

#include <memory>

#include "DeviceNotificationShower.h"

namespace unity
{
namespace launcher
{

class DeviceNotificationShowerImp : public DeviceNotificationShower
{
public:
  DeviceNotificationShowerImp();
  virtual ~DeviceNotificationShowerImp();

  virtual void Show(std::string const& icon_name, std::string const& volume_name);

private:
  class Impl;
  std::unique_ptr<Impl> pimpl;
};

}
}

#endif