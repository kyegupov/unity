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
 *              Marco Trevisan <3v1n0@ubuntu.com>
 */
#include <glib.h>
#include <pango/pangocairo.h>
#include <gtk/gtk.h>

#include <Nux/Nux.h>
#include <Nux/HLayout.h>
#include <Nux/VLayout.h>
#include <Nux/TextureArea.h>
#include <NuxCore/Logger.h>

#include <NuxGraphics/GLThread.h>
#include <NuxGraphics/XInputWindow.h>
#include <Nux/BaseWindow.h>

#include "CairoTexture.h"
#include "PanelMenuView.h"
#include "PanelStyle.h"
#include "DashSettings.h"
#include "UBusMessages.h"
#include "UScreen.h"

#include <UnityCore/Variant.h>
#include <UnityCore/AppmenuIndicator.h>

#include <gio/gdesktopappinfo.h>
#include <gconf/gconf-client.h>

#include <glib/gi18n-lib.h>

#define WINDOW_TITLE_FONT_KEY "/apps/metacity/general/titlebar_font"

namespace {
  nux::logging::Logger logger("unity.panel.menu");
  const int MENUS_PADDING = 6;
}

namespace unity
{

PanelMenuView::PanelMenuView(int padding)
  : _matcher(bamf_matcher_get_default()),
    _is_integrated(false),
    _is_inside(false),
    _is_maximized(false),
    _is_own_window(false),
    _integrated_menu(nullptr),
    _last_active_view(nullptr),
    _new_application(nullptr),
    _last_width(0),
    _last_height(0),
    _dash_showing(false),
    _switcher_showing(false),
    _show_now_activated(false),
    _we_control_active(false),
    _new_app_menu_shown(false),
    _monitor(0),
    _active_xid(0),
    _active_moved_id(0),
    _update_show_now_id(0),
    _new_app_show_id(0),
    _new_app_hide_id(0),
    _menus_fadein(100),
    _menus_fadeout(120),
    _menus_discovery(2),
    _menus_discovery_fadein(200),
    _menus_discovery_fadeout(300),
    _fade_in_animator(_menus_fadein),
    _fade_out_animator(_menus_fadeout)
{
  WindowManager* win_manager;

  // TODO: kill _menu_layout - should just use the _layout defined
  // in the base class.
  _menu_layout = new nux::HLayout("", NUX_TRACKER_LOCATION);
  _menu_layout->SetParentObject(this);

  /* This is for our parent and for PanelView to read indicator entries, we
   * shouldn't touch this again
   */
  layout_ = _menu_layout;

  BamfWindow* active_win = bamf_matcher_get_active_window(_matcher);
  if (BAMF_IS_WINDOW(active_win))
    _active_xid = bamf_window_get_xid(active_win);

  _view_opened_signal.Connect(_matcher, "view-opened",
                              sigc::mem_fun(this, &PanelMenuView::OnViewOpened));
  _view_closed_signal.Connect(_matcher, "view-closed",
                              sigc::mem_fun(this, &PanelMenuView::OnViewClosed));
  _active_win_changed_signal.Connect(_matcher, "active-window-changed",
                                     sigc::mem_fun(this, &PanelMenuView::OnActiveWindowChanged));
  _active_app_changed_signal.Connect(_matcher, "active-application-changed",
                                     sigc::mem_fun(this, &PanelMenuView::OnActiveAppChanged));

  _padding = padding;

  _window_buttons = new WindowButtons();
  _window_buttons->SetParentObject(this);
  _window_buttons->NeedRedraw();

  _window_buttons->close_clicked.connect(sigc::mem_fun(this, &PanelMenuView::OnCloseClicked));
  _window_buttons->minimize_clicked.connect(sigc::mem_fun(this, &PanelMenuView::OnMinimizeClicked));
  _window_buttons->restore_clicked.connect(sigc::mem_fun(this, &PanelMenuView::OnRestoreClicked));
  _window_buttons->mouse_enter.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseEnter));
  _window_buttons->mouse_leave.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseLeave));
  //_window_buttons->mouse_move.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseMove));

  _panel_titlebar_grab_area = new PanelTitlebarGrabArea();
  _panel_titlebar_grab_area->SetParentObject(this);
  _panel_titlebar_grab_area->SinkReference();
  _panel_titlebar_grab_area->mouse_down.connect(sigc::mem_fun(this, &PanelMenuView::OnMouseClicked));
  _panel_titlebar_grab_area->mouse_down.connect(sigc::mem_fun(this, &PanelMenuView::OnMouseMiddleClicked));
  _panel_titlebar_grab_area->mouse_down.connect(sigc::mem_fun(this, &PanelMenuView::OnMaximizedGrabStart));
  _panel_titlebar_grab_area->mouse_drag.connect(sigc::mem_fun(this, &PanelMenuView::OnMaximizedGrabMove));
  _panel_titlebar_grab_area->mouse_up.connect(sigc::mem_fun(this, &PanelMenuView::OnMaximizedGrabEnd));
  _panel_titlebar_grab_area->mouse_double_click.connect(sigc::mem_fun(this, &PanelMenuView::OnMouseDoubleClicked));

  win_manager = WindowManager::Default();

  win_manager->window_minimized.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowMinimized));
  win_manager->window_unminimized.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowUnminimized));
  //win_manager->initiate_spread.connect(sigc::mem_fun(this, &PanelMenuView::OnSpreadInitiate));
  //win_manager->terminate_spread.connect(sigc::mem_fun(this, &PanelMenuView::OnSpreadTerminate));

  win_manager->window_maximized.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowMaximized));
  win_manager->window_restored.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowRestored));
  win_manager->window_unmapped.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowUnmapped));
  win_manager->window_mapped.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowMapped));
  win_manager->window_moved.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowMoved));
  win_manager->window_resized.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowMoved));
  win_manager->window_decorated.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowDecorated));
  win_manager->window_undecorated.connect(sigc::mem_fun(this, &PanelMenuView::OnWindowUndecorated));

  _style_changed_connection = panel::Style::Instance().changed.connect([&] {
    _title_texture = nullptr;
    Refresh();
  });

  mouse_enter.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseEnter));
  mouse_leave.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseLeave));
  //mouse_move.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseMove));

  _panel_titlebar_grab_area->mouse_enter.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseEnter));
  _panel_titlebar_grab_area->mouse_leave.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseLeave));

  // Register for all the interesting events
  _ubus_manager.RegisterInterest(UBUS_OVERLAY_SHOWN, [&] (GVariant*) {
    _dash_showing = true;
    QueueDraw();
  });

  _ubus_manager.RegisterInterest(UBUS_OVERLAY_HIDDEN, [&] (GVariant*) {
    _dash_showing = false;
    QueueDraw();
  });

  _ubus_manager.RegisterInterest(UBUS_SWITCHER_SHOWN, sigc::mem_fun(this, &PanelMenuView::OnSwitcherShown));
  _ubus_manager.RegisterInterest(UBUS_SWITCHER_SELECTION_CHANGED, sigc::mem_fun(this, &PanelMenuView::OnSwitcherSelectionChanged));

  _fade_in_animator.animation_updated.connect(sigc::mem_fun(this, &PanelMenuView::OnFadeInChanged));
  _fade_in_animator.animation_ended.connect(sigc::mem_fun(this, &PanelMenuView::FullRedraw));
  _fade_out_animator.animation_updated.connect(sigc::mem_fun(this, &PanelMenuView::OnFadeOutChanged));
  _fade_out_animator.animation_ended.connect(sigc::mem_fun(this, &PanelMenuView::FullRedraw));

  SetOpacity(0.0f);
  _window_buttons->SetOpacity(0.0f);

  Refresh();
  FullRedraw();
}

