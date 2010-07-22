/* quicklist-menu-item.c generated by valac, the Vala compiler
 * generated from quicklist-menu-item.vala, do not modify */

/* -*- Mode: vala; indent-tabs-mode: nil; c-basic-offset: 2; tab-width: 2 -*- */
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
 * Authored by Gordon Allott <gord.allott@canonical.com>,
 *             Mirco "MacSlow" Müller <mirco.mueller@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>
#include <float.h>
#include <math.h>
#include <gtk/gtk.h>
#include <unity.h>
#include <cairo.h>


#define UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM (unity_launcher_quicklist_menu_item_get_type ())
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItem))
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItemClass))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_ITEM(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM))
#define UNITY_LAUNCHER_IS_QUICKLIST_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM))
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItemClass))

typedef struct _UnityLauncherQuicklistMenuItem UnityLauncherQuicklistMenuItem;
typedef struct _UnityLauncherQuicklistMenuItemClass UnityLauncherQuicklistMenuItemClass;
typedef struct _UnityLauncherQuicklistMenuItemPrivate UnityLauncherQuicklistMenuItemPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _cairo_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_destroy (var), NULL)))
#define _cairo_surface_destroy0(var) ((var == NULL) ? NULL : (var = (cairo_surface_destroy (var), NULL)))

struct _UnityLauncherQuicklistMenuItem {
	CtkMenuItem parent_instance;
	UnityLauncherQuicklistMenuItemPrivate * priv;
};

struct _UnityLauncherQuicklistMenuItemClass {
	CtkMenuItemClass parent_class;
};

struct _UnityLauncherQuicklistMenuItemPrivate {
	CtkLayerActor* item_background;
	gint last_width;
	gint last_height;
	char* old_label;
};


static gpointer unity_launcher_quicklist_menu_item_parent_class = NULL;

GType unity_launcher_quicklist_menu_item_get_type (void) G_GNUC_CONST;
#define UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, UnityLauncherQuicklistMenuItemPrivate))
enum  {
	UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_DUMMY_PROPERTY
};
static void unity_launcher_quicklist_menu_item_real_paint (ClutterActor* base);
#define UNITY_LAUNCHER_ITEM_HEIGHT 2.0f
static void unity_launcher_quicklist_menu_item_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height_p, float* natural_height_p);
#define UNITY_LAUNCHER_MARGIN 0.5f
static void unity_launcher_quicklist_menu_item_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width_p, float* natural_width_p);
static gboolean _unity_launcher_quicklist_menu_item_update_item_background (UnityLauncherQuicklistMenuItem* self);
static gboolean __unity_launcher_quicklist_menu_item_update_item_background_gsource_func (gpointer self);
static void unity_launcher_quicklist_menu_item_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static gboolean _unity_launcher_quicklist_menu_item_on_enter (UnityLauncherQuicklistMenuItem* self, ClutterEvent* event);
static gboolean _unity_launcher_quicklist_menu_item_on_leave (UnityLauncherQuicklistMenuItem* self, ClutterEvent* event);
static void _unity_launcher_quicklist_menu_item_on_label_changed (UnityLauncherQuicklistMenuItem* self);
static void __unity_launcher_quicklist_menu_item_on_label_changed_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self);
static gboolean __unity_launcher_quicklist_menu_item_on_enter_clutter_actor_enter_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean __unity_launcher_quicklist_menu_item_on_leave_clutter_actor_leave_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
static gboolean _unity_launcher_quicklist_menu_item_on_mouse_down (UnityLauncherQuicklistMenuItem* self, ClutterEvent* event);
static gboolean __unity_launcher_quicklist_menu_item_on_mouse_down_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self);
UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_new (void);
UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_construct (GType object_type);
UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_new_with_label (const char* label);
UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_construct_with_label (GType object_type, const char* label);
static GObject * unity_launcher_quicklist_menu_item_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_launcher_quicklist_menu_item_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void unity_launcher_quicklist_menu_item_real_paint (ClutterActor* base) {
	UnityLauncherQuicklistMenuItem * self;
	self = (UnityLauncherQuicklistMenuItem*) base;
	if (CTK_IS_LAYER_ACTOR (self->priv->item_background)) {
		clutter_actor_paint ((ClutterActor*) self->priv->item_background);
	}
}


