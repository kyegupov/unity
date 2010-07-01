/* panel-menubar.c generated by valac, the Vala compiler
 * generated from panel-menubar.vala, do not modify */

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
 * Authored by canonical.com
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <gtk/gtk.h>
#include <gee.h>
#include <libindicator/indicator-object.h>
#include <stdlib.h>
#include <string.h>
#include <clutter/clutter.h>


#define UNITY_PANEL_INDICATORS_TYPE_MENU_BAR (unity_panel_indicators_menu_bar_get_type ())
#define UNITY_PANEL_INDICATORS_MENU_BAR(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR, UnityPanelIndicatorsMenuBar))
#define UNITY_PANEL_INDICATORS_MENU_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR, UnityPanelIndicatorsMenuBarClass))
#define UNITY_PANEL_INDICATORS_IS_MENU_BAR(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR))
#define UNITY_PANEL_INDICATORS_IS_MENU_BAR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR))
#define UNITY_PANEL_INDICATORS_MENU_BAR_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_MENU_BAR, UnityPanelIndicatorsMenuBarClass))

typedef struct _UnityPanelIndicatorsMenuBar UnityPanelIndicatorsMenuBar;
typedef struct _UnityPanelIndicatorsMenuBarClass UnityPanelIndicatorsMenuBarClass;
typedef struct _UnityPanelIndicatorsMenuBarPrivate UnityPanelIndicatorsMenuBarPrivate;

#define UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW (unity_panel_indicators_indicator_object_view_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectView))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewClass))

typedef struct _UnityPanelIndicatorsIndicatorObjectView UnityPanelIndicatorsIndicatorObjectView;
typedef struct _UnityPanelIndicatorsIndicatorObjectViewClass UnityPanelIndicatorsIndicatorObjectViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL (unity_panel_indicators_indicators_model_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModel))
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModelClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL))
#define UNITY_PANEL_INDICATORS_IS_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL))
#define UNITY_PANEL_INDICATORS_INDICATORS_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, UnityPanelIndicatorsIndicatorsModelClass))

typedef struct _UnityPanelIndicatorsIndicatorsModel UnityPanelIndicatorsIndicatorsModel;
typedef struct _UnityPanelIndicatorsIndicatorsModelClass UnityPanelIndicatorsIndicatorsModelClass;
#define _g_free0(var) (var = (g_free (var), NULL))

struct _UnityPanelIndicatorsMenuBar {
	CtkBox parent_instance;
	UnityPanelIndicatorsMenuBarPrivate * priv;
	UnityPanelIndicatorsIndicatorObjectView* indicator_object_view;
};

struct _UnityPanelIndicatorsMenuBarClass {
	CtkBoxClass parent_class;
};


static gpointer unity_panel_indicators_menu_bar_parent_class = NULL;

GType unity_panel_indicators_menu_bar_get_type (void);
GType unity_panel_indicators_indicator_object_view_get_type (void);
enum  {
	UNITY_PANEL_INDICATORS_MENU_BAR_DUMMY_PROPERTY
};
UnityPanelIndicatorsMenuBar* unity_panel_indicators_menu_bar_new (void);
UnityPanelIndicatorsMenuBar* unity_panel_indicators_menu_bar_construct (GType object_type);
void unity_panel_indicators_indicator_object_view_open_last_menu_entry (UnityPanelIndicatorsIndicatorObjectView* self);
void unity_panel_indicators_indicator_object_view_open_first_menu_entry (UnityPanelIndicatorsIndicatorObjectView* self);
static void unity_panel_indicators_menu_bar_on_menu_moved (UnityPanelIndicatorsMenuBar* self, UnityPanelIndicatorsIndicatorObjectView* object_view, GtkMenuDirectionType type);
GType unity_panel_indicators_indicators_model_get_type (void);
UnityPanelIndicatorsIndicatorsModel* unity_panel_indicators_indicators_model_get_default (void);
GeeArrayList* unity_panel_indicators_indicators_model_get_indicators (UnityPanelIndicatorsIndicatorsModel* self);
char* unity_panel_indicators_indicators_model_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* self, IndicatorObject* o);
UnityPanelIndicatorsIndicatorObjectView* unity_panel_indicators_indicator_object_view_new (IndicatorObject* _object);
UnityPanelIndicatorsIndicatorObjectView* unity_panel_indicators_indicator_object_view_construct (GType object_type, IndicatorObject* _object);
static void _unity_panel_indicators_menu_bar_on_menu_moved_unity_panel_indicators_indicator_object_view_menu_moved (UnityPanelIndicatorsIndicatorObjectView* _sender, GtkMenuDirectionType type, gpointer self);
static GObject * unity_panel_indicators_menu_bar_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_indicators_menu_bar_finalize (GObject* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



UnityPanelIndicatorsMenuBar* unity_panel_indicators_menu_bar_construct (GType object_type) {
	UnityPanelIndicatorsMenuBar * self;
	self = (UnityPanelIndicatorsMenuBar*) g_object_new (object_type, "spacing", 0, "homogeneous", FALSE, "orientation", CTK_ORIENTATION_HORIZONTAL, NULL);
	return self;
}


UnityPanelIndicatorsMenuBar* unity_panel_indicators_menu_bar_new (void) {
	return unity_panel_indicators_menu_bar_construct (UNITY_PANEL_INDICATORS_TYPE_MENU_BAR);
}


static void unity_panel_indicators_menu_bar_on_menu_moved (UnityPanelIndicatorsMenuBar* self, UnityPanelIndicatorsIndicatorObjectView* object_view, GtkMenuDirectionType type) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (object_view != NULL);
	if (type == GTK_MENU_DIR_PARENT) {
		unity_panel_indicators_indicator_object_view_open_last_menu_entry (self->indicator_object_view);
	}
	if (type == GTK_MENU_DIR_CHILD) {
		unity_panel_indicators_indicator_object_view_open_first_menu_entry (self->indicator_object_view);
	}
}


