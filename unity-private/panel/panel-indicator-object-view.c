/* panel-indicator-object-view.c generated by valac, the Vala compiler
 * generated from panel-indicator-object-view.vala, do not modify */

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
 *              Jay Taoko <jay.taoko@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <libindicator/indicator-object.h>
#include <gee.h>
#include <gtk/gtk.h>
#include <libindicator/indicator.h>
#include <libindicator/indicator-service.h>
#include <libindicator/indicator-service-manager.h>
#include <clutter/clutter.h>
#include <unity-utils.h>


#define UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW (unity_panel_indicators_indicator_object_view_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectView))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewClass))

typedef struct _UnityPanelIndicatorsIndicatorObjectView UnityPanelIndicatorsIndicatorObjectView;
typedef struct _UnityPanelIndicatorsIndicatorObjectViewClass UnityPanelIndicatorsIndicatorObjectViewClass;
typedef struct _UnityPanelIndicatorsIndicatorObjectViewPrivate UnityPanelIndicatorsIndicatorObjectViewPrivate;

#define UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW (unity_panel_indicators_indicator_object_entry_view_get_type ())
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_ENTRY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW, UnityPanelIndicatorsIndicatorObjectEntryView))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_ENTRY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW, UnityPanelIndicatorsIndicatorObjectEntryViewClass))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW))
#define UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW))
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_ENTRY_VIEW_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW, UnityPanelIndicatorsIndicatorObjectEntryViewClass))

typedef struct _UnityPanelIndicatorsIndicatorObjectEntryView UnityPanelIndicatorsIndicatorObjectEntryView;
typedef struct _UnityPanelIndicatorsIndicatorObjectEntryViewClass UnityPanelIndicatorsIndicatorObjectEntryViewClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityPanelIndicatorsIndicatorObjectView {
	CtkBox parent_instance;
	UnityPanelIndicatorsIndicatorObjectViewPrivate * priv;
};

struct _UnityPanelIndicatorsIndicatorObjectViewClass {
	CtkBoxClass parent_class;
};

struct _UnityPanelIndicatorsIndicatorObjectViewPrivate {
	IndicatorObject* _indicator_object;
	GeeArrayList* indicator_entry_array;
};


static gpointer unity_panel_indicators_indicator_object_view_parent_class = NULL;