PanelMenuView::~PanelMenuView()
{
  if (_active_moved_id)
    g_source_remove(_active_moved_id);

  if (_new_app_show_id)
    g_source_remove(_new_app_show_id);

  if (_new_app_hide_id)
    g_source_remove(_new_app_hide_id);

  _menu_layout->UnReference();
  _window_buttons->UnReference();
  _panel_titlebar_grab_area->UnReference();

  _style_changed_connection.disconnect();
  _mode_changed_connection.disconnect();
}

void
PanelMenuView::AddIndicator(indicator::Indicator::Ptr const& indicator)
{
  if (!GetIndicators().empty())
  {
    LOG_ERROR(logger) << "PanelMenuView has already an indicator!";
    return;
  }

  PanelIndicatorsView::AddIndicator(indicator);

  if (indicator->IsAppmenu())
  {
    auto appmenuindicator = dynamic_cast<indicator::AppmenuIndicator*>(indicator.get());

    if (appmenuindicator)
    {
      _is_integrated = appmenuindicator->IsIntegrated();
      _window_buttons->SetFocusedState(!_is_integrated ||
                                       GetMaximizedWindow() == _active_xid);

      if (!_is_integrated)
        _integrated_menu = nullptr;

      auto conn = appmenuindicator->integrated_changed.connect([&] (bool integrated) {
        _is_integrated = integrated;
        _window_buttons->SetFocusedState(!_is_integrated ||
                                         GetMaximizedWindow() == _active_xid);

        if (!_is_integrated)
          _integrated_menu = nullptr;

        Refresh();
        FullRedraw();
      });

      _mode_changed_connection = conn;
    }
  }
}

void
PanelMenuView::RemoveIndicator(indicator::Indicator::Ptr const& indicator)
{
  PanelIndicatorsView::RemoveIndicator(indicator);

  if (indicator->IsAppmenu())
    _mode_changed_connection.disconnect();
}

void
PanelMenuView::SetMenuShowTimings(int fadein, int fadeout, int discovery,
                                  int discovery_fadein, int discovery_fadeout)
{
  if (fadein > -1)
  {
    _menus_fadein = fadein;
    _fade_in_animator.SetDuration(_menus_fadein);
  }

  if (fadeout > -1)
  {
    _menus_fadeout = fadeout;
    _fade_out_animator.SetDuration(_menus_fadeout);
  }

  if (discovery > -1)
    _menus_discovery = discovery;

  if (discovery_fadein > -1)
    _menus_discovery_fadein = discovery_fadein;

  if (discovery_fadeout > -1)
    _menus_discovery_fadeout = discovery_fadeout;
}

void
PanelMenuView::FullRedraw()
{
  _menu_layout->NeedRedraw();
  _window_buttons->NeedRedraw();
  NeedRedraw();
}

nux::Area*
PanelMenuView::FindAreaUnderMouse(const nux::Point& mouse_position, nux::NuxEventType event_type)
{
  bool mouse_inside = TestMousePointerInclusionFilterMouseWheel(mouse_position, event_type);

  if (mouse_inside == false)
    return nullptr;

  Area* found_area = nullptr;
  if (!_we_control_active)
  {
    found_area = _panel_titlebar_grab_area->FindAreaUnderMouse(mouse_position, event_type);
    NUX_RETURN_VALUE_IF_NOTNULL(found_area, found_area);
  }

  if (_is_maximized || _dash_showing || (_is_integrated && GetMaximizedWindow()))
  {
    if (_window_buttons)
    {
      found_area = _window_buttons->FindAreaUnderMouse(mouse_position, event_type);
      NUX_RETURN_VALUE_IF_NOTNULL(found_area, found_area);
    }
  }

  if (_panel_titlebar_grab_area)
  {
    found_area = _panel_titlebar_grab_area->FindAreaUnderMouse(mouse_position, event_type);
    NUX_RETURN_VALUE_IF_NOTNULL(found_area, found_area);
  }

  if (!_is_own_window)
  {
    found_area = _menu_layout->FindAreaUnderMouse(mouse_position, event_type);
    NUX_RETURN_VALUE_IF_NOTNULL(found_area, found_area);
  }

  return View::FindAreaUnderMouse(mouse_position, event_type);
}

long PanelMenuView::PostLayoutManagement(long LayoutResult)
{
  long res = View::PostLayoutManagement(LayoutResult);
  int old_window_buttons_w, new_window_buttons_w;
  int old_menu_area_w, new_menu_area_w;

  nux::Geometry geo = GetGeometry();

  old_window_buttons_w = _window_buttons->GetContentWidth();
  _window_buttons->SetGeometry(geo.x + _padding, geo.y, old_window_buttons_w, geo.height);
  _window_buttons->ComputeContentSize();
  new_window_buttons_w = _window_buttons->GetContentWidth();

  /* Explicitly set the size and position of the widgets */
  geo.x += _padding + new_window_buttons_w + _padding;
  geo.width -= _padding + new_window_buttons_w + _padding;

  old_menu_area_w = _menu_layout->GetContentWidth();
  _menu_layout->SetGeometry(geo.x, geo.y, old_menu_area_w, geo.height);
  _menu_layout->ComputeContentSize();
  new_menu_area_w = _menu_layout->GetContentWidth();

  geo.x += new_menu_area_w;
  geo.width -= new_menu_area_w;

  _panel_titlebar_grab_area->SetGeometry(geo.x, geo.y, geo.width, geo.height);

  if (_is_inside)
    NeedRedraw();

  return res;
}