static void _unity_panel_indicators_menu_bar_on_menu_moved_unity_panel_indicators_indicator_object_view_menu_moved (UnityPanelIndicatorsIndicatorObjectView* _sender, GtkMenuDirectionType type, gpointer self) {
	unity_panel_indicators_menu_bar_on_menu_moved (self, _sender, type);
}


static GObject * unity_panel_indicators_menu_bar_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelIndicatorsMenuBar * self;
	parent_class = G_OBJECT_CLASS (unity_panel_indicators_menu_bar_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_INDICATORS_MENU_BAR (obj);
	{
		UnityPanelIndicatorsIndicatorsModel* model;
		GeeArrayList* indicators_list;
		ClutterColor _tmp2_;
		ClutterColor _tmp1_ = {0};
		ClutterRectangle* rect;
		model = unity_panel_indicators_indicators_model_get_default ();
		indicators_list = unity_panel_indicators_indicators_model_get_indicators (model);
		{
			GeeIterator* _o_it;
			_o_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) indicators_list);
			while (TRUE) {
				IndicatorObject* o;
				char* name;
				if (!gee_iterator_next (_o_it)) {
					break;
				}
				o = (IndicatorObject*) gee_iterator_get (_o_it);
				name = unity_panel_indicators_indicators_model_get_indicator_name (model, o);
				if (_vala_strcmp0 (name, "libappmenu.so") == 0) {
					UnityPanelIndicatorsIndicatorObjectView* _tmp0_;
					self->indicator_object_view = (_tmp0_ = g_object_ref_sink (unity_panel_indicators_indicator_object_view_new (o)), _g_object_unref0 (self->indicator_object_view), _tmp0_);
					g_signal_connect_object (self->indicator_object_view, "menu-moved", (GCallback) _unity_panel_indicators_menu_bar_on_menu_moved_unity_panel_indicators_indicator_object_view_menu_moved, self, 0);
					ctk_box_pack ((CtkBox*) self, (ClutterActor*) self->indicator_object_view, FALSE, TRUE);
					clutter_actor_show ((ClutterActor*) self->indicator_object_view);
					_g_object_unref0 (o);
					_g_free0 (name);
					break;
				}
				_g_object_unref0 (o);
				_g_free0 (name);
			}
			_g_object_unref0 (_o_it);
		}
		rect = g_object_ref_sink ((ClutterRectangle*) clutter_rectangle_new_with_color ((_tmp2_ = (_tmp1_.red = (guint8) 255, _tmp1_.green = (guint8) 0, _tmp1_.blue = (guint8) 0, _tmp1_.alpha = (guint8) 0, _tmp1_), &_tmp2_)));
		ctk_box_pack ((CtkBox*) self, (ClutterActor*) rect, TRUE, TRUE);
		clutter_actor_show ((ClutterActor*) rect);
		_g_object_unref0 (model);
		_g_object_unref0 (indicators_list);
		_g_object_unref0 (rect);
	}
	return obj;
}


static void unity_panel_indicators_menu_bar_class_init (UnityPanelIndicatorsMenuBarClass * klass) {
	unity_panel_indicators_menu_bar_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructor = unity_panel_indicators_menu_bar_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_indicators_menu_bar_finalize;
}


static void unity_panel_indicators_menu_bar_instance_init (UnityPanelIndicatorsMenuBar * self) {
}


static void unity_panel_indicators_menu_bar_finalize (GObject* obj) {
	UnityPanelIndicatorsMenuBar * self;
	self = UNITY_PANEL_INDICATORS_MENU_BAR (obj);
	_g_object_unref0 (self->indicator_object_view);
	G_OBJECT_CLASS (unity_panel_indicators_menu_bar_parent_class)->finalize (obj);
}


GType unity_panel_indicators_menu_bar_get_type (void) {
	static volatile gsize unity_panel_indicators_menu_bar_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_indicators_menu_bar_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelIndicatorsMenuBarClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_indicators_menu_bar_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelIndicatorsMenuBar), 0, (GInstanceInitFunc) unity_panel_indicators_menu_bar_instance_init, NULL };
		GType unity_panel_indicators_menu_bar_type_id;
		unity_panel_indicators_menu_bar_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPanelIndicatorsMenuBar", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_indicators_menu_bar_type_id__volatile, unity_panel_indicators_menu_bar_type_id);
	}
	return unity_panel_indicators_menu_bar_type_id__volatile;
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