GType unity_panel_indicators_indicator_object_view_get_type (void) G_GNUC_CONST;
GType unity_panel_indicators_indicator_object_entry_view_get_type (void) G_GNUC_CONST;
#define UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, UnityPanelIndicatorsIndicatorObjectViewPrivate))
enum  {
	UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_DUMMY_PROPERTY,
	UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_INDICATOR_OBJECT
};
UnityPanelIndicatorsIndicatorObjectView* unity_panel_indicators_indicator_object_view_new (IndicatorObject* _object);
UnityPanelIndicatorsIndicatorObjectView* unity_panel_indicators_indicator_object_view_construct (GType object_type, IndicatorObject* _object);
void unity_panel_indicators_indicator_object_view_show_entry_menu (UnityPanelIndicatorsIndicatorObjectView* self, gint entry);
void unity_panel_indicators_indicator_object_entry_view_show_menu (UnityPanelIndicatorsIndicatorObjectEntryView* self);
static void unity_panel_indicators_indicator_object_view_on_menu_moved (UnityPanelIndicatorsIndicatorObjectView* self, UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view, GtkMenuDirectionType type);
IndicatorObjectEntry* unity_panel_indicators_indicator_object_entry_view_get_entry (UnityPanelIndicatorsIndicatorObjectEntryView* self);
UnityPanelIndicatorsIndicatorObjectEntryView* unity_panel_indicators_indicator_object_entry_view_new (IndicatorObjectEntry* _entry);
UnityPanelIndicatorsIndicatorObjectEntryView* unity_panel_indicators_indicator_object_entry_view_construct (GType object_type, IndicatorObjectEntry* _entry);
static void _unity_panel_indicators_indicator_object_view_on_menu_moved_unity_panel_indicators_indicator_object_entry_view_menu_moved (UnityPanelIndicatorsIndicatorObjectEntryView* _sender, GtkMenuDirectionType type, gpointer self);
static void unity_panel_indicators_indicator_object_view_on_entry_added (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObject* object, IndicatorObjectEntry* indicator_object_entry);
static void unity_panel_indicators_indicator_object_view_remove_entry (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObjectEntry* entry);
void unity_panel_indicators_indicator_object_view_open_first_menu_entry (UnityPanelIndicatorsIndicatorObjectView* self);
void unity_panel_indicators_indicator_object_view_open_last_menu_entry (UnityPanelIndicatorsIndicatorObjectView* self);
gboolean unity_panel_indicators_indicator_object_view_find_entry (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObjectEntry* entry);
UnityPanelIndicatorsIndicatorObjectEntryView* unity_panel_indicators_indicator_object_view_get_entry_view (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObjectEntry* entry);
void unity_panel_indicators_indicator_object_view_remove_first_entry (UnityPanelIndicatorsIndicatorObjectView* self);
IndicatorObject* unity_panel_indicators_indicator_object_view_get_indicator_object (UnityPanelIndicatorsIndicatorObjectView* self);
static void unity_panel_indicators_indicator_object_view_set_indicator_object (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObject* value);
static void _unity_panel_indicators_indicator_object_view_on_entry_added_indicator_object_entry_added (IndicatorObject* _sender, IndicatorObjectEntry* entry, gpointer self);
static void _unity_panel_indicators_indicator_object_view_remove_entry_indicator_object_entry_removed (IndicatorObject* _sender, IndicatorObjectEntry* entry, gpointer self);
static GObject * unity_panel_indicators_indicator_object_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_panel_indicators_indicator_object_view_finalize (GObject* obj);
static void unity_panel_indicators_indicator_object_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_panel_indicators_indicator_object_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPanelIndicatorsIndicatorObjectView* unity_panel_indicators_indicator_object_view_construct (GType object_type, IndicatorObject* _object) {
	UnityPanelIndicatorsIndicatorObjectView * self;
	g_return_val_if_fail (_object != NULL, NULL);
	self = (UnityPanelIndicatorsIndicatorObjectView*) g_object_new (object_type, "indicator-object", _object, "orientation", CTK_ORIENTATION_HORIZONTAL, "spacing", 0, "homogeneous", FALSE, NULL);
	return self;
}


UnityPanelIndicatorsIndicatorObjectView* unity_panel_indicators_indicator_object_view_new (IndicatorObject* _object) {
	return unity_panel_indicators_indicator_object_view_construct (UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, _object);
}


void unity_panel_indicators_indicator_object_view_show_entry_menu (UnityPanelIndicatorsIndicatorObjectView* self, gint entry) {
	g_return_if_fail (self != NULL);
}


static void unity_panel_indicators_indicator_object_view_on_menu_moved (UnityPanelIndicatorsIndicatorObjectView* self, UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view, GtkMenuDirectionType type) {
	gint pos;
	UnityPanelIndicatorsIndicatorObjectEntryView* next_object_entry_view;
	g_return_if_fail (self != NULL);
	g_return_if_fail (object_entry_view != NULL);
	pos = gee_abstract_list_index_of ((GeeAbstractList*) self->priv->indicator_entry_array, object_entry_view);
	if (pos == (-1)) {
		return;
	}
	if (type == GTK_MENU_DIR_PARENT) {
		if (pos == 0) {
			g_signal_emit_by_name (self, "menu-moved", type);
			return;
		}
		pos = pos - 1;
	} else {
		if (type == GTK_MENU_DIR_CHILD) {
			if (pos == (gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array) - 1)) {
				g_signal_emit_by_name (self, "menu-moved", type);
				return;
			}
			pos = pos + 1;
		}
	}
	next_object_entry_view = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, pos);
	unity_panel_indicators_indicator_object_entry_view_show_menu (next_object_entry_view);
	_g_object_unref0 (next_object_entry_view);
}


static void _unity_panel_indicators_indicator_object_view_on_menu_moved_unity_panel_indicators_indicator_object_entry_view_menu_moved (UnityPanelIndicatorsIndicatorObjectEntryView* _sender, GtkMenuDirectionType type, gpointer self) {
	unity_panel_indicators_indicator_object_view_on_menu_moved (self, _sender, type);
}