void
PanelMenuView::OnFadeInChanged(double opacity)
{
  if (DrawMenus() && GetOpacity() != 1.0f)
    SetOpacity(opacity);

  if (DrawWindowButtons() && _window_buttons->GetOpacity() != 1.0f)
    _window_buttons->SetOpacity(opacity);

  NeedRedraw();
}

void
PanelMenuView::OnFadeOutChanged(double progress)
{
  double opacity = CLAMP(1.0f - progress, 0.0f, 1.0f);

  if (!DrawMenus() && GetOpacity() != 0.0f)
    SetOpacity(opacity);

  if (!DrawWindowButtons() && _window_buttons->GetOpacity() != 0.0f)
    _window_buttons->SetOpacity(opacity);

  NeedRedraw();
}

bool
PanelMenuView::DrawMenus()
{
  if (_is_integrated)
  {
    return (GetMaximizedWindow() != 0);
  }

  if (!_is_own_window && !_dash_showing && _we_control_active && !_switcher_showing)
  {
    if (_is_inside || _last_active_view || _show_now_activated || _new_application)
    {
      return true;
    }
  }

  return false;
}

bool
PanelMenuView::DrawWindowButtons()
{
  if (_dash_showing || (_is_integrated && GetMaximizedWindow() != 0))
    return true;

  if (!_is_own_window && _we_control_active && _is_maximized && !_switcher_showing)
  {
    if (_is_inside || _show_now_activated || _new_application)
    {
      return true;
    }
  }

  return false;
}

void
PanelMenuView::Draw(nux::GraphicsEngine& GfxContext, bool force_draw)
{
  nux::Geometry geo = GetGeometry();
  int button_width = _padding + _window_buttons->GetContentWidth() + _padding;
  const float factor = 4;
  button_width /= factor;

  if (geo.width != _last_width || geo.height != _last_height)
  {
    _last_width = geo.width;
    _last_height = geo.height;
    Refresh();
  }

  GfxContext.PushClippingRectangle(geo);

  /* "Clear" out the background */
  nux::ROPConfig rop;
  rop.Blend = true;
  rop.SrcBlend = GL_ONE;
  rop.DstBlend = GL_ONE_MINUS_SRC_ALPHA;

  nux::ColorLayer layer(nux::Color(0x00000000), true, rop);
  nux::GetPainter().PushDrawLayer(GfxContext, GetGeometry(), &layer);

  if (_title_texture && !_is_own_window)
  {
    guint blend_alpha = 0, blend_src = 0, blend_dest = 0;
    bool draw_menus = DrawMenus();
    bool draw_window_buttons = DrawWindowButtons();
    bool has_menu = false;
    bool draw_faded_title = false;

    GfxContext.GetRenderStates().GetBlend(blend_alpha, blend_src, blend_dest);

    for (auto entry : entries_)
    {
      if (entry.second->IsVisible())
      {
        has_menu = true;
        break;
      }
    }

    if (!draw_window_buttons && _we_control_active && has_menu &&
        (draw_menus || (GetOpacity() > 0.0f && _window_buttons->GetOpacity() == 0.0f)))
    {
      draw_faded_title = true;
    }

    if (draw_faded_title)
    {
      bool build_gradient = false;
      nux::SURFACE_LOCKED_RECT lockrect;
      lockrect.pBits = 0;
      bool locked = false;

      if (_gradient_texture.IsNull() || (_gradient_texture->GetWidth() != geo.width))
      {
        build_gradient = true;
      }
      else
      {
        if (_gradient_texture->LockRect(0, &lockrect, nullptr) != OGL_OK)
          build_gradient = true;
        else
          locked = true;

        if (!lockrect.pBits)
        {
          build_gradient = true;

          if (locked)
            _gradient_texture->UnlockRect(0);
        }
      }

      if (build_gradient)
      {
        nux::NTextureData texture_data(nux::BITFMT_R8G8B8A8, geo.width, 1, 1);

        _gradient_texture = nux::GetGraphicsDisplay()->GetGpuDevice()->
                            CreateSystemCapableDeviceTexture(texture_data.GetWidth(),
                            texture_data.GetHeight(), 1, texture_data.GetFormat());
        locked = (_gradient_texture->LockRect(0, &lockrect, nullptr) == OGL_OK);
      }

      BYTE* dest_buffer = (BYTE*) lockrect.pBits;
      int gradient_opacity = 255.0f * GetOpacity();
      int buttons_opacity = 255.0f * _window_buttons->GetOpacity();

      int first_step = button_width * (factor - 1);
      int second_step = button_width * factor;

      for (int x = 0; x < geo.width && dest_buffer && locked; x++)
      {
        BYTE r, g, b, a;

        r = 223;
        g = 219;
        b = 210;

        if (x < first_step)
        {
          int color_increment = (first_step - x) * 4;

          r = CLAMP(r + color_increment, r, 0xff);
          g = CLAMP(g + color_increment, g, 0xff);
          b = CLAMP(b + color_increment, b, 0xff);
          a = 0xff - buttons_opacity;
        }
        else if (x < second_step)
        {
          a = 0xff - gradient_opacity * (((float)x - (first_step)) /
                                         (float)(button_width));
        }
        else
        {
          if (!draw_menus)
          {
            a = 0xff - gradient_opacity;
          }
          else
          {
            // If we're fading-out the title, it's better to quickly hide
            // the transparent right-most area
            a = CLAMP(0xff - gradient_opacity - 0x55, 0x00, 0xff);
          }
        }

        *(dest_buffer + 4 * x + 0) = (r * a) / 0xff; //red
        *(dest_buffer + 4 * x + 1) = (g * a) / 0xff; //green
        *(dest_buffer + 4 * x + 2) = (b * a) / 0xff; //blue
        *(dest_buffer + 4 * x + 3) = a;
      }

      // FIXME Nux shouldn't make unity to crash if we try to unlock a wrong rect
      if (locked)
        _gradient_texture->UnlockRect(0);

      GfxContext.GetRenderStates().SetBlend(true, GL_ONE, GL_ONE_MINUS_SRC_ALPHA);

      nux::TexCoordXForm texxform0;
      nux::TexCoordXForm texxform1;

      // Modulate the checkboard and the gradient texture
      GfxContext.QRP_2TexMod(geo.x, geo.y,
                             geo.width, geo.height,
                             _gradient_texture, texxform0,
                             nux::color::White,
                             _title_texture->GetDeviceTexture(),
                             texxform1,
                             nux::color::White);
    }
    else if (!_dash_showing)
    {
      if (_we_control_active && _window_buttons->GetOpacity() == 0.0 &&
          (!has_menu || (has_menu && GetOpacity() == 0.0)))
      {
        nux::TexCoordXForm texxform;
        GfxContext.QRP_1Tex(geo.x, geo.y, geo.width, geo.height,
                            _title_texture->GetDeviceTexture(), texxform,
                            nux::color::White);
      }
      else
      {
        double title_opacity = 1.0f;

        if (has_menu)
          title_opacity -= MAX(GetOpacity(), _window_buttons->GetOpacity());
        else
          title_opacity -= _window_buttons->GetOpacity();

        if (!draw_window_buttons && !draw_menus)
        {
          // If we're fading-out the buttons/menus, let's fade-in quickly the title
          title_opacity = CLAMP(title_opacity + 0.1f, 0.0f, 1.0f);
        }
        else
        {
          // If we're fading-in the buttons/menus, let's fade-out quickly the title
          title_opacity = CLAMP(title_opacity - 0.2f, 0.0f, 1.0f);
        }

        if (title_opacity > 0.0f)
        {
          nux::TexCoordXForm texxform;
          GfxContext.QRP_1Tex(geo.x, geo.y, geo.width, geo.height,
                              _title_texture->GetDeviceTexture(), texxform,
                              nux::color::White * title_opacity);
        }
      }
    }

    GfxContext.GetRenderStates().SetBlend(blend_alpha, blend_src, blend_dest);
  }

  nux::GetPainter().PopBackground();

  GfxContext.PopClippingRectangle();
}

