/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
/*
 * Copyright (C) 2009 Canonical Ltd
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
 * Authored by Gordon Allott <gord.allott@canonical.com>,
 *             Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *
 */

namespace Unity.Launcher
{
  const float LINE_WIDTH             = 0.083f;
  const float LINE_WIDTH_ABS         = 1.5f;
  const float TEXT_HEIGHT            = 1.0f;
  const float MAX_TEXT_WIDTH         = 15.0f;
  const float GAP                    = 0.25f;
  const float MARGIN                 = 0.5f;
  const float BORDER                 = 0.25f;
  const float CORNER_RADIUS          = 0.3f;
  const float CORNER_RADIUS_ABS      = 5.0f;
  const float SHADOW_SIZE            = 1.25f;
  const float ITEM_HEIGHT            = 2.0f;
  const float ITEM_CORNER_RADIUS     = 0.3f;
  const float ITEM_CORNER_RADIUS_ABS = 4.0f;
  const float ANCHOR_HEIGHT          = 1.5f;
  const float ANCHOR_HEIGHT_ABS      = 18.0f;
  const float ANCHOR_WIDTH           = 0.75f;
  const float ANCHOR_WIDTH_ABS       = 10.0f;

  // we call this instead of Ctk.Menu so you can alter this to look right
  public class QuicklistMenu : Ctk.Menu
  {
    Ctk.LayerActor ql_background;
    int            old_width;
    int            old_height;
    float          cached_x; // needed to fix LP: #525905
    float          cached_y; // needed to fix LP: #526335

    public override void
    paint ()
    {
      // FIXME00: this is the brute force-approach pulling the blurred-bg
      // texture constantly... harder on the system (especially since we atm
      // still have to do glReadPixels()) but more robust in terms of intented
      // look as we'll have a cleanly updating blurred bg in case there's a
      // video being displayed in a video-player, or a GL-app renders some
      // animation or mutter does some animation stuff with the windows
      base.refresh_background_texture ();

      // needed to fix LP: #525905
      float x;
      float y;
      this.get_position (out x, out y);
      if (this.cached_x == 0.0f)
        this.cached_x = x;
      if (this.cached_x != x)
        this.set_position (this.cached_x, y);

      // important run-time optimization!
      if (!this.ql_background.is_flattened ())
        this.ql_background.flatten ();

      base.paint ();
    }

    private override void
    allocate (Clutter.ActorBox        box,
              Clutter.AllocationFlags flags)
    {
      int  w;
      int  h;
      uint blurred_id = 0;

      w = (int) (box.x2 - box.x1);
      h = (int) (box.y2 - box.y1);

      // exit early if the allocation-width/height didn't change, this is needed
      // because clutter triggers calling allocate even if nothing changed
      if ((old_width == w) && (old_height == h))
        return;

      base.allocate (box, flags);

      // FIXME01: this is the conservative approach only updating the blurred-bg
      // texture when the allocation changed... this way we'll miss any updates
      // of say a video-player displaying a movie behind the tooltip/quicklist
      // or a GL-app displaying an animation or any other client app rendering
      // a dynamic UI with screen-changes (also applies to any mutter-based
      // animations, e.g. its expose)
      //base.refresh_background_texture ();

      if (get_num_items () == 1)
        cached_y = (float) h / 2.0f;

      // do the texture-update/glReadPixels() thing here ... call it whatever
      // you feel fits best here ctk_menu_get_framebuffer_background()
      blurred_id = base.get_framebuffer_background ();

      // store the new width/height
      old_width  = w;
      old_height = h;

      // before creating a new CtkLayerActor make sure we don't leak any memory
      if (this.ql_background is Ctk.LayerActor)
         this.ql_background.destroy ();
      this.ql_background = new Ctk.LayerActor (w, h);

      Ctk.Layer main_layer = new Ctk.Layer (w,
                                            h,
                                            Ctk.LayerRepeatMode.NONE,
                                            Ctk.LayerRepeatMode.NONE);
      Ctk.Layer blurred_layer = new Ctk.Layer (w,
                                              h,
                                              Ctk.LayerRepeatMode.NONE,
                                              Ctk.LayerRepeatMode.NONE);

      Cairo.Surface full_surf = new Cairo.ImageSurface (Cairo.Format.ARGB32,
                                                        w,
                                                        h);
      Cairo.Surface fill_surf = new Cairo.ImageSurface (Cairo.Format.ARGB32,
                                                        w,
                                                        h);
      Cairo.Surface main_surf = new Cairo.ImageSurface (Cairo.Format.ARGB32,
                                                        w,
                                                        h);

      Cairo.Context full_cr = new Cairo.Context (full_surf);
      Cairo.Context fill_cr = new Cairo.Context (fill_surf);
      Cairo.Context main_cr = new Cairo.Context (main_surf);

      Unity.QuicklistRendering.Menu.full_mask (full_cr, w, h, cached_y);
      Unity.QuicklistRendering.Menu.fill_mask (fill_cr, w, h, cached_y);
      Unity.QuicklistRendering.Menu.background (main_cr, w, h, cached_y);
      //main_surf.write_to_png ("/tmp/main-surf.png");

      main_layer.set_mask_from_surface (full_surf);
      main_layer.set_image_from_surface (main_surf);
      main_layer.set_opacity (255);

      blurred_layer.set_mask_from_surface (fill_surf);
      blurred_layer.set_image_from_id (blurred_id);
      blurred_layer.set_opacity (255);

      // order is important here... don't mess around!
      this.ql_background.add_layer (blurred_layer);
      this.ql_background.add_layer (main_layer);

      this.set_background (this.ql_background);
      this.ql_background.set_opacity (255);
    }

    construct
    {
      Ctk.Padding padding = Ctk.Padding () {
        left   = (int) (Ctk.em_to_pixel (BORDER + SHADOW_SIZE) + ANCHOR_WIDTH_ABS),
        right  = (int) Ctk.em_to_pixel (BORDER + SHADOW_SIZE) - 1,
        top    = (int) Ctk.em_to_pixel (BORDER + SHADOW_SIZE),
        bottom = (int) Ctk.em_to_pixel (SHADOW_SIZE) + 1
      };
      this.set_padding (padding);
      //this.spacing = (int) Ctk.em_to_pixel (GAP);

      old_width  = 0;
      old_height = 0;
      cached_x   = 0.0f; // needed to fix LP: #525905
      cached_y   = 0.0f; // needed to fix LP: #526335

    }
  }
}