static void unity_launcher_quicklist_menu_item_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height_p, float* natural_height_p) {
	UnityLauncherQuicklistMenuItem * self;
	self = (UnityLauncherQuicklistMenuItem*) base;
	*min_height_p = (float) ctk_em_to_pixel ((double) UNITY_LAUNCHER_ITEM_HEIGHT);
	*natural_height_p = *min_height_p;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_launcher_quicklist_menu_item_real_get_preferred_width (ClutterActor* base, float for_height, float* min_width_p, float* natural_width_p) {
	UnityLauncherQuicklistMenuItem * self;
	gint width = 0;
	gint height = 0;
	GtkSettings* settings;
	char* _tmp1_;
	char* _tmp0_ = NULL;
	self = (UnityLauncherQuicklistMenuItem*) base;
	settings = _g_object_ref0 (gtk_settings_get_default ());
	unity_quicklist_rendering_item_get_text_extents (_tmp1_ = (g_object_get (settings, "gtk-font-name", &_tmp0_, NULL), _tmp0_), ctk_menu_item_get_label ((CtkMenuItem*) self), &width, &height);
	_g_free0 (_tmp1_);
	*min_width_p = ((float) width) + ((float) ctk_em_to_pixel ((double) (2 * UNITY_LAUNCHER_MARGIN)));
	*natural_width_p = *min_width_p;
	_g_object_unref0 (settings);
}


static gboolean __unity_launcher_quicklist_menu_item_update_item_background_gsource_func (gpointer self) {
	gboolean result;
	result = _unity_launcher_quicklist_menu_item_update_item_background (self);
	return result;
}


static void unity_launcher_quicklist_menu_item_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityLauncherQuicklistMenuItem * self;
	gint new_width;
	gint new_height;
	gboolean _tmp0_ = FALSE;
	self = (UnityLauncherQuicklistMenuItem*) base;
	new_width = 0;
	new_height = 0;
	CLUTTER_ACTOR_CLASS (unity_launcher_quicklist_menu_item_parent_class)->allocate ((ClutterActor*) CTK_MENU_ITEM (self), box, flags);
	new_width = (gint) ((*box).x2 - (*box).x1);
	new_height = (gint) ((*box).y2 - (*box).y1);
	if (self->priv->last_width == new_width) {
		_tmp0_ = self->priv->last_height == new_height;
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		return;
	}
	self->priv->last_width = new_width;
	self->priv->last_height = new_height;
	g_timeout_add_full (G_PRIORITY_DEFAULT, (guint) 0, __unity_launcher_quicklist_menu_item_update_item_background_gsource_func, g_object_ref (self), g_object_unref);
}