void
PanelMenuView::DrawContent(nux::GraphicsEngine& GfxContext, bool force_draw)
{
  nux::Geometry geo = GetGeometry();
  bool draw_menus = DrawMenus();
  bool draw_buttons = DrawWindowButtons();

  GfxContext.PushClippingRectangle(geo);

  if (draw_menus)
  {
    for (auto entry : entries_)
      entry.second->SetDisabled(false);

    _menu_layout->ProcessDraw(GfxContext, true);

    _fade_out_animator.Stop();

    if (_new_application && !_is_inside)
    {
      _fade_in_animator.Start(_menus_discovery_fadein, GetOpacity());
    }
    else
    {
      _fade_in_animator.Start(GetOpacity());
      _new_app_menu_shown = false;
    }
  }
  else
  {
    for (auto entry : entries_)
      entry.second->SetDisabled(true);
  }

  if (GetOpacity() != 0.0f && !draw_menus)
  {
    _menu_layout->ProcessDraw(GfxContext, true);

    _fade_in_animator.Stop();

    if (!_new_app_menu_shown)
    {
      _fade_out_animator.Start(1.0f - GetOpacity());
    }
    else
    {
      _fade_out_animator.Start(_menus_discovery_fadeout, 1.0f - GetOpacity());
    }
  }

  if (draw_buttons)
  {
    _window_buttons->ProcessDraw(GfxContext, true);

    _fade_out_animator.Stop();
    _fade_in_animator.Start(_window_buttons->GetOpacity());
  }

  if (_window_buttons->GetOpacity() != 0.0f && !draw_buttons)
  {
    _window_buttons->ProcessDraw(GfxContext, true);
    _fade_in_animator.Stop();

    /* If we try to hide only the buttons, then use a faster fadeout */
    if (!_fade_out_animator.IsRunning())
    {
      _fade_out_animator.Start(_menus_fadeout/3, 1.0f - _window_buttons->GetOpacity());
    }
  }

  GfxContext.PopClippingRectangle();
}

std::string
PanelMenuView::GetActiveViewName()
{
  std::string label;
  BamfWindow* window;

  _is_own_window = false;

  window = bamf_matcher_get_active_window(_matcher);

  if (BAMF_IS_WINDOW(window))
  {
    std::vector<Window> const& our_xids = nux::XInputWindow::NativeHandleList();
    guint32 window_xid = bamf_window_get_xid(BAMF_WINDOW(window));

    if (std::find(our_xids.begin(), our_xids.end(), window_xid) != our_xids.end())
    {
      _is_own_window = true;
      return "";
    }

    if (BAMF_IS_WINDOW(window) &&
        bamf_window_get_window_type(window) == BAMF_WINDOW_DESKTOP)
    {
      label = _("Ubuntu Desktop");
    }
    else if (!WindowManager::Default()->IsWindowOnCurrentDesktop(window_xid) ||
        WindowManager::Default()->IsWindowObscured(window_xid))
    {
       return "";
    }

    if (_is_maximized)
      label = glib::String(bamf_view_get_name(BAMF_VIEW(window))).Str();
  }

  if (label.empty())
  {
    BamfApplication* app = bamf_matcher_get_active_application(_matcher);
    if (BAMF_IS_APPLICATION(app))
    {
      const gchar* desktop_file = bamf_application_get_desktop_file(app);
      std::string filename(desktop_file ? desktop_file : "");

      if (!filename.empty())
      {
        glib::Object<GDesktopAppInfo> info(g_desktop_app_info_new_from_filename(filename.c_str()));

        if (info)
        {
          const gchar* name = g_app_info_get_display_name(glib::object_cast<GAppInfo>(info));
          label = (name ? name : "");
        }
        else
        {
          g_warning("Unable to get GDesktopAppInfo for %s",
                    bamf_application_get_desktop_file(app));
        }
      }

      if (label.empty())
      {
        BamfWindow* active_win = bamf_matcher_get_active_window(_matcher);

        if (BAMF_IS_VIEW(active_win))
        {
          auto view = reinterpret_cast<BamfView*>(active_win);
          label = glib::String(bamf_view_get_name(view)).Str();
        }
      }
    }
    else
    {
      label = "";
    }
  }

  glib::String escaped(g_markup_escape_text(label.c_str(), -1));

  std::ostringstream bold_label;
  bold_label << "<b>" << escaped.Str() << "</b>";

  return bold_label.str();
}

std::string
PanelMenuView::GetMaximizedViewName()
{
  Window maximized = GetMaximizedWindow();
  BamfWindow* window = nullptr;
  std::string label(_("Ubuntu Desktop"));

  if (maximized != 0)
  {
    GList* windows = bamf_matcher_get_window_stack_for_monitor(_matcher, _monitor);

    for (GList* l = windows; l; l = l->next)
    {
      if (!BAMF_IS_WINDOW(l->data))
        continue;

      auto win = static_cast<BamfWindow*>(l->data);

      if (bamf_window_get_xid(win) == maximized)
      {
        window = win;
        break;
      }
    }

    g_list_free(windows);
  }

  if (BAMF_IS_WINDOW(window))
  {
    BamfView* view = reinterpret_cast<BamfView*>(window);
    BamfApplication* app = bamf_matcher_get_application_for_window(_matcher, window);

    if (BAMF_IS_APPLICATION(app))
      view = reinterpret_cast<BamfView*>(app);

    label = glib::String(bamf_view_get_name(view)).Str();
  }

  glib::String escaped(g_markup_escape_text(label.c_str(), -1));

  std::ostringstream bold_label;
  bold_label << "<b>" << escaped.Str() << "</b>";

  return bold_label.str();
}

