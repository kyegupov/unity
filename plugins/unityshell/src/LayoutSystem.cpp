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

#include "LayoutSystem.h"
#include "WindowManager.h"

namespace unity {
namespace ui {
	
LayoutSystem::LayoutSystem()
{
  spacing = 8;
}

LayoutSystem::~LayoutSystem()
{
}

void LayoutSystem::LayoutWindows (LayoutWindowList windows, nux::Geometry const& max_bounds, nux::Geometry& final_bounds)
{
  unsigned int size = windows.size();

  if (size == 0)
    return;
  
  for (auto window : windows)
  {
  	window->geo = WindowManager::Default ()->GetWindowGeometry (window->xid);
    window->aspect_ratio = (float)window->geo.width / (float)window->geo.height;
  }
  
  LayoutGridWindows (windows, max_bounds, final_bounds);
}

nux::Size LayoutSystem::GridSizeForWindows (LayoutWindowList windows, nux::Geometry const& max_bounds)
{
  int count = (int)windows.size();

  int width = 1;
  int height = 1;

  if (count == 2)
  {
    float stacked_aspect = std::max (windows[0]->geo.width, windows[1]->geo.width) / (float)(windows[0]->geo.height + windows[1]->geo.height);  
    float row_aspect = (float)(windows[0]->geo.width + windows[1]->geo.width) / std::max(windows[0]->geo.height, windows[1]->geo.height);
    float box_aspect = (float)max_bounds.width / max_bounds.height;
    if (abs(row_aspect - box_aspect) > abs(stacked_aspect - box_aspect))
    {
      height = 2;
    }
    else
    {
      width = 2;
    }
  }
  else
  {
    while (width * height < count)
    {
      if (height < width)
        height++;
      else
        width++;
    }
  }

  return nux::Size (width, height);
}

nux::Geometry LayoutSystem::CompressAndPadRow (LayoutWindowList const& windows, nux::Geometry const& max_bounds)
{
  int total_width = 0;
  int max_height = 0;
  for (LayoutWindow::Ptr window : windows)
  {
    window->result.x = total_width;
    total_width += spacing + window->result.width;
    max_height = std::max (window->result.height, max_height);
  }

  total_width -= spacing;

  int x1 = G_MAXINT;
  int y1 = G_MAXINT;
  int x2 = G_MININT;
  int y2 = G_MININT;

  int offset = std::max (0, (max_bounds.width - total_width) / 2);
  for (LayoutWindow::Ptr window : windows)
  {
    window->result.x += max_bounds.x + offset;
    window->result.y = max_bounds.y + (max_height - window->result.height) / 2;
    
    x1 = std::min (window->result.x, x1);
    y1 = std::min (window->result.y, y1);
    x2 = std::max (window->result.x + window->result.width, x2);
    y2 = std::max (window->result.y + window->result.height, y2);
  }

  return nux::Geometry (x1, y1, x2 - x1, y2 - y1);
}

nux::Geometry LayoutSystem::LayoutRow (LayoutWindowList const& row, nux::Geometry const& row_bounds)
{
  nux::Geometry unpadded_bounds = row_bounds;
  unpadded_bounds.width -= spacing * (row.size () - 1);

  int combined_width = 0;
  for (LayoutWindow::Ptr window : row)
  {
    float scalar = unpadded_bounds.height / (float)window->geo.height;
    combined_width += window->geo.width * scalar;
  }

  float global_scalar = unpadded_bounds.width / (float)combined_width;

  int x = unpadded_bounds.x;
  int y = unpadded_bounds.y;

  // precision of X,Y is relatively unimportant as the Compression stage will fix any issues, sizing
  // is however set at this point.
  for (LayoutWindow::Ptr window : row)
  {
    // we dont allow scaling up
    float final_scalar = std::min (1.0f, (unpadded_bounds.height / (float)window->geo.height) * global_scalar);
    
    window->result.x = x;
    window->result.y = y;
    window->result.width = window->geo.width * final_scalar;
    window->result.height = window->geo.height * final_scalar;

    x += window->result.width;
  }

  return CompressAndPadRow (row, row_bounds);
}

void LayoutSystem::LayoutGridWindows (LayoutWindowList const& windows, nux::Geometry const& max_bounds, nux::Geometry& final_bounds)
{
  nux::Size grid_size = GridSizeForWindows (windows, max_bounds);

  int width = grid_size.width;
  int height = grid_size.height;

  int non_spacing_height = max_bounds.height - ((height - 1) * spacing);
  int row_height = non_spacing_height / height;
  int start_y = max_bounds.y;

  int x = 0;
  int y = 0;

  int low_y = 0;

  int first_row_size = (int)windows.size() - (width * (height - 1));

  LayoutWindowList row_accum;
  for (LayoutWindow::Ptr window : windows)
  {
    row_accum.push_back (window);
    ++x;

    if (x >= width || (y == 0 && x == first_row_size))
    {
      // end of row
      x = 0;
      ++y;

      nux::Geometry row_max_bounds (max_bounds.x, start_y, max_bounds.width, row_height);
      nux::Geometry row_final_bounds = LayoutRow (row_accum, row_max_bounds);

      low_y = row_final_bounds.y + row_final_bounds.height;

      start_y += row_final_bounds.height + spacing;

      row_accum.clear ();
    }
  }

  int x1 = G_MAXINT;
  int y1 = G_MAXINT;
  int x2 = G_MININT;
  int y2 = G_MININT;

  int offset = (max_bounds.height - (low_y - max_bounds.y)) / 2;
  for (auto window : windows)
  {
    window->result.y += offset;

  	x1 = std::min (window->result.x, x1);
    y1 = std::min (window->result.y, y1);
    x2 = std::max (window->result.x + window->result.width, x2);
    y2 = std::max (window->result.y + window->result.height, y2);
  }

  final_bounds = nux::Geometry (x1, y1, x2 - x1, y2 - y1);
}

nux::Geometry LayoutSystem::ScaleBoxIntoBox (nux::Geometry const& bounds, nux::Geometry const& box)
{
	float bound_aspect = (float) bounds.width / (float) bounds.height;
	float box_aspect = (float) box.width / (float) box.height;

	nux::Geometry result;

	if (box_aspect > bound_aspect)
	{
		// box wider than bounds
		result.x = bounds.x;

		result.width = bounds.width;
		result.height = result.width / box_aspect;

		result.y = bounds.y + (bounds.height - result.height) / 2;
	}
	else
	{
		result.y = bounds.y;

		result.height = bounds.height;
		result.width = result.height * box_aspect;

		result.x = bounds.x + (bounds.width - result.width) / 2;
	}

  if (result.width > box.width)
  {
    result.x += (result.width - box.width) / 2;
    result.width = box.width;
    result.y += (result.height - box.height) / 2;
    result.height = box.height;
  }

	return result;
}

LayoutWindow::LayoutWindow(Window xid)
 : xid (xid)
{

}

}
}