static void unity_panel_indicators_indicator_object_view_on_entry_added (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObject* object, IndicatorObjectEntry* indicator_object_entry) {
	UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
	g_return_if_fail (self != NULL);
	g_return_if_fail (object != NULL);
	g_return_if_fail (indicator_object_entry != NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				UnityPanelIndicatorsIndicatorObjectEntryView* _tmp1_;
				UnityPanelIndicatorsIndicatorObjectEntryView* entry_view;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array))) {
					break;
				}
				entry_view = (_tmp1_ = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, i), UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (_tmp1_) ? ((UnityPanelIndicatorsIndicatorObjectEntryView*) _tmp1_) : NULL);
				if (unity_panel_indicators_indicator_object_entry_view_get_entry (entry_view) == indicator_object_entry) {
					_g_object_unref0 (entry_view);
					return;
				}
				_g_object_unref0 (entry_view);
			}
		}
	}
	object_entry_view = g_object_ref_sink (unity_panel_indicators_indicator_object_entry_view_new (indicator_object_entry));
	g_signal_connect_object (object_entry_view, "menu-moved", (GCallback) _unity_panel_indicators_indicator_object_view_on_menu_moved_unity_panel_indicators_indicator_object_entry_view_menu_moved, self, 0);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->indicator_entry_array, object_entry_view);
	clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) object_entry_view);
	_g_object_unref0 (object_entry_view);
}


static void unity_panel_indicators_indicator_object_view_remove_entry (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObjectEntry* entry) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				UnityPanelIndicatorsIndicatorObjectEntryView* _tmp1_;
				UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array))) {
					break;
				}
				object_entry_view = (_tmp1_ = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, i), UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (_tmp1_) ? ((UnityPanelIndicatorsIndicatorObjectEntryView*) _tmp1_) : NULL);
				if (unity_panel_indicators_indicator_object_entry_view_get_entry (object_entry_view) == entry) {
					clutter_container_remove_actor ((ClutterContainer*) self, (ClutterActor*) object_entry_view);
					gee_abstract_collection_remove ((GeeAbstractCollection*) self->priv->indicator_entry_array, object_entry_view);
				}
				_g_object_unref0 (object_entry_view);
			}
		}
	}
}


void unity_panel_indicators_indicator_object_view_open_first_menu_entry (UnityPanelIndicatorsIndicatorObjectView* self) {
	g_return_if_fail (self != NULL);
	if (gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array) > 0) {
		UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
		object_entry_view = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, 0);
		unity_panel_indicators_indicator_object_entry_view_show_menu (object_entry_view);
		_g_object_unref0 (object_entry_view);
	}
}


void unity_panel_indicators_indicator_object_view_open_last_menu_entry (UnityPanelIndicatorsIndicatorObjectView* self) {
	g_return_if_fail (self != NULL);
	if (gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array) > 0) {
		UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
		object_entry_view = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array) - 1);
		unity_panel_indicators_indicator_object_entry_view_show_menu (object_entry_view);
		_g_object_unref0 (object_entry_view);
	}
}


gboolean unity_panel_indicators_indicator_object_view_find_entry (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObjectEntry* entry) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (entry != NULL, FALSE);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				UnityPanelIndicatorsIndicatorObjectEntryView* _tmp1_;
				UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array))) {
					break;
				}
				object_entry_view = (_tmp1_ = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, i), UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (_tmp1_) ? ((UnityPanelIndicatorsIndicatorObjectEntryView*) _tmp1_) : NULL);
				if (unity_panel_indicators_indicator_object_entry_view_get_entry (object_entry_view) == entry) {
					result = TRUE;
					_g_object_unref0 (object_entry_view);
					return result;
				}
				_g_object_unref0 (object_entry_view);
			}
		}
	}
	result = FALSE;
	return result;
}