static gboolean _unity_launcher_quicklist_menu_item_update_item_background (UnityLauncherQuicklistMenuItem* self) {
	gboolean result = FALSE;
	ClutterColor _tmp0_ = {0};
	ClutterColor white_color;
	CtkLayerActor* _tmp1_;
	CtkLayer* normal_layer;
	CtkLayer* selected_layer;
	cairo_surface_t* normal_surf;
	cairo_surface_t* selected_surf;
	cairo_t* normal_cr;
	cairo_t* selected_cr;
	GtkSettings* settings;
	char* _tmp3_;
	char* _tmp2_ = NULL;
	char* _tmp5_;
	char* _tmp4_ = NULL;
	g_return_val_if_fail (self != NULL, FALSE);
	white_color = (memset (&_tmp0_, 0, sizeof (ClutterColor)), _tmp0_.red = (guint8) 255, _tmp0_.green = (guint8) 255, _tmp0_.blue = (guint8) 255, _tmp0_.alpha = (guint8) 255, _tmp0_);
	if (CTK_IS_LAYER_ACTOR (self->priv->item_background)) {
		clutter_actor_unparent ((ClutterActor*) self->priv->item_background);
		clutter_actor_destroy ((ClutterActor*) self->priv->item_background);
	}
	self->priv->item_background = (_tmp1_ = g_object_ref_sink ((CtkLayerActor*) ctk_layer_actor_new ((guint) self->priv->last_width, (guint) self->priv->last_height)), _g_object_unref0 (self->priv->item_background), _tmp1_);
	normal_layer = ctk_layer_new ((guint) self->priv->last_width, (guint) self->priv->last_height, CTK_LAYER_REPEAT_NONE, CTK_LAYER_REPEAT_NONE);
	selected_layer = ctk_layer_new ((guint) self->priv->last_width, (guint) self->priv->last_height, CTK_LAYER_REPEAT_NONE, CTK_LAYER_REPEAT_NONE);
	normal_surf = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, self->priv->last_width, self->priv->last_height);
	selected_surf = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, self->priv->last_width, self->priv->last_height);
	normal_cr = cairo_create (normal_surf);
	selected_cr = cairo_create (selected_surf);
	settings = _g_object_ref0 (gtk_settings_get_default ());
	unity_quicklist_rendering_item_normal_mask (normal_cr, self->priv->last_width, self->priv->last_height, _tmp3_ = (g_object_get (settings, "gtk-font-name", &_tmp2_, NULL), _tmp2_), ctk_menu_item_get_label ((CtkMenuItem*) self));
	_g_free0 (_tmp3_);
	unity_quicklist_rendering_item_selected_mask (selected_cr, self->priv->last_width, self->priv->last_height, _tmp5_ = (g_object_get (settings, "gtk-font-name", &_tmp4_, NULL), _tmp4_), ctk_menu_item_get_label ((CtkMenuItem*) self));
	_g_free0 (_tmp5_);
	ctk_layer_set_mask_from_surface (normal_layer, normal_surf);
	ctk_layer_set_color (normal_layer, &white_color);
	ctk_layer_set_mask_from_surface (selected_layer, selected_surf);
	ctk_layer_set_color (selected_layer, &white_color);
	ctk_layer_actor_add_layer (self->priv->item_background, normal_layer);
	ctk_layer_actor_add_layer (self->priv->item_background, selected_layer);
	ctk_layer_set_enabled (ctk_layer_actor_get_layer (self->priv->item_background, (guint) 0), TRUE);
	ctk_layer_set_enabled (ctk_layer_actor_get_layer (self->priv->item_background, (guint) 1), FALSE);
	if (CLUTTER_IS_STAGE (clutter_actor_get_stage ((ClutterActor*) self))) {
		clutter_actor_queue_redraw ((ClutterActor*) self);
	}
	clutter_actor_set_parent ((ClutterActor*) self->priv->item_background, (ClutterActor*) self);
	clutter_actor_map ((ClutterActor*) self->priv->item_background);
	clutter_actor_show ((ClutterActor*) self->priv->item_background);
	result = FALSE;
	_g_object_unref0 (settings);
	_cairo_destroy0 (selected_cr);
	_cairo_destroy0 (normal_cr);
	_cairo_surface_destroy0 (selected_surf);
	_cairo_surface_destroy0 (normal_surf);
	_g_object_unref0 (selected_layer);
	_g_object_unref0 (normal_layer);
	return result;
}


static gboolean _unity_launcher_quicklist_menu_item_on_enter (UnityLauncherQuicklistMenuItem* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (UNITY_LAUNCHER_IS_QUICKLIST_MENU_ITEM (self), FALSE);
	ctk_layer_set_enabled (ctk_layer_actor_get_layer (self->priv->item_background, (guint) 0), FALSE);
	ctk_layer_set_enabled (ctk_layer_actor_get_layer (self->priv->item_background, (guint) 1), TRUE);
	if (CLUTTER_IS_STAGE (clutter_actor_get_stage ((ClutterActor*) self))) {
		clutter_actor_queue_redraw ((ClutterActor*) self);
	}
	result = FALSE;
	return result;
}


static gboolean _unity_launcher_quicklist_menu_item_on_leave (UnityLauncherQuicklistMenuItem* self, ClutterEvent* event) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (UNITY_LAUNCHER_IS_QUICKLIST_MENU_ITEM (self), FALSE);
	ctk_layer_set_enabled (ctk_layer_actor_get_layer (self->priv->item_background, (guint) 0), TRUE);
	ctk_layer_set_enabled (ctk_layer_actor_get_layer (self->priv->item_background, (guint) 1), FALSE);
	if (CLUTTER_IS_STAGE (clutter_actor_get_stage ((ClutterActor*) self))) {
		clutter_actor_queue_redraw ((ClutterActor*) self);
	}
	result = FALSE;
	return result;
}


static void _unity_launcher_quicklist_menu_item_on_label_changed (UnityLauncherQuicklistMenuItem* self) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	if (_vala_strcmp0 (self->priv->old_label, ctk_menu_item_get_label ((CtkMenuItem*) self)) == 0) {
		return;
	}
	self->priv->old_label = (_tmp0_ = g_strdup (ctk_menu_item_get_label ((CtkMenuItem*) self)), _g_free0 (self->priv->old_label), _tmp0_);
}


static void __unity_launcher_quicklist_menu_item_on_label_changed_g_object_notify (GObject* _sender, GParamSpec* pspec, gpointer self) {
	_unity_launcher_quicklist_menu_item_on_label_changed (self);
}


static gboolean __unity_launcher_quicklist_menu_item_on_enter_clutter_actor_enter_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = _unity_launcher_quicklist_menu_item_on_enter (self, event);
	return result;
}