void PanelMenuView::DrawText(cairo_t *cr_real, int x, int y, int width, int height,
                             std::string const& label)
{
  cairo_t* cr;
  cairo_pattern_t* linpat;
  const int fading_pixels = 35;

  int  text_width = 0;
  int  text_height = 0;
  int  text_space = 0;

  // Find out dimensions first
  GdkScreen* screen = gdk_screen_get_default();
  GtkSettings* settings = gtk_settings_get_default();
  glib::Object<GConfClient> client(gconf_client_get_default());
  PangoContext* cxt;
  PangoRectangle log_rect;
  PangoFontDescription* desc;
  gint dpi;

  nux::CairoGraphics util_cg(CAIRO_FORMAT_ARGB32, 1, 1);
  cr = util_cg.GetContext();

  g_object_get(settings, "gtk-xft-dpi", &dpi, nullptr);

  glib::String font_description(gconf_client_get_string(client, WINDOW_TITLE_FONT_KEY, nullptr));
  desc = pango_font_description_from_string(font_description);

  glib::Object<PangoLayout> layout(pango_cairo_create_layout(cr));
  pango_layout_set_font_description(layout, desc);
  pango_layout_set_markup(layout, label.c_str(), -1);

  cxt = pango_layout_get_context(layout);
  pango_cairo_context_set_font_options(cxt, gdk_screen_get_font_options(screen));
  pango_cairo_context_set_resolution(cxt, (float)dpi / (float)PANGO_SCALE);
  pango_layout_context_changed(layout);

  pango_layout_get_extents(layout, nullptr, &log_rect);
  text_width = log_rect.width / PANGO_SCALE;
  text_height = log_rect.height / PANGO_SCALE;

  pango_font_description_free(desc);
  cairo_destroy(cr);


  // Draw the text
  GtkStyleContext* style_context = panel::Style::Instance().GetStyleContext();
  text_space = width - x;
  cr = cr_real;

  gtk_style_context_save(style_context);

  GtkWidgetPath* widget_path = gtk_widget_path_new();
  gtk_widget_path_iter_set_name(widget_path, -1 , "UnityPanelWidget");
  gtk_widget_path_append_type(widget_path, GTK_TYPE_MENU_BAR);
  gtk_widget_path_append_type(widget_path, GTK_TYPE_MENU_ITEM);

  gtk_style_context_set_path(style_context, widget_path);
  gtk_style_context_add_class(style_context, GTK_STYLE_CLASS_MENUBAR);
  gtk_style_context_add_class(style_context, GTK_STYLE_CLASS_MENUITEM);

  y += (height - text_height) / 2;

  pango_cairo_update_layout(cr, layout);

  if (text_width > text_space)
  {
    int out_pixels = text_width - text_space;
    int fading_width = out_pixels < fading_pixels ? out_pixels : fading_pixels;

    cairo_push_group(cr);
    gtk_render_layout(style_context, cr, x, y, layout);
    cairo_pop_group_to_source(cr);

    linpat = cairo_pattern_create_linear(width - fading_width, y, width, y);
    cairo_pattern_add_color_stop_rgba(linpat, 0, 0, 0, 0, 1);
    cairo_pattern_add_color_stop_rgba(linpat, 1, 0, 0, 0, 0);
    cairo_mask(cr, linpat);

    cairo_pattern_destroy(linpat);
  }
  else
  {
    gtk_render_layout(style_context, cr, x, y, layout);
  }

  x += text_width;

  gtk_widget_path_free(widget_path);
  gtk_style_context_restore(style_context);
}

void
PanelMenuView::Refresh()
{
  nux::Geometry const& geo = GetGeometry();
  static nux::Geometry old_geo;

  // We can get into a race that causes the geometry to be wrong as there hasn't been a
  // layout cycle before the first callback. This is to protect from that.
  if (geo.width > _monitor_geo.width)
    return;

  if (!_switcher_showing)
  {
    std::string new_title;

    if (_is_integrated)
    {
      new_title = GetMaximizedViewName();

      if (_integrated_menu)
        _integrated_menu->SetLabel(new_title);
    }
    else
    {
      new_title = GetActiveViewName();
    }

    if (_panel_title != new_title)
    {
      _panel_title = new_title;
    }
    else if (old_geo == geo && _title_texture)
    {
      return;
    }
  }

  int  x = 0;
  int  y = 0;
  int  width = geo.width;
  int  height = geo.height;

  nux::CairoGraphics cairo_graphics(CAIRO_FORMAT_ARGB32, width, height);
  cairo_t* cr = cairo_graphics.GetContext();
  cairo_set_line_width(cr, 1);

  cairo_set_operator(cr, CAIRO_OPERATOR_CLEAR);
  cairo_paint(cr);

  cairo_set_operator(cr, CAIRO_OPERATOR_OVER);

  x += _padding;
  DrawText(cr, x, y, width, height, _panel_title);

  cairo_destroy(cr);

  _title_texture = texture_from_cairo_graphics(cairo_graphics);

  old_geo = geo;
}

void
PanelMenuView::OnActiveChanged(PanelIndicatorEntryView* view,
                               bool                           is_active)
{
  if (is_active)
    _last_active_view = view;
  else
  {
    if (_last_active_view == view)
    {
      _last_active_view = nullptr;
    }
  }

  Refresh();
  FullRedraw();
}

void
PanelMenuView::OnEntryAdded(indicator::Entry::Ptr const& entry)
{
  PanelIndicatorEntryView* view;

  if (!_is_integrated)
  {
    view = new PanelIndicatorEntryView(entry, MENUS_PADDING, IndicatorEntryType::MENU);
    view->mouse_enter.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseEnter));
    view->mouse_leave.connect(sigc::mem_fun(this, &PanelMenuView::OnPanelViewMouseLeave));
  }
  else
  {
    _integrated_menu = new PanelIndicatorAppmenuView(entry);
    _integrated_menu->SetControlledWindowXid(GetMaximizedWindow());
    _integrated_menu->SetLabel(GetMaximizedViewName());
    view = _integrated_menu;
  }

  entry->show_now_changed.connect(sigc::mem_fun(this, &PanelMenuView::UpdateShowNow));
  view->active_changed.connect(sigc::mem_fun(this, &PanelMenuView::OnActiveChanged));

  AddEntryView(view, IndicatorEntryPosition::END);
}

void
PanelMenuView::AllMenusClosed()
{
  auto mouse = nux::GetGraphicsDisplay()->GetMouseScreenCoord();
  _is_inside = GetAbsoluteGeometry().IsPointInside(mouse.x, mouse.y);
  _last_active_view = nullptr;

  FullRedraw();
}

