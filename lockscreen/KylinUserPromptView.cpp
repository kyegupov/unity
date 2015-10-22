// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright (C) 2014 Canonical Ltd
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
* Authored by: handsome_feng <jianfengli@ubuntukylin.com>
*/

#include "KylinUserPromptView.h"

#include "config.h"
#include <gtk/gtk.h>
#include <glib/gi18n-lib.h>

#include <boost/algorithm/string/trim.hpp>
#include <Nux/VLayout.h>
#include <Nux/HLayout.h>
#include <NuxCore/Logger.h>
#include "Variant.h"

#include "LockScreenSettings.h"
#include "unity-shared/CairoTexture.h"
#include "unity-shared/TextInput.h"
#include "unity-shared/StaticCairoText.h"
#include "unity-shared/RawPixel.h"
#include "unity-shared/IconTexture.h"
#include "unity-shared/TextureCache.h"

namespace unity
{
namespace lockscreen
{
namespace
{
const RawPixel PADDING                                = 10_em;
const RawPixel LAYOUT_MARGIN                   = 20_em;
const RawPixel MSG_LAYOUT_MARGIN         = 15_em;
const RawPixel PROMPT_LAYOUT_MARGIN  =  5_em;
const RawPixel SWITCH_ICON_HEIGHT           = 32_em;
const RawPixel SWITCH_ICON_WIDTH           = 100_em;
const RawPixel AVATAR_SIZE                           = 128_em;
const RawPixel TEXT_INPUT_HEIGHT             =  36_em;
const RawPixel TEXT_INPUT_WIDTH               = 320_em;
const int PROMPT_FONT_SIZE = 14;

std::string SanitizeMessage(std::string const& message)
{
  std::string msg = boost::algorithm::trim_copy(message);

  if (msg.empty())
    return msg;

  if (msg[msg.size()-1] == ':')
    msg = msg.substr(0, msg.size()-1);

  if (msg == "Password")
    return _("Password");

  if (msg == "login")
    return _("Username");

  return msg;
}

}

KylinUserPromptView::KylinUserPromptView(session::Manager::Ptr const& session_manager)
  : AbstractUserPromptView(session_manager)
  , scale(1.0)
  , session_manager_(session_manager)
  , username_(nullptr)
  , msg_layout_(nullptr)
  , prompt_layout_(nullptr)
{
    user_authenticator_.echo_on_requested.connect([this](std::string const& message, PromiseAuthCodePtr const& promise){
        AddPrompt(message, true, promise);
    });

    user_authenticator_.echo_off_requested.connect([this](std::string const& message, PromiseAuthCodePtr const& promise){
        AddPrompt(message, false, promise);
    });

    user_authenticator_.message_requested.connect([this](std::string const& message){
        AddMessage(message, nux::color::White);
    });

    user_authenticator_.error_requested.connect([this](std::string const& message){
        AddMessage(message, nux::color::Red);
    });

    user_authenticator_.clear_prompts.connect([this](){
        ResetLayout();
    });

    scale.changed.connect(sigc::hide(sigc::mem_fun(this, &KylinUserPromptView::UpdateSize)));

    UpdateSize();
    ResetLayout();

    user_authenticator_.AuthenticateStart(session_manager_->UserName(),
                                          sigc::mem_fun(this, &KylinUserPromptView::AuthenticationCb));
}

void KylinUserPromptView::ResetLayout()
{
  focus_queue_.clear();

  SetLayout(new nux::HLayout());

  static_cast<nux::HLayout*>(GetLayout())->SetHorizontalInternalMargin(LAYOUT_MARGIN.CP(scale));

  nux::Layout* switch_layout = new nux::HLayout();

  TextureCache& cache = TextureCache::GetDefault();
  SwitchIcon_ = new IconTexture(cache.FindTexture("switch_user.png", SWITCH_ICON_WIDTH, SWITCH_ICON_HEIGHT));
  switch_layout->AddView(SwitchIcon_);
  SwitchIcon_->mouse_click.connect([this](int x, int y, unsigned long button_flags, unsigned long key_flags) {
    session_manager_->SwitchToGreeter();
  });
  switch_layout->SetMaximumSize(SWITCH_ICON_WIDTH, SWITCH_ICON_HEIGHT);
  GetLayout()->AddLayout(switch_layout);

  Avatar_ = new IconTexture(LoadUserIcon(AVATAR_SIZE));
  Avatar_->SetMinimumWidth(AVATAR_SIZE);
  Avatar_->SetMaximumWidth(AVATAR_SIZE);
  GetLayout()->AddView(Avatar_);

  nux::Layout* prompt_layout = new nux::VLayout();

  auto const& real_name = session_manager_->RealName();
  auto const& name = (real_name.empty() ? session_manager_->UserName() : real_name);

  username_ = new unity::StaticCairoText(name);
  username_->SetScale(scale);
  username_->SetFont("Ubuntu "+std::to_string(PROMPT_FONT_SIZE));
  prompt_layout->AddView(username_);

  msg_layout_ = new nux::VLayout();
  msg_layout_->SetVerticalInternalMargin(MSG_LAYOUT_MARGIN.CP(scale));
  msg_layout_->SetTopAndBottomPadding(33, 0);
  prompt_layout->AddLayout(msg_layout_);

  prompt_layout_ = new nux::VLayout();
  prompt_layout_->SetVerticalInternalMargin(PROMPT_LAYOUT_MARGIN.CP(scale));
  prompt_layout->AddLayout(prompt_layout_);

  GetLayout()->AddLayout(prompt_layout);
  QueueRelayout();
  QueueDraw();
}

void KylinUserPromptView::UpdateSize()
{
  auto width = 15 * Settings::GRID_SIZE.CP(scale);
  auto height = 3 * Settings::GRID_SIZE.CP(scale);

  SetMinimumWidth(width);
  SetMaximumWidth(width);
  SetMinimumHeight(height);

  if (nux::Layout* layout = GetLayout())
  {
    layout->SetLeftAndRightPadding(PADDING.CP(scale));
    layout->SetTopAndBottomPadding(PADDING.CP(scale));
  }

  if (username_)
    username_->SetScale(scale);

  if (msg_layout_)
  {
    msg_layout_->SetVerticalInternalMargin(MSG_LAYOUT_MARGIN.CP(scale));

    for (auto* area : msg_layout_->GetChildren())
    {
      area->SetMaximumWidth(TEXT_INPUT_WIDTH);
      static_cast<StaticCairoText*>(area)->SetScale(scale);
    }
  }

  if (prompt_layout_)
  {
    prompt_layout_->SetVerticalInternalMargin(PROMPT_LAYOUT_MARGIN.CP(scale));

    for (auto* area : prompt_layout_->GetChildren())
    {
      auto* text_input = static_cast<TextInput*>(area);
      text_input->SetMinimumHeight(TEXT_INPUT_HEIGHT.CP(scale));
      text_input->SetMaximumHeight(TEXT_INPUT_HEIGHT.CP(scale));
      text_input->SetMinimumWidth(TEXT_INPUT_WIDTH.CP(scale));
      text_input->SetMaximumWidth(TEXT_INPUT_WIDTH.CP(scale));
      text_input->scale = scale();
    }
  }

  ComputeContentSize();
  QueueRelayout();
  QueueDraw();
}

bool KylinUserPromptView::InspectKeyEvent(unsigned int eventType, unsigned int key_sym, const char* character)
{
  if ((eventType == nux::NUX_KEYDOWN) && (key_sym == NUX_VK_ESCAPE))
  {
    if (!focus_queue_.empty())
      focus_queue_.front()->text_entry()->SetText("");

    return true;
  }

  return false;
}

void KylinUserPromptView::AuthenticationCb(bool authenticated)
{
  ResetLayout();

  if (authenticated)
  {
    session_manager_->unlock_requested.emit();
  }
  else
  {
    AddMessage(_("Invalid password, please try again"), nux::color::Red);

    user_authenticator_.AuthenticateStart(session_manager_->UserName(),
                                          sigc::mem_fun(this, &KylinUserPromptView::AuthenticationCb));
  }
}

void KylinUserPromptView::Draw(nux::GraphicsEngine& graphics_engine, bool force_draw)
{
  nux::Geometry const& geo = GetGeometry();

  graphics_engine.PushClippingRectangle(geo);
  nux::GetPainter().PaintBackground(graphics_engine, geo);

  graphics_engine.PopClippingRectangle();
}

void KylinUserPromptView::DrawContent(nux::GraphicsEngine& graphics_engine, bool force_draw)
{
  nux::Geometry const& geo = GetGeometry();
  graphics_engine.PushClippingRectangle(geo);

  if (GetLayout())
    GetLayout()->ProcessDraw(graphics_engine, force_draw);

  graphics_engine.PopClippingRectangle();
}

nux::View* KylinUserPromptView::focus_view()
{
  if (focus_queue_.empty())
    return nullptr;

  for (auto* view : focus_queue_)
    if (view->text_entry()->HasKeyboardFocus())
      return view;

  return focus_queue_.front()->text_entry();
}

void KylinUserPromptView::AddPrompt(std::string const& message, bool visible, PromiseAuthCodePtr const& promise)
{
  auto* text_input = new unity::TextInput();
  auto* text_entry = text_input->text_entry();

  text_input->scale = scale();
  text_input->input_hint = SanitizeMessage(message);
  text_input->hint_font_size = PROMPT_FONT_SIZE;
  text_input->show_caps_lock = true;
  text_input->show_activator = true;
  text_entry->SetPasswordMode(!visible);
  text_entry->SetPasswordChar("•");
  text_entry->SetToggleCursorVisibilityOnKeyFocus(true);
  text_entry->clipboard_enabled = false;
  text_entry->SetTextColor(nux::color::Black);

  text_input->SetMinimumHeight(TEXT_INPUT_HEIGHT.CP(scale));
  text_input->SetMaximumHeight(TEXT_INPUT_HEIGHT.CP(scale));
  text_input->SetMinimumWidth(TEXT_INPUT_WIDTH.CP(scale));
  text_input->SetMaximumWidth(TEXT_INPUT_WIDTH.CP(scale));
  prompt_layout_->AddView(text_input, 1);
  focus_queue_.push_back(text_input);

  // Don't remove it, it helps with a11y.
  if (focus_queue_.size() == 1)
    nux::GetWindowCompositor().SetKeyFocusArea(text_entry);

  text_entry->activated.connect([this, text_input, promise](){
    auto* text_entry = text_input->text_entry();

    if (!text_entry->GetInputEventSensitivity())
      return;

    if (focus_queue_.size() == 1)
    {
      text_input->SetSpinnerVisible(true);
      text_input->SetSpinnerState(STATE_SEARCHING);
    }

    focus_queue_.pop_front();
    cached_focused_geo_ = text_entry->GetGeometry();
    text_entry->SetInputEventSensitivity(false);
    QueueRelayout();
    QueueDraw();

    std::string const& password = text_entry->GetText();
    if (promise)
      promise->set_value(password);
  });

  GetLayout()->ComputeContentPosition(0, 0);
  ComputeContentSize();
  QueueRelayout();
  QueueDraw();
}

void KylinUserPromptView::AddMessage(std::string const& message, nux::Color const& color)
{
  auto* view = new unity::StaticCairoText("");
  view->SetScale(scale);
  view->SetFont(Settings::Instance().font_name());
  view->SetTextColor(color);
  view->SetText(message);
  view->SetMaximumWidth(TEXT_INPUT_WIDTH.CP(scale));
  msg_layout_->AddView(view);

  GetLayout()->ComputeContentPosition(0, 0);
  ComputeContentSize();
  QueueRelayout();
  QueueDraw();
}

nux::ObjectPtr<nux::BaseTexture> KylinUserPromptView::LoadUserIcon(int SWITCH_ICON_SIZE)
{
  glib::Error error;
  glib::Object<GdkPixbuf> pixbuf(gdk_pixbuf_new_from_file_at_size(session_manager_->UserIconFile().c_str(), SWITCH_ICON_SIZE, SWITCH_ICON_SIZE, &error));
  if (pixbuf == nullptr)
  {
    auto* theme = gtk_icon_theme_get_default();
    GtkIconLookupFlags flags = GTK_ICON_LOOKUP_FORCE_SIZE;
    pixbuf = gtk_icon_theme_load_icon(theme, "avatar-default", SWITCH_ICON_SIZE, flags, &error);
  }
  nux::CairoGraphics cg(CAIRO_FORMAT_ARGB32, gdk_pixbuf_get_width(pixbuf), gdk_pixbuf_get_height(pixbuf));
  cairo_t* cr = cg.GetInternalContext();

  gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
  cairo_paint_with_alpha(cr, 1.0);
  cairo_set_source_rgba(cr, 1.0f, 1.0f, 1.0f, 1.0f);
  cairo_rectangle(cr, 0, 0, gdk_pixbuf_get_width(pixbuf), gdk_pixbuf_get_height(pixbuf));
  cairo_set_line_width(cr, 3);
  cairo_stroke(cr);

  return texture_ptr_from_cairo_graphics(cg);
}

}
}
