// -*- Mode: C++; indent-tabs-mode: nil; tab-width: 2 -*-
/*
 * Copyright 2012 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License version 3, as
 * published by the  Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the applicable version of the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of both the GNU Lesser General Public
 * License version 3 along with this program.  If not, see
 * <http://www.gnu.org/licenses/>
 *
 * Authored by: Andrea Azzarone <andrea.azzarone@canonical.com>
 *
 */

#ifndef UNITYSHELL_G_MOCK_VOLUME_H
#define UNITYSHELL_G_MOCK_VOLUME_H

#include <gio/gio.h>

G_BEGIN_DECLS

#define G_TYPE_MOCK_VOLUME        (g_mock_volume_get_type ())
#define G_MOCK_VOLUME(o)          (G_TYPE_CHECK_INSTANCE_CAST ((o), G_TYPE_MOCK_VOLUME, GMockVolume))
#define G_MOCK_VOLUME_CLASS(k)    (G_TYPE_CHECK_CLASS_CAST((k), G_TYPE_MOCK_VOLUME, GMockVolumeClass))
#define G_IS_MOCK_VOLUME(o)       (G_TYPE_CHECK_INSTANCE_TYPE ((o), G_TYPE_MOCK_VOLUME))
#define G_IS_MOCK_VOLUME_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), G_TYPE_MOCK_VOLUME))

typedef struct _GMockVolume GMockVolume;
typedef struct _GMockVolumeClass GMockVolumeClass;

struct _GMockVolume {
  GObject parent;
};

struct _GMockVolumeClass {
  GObjectClass parent_class;
};

GType         g_mock_volume_get_type (void) G_GNUC_CONST;
GMockVolume * g_mock_volume_new      ();

G_END_DECLS

#endif // UNITYSHELL_G_MOCK_VOLUME_H