void
PanelMenuView::OnNameChanged(BamfView* bamf_view, gchar* new_name, gchar* old_name)
{
  Refresh();
  FullRedraw();
}

gboolean
PanelMenuView::OnNewAppShow(PanelMenuView* self)
{
  BamfApplication* active_app = bamf_matcher_get_active_application(self->_matcher);
  self->_new_application = glib::Object<BamfApplication>(active_app, glib::AddRef());
  self->QueueDraw();

  if (self->_new_app_hide_id)
  {
    g_source_remove(self->_new_app_hide_id);
    self->_new_app_hide_id = 0;
    self->_new_app_menu_shown = false;
  }

  self->_new_app_hide_id = g_timeout_add_seconds(self->_menus_discovery,
                                                 (GSourceFunc)PanelMenuView::OnNewAppHide,
                                                 self);
  self->_new_app_show_id = 0;

  return FALSE;
}

gboolean
PanelMenuView::OnNewAppHide(PanelMenuView* self)
{
  self->OnViewClosed(self->_matcher, BAMF_VIEW(self->_new_application.RawPtr()));
  self->_new_app_hide_id = 0;
  self->_new_app_menu_shown = true;
  self->QueueDraw();

  return FALSE;
}

void
PanelMenuView::OnViewOpened(BamfMatcher *matcher, BamfView *view)
{
  /* FIXME: here we should also check for if the view is also user_visible
   * but it seems that BAMF doesn't handle this correctly after some
   * stress tests (repeated launches). */
  if (!BAMF_IS_APPLICATION(view))
    return;

  _new_apps.push_front(glib::Object<BamfApplication>(BAMF_APPLICATION(view), glib::AddRef()));
}

void
PanelMenuView::OnViewClosed(BamfMatcher *matcher, BamfView *view)
{
  if (!BAMF_IS_APPLICATION(view))
    return;

  BamfApplication* app = BAMF_APPLICATION(view);

  if (std::find(_new_apps.begin(), _new_apps.end(), app) != _new_apps.end())
  {
    _new_apps.remove(glib::Object<BamfApplication>(app, glib::AddRef()));

    if (_new_application == app || _new_apps.empty())
      _new_application = nullptr;
  }
}

void
PanelMenuView::OnActiveAppChanged(BamfMatcher *matcher,
                                  BamfApplication* old_app,
                                  BamfApplication* new_app)
{
  if (BAMF_IS_APPLICATION(new_app))
  {
    if (std::find(_new_apps.begin(), _new_apps.end(), new_app) != _new_apps.end())
    {
      if (_new_application != new_app)
      {
        /* Add a small delay before showing the menus, this is done both
         * to fix the issues with applications that takes some time to loads
         * menus and to show the menus only when an application has been
         * kept active for some time */

        if (_new_app_show_id)
          g_source_remove(_new_app_show_id);

        _new_app_show_id = g_timeout_add(300,
                                         (GSourceFunc)PanelMenuView::OnNewAppShow,
                                         this);
      }
    }
    else
    {
      if (_new_app_show_id)
      {
        g_source_remove(_new_app_show_id);
        _new_app_show_id = 0;
      }

      if (_new_app_hide_id)
      {
        g_source_remove(_new_app_hide_id);
        _new_app_hide_id = 0;
        _new_app_menu_shown = false;
      }

      if (_new_application)
        OnViewClosed(matcher, BAMF_VIEW(_new_application.RawPtr()));
    }
  }
}

void
PanelMenuView::OnActiveWindowChanged(BamfMatcher *matcher,
                                     BamfView* old_view,
                                     BamfView* new_view)
{
  _show_now_activated = false;
  _is_maximized = false;
  _active_xid = 0;

  if (_active_moved_id)
  {
    g_source_remove(_active_moved_id);
    _active_moved_id = 0;
  }

  if (BAMF_IS_WINDOW(new_view))
  {
    BamfWindow* window = BAMF_WINDOW(new_view);
    guint32 xid = bamf_window_get_xid(window);
    _active_xid = xid;
    _is_maximized = bamf_window_maximized(window) == BAMF_WINDOW_MAXIMIZED;
    nux::Geometry geo = WindowManager::Default()->GetWindowGeometry(xid);

    if (bamf_window_get_window_type(window) == BAMF_WINDOW_DESKTOP)
      _we_control_active = true;
    else
      _we_control_active = _monitor_geo.IsPointInside(geo.x + (geo.width / 2), geo.y);

    if (_decor_map.find(xid) == _decor_map.end())
    {
      _decor_map[xid] = true;

      // if we've just started tracking this window and it is maximized, let's
      // make sure it's undecorated just in case it slipped by us earlier
      // (I'm looking at you, Chromium!)
      if (_is_maximized && WindowManager::Default ()->IsWindowDecorated(xid))
      {
        WindowManager::Default()->Undecorate(xid);
        _maximized_set.insert(xid);
      }
    }

    // first see if we need to remove and old callback
    _view_name_changed_signal.Disconnect();

    // register callback for new view
    _view_name_changed_signal.Connect(new_view, "name-changed",
                                      sigc::mem_fun(this, &PanelMenuView::OnNameChanged));

    if (_is_integrated)
    {
      _window_buttons->SetFocusedState(GetMaximizedWindow() == _active_xid);

      if (_integrated_menu && _is_maximized)
        _integrated_menu->SetControlledWindowXid(_active_xid);
    } 
  }

  Refresh();
  FullRedraw();
}

void
PanelMenuView::OnSpreadInitiate()
{
  /*foreach (guint32 &xid, windows)
  {
    if (WindowManager::Default ()->IsWindowMaximized (xid))
      WindowManager::Default ()->Decorate (xid);
  }*/
}

void
PanelMenuView::OnSpreadTerminate()
{
  /*foreach (guint32 &xid, windows)
  {
    if (WindowManager::Default ()->IsWindowMaximized (xid))
      WindowManager::Default ()->Undecorate (xid);
  }*/
}

void
PanelMenuView::OnWindowMinimized(guint32 xid)
{
  if (WindowManager::Default()->IsWindowMaximized(xid))
  {
    WindowManager::Default()->Decorate(xid);
    _maximized_set.erase(xid);
  }
}

void
PanelMenuView::OnWindowUnminimized(guint32 xid)
{
  if (WindowManager::Default()->IsWindowMaximized(xid))
  {
    WindowManager::Default()->Undecorate(xid);
    _maximized_set.insert(xid);
  }
}

void
PanelMenuView::OnWindowUnmapped(guint32 xid)
{
  if (WindowManager::Default()->IsWindowMaximized(xid))
  {
    WindowManager::Default()->Decorate(xid);
    _maximized_set.erase(xid);
  }
}

