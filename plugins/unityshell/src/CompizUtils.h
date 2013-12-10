// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
* Copyright (C) 2013 Canonical Ltd
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

#include <Nux/Nux.h>
#include <opengl/texture.h>
#include <cairo.h>
#include <memory>

namespace unity
{
namespace compiz_utils
{

struct TextureQuad
{
  CompRect box;
  GLTexture::Matrix matrix;
};

struct PixmapTexture
{
  typedef std::shared_ptr<PixmapTexture> Ptr;

  PixmapTexture(unsigned width, unsigned height);
  ~PixmapTexture();

  GLTexture::List const& texture_list() const { return texture_; }
  GLTexture* texture() const { return texture_[0]; }
  Pixmap pixmap() const { return pixmap_; }

private:
  Pixmap pixmap_;
  GLTexture::List texture_;
};

struct PixmapTextureQuad
{
  void Init(PixmapTexture::Ptr const& pixmap_texture)
  {
    pt = pixmap_texture;

    if (pt && pt->texture())
    {
      auto* tex = pt->texture();
      quad.box.setWidth(tex->width());
      quad.box.setHeight(tex->height());
    }
  }

  void SetCoords(int x, int y)
  {
    quad.box.setX(x);
    quad.box.setY(y);
    quad.matrix = (pt && pt->texture()) ? pt->texture()->matrix() : GLTexture::Matrix();
    quad.matrix.x0 = 0.0f - COMP_TEX_COORD_X(quad.matrix, x);
    quad.matrix.y0 = 0.0f - COMP_TEX_COORD_Y(quad.matrix, y);
  }

  PixmapTexture::Ptr pt;
  TextureQuad quad;
};

struct CairoContext
{
  CairoContext(unsigned width, unsigned height);
  ~CairoContext();

  int width() const;
  int height() const;

  PixmapTexture::Ptr const& texture() const { return pixmap_texture_; }
  cairo_t* context() const { return cr_; }

  operator cairo_t*() const { return cr_; }
  operator PixmapTexture::Ptr() const { return pixmap_texture_; }

private:
  PixmapTexture::Ptr pixmap_texture_;
  cairo_surface_t* surface_;
  cairo_t *cr_;
};

} // compiz_utils namespace
} // unity namespace