static gboolean __unity_launcher_quicklist_menu_item_on_leave_clutter_actor_leave_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = _unity_launcher_quicklist_menu_item_on_leave (self, event);
	return result;
}


static gboolean __unity_launcher_quicklist_menu_item_on_mouse_down_clutter_actor_button_press_event (ClutterActor* _sender, ClutterEvent* event, gpointer self) {
	gboolean result;
	result = _unity_launcher_quicklist_menu_item_on_mouse_down (self, event);
	return result;
}


static gboolean _unity_launcher_quicklist_menu_item_on_mouse_down (UnityLauncherQuicklistMenuItem* self, ClutterEvent* event) {
	gboolean result = FALSE;
	GQuark _tmp1_;
	guint _tmp0_;
	guint _tmp2_;
	guint _tmp3_;
	guint _tmp4_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_signal_parse_name ("notify::label", G_TYPE_OBJECT, &_tmp0_, &_tmp1_, TRUE);
	g_signal_handlers_disconnect_matched ((GObject*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_DETAIL | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp0_, _tmp1_, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_label_changed_g_object_notify, self);
	g_signal_parse_name ("enter-event", CLUTTER_TYPE_ACTOR, &_tmp2_, NULL, FALSE);
	g_signal_handlers_disconnect_matched ((ClutterActor*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp2_, 0, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_enter_clutter_actor_enter_event, self);
	g_signal_parse_name ("leave-event", CLUTTER_TYPE_ACTOR, &_tmp3_, NULL, FALSE);
	g_signal_handlers_disconnect_matched ((ClutterActor*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp3_, 0, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_leave_clutter_actor_leave_event, self);
	g_signal_parse_name ("button-press-event", CLUTTER_TYPE_ACTOR, &_tmp4_, NULL, FALSE);
	g_signal_handlers_disconnect_matched ((ClutterActor*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp4_, 0, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_mouse_down_clutter_actor_button_press_event, self);
	g_signal_emit_by_name ((CtkMenuItem*) self, "activated");
	result = TRUE;
	return result;
}


UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_construct (GType object_type) {
	UnityLauncherQuicklistMenuItem * self;
	self = (UnityLauncherQuicklistMenuItem*) g_object_new (object_type, "label", "", NULL);
	return self;
}


UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_new (void) {
	return unity_launcher_quicklist_menu_item_construct (UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM);
}


UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_construct_with_label (GType object_type, const char* label) {
	UnityLauncherQuicklistMenuItem * self;
	g_return_val_if_fail (label != NULL, NULL);
	self = (UnityLauncherQuicklistMenuItem*) g_object_new (object_type, "label", label, NULL);
	return self;
}


UnityLauncherQuicklistMenuItem* unity_launcher_quicklist_menu_item_new_with_label (const char* label) {
	return unity_launcher_quicklist_menu_item_construct_with_label (UNITY_LAUNCHER_TYPE_QUICKLIST_MENU_ITEM, label);
}


static GObject * unity_launcher_quicklist_menu_item_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLauncherQuicklistMenuItem * self;
	parent_class = G_OBJECT_CLASS (unity_launcher_quicklist_menu_item_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAUNCHER_QUICKLIST_MENU_ITEM (obj);
	{
		CtkPadding _tmp0_ = {0};
		CtkPadding padding;
		char* _tmp1_;
		padding = (memset (&_tmp0_, 0, sizeof (CtkPadding)), _tmp0_.left = (float) ((gint) ctk_em_to_pixel ((double) UNITY_LAUNCHER_MARGIN)), _tmp0_.right = (float) ((gint) ctk_em_to_pixel ((double) UNITY_LAUNCHER_MARGIN)), _tmp0_.top = (float) ((gint) ctk_em_to_pixel ((double) UNITY_LAUNCHER_MARGIN)), _tmp0_.bottom = (float) ((gint) ctk_em_to_pixel ((double) UNITY_LAUNCHER_MARGIN)), _tmp0_);
		ctk_actor_set_padding ((CtkActor*) self, &padding);
		g_signal_connect_object ((GObject*) self, "notify::label", (GCallback) __unity_launcher_quicklist_menu_item_on_label_changed_g_object_notify, self, 0);
		g_signal_connect_object ((ClutterActor*) self, "enter-event", (GCallback) __unity_launcher_quicklist_menu_item_on_enter_clutter_actor_enter_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self, "leave-event", (GCallback) __unity_launcher_quicklist_menu_item_on_leave_clutter_actor_leave_event, self, 0);
		g_signal_connect_object ((ClutterActor*) self, "button-press-event", (GCallback) __unity_launcher_quicklist_menu_item_on_mouse_down_clutter_actor_button_press_event, self, 0);
		clutter_actor_set_reactive ((ClutterActor*) self, TRUE);
		self->priv->last_width = -1;
		self->priv->last_height = -1;
		self->priv->old_label = (_tmp1_ = g_strdup (""), _g_free0 (self->priv->old_label), _tmp1_);
	}
	return obj;
}


static void unity_launcher_quicklist_menu_item_class_init (UnityLauncherQuicklistMenuItemClass * klass) {
	unity_launcher_quicklist_menu_item_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityLauncherQuicklistMenuItemPrivate));
	CLUTTER_ACTOR_CLASS (klass)->paint = unity_launcher_quicklist_menu_item_real_paint;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_launcher_quicklist_menu_item_real_get_preferred_height;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_launcher_quicklist_menu_item_real_get_preferred_width;
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_launcher_quicklist_menu_item_real_allocate;
	G_OBJECT_CLASS (klass)->constructor = unity_launcher_quicklist_menu_item_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_launcher_quicklist_menu_item_finalize;
}


static void unity_launcher_quicklist_menu_item_instance_init (UnityLauncherQuicklistMenuItem * self) {
	self->priv = UNITY_LAUNCHER_QUICKLIST_MENU_ITEM_GET_PRIVATE (self);
}


static void unity_launcher_quicklist_menu_item_finalize (GObject* obj) {
	UnityLauncherQuicklistMenuItem * self;
	self = UNITY_LAUNCHER_QUICKLIST_MENU_ITEM (obj);
	{
		GQuark _tmp3_;
		guint _tmp2_;
		guint _tmp4_;
		guint _tmp5_;
		guint _tmp6_;
		g_signal_parse_name ("notify::label", G_TYPE_OBJECT, &_tmp2_, &_tmp3_, TRUE);
		g_signal_handlers_disconnect_matched ((GObject*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_DETAIL | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp2_, _tmp3_, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_label_changed_g_object_notify, self);
		g_signal_parse_name ("enter-event", CLUTTER_TYPE_ACTOR, &_tmp4_, NULL, FALSE);
		g_signal_handlers_disconnect_matched ((ClutterActor*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp4_, 0, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_enter_clutter_actor_enter_event, self);
		g_signal_parse_name ("leave-event", CLUTTER_TYPE_ACTOR, &_tmp5_, NULL, FALSE);
		g_signal_handlers_disconnect_matched ((ClutterActor*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp5_, 0, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_leave_clutter_actor_leave_event, self);
		g_signal_parse_name ("button-press-event", CLUTTER_TYPE_ACTOR, &_tmp6_, NULL, FALSE);
		g_signal_handlers_disconnect_matched ((ClutterActor*) self, G_SIGNAL_MATCH_ID | G_SIGNAL_MATCH_FUNC | G_SIGNAL_MATCH_DATA, _tmp6_, 0, NULL, (GCallback) __unity_launcher_quicklist_menu_item_on_mouse_down_clutter_actor_button_press_event, self);
	}
	_g_object_unref0 (self->priv->item_background);
	_g_free0 (self->priv->old_label);
	G_OBJECT_CLASS (unity_launcher_quicklist_menu_item_parent_class)->finalize (obj);
}


GType unity_launcher_quicklist_menu_item_get_type (void) {
	static volatile gsize unity_launcher_quicklist_menu_item_type_id__volatile = 0;
	if (g_once_init_enter (&unity_launcher_quicklist_menu_item_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLauncherQuicklistMenuItemClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_launcher_quicklist_menu_item_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLauncherQuicklistMenuItem), 0, (GInstanceInitFunc) unity_launcher_quicklist_menu_item_instance_init, NULL };
		GType unity_launcher_quicklist_menu_item_type_id;
		unity_launcher_quicklist_menu_item_type_id = g_type_register_static (CTK_TYPE_MENU_ITEM, "UnityLauncherQuicklistMenuItem", &g_define_type_info, 0);
		g_once_init_leave (&unity_launcher_quicklist_menu_item_type_id__volatile, unity_launcher_quicklist_menu_item_type_id);
	}
	return unity_launcher_quicklist_menu_item_type_id__volatile;
}


static int _vala_strcmp0 (const char * str1, const char * str2) {
	if (str1 == NULL) {
		return -(str1 != str2);
	}
	if (str2 == NULL) {
		return str1 != str2;
	}
	return strcmp (str1, str2);
}