void
PanelMenuView::OnWindowMapped(guint32 xid)
{
  if (WindowManager::Default()->IsWindowMaximized(xid))
  {
    WindowManager::Default()->Undecorate(xid);
    _maximized_set.insert(xid);
  }
}

void
PanelMenuView::OnWindowDecorated(guint32 xid)
{
  _decor_map[xid] = true;

  if (_maximized_set.find(xid) != _maximized_set.end ())
  {
    WindowManager::Default ()->Undecorate(xid);
  }
}

void
PanelMenuView::OnWindowUndecorated(guint32 xid)
{
  _decor_map[xid] = false;
}

void
PanelMenuView::OnWindowMaximized(guint xid)
{
  bool updated = false;

  if (_active_xid == xid)
  {
    _is_maximized = true;

    // We need to update the _is_inside state in the case of maximization by grab
    auto mouse = nux::GetGraphicsDisplay()->GetMouseScreenCoord();
    _is_inside = GetAbsoluteGeometry().IsPointInside(mouse.x, mouse.y);

    updated = true;
  }

  if (_is_integrated)
  {
    _window_buttons->SetFocusedState(xid == _active_xid);

    if (_integrated_menu && xid == _active_xid)
      _integrated_menu->SetControlledWindowXid(_active_xid);
  }

  // update the state of the window in the _decor_map
  _decor_map[xid] = WindowManager::Default()->IsWindowDecorated(xid);

  if (_decor_map[xid])
    WindowManager::Default()->Undecorate(xid);

  _maximized_set.insert(xid);

  if (updated)
  {
    Refresh();
    FullRedraw();
  }
}

void
PanelMenuView::OnWindowRestored(guint xid)
{
  if (_maximized_set.find(xid) == _maximized_set.end())
    return;

  if (_active_xid == xid)
  {
    _is_maximized = false;
    _is_grabbed = false;
  }

  if (_is_integrated)
  {
    Window maximized = GetMaximizedWindow();
    _window_buttons->SetFocusedState(maximized == _active_xid);

    if (_integrated_menu)
      _integrated_menu->SetControlledWindowXid(maximized);
  }

  if (_decor_map[xid])
    WindowManager::Default()->Decorate(xid);

  _maximized_set.erase(xid);

  Refresh();
  FullRedraw();
}

gboolean
PanelMenuView::UpdateActiveWindowPosition(PanelMenuView* self)
{
  auto wm = WindowManager::Default();
  nux::Geometry const& window_geo = wm->GetWindowGeometry(self->_active_xid);
  nux::Geometry const& intersect = self->_monitor_geo.Intersect(window_geo);

  self->_we_control_active = (intersect.width > window_geo.width/4 &&
                              intersect.height > window_geo.height/4);

  self->_active_moved_id = 0;
  self->QueueDraw();

  return FALSE;
}

void
PanelMenuView::OnWindowMoved(guint xid)
{
  if (_active_xid == xid)
  {
    if (_active_moved_id)
      g_source_remove(_active_moved_id);

    if (!_we_control_active)
      UpdateActiveWindowPosition(this);
    else
      _active_moved_id = g_timeout_add(250, (GSourceFunc)PanelMenuView::UpdateActiveWindowPosition, this);
  }
}

void
PanelMenuView::OnCloseClicked()
{
  if (_dash_showing)
  {
    _ubus_manager.SendMessage(UBUS_PLACE_VIEW_CLOSE_REQUEST);
  }
  else
  {
    Window target_win = _active_xid;

    if (_is_integrated)
    {
      target_win = GetMaximizedWindow();
    }

    if (target_win != 0)
    {
      WindowManager::Default()->Close(target_win);
      NeedRedraw();
    }
  }
}

void
PanelMenuView::OnMinimizeClicked()
{
  if (_dash_showing)
  {
    // no action when dash is opened, LP bug #838875
    return;
  }
  else
  {
    Window target_win = _active_xid;

    if (_is_integrated)
    {
      target_win = GetMaximizedWindow();
    }

    if (target_win != 0)
    {
      WindowManager::Default()->Minimize(target_win);
      NeedRedraw();
    }
  }
}

void
PanelMenuView::OnRestoreClicked()
{
  if (_dash_showing)
  {
    if (dash::Settings::Instance().GetFormFactor() == dash::FormFactor::DESKTOP)
      dash::Settings::Instance().SetFormFactor(dash::FormFactor::NETBOOK);
    else
      dash::Settings::Instance().SetFormFactor(dash::FormFactor::DESKTOP);
  }
  else
  {
    Window target_win = _active_xid;

    if (_is_integrated)
    {
      target_win = GetMaximizedWindow();
    }

    if (target_win != 0)
    {
      WindowManager::Default()->Restore(target_win);
      NeedRedraw();
    }
  }
}

Window
PanelMenuView::GetMaximizedWindow()
{
  Window window_xid = 0;
  auto wm = WindowManager::Default();

  // Find the front-most of the maximized windows we are controlling
  for (auto xid : _maximized_set)
  {
    // We can safely assume only the front-most is visible
    if (wm->IsWindowOnCurrentDesktop(xid) && !wm->IsWindowObscured(xid))
    {
      nux::Geometry const& geo = wm->GetWindowGeometry(xid);

      if (_monitor_geo.IsPointInside(geo.x + (geo.width / 2), geo.y))
      {
        window_xid = xid;
        break;
      }
    }
  }

  return window_xid;
}

void
PanelMenuView::OnMaximizedGrabStart(int x, int y, unsigned long button_flags, unsigned long)
{
  Window maximized_win;
  if (nux::GetEventButton(button_flags) != 1 || _dash_showing)
    return;

  // When Start dragging the panelmenu of a maximized window, change cursor
  // to simulate the dragging, waiting to go out of the panel area.
  //
  // This is a workaround to avoid that the grid plugin would be fired
  // showing the window shape preview effect. See bug #838923

  maximized_win = GetMaximizedWindow();

  if (maximized_win != 0)
  {
    /* Always activate the window in case it is on another monitor */
    WindowManager::Default ()->Activate (maximized_win);
    _panel_titlebar_grab_area->SetGrabbed(true);
  }
}