UnityPanelIndicatorsIndicatorObjectEntryView* unity_panel_indicators_indicator_object_view_get_entry_view (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObjectEntry* entry) {
	UnityPanelIndicatorsIndicatorObjectEntryView* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (entry != NULL, NULL);
	{
		gint i;
		i = 0;
		{
			gboolean _tmp0_;
			_tmp0_ = TRUE;
			while (TRUE) {
				UnityPanelIndicatorsIndicatorObjectEntryView* _tmp1_;
				UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
				if (!_tmp0_) {
					i++;
				}
				_tmp0_ = FALSE;
				if (!(i < gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array))) {
					break;
				}
				object_entry_view = (_tmp1_ = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_get ((GeeAbstractList*) self->priv->indicator_entry_array, i), UNITY_PANEL_INDICATORS_IS_INDICATOR_OBJECT_ENTRY_VIEW (_tmp1_) ? ((UnityPanelIndicatorsIndicatorObjectEntryView*) _tmp1_) : NULL);
				if (unity_panel_indicators_indicator_object_entry_view_get_entry (object_entry_view) == entry) {
					result = object_entry_view;
					return result;
				}
				_g_object_unref0 (object_entry_view);
			}
		}
	}
	result = NULL;
	return result;
}


void unity_panel_indicators_indicator_object_view_remove_first_entry (UnityPanelIndicatorsIndicatorObjectView* self) {
	UnityPanelIndicatorsIndicatorObjectEntryView* _tmp0_;
	g_return_if_fail (self != NULL);
	if (gee_collection_get_size ((GeeCollection*) self->priv->indicator_entry_array) == 0) {
		return;
	}
	clutter_container_remove_actor ((ClutterContainer*) self, (ClutterActor*) (_tmp0_ = (UnityPanelIndicatorsIndicatorObjectEntryView*) gee_abstract_list_remove_at ((GeeAbstractList*) self->priv->indicator_entry_array, 0)));
	_g_object_unref0 (_tmp0_);
}


IndicatorObject* unity_panel_indicators_indicator_object_view_get_indicator_object (UnityPanelIndicatorsIndicatorObjectView* self) {
	IndicatorObject* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_indicator_object;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_panel_indicators_indicator_object_view_set_indicator_object (UnityPanelIndicatorsIndicatorObjectView* self, IndicatorObject* value) {
	IndicatorObject* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_indicator_object = (_tmp0_ = _g_object_ref0 (value), _g_object_unref0 (self->priv->_indicator_object), _tmp0_);
	g_object_notify ((GObject *) self, "indicator-object");
}


static void _unity_panel_indicators_indicator_object_view_on_entry_added_indicator_object_entry_added (IndicatorObject* _sender, IndicatorObjectEntry* entry, gpointer self) {
	unity_panel_indicators_indicator_object_view_on_entry_added (self, _sender, entry);
}


static void _unity_panel_indicators_indicator_object_view_remove_entry_indicator_object_entry_removed (IndicatorObject* _sender, IndicatorObjectEntry* entry, gpointer self) {
	unity_panel_indicators_indicator_object_view_remove_entry (self, entry);
}


static GObject * unity_panel_indicators_indicator_object_view_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPanelIndicatorsIndicatorObjectView * self;
	parent_class = G_OBJECT_CLASS (unity_panel_indicators_indicator_object_view_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW (obj);
	{
		GeeArrayList* _tmp0_;
		GList* list;
		START_FUNCTION ();
		self->priv->indicator_entry_array = (_tmp0_ = gee_array_list_new (UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_ENTRY_VIEW, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->indicator_entry_array), _tmp0_);
		g_signal_connect_object (self->priv->_indicator_object, "entry-added", (GCallback) _unity_panel_indicators_indicator_object_view_on_entry_added_indicator_object_entry_added, self, 0);
		g_signal_connect_object (self->priv->_indicator_object, "entry-removed", (GCallback) _unity_panel_indicators_indicator_object_view_remove_entry_indicator_object_entry_removed, self, 0);
		list = indicator_object_get_entries (self->priv->_indicator_object);
		{
			gint i;
			i = 0;
			{
				gboolean _tmp1_;
				_tmp1_ = TRUE;
				while (TRUE) {
					IndicatorObjectEntry* indicator_object_entry;
					UnityPanelIndicatorsIndicatorObjectEntryView* object_entry_view;
					if (!_tmp1_) {
						i++;
					}
					_tmp1_ = FALSE;
					if (!(i < g_list_length (list))) {
						break;
					}
					indicator_object_entry = (IndicatorObjectEntry*) ((IndicatorObjectEntry*) g_list_nth_data (list, (guint) i));
					object_entry_view = g_object_ref_sink (unity_panel_indicators_indicator_object_entry_view_new (indicator_object_entry));
					g_signal_connect_object (object_entry_view, "menu-moved", (GCallback) _unity_panel_indicators_indicator_object_view_on_menu_moved_unity_panel_indicators_indicator_object_entry_view_menu_moved, self, 0);
					gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->indicator_entry_array, object_entry_view);
					clutter_container_add_actor ((ClutterContainer*) self, (ClutterActor*) object_entry_view);
					_g_object_unref0 (object_entry_view);
				}
			}
		}
		END_FUNCTION ();
	}
	return obj;
}


