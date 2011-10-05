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
 *              Tim Penhey <tim.penhey@canonical.com>
 */

#ifndef LAUNCHERCONTROLLER_H
#define LAUNCHERCONTROLLER_H

#include <memory>
#include <sigc++/sigc++.h>

class Launcher;

namespace unity
{
namespace launcher
{

class Controller : public sigc::trackable
{
public:
  typedef std::shared_ptr<Controller> Ptr;

  Controller();
  ~Controller();

  void UpdateNumWorkspaces(int workspaces);

private:
  class Impl;
  Impl* pimpl;
};

}
}

#endif // LAUNCHERCONTROLLER_H