void
PanelMenuView::OnMaximizedGrabMove(int x, int y, int, int, unsigned long button_flags, unsigned long)
{
//  FIXME nux doesn't export it with drag event.
//  if (nux::GetEventButton(button_flags) != 1)
//    return;

  // We use this, due to the problem above
  if (!_panel_titlebar_grab_area->IsGrabbed())
    return;

  auto panel = static_cast<nux::BaseWindow*>(GetTopLevelViewWindow());

  if (!panel)
    return;

  x += _panel_titlebar_grab_area->GetAbsoluteX();
  y += _panel_titlebar_grab_area->GetAbsoluteY();

  Window window_xid = GetMaximizedWindow();

  // When the drag goes out from the Panel, start the real movement.
  //
  // This is a workaround to avoid that the grid plugin would be fired
  // showing the window shape preview effect. See bug #838923
  if (window_xid != 0 && panel && !panel->GetAbsoluteGeometry().IsPointInside(x, y))
  {
    _panel_titlebar_grab_area->SetGrabbed(false);

    WindowManager::Default()->Activate(window_xid);
    _is_inside = true;
    _is_grabbed = true;
    Refresh();
    FullRedraw();
    WindowManager::Default()->StartMove(window_xid, x, y);
  }
}

void
PanelMenuView::OnMaximizedGrabEnd(int x, int y, unsigned long, unsigned long)
{
  _panel_titlebar_grab_area->SetGrabbed(false);

  x += _panel_titlebar_grab_area->GetAbsoluteX();
  y += _panel_titlebar_grab_area->GetAbsoluteY();
  _is_inside = GetAbsoluteGeometry().IsPointInside(x, y);

  if (!_is_inside)
    _is_grabbed = false;

  Refresh();
  FullRedraw();
}

void
PanelMenuView::OnMouseDoubleClicked(int x, int y, unsigned long button_flags, unsigned long)
{
  if (nux::GetEventButton(button_flags) != 1 || _dash_showing)
    return;

  Window window_xid = GetMaximizedWindow();

  if (window_xid != 0)
  {
    WindowManager::Default()->Restore(window_xid);
    _is_inside = true;
  }
}

void
PanelMenuView::OnMouseClicked(int x, int y, unsigned long button_flags, unsigned long)
{
  if (nux::GetEventButton(button_flags) != 1 || _dash_showing)
    return;

  Window window_xid = GetMaximizedWindow();

  if (window_xid != 0)
  {
    WindowManager::Default()->Raise(window_xid);
  }
}

void
PanelMenuView::OnMouseMiddleClicked(int x, int y, unsigned long button_flags, unsigned long)
{
  if (nux::GetEventButton(button_flags) != 2 || _dash_showing)
    return;

  Window window_xid = GetMaximizedWindow();

  if (window_xid != 0)
  {
    WindowManager::Default()->Lower(window_xid);
  }
}

// Introspectable
std::string
PanelMenuView::GetName() const
{
  return "";
}

void PanelMenuView::AddProperties(GVariantBuilder* builder)
{
}

void PanelMenuView::OnSwitcherShown(GVariant* data)
{
  if (!data)
    return;

  _switcher_showing = g_variant_get_boolean(data);

  if (!_switcher_showing)
  {
    auto mouse = nux::GetGraphicsDisplay()->GetMouseScreenCoord();
    _is_inside = GetAbsoluteGeometry().IsPointInside(mouse.x, mouse.y);

    if (!_panel_title.empty())
    {
      _panel_title = "";
    }
  }
  else
  {
    _show_now_activated = false;
  }

  Refresh();
  QueueDraw();
}

void PanelMenuView::OnSwitcherSelectionChanged(GVariant* data)
{
  if (!data)
    return;

  const gchar *title = g_variant_get_string(data, 0);
  _panel_title = (title ? title : "");

  Refresh();
  QueueDraw();
}

gboolean
PanelMenuView::UpdateShowNowWithDelay(PanelMenuView *self)
{
  bool active = false;

  for (auto entry : self->entries_)
  {
    if (entry.second->GetShowNow())
    {
      active = true;
      break;
    }
  }

  self->_update_show_now_id = 0;

  if (active)
  {
    self->_show_now_activated = true;
    self->QueueDraw();
  }

  return FALSE;
}

void
PanelMenuView::UpdateShowNow(bool status)
{
  /* When we get a show now event, if we are requested to show the menus,
   * we take the last incoming event and we wait for small delay (to avoid the
   * Alt+Tab conflict) then we check if any menuitem has requested to show.
   * If the status is false, we just check that the menus entries are hidden
   * and we remove any eventual delayed request */

  if (!status && _show_now_activated)
  {
    _show_now_activated = false;
    QueueDraw();
  }

  if (_update_show_now_id != 0)
  {
    g_source_remove(_update_show_now_id);
    _update_show_now_id = 0;
  }

  if (status && !_show_now_activated)
  {
    _update_show_now_id = g_timeout_add(180, (GSourceFunc)
                                        &PanelMenuView::UpdateShowNowWithDelay,
                                        this);
  }
}

void
PanelMenuView::SetMonitor(int monitor)
{
  _monitor = monitor;
  _monitor_geo = UScreen::GetDefault()->GetMonitorGeometry(_monitor);

  _maximized_set.clear();
  GList* windows = bamf_matcher_get_window_stack_for_monitor(_matcher, _monitor);

  for (GList* l = windows; l; l = l->next)
  {
    if (!BAMF_IS_WINDOW(l->data))
      continue;

    auto window = static_cast<BamfWindow*>(l->data);

    if (bamf_window_maximized(window) == BAMF_WINDOW_MAXIMIZED)
    {
      Window xid = bamf_window_get_xid(window);
      _maximized_set.insert(xid);
    }
  }

  g_list_free(windows);
}

bool
PanelMenuView::GetControlsActive()
{
  return _we_control_active;
}

bool
PanelMenuView::HasOurWindowFocused()
{
  return _is_own_window;
}

void
PanelMenuView::OnPanelViewMouseEnter(int x, int y, unsigned long mouse_button_state, unsigned long special_keys_state)
{
  if (_is_inside != true)
  {
    if (_is_grabbed)
      _is_grabbed = false;
    else
      _is_inside = true;

    FullRedraw();
  }
}

void
PanelMenuView::OnPanelViewMouseLeave(int x, int y, unsigned long mouse_button_state, unsigned long special_keys_state)
{
  if (_is_inside != false)
  {
    _is_inside = false;
    FullRedraw();
  }
}

void PanelMenuView::OnPanelViewMouseMove(int x, int y, int dx, int dy, unsigned long mouse_button_state, unsigned long special_keys_state)
{}

void PanelMenuView::SetMousePosition(int x, int y)
{
  if (_last_active_view ||
      (x >= 0 && y >= 0 && GetAbsoluteGeometry().IsPointInside(x, y)))
  {
    if (!_is_inside)
    {
      _is_inside = true;
      FullRedraw();
    }
  }
  else
  {
    if (_is_inside)
    {
      _is_inside = false;
      FullRedraw();
    }
  }
}
} // namespace unity