static void unity_panel_indicators_indicator_object_view_class_init (UnityPanelIndicatorsIndicatorObjectViewClass * klass) {
	unity_panel_indicators_indicator_object_view_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPanelIndicatorsIndicatorObjectViewPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_panel_indicators_indicator_object_view_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_panel_indicators_indicator_object_view_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_panel_indicators_indicator_object_view_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_panel_indicators_indicator_object_view_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_INDICATOR_OBJECT, g_param_spec_object ("indicator-object", "indicator-object", "indicator-object", INDICATOR_TYPE_OBJECT, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_signal_new ("menu_moved", UNITY_PANEL_INDICATORS_TYPE_INDICATOR_OBJECT_VIEW, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__ENUM, G_TYPE_NONE, 1, GTK_TYPE_MENU_DIRECTION_TYPE);
}


static void unity_panel_indicators_indicator_object_view_instance_init (UnityPanelIndicatorsIndicatorObjectView * self) {
	self->priv = UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_GET_PRIVATE (self);
}


static void unity_panel_indicators_indicator_object_view_finalize (GObject* obj) {
	UnityPanelIndicatorsIndicatorObjectView * self;
	self = UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW (obj);
	_g_object_unref0 (self->priv->_indicator_object);
	_g_object_unref0 (self->priv->indicator_entry_array);
	G_OBJECT_CLASS (unity_panel_indicators_indicator_object_view_parent_class)->finalize (obj);
}


GType unity_panel_indicators_indicator_object_view_get_type (void) {
	static volatile gsize unity_panel_indicators_indicator_object_view_type_id__volatile = 0;
	if (g_once_init_enter (&unity_panel_indicators_indicator_object_view_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPanelIndicatorsIndicatorObjectViewClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_panel_indicators_indicator_object_view_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPanelIndicatorsIndicatorObjectView), 0, (GInstanceInitFunc) unity_panel_indicators_indicator_object_view_instance_init, NULL };
		GType unity_panel_indicators_indicator_object_view_type_id;
		unity_panel_indicators_indicator_object_view_type_id = g_type_register_static (CTK_TYPE_BOX, "UnityPanelIndicatorsIndicatorObjectView", &g_define_type_info, 0);
		g_once_init_leave (&unity_panel_indicators_indicator_object_view_type_id__volatile, unity_panel_indicators_indicator_object_view_type_id);
	}
	return unity_panel_indicators_indicator_object_view_type_id__volatile;
}


static void unity_panel_indicators_indicator_object_view_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPanelIndicatorsIndicatorObjectView * self;
	self = UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW (object);
	switch (property_id) {
		case UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_INDICATOR_OBJECT:
		g_value_set_object (value, unity_panel_indicators_indicator_object_view_get_indicator_object (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_panel_indicators_indicator_object_view_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPanelIndicatorsIndicatorObjectView * self;
	self = UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW (object);
	switch (property_id) {
		case UNITY_PANEL_INDICATORS_INDICATOR_OBJECT_VIEW_INDICATOR_OBJECT:
		unity_panel_indicators_indicator_object_view_set_indicator_object (self, g_value_get_object (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




