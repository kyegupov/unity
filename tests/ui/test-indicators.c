/* test-indicators.c generated by valac 0.10.0, the Vala compiler
 * generated from test-indicators.vala, do not modify */

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
 * Authored by Jay Taoko <jay.taoko@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <libindicator/indicator-object.h>
#include <gee.h>
#include <gtk/gtk.h>
#include <libindicator/indicator.h>
#include <libindicator/indicator-service.h>
#include <libindicator/indicator-service-manager.h>
#include <unity-utils.h>
#include <stdlib.h>
#include <string.h>
#include <unity-private.h>
#include <clutter/clutter.h>


#define UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT (unity_tests_ui_fake_indicator_object_get_type ())
#define UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUIFakeIndicatorObject))
#define UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUIFakeIndicatorObjectClass))
#define UNITY_TESTS_UI_IS_FAKE_INDICATOR_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT))
#define UNITY_TESTS_UI_IS_FAKE_INDICATOR_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT))
#define UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUIFakeIndicatorObjectClass))

typedef struct _UnityTestsUIFakeIndicatorObject UnityTestsUIFakeIndicatorObject;
typedef struct _UnityTestsUIFakeIndicatorObjectClass UnityTestsUIFakeIndicatorObjectClass;
typedef struct _UnityTestsUIFakeIndicatorObjectPrivate UnityTestsUIFakeIndicatorObjectPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _indicator_object_entry_free0(var) ((var == NULL) ? NULL : (var = (indicator_object_entry_free (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))

#define UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL (unity_tests_ui_fake_indicators_model_get_type ())
#define UNITY_TESTS_UI_FAKE_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL, UnityTestsUIFakeIndicatorsModel))
#define UNITY_TESTS_UI_FAKE_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL, UnityTestsUIFakeIndicatorsModelClass))
#define UNITY_TESTS_UI_IS_FAKE_INDICATORS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL))
#define UNITY_TESTS_UI_IS_FAKE_INDICATORS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL))
#define UNITY_TESTS_UI_FAKE_INDICATORS_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL, UnityTestsUIFakeIndicatorsModelClass))

typedef struct _UnityTestsUIFakeIndicatorsModel UnityTestsUIFakeIndicatorsModel;
typedef struct _UnityTestsUIFakeIndicatorsModelClass UnityTestsUIFakeIndicatorsModelClass;
typedef struct _UnityTestsUIFakeIndicatorsModelPrivate UnityTestsUIFakeIndicatorsModelPrivate;

#define UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE (unity_tests_ui_indicator_test_suite_get_type ())
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuite))
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuiteClass))
#define UNITY_TESTS_UI_IS_INDICATOR_TEST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE))
#define UNITY_TESTS_UI_IS_INDICATOR_TEST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE))
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuiteClass))

typedef struct _UnityTestsUIIndicatorTestSuite UnityTestsUIIndicatorTestSuite;
typedef struct _UnityTestsUIIndicatorTestSuiteClass UnityTestsUIIndicatorTestSuiteClass;
typedef struct _UnityTestsUIIndicatorTestSuitePrivate UnityTestsUIIndicatorTestSuitePrivate;
#define _unity_testing_object_registry_unref0(var) ((var == NULL) ? NULL : (var = (unity_testing_object_registry_unref (var), NULL)))

struct _UnityTestsUIFakeIndicatorObject {
	IndicatorObject parent_instance;
	UnityTestsUIFakeIndicatorObjectPrivate * priv;
	GeeArrayList* indicator_entry_array;
	GtkLabel* _label;
	GtkImage* _image;
	GtkMenu* _menu;
};

struct _UnityTestsUIFakeIndicatorObjectClass {
	IndicatorObjectClass parent_class;
};

struct _UnityTestsUIFakeIndicatorObjectPrivate {
	gint _index;
};

struct _UnityTestsUIFakeIndicatorsModel {
	UnityPanelIndicatorsIndicatorsModel parent_instance;
	UnityTestsUIFakeIndicatorsModelPrivate * priv;
	GeeHashMap* indicator_map;
	GeeArrayList* indicator_list;
	UnityTestsUIFakeIndicatorObject* indicator_object_0;
	UnityTestsUIFakeIndicatorObject* indicator_object_1;
};

struct _UnityTestsUIFakeIndicatorsModelClass {
	UnityPanelIndicatorsIndicatorsModelClass parent_class;
};

struct _UnityTestsUIIndicatorTestSuite {
	GObject parent_instance;
	UnityTestsUIIndicatorTestSuitePrivate * priv;
	IndicatorObjectEntry* entry0;
	IndicatorObjectEntry* entry1;
};

struct _UnityTestsUIIndicatorTestSuiteClass {
	GObjectClass parent_class;
};

struct _UnityTestsUIIndicatorTestSuitePrivate {
	UnityTestingWindow* window;
	ClutterStage* stage;
	UnityTestingDirector* director;
	GtkMenu* menu0;
	GtkLabel* label0;
	GtkImage* image0;
	GtkMenu* menu1;
	GtkLabel* label1;
	GtkImage* image1;
	GtkMenuItem* item;
};


static gpointer unity_tests_ui_fake_indicator_object_parent_class = NULL;
static gpointer unity_tests_ui_fake_indicators_model_parent_class = NULL;
static gpointer unity_tests_ui_indicator_test_suite_parent_class = NULL;

GType unity_tests_ui_fake_indicator_object_get_type (void) G_GNUC_CONST;
#define UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUIFakeIndicatorObjectPrivate))
enum  {
	UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_DUMMY_PROPERTY,
	UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_INDEX
};
UnityTestsUIFakeIndicatorObject* unity_tests_ui_fake_indicator_object_new (gint i);
UnityTestsUIFakeIndicatorObject* unity_tests_ui_fake_indicator_object_construct (GType object_type, gint i);
void unity_tests_ui_fake_indicator_object_add_entry (UnityTestsUIFakeIndicatorObject* self, IndicatorObjectEntry* entry);
void unity_tests_ui_fake_indicator_object_remove_entry (UnityTestsUIFakeIndicatorObject* self, IndicatorObjectEntry* entry);
static GtkLabel* unity_tests_ui_fake_indicator_object_real_get_label (IndicatorObject* base);
static GtkImage* unity_tests_ui_fake_indicator_object_real_get_image (IndicatorObject* base);
static GtkMenu* unity_tests_ui_fake_indicator_object_real_get_menu (IndicatorObject* base);
gint unity_tests_ui_fake_indicator_object_get_index (UnityTestsUIFakeIndicatorObject* self);
void unity_tests_ui_fake_indicator_object_set_index (UnityTestsUIFakeIndicatorObject* self, gint value);
static GObject * unity_tests_ui_fake_indicator_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_tests_ui_fake_indicator_object_finalize (GObject* obj);
static void unity_tests_ui_fake_indicator_object_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_tests_ui_fake_indicator_object_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
GType unity_tests_ui_fake_indicators_model_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_TESTS_UI_FAKE_INDICATORS_MODEL_DUMMY_PROPERTY
};
UnityTestsUIFakeIndicatorsModel* unity_tests_ui_fake_indicators_model_new (void);
UnityTestsUIFakeIndicatorsModel* unity_tests_ui_fake_indicators_model_construct (GType object_type);
static void unity_tests_ui_fake_indicators_model_load_fake_indicators (UnityTestsUIFakeIndicatorsModel* self);
static GeeArrayList* unity_tests_ui_fake_indicators_model_real_get_indicators (UnityPanelIndicatorsIndicatorsModel* base);
static char* unity_tests_ui_fake_indicators_model_real_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* base, IndicatorObject* o);
static void unity_tests_ui_fake_indicators_model_finalize (GObject* obj);
GType unity_tests_ui_indicator_test_suite_get_type (void) G_GNUC_CONST;
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE, UnityTestsUIIndicatorTestSuitePrivate))
enum  {
	UNITY_TESTS_UI_INDICATOR_TEST_SUITE_DUMMY_PROPERTY
};
#define UNITY_TESTS_UI_INDICATOR_TEST_SUITE_DOMAIN "/UI/Indicators"
UnityTestsUIIndicatorTestSuite* unity_tests_ui_indicator_test_suite_new (void);
UnityTestsUIIndicatorTestSuite* unity_tests_ui_indicator_test_suite_construct (GType object_type);
static void unity_tests_ui_indicator_test_suite_test_indicators_mouse_event (UnityTestsUIIndicatorTestSuite* self);
static void _unity_tests_ui_indicator_test_suite_test_indicators_mouse_event_gdata_test_func (gpointer self);
static void unity_tests_ui_indicator_test_suite_test_indicators_keyboard_event (UnityTestsUIIndicatorTestSuite* self);
static void _unity_tests_ui_indicator_test_suite_test_indicators_keyboard_event_gdata_test_func (gpointer self);
static void unity_tests_ui_indicator_test_suite_finalize (GObject* obj);



UnityTestsUIFakeIndicatorObject* unity_tests_ui_fake_indicator_object_construct (GType object_type, gint i) {
	UnityTestsUIFakeIndicatorObject * self;
	self = (UnityTestsUIFakeIndicatorObject*) g_object_new (object_type, "index", i, NULL);
	return self;
}


UnityTestsUIFakeIndicatorObject* unity_tests_ui_fake_indicator_object_new (gint i) {
	return unity_tests_ui_fake_indicator_object_construct (UNITY_TESTS_UI_TYPE_FAKE_INDICATOR_OBJECT, i);
}


void unity_tests_ui_fake_indicator_object_add_entry (UnityTestsUIFakeIndicatorObject* self, IndicatorObjectEntry* entry) {
	gint pos;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	pos = gee_abstract_list_index_of ((GeeAbstractList*) self->indicator_entry_array, entry);
	if (pos != (-1)) {
		return;
	}
	gee_abstract_collection_add ((GeeAbstractCollection*) self->indicator_entry_array, entry);
	g_signal_emit_by_name ((IndicatorObject*) self, "entry-added", entry);
}


void unity_tests_ui_fake_indicator_object_remove_entry (UnityTestsUIFakeIndicatorObject* self, IndicatorObjectEntry* entry) {
	gint pos;
	g_return_if_fail (self != NULL);
	g_return_if_fail (entry != NULL);
	pos = gee_abstract_list_index_of ((GeeAbstractList*) self->indicator_entry_array, entry);
	if (pos != (-1)) {
		IndicatorObjectEntry* _tmp0_;
		_tmp0_ = (IndicatorObjectEntry*) gee_abstract_list_remove_at ((GeeAbstractList*) self->indicator_entry_array, pos);
		_indicator_object_entry_free0 (_tmp0_);
		g_signal_emit_by_name ((IndicatorObject*) self, "entry-removed", entry);
	}
}


static GtkLabel* unity_tests_ui_fake_indicator_object_real_get_label (IndicatorObject* base) {
	UnityTestsUIFakeIndicatorObject * self;
	GtkLabel* result = NULL;
	self = (UnityTestsUIFakeIndicatorObject*) base;
	result = self->_label;
	return result;
}


static GtkImage* unity_tests_ui_fake_indicator_object_real_get_image (IndicatorObject* base) {
	UnityTestsUIFakeIndicatorObject * self;
	GtkImage* result = NULL;
	self = (UnityTestsUIFakeIndicatorObject*) base;
	result = self->_image;
	return result;
}


static GtkMenu* unity_tests_ui_fake_indicator_object_real_get_menu (IndicatorObject* base) {
	UnityTestsUIFakeIndicatorObject * self;
	GtkMenu* result = NULL;
	self = (UnityTestsUIFakeIndicatorObject*) base;
	result = self->_menu;
	return result;
}


gint unity_tests_ui_fake_indicator_object_get_index (UnityTestsUIFakeIndicatorObject* self) {
	gint result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_index;
	return result;
}


void unity_tests_ui_fake_indicator_object_set_index (UnityTestsUIFakeIndicatorObject* self, gint value) {
	g_return_if_fail (self != NULL);
	self->priv->_index = value;
	g_object_notify ((GObject *) self, "index");
}


static GObject * unity_tests_ui_fake_indicator_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityTestsUIFakeIndicatorObject * self;
	parent_class = G_OBJECT_CLASS (unity_tests_ui_fake_indicator_object_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT (obj);
	{
		char* index_string;
		GeeArrayList* _tmp0_;
		char* _tmp1_;
		GtkLabel* _tmp2_;
		GtkImage* _tmp3_;
		GtkMenu* _tmp4_;
		START_FUNCTION ();
		index_string = g_strdup_printf ("%d", self->priv->_index);
		self->indicator_entry_array = (_tmp0_ = gee_array_list_new (G_TYPE_POINTER, NULL, NULL, NULL), _g_object_unref0 (self->indicator_entry_array), _tmp0_);
		self->_label = (_tmp2_ = g_object_ref_sink ((GtkLabel*) gtk_label_new (_tmp1_ = g_strconcat ("Indicator", index_string, NULL))), _g_object_unref0 (self->_label), _tmp2_);
		_g_free0 (_tmp1_);
		self->_image = (_tmp3_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_icon_name ("gtk-apply", GTK_ICON_SIZE_MENU)), _g_object_unref0 (self->_image), _tmp3_);
		self->_menu = (_tmp4_ = g_object_ref_sink ((GtkMenu*) gtk_menu_new ()), _g_object_unref0 (self->_menu), _tmp4_);
		END_FUNCTION ();
		_g_free0 (index_string);
	}
	return obj;
}


static void unity_tests_ui_fake_indicator_object_class_init (UnityTestsUIFakeIndicatorObjectClass * klass) {
	unity_tests_ui_fake_indicator_object_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUIFakeIndicatorObjectPrivate));
	INDICATOR_OBJECT_CLASS (klass)->get_label = unity_tests_ui_fake_indicator_object_real_get_label;
	INDICATOR_OBJECT_CLASS (klass)->get_image = unity_tests_ui_fake_indicator_object_real_get_image;
	INDICATOR_OBJECT_CLASS (klass)->get_menu = unity_tests_ui_fake_indicator_object_real_get_menu;
	G_OBJECT_CLASS (klass)->get_property = unity_tests_ui_fake_indicator_object_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_tests_ui_fake_indicator_object_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_tests_ui_fake_indicator_object_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_tests_ui_fake_indicator_object_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_INDEX, g_param_spec_int ("index", "index", "index", G_MININT, G_MAXINT, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
}


static void unity_tests_ui_fake_indicator_object_instance_init (UnityTestsUIFakeIndicatorObject * self) {
	self->priv = UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_GET_PRIVATE (self);
	self->_label = NULL;
	self->_image = NULL;
	self->_menu = NULL;
}


static void unity_tests_ui_fake_indicator_object_finalize (GObject* obj) {
	UnityTestsUIFakeIndicatorObject * self;
	self = UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT (obj);
	_g_object_unref0 (self->indicator_entry_array);
	_g_object_unref0 (self->_label);
	_g_object_unref0 (self->_image);
	_g_object_unref0 (self->_menu);
	G_OBJECT_CLASS (unity_tests_ui_fake_indicator_object_parent_class)->finalize (obj);
}


GType unity_tests_ui_fake_indicator_object_get_type (void) {
	static volatile gsize unity_tests_ui_fake_indicator_object_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_fake_indicator_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUIFakeIndicatorObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_fake_indicator_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUIFakeIndicatorObject), 0, (GInstanceInitFunc) unity_tests_ui_fake_indicator_object_instance_init, NULL };
		GType unity_tests_ui_fake_indicator_object_type_id;
		unity_tests_ui_fake_indicator_object_type_id = g_type_register_static (INDICATOR_TYPE_OBJECT, "UnityTestsUIFakeIndicatorObject", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_ui_fake_indicator_object_type_id__volatile, unity_tests_ui_fake_indicator_object_type_id);
	}
	return unity_tests_ui_fake_indicator_object_type_id__volatile;
}


static void unity_tests_ui_fake_indicator_object_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityTestsUIFakeIndicatorObject * self;
	self = UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT (object);
	switch (property_id) {
		case UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_INDEX:
		g_value_set_int (value, unity_tests_ui_fake_indicator_object_get_index (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_tests_ui_fake_indicator_object_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityTestsUIFakeIndicatorObject * self;
	self = UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT (object);
	switch (property_id) {
		case UNITY_TESTS_UI_FAKE_INDICATOR_OBJECT_INDEX:
		unity_tests_ui_fake_indicator_object_set_index (self, g_value_get_int (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


UnityTestsUIFakeIndicatorsModel* unity_tests_ui_fake_indicators_model_construct (GType object_type) {
	UnityTestsUIFakeIndicatorsModel * self;
	GeeHashMap* _tmp0_;
	GeeArrayList* _tmp1_;
	self = (UnityTestsUIFakeIndicatorsModel*) unity_panel_indicators_indicators_model_construct (object_type);
	START_FUNCTION ();
	self->indicator_map = (_tmp0_ = gee_hash_map_new (INDICATOR_TYPE_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, G_TYPE_STRING, (GBoxedCopyFunc) g_strdup, g_free, NULL, NULL, NULL), _g_object_unref0 (self->indicator_map), _tmp0_);
	self->indicator_list = (_tmp1_ = gee_array_list_new (INDICATOR_TYPE_OBJECT, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->indicator_list), _tmp1_);
	unity_tests_ui_fake_indicators_model_load_fake_indicators (self);
	END_FUNCTION ();
	return self;
}


UnityTestsUIFakeIndicatorsModel* unity_tests_ui_fake_indicators_model_new (void) {
	return unity_tests_ui_fake_indicators_model_construct (UNITY_TESTS_UI_TYPE_FAKE_INDICATORS_MODEL);
}


static void unity_tests_ui_fake_indicators_model_load_fake_indicators (UnityTestsUIFakeIndicatorsModel* self) {
	UnityTestsUIFakeIndicatorObject* _tmp0_;
	UnityTestsUIFakeIndicatorObject* _tmp1_;
	g_return_if_fail (self != NULL);
	self->indicator_object_0 = (_tmp0_ = unity_tests_ui_fake_indicator_object_new (0), _g_object_unref0 (self->indicator_object_0), _tmp0_);
	self->indicator_object_1 = (_tmp1_ = unity_tests_ui_fake_indicator_object_new (1), _g_object_unref0 (self->indicator_object_1), _tmp1_);
	gee_abstract_map_set ((GeeAbstractMap*) self->indicator_map, (IndicatorObject*) self->indicator_object_0, "fakeindicator0");
	gee_abstract_collection_add ((GeeAbstractCollection*) self->indicator_list, (IndicatorObject*) self->indicator_object_0);
	gee_abstract_map_set ((GeeAbstractMap*) self->indicator_map, (IndicatorObject*) self->indicator_object_1, "fakeindicator1");
	gee_abstract_collection_add ((GeeAbstractCollection*) self->indicator_list, (IndicatorObject*) self->indicator_object_1);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GeeArrayList* unity_tests_ui_fake_indicators_model_real_get_indicators (UnityPanelIndicatorsIndicatorsModel* base) {
	UnityTestsUIFakeIndicatorsModel * self;
	GeeArrayList* result = NULL;
	self = (UnityTestsUIFakeIndicatorsModel*) base;
	result = _g_object_ref0 (self->indicator_list);
	return result;
}


static char* unity_tests_ui_fake_indicators_model_real_get_indicator_name (UnityPanelIndicatorsIndicatorsModel* base, IndicatorObject* o) {
	UnityTestsUIFakeIndicatorsModel * self;
	char* result = NULL;
	self = (UnityTestsUIFakeIndicatorsModel*) base;
	g_return_val_if_fail (o != NULL, NULL);
	result = (char*) gee_abstract_map_get ((GeeAbstractMap*) self->indicator_map, o);
	return result;
}


static void unity_tests_ui_fake_indicators_model_class_init (UnityTestsUIFakeIndicatorsModelClass * klass) {
	unity_tests_ui_fake_indicators_model_parent_class = g_type_class_peek_parent (klass);
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS (klass)->get_indicators = unity_tests_ui_fake_indicators_model_real_get_indicators;
	UNITY_PANEL_INDICATORS_INDICATORS_MODEL_CLASS (klass)->get_indicator_name = unity_tests_ui_fake_indicators_model_real_get_indicator_name;
	G_OBJECT_CLASS (klass)->finalize = unity_tests_ui_fake_indicators_model_finalize;
}


static void unity_tests_ui_fake_indicators_model_instance_init (UnityTestsUIFakeIndicatorsModel * self) {
}


static void unity_tests_ui_fake_indicators_model_finalize (GObject* obj) {
	UnityTestsUIFakeIndicatorsModel * self;
	self = UNITY_TESTS_UI_FAKE_INDICATORS_MODEL (obj);
	_g_object_unref0 (self->indicator_map);
	_g_object_unref0 (self->indicator_list);
	_g_object_unref0 (self->indicator_object_0);
	_g_object_unref0 (self->indicator_object_1);
	G_OBJECT_CLASS (unity_tests_ui_fake_indicators_model_parent_class)->finalize (obj);
}


GType unity_tests_ui_fake_indicators_model_get_type (void) {
	static volatile gsize unity_tests_ui_fake_indicators_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_fake_indicators_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUIFakeIndicatorsModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_fake_indicators_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUIFakeIndicatorsModel), 0, (GInstanceInitFunc) unity_tests_ui_fake_indicators_model_instance_init, NULL };
		GType unity_tests_ui_fake_indicators_model_type_id;
		unity_tests_ui_fake_indicators_model_type_id = g_type_register_static (UNITY_PANEL_INDICATORS_TYPE_INDICATORS_MODEL, "UnityTestsUIFakeIndicatorsModel", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_ui_fake_indicators_model_type_id__volatile, unity_tests_ui_fake_indicators_model_type_id);
	}
	return unity_tests_ui_fake_indicators_model_type_id__volatile;
}


static void _unity_tests_ui_indicator_test_suite_test_indicators_mouse_event_gdata_test_func (gpointer self) {
	unity_tests_ui_indicator_test_suite_test_indicators_mouse_event (self);
}


static void _unity_tests_ui_indicator_test_suite_test_indicators_keyboard_event_gdata_test_func (gpointer self) {
	unity_tests_ui_indicator_test_suite_test_indicators_keyboard_event (self);
}


UnityTestsUIIndicatorTestSuite* unity_tests_ui_indicator_test_suite_construct (GType object_type) {
	UnityTestsUIIndicatorTestSuite * self;
	UnityTestsUIFakeIndicatorsModel* fake_indicator_model;
	UnityTestingWindow* _tmp0_;
	ClutterStage* _tmp1_;
	UnityTestingDirector* _tmp2_;
	UnityPanelIndicatorsIndicatorsModel* _tmp3_;
	UnityTestsUIFakeIndicatorsModel* indicator_model;
	GtkMenu* _tmp4_;
	GtkLabel* _tmp5_;
	GtkImage* _tmp6_;
	GtkMenuItem* _tmp7_;
	GtkMenuItem* _tmp8_;
	GtkMenuItem* _tmp9_;
	GtkMenuItem* _tmp10_;
	IndicatorObjectEntry* _tmp11_;
	GtkMenu* _tmp12_;
	GtkLabel* _tmp13_;
	GtkImage* _tmp14_;
	GtkMenuItem* _tmp15_;
	GtkMenuItem* _tmp16_;
	GtkMenuItem* _tmp17_;
	GtkMenuItem* _tmp18_;
	IndicatorObjectEntry* _tmp19_;
	self = (UnityTestsUIIndicatorTestSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	fake_indicator_model = unity_tests_ui_fake_indicators_model_new ();
	unity_panel_indicators_indicators_model_set_default ((UnityPanelIndicatorsIndicatorsModel*) fake_indicator_model);
	self->priv->window = (_tmp0_ = g_object_ref_sink (unity_testing_window_new (TRUE, 1024, 600)), _g_object_unref0 (self->priv->window), _tmp0_);
	unity_testing_window_init_test_mode (self->priv->window);
	self->priv->stage = (_tmp1_ = _g_object_ref0 (self->priv->window->stage), _g_object_unref0 (self->priv->stage), _tmp1_);
	gtk_window_set_title ((GtkWindow*) self->priv->window, "Indicators testing");
	gtk_widget_show_all ((GtkWidget*) self->priv->window);
	self->priv->director = (_tmp2_ = unity_testing_director_new (self->priv->stage), _g_object_unref0 (self->priv->director), _tmp2_);
	indicator_model = (_tmp3_ = unity_panel_indicators_indicators_model_get_default (), UNITY_TESTS_UI_IS_FAKE_INDICATORS_MODEL (_tmp3_) ? ((UnityTestsUIFakeIndicatorsModel*) _tmp3_) : NULL);
	self->priv->menu0 = (_tmp4_ = g_object_ref_sink ((GtkMenu*) gtk_menu_new ()), _g_object_unref0 (self->priv->menu0), _tmp4_);
	self->priv->label0 = (_tmp5_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Entry0")), _g_object_unref0 (self->priv->label0), _tmp5_);
	self->priv->image0 = (_tmp6_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_icon_name ("gtk-apply", GTK_ICON_SIZE_MENU)), _g_object_unref0 (self->priv->image0), _tmp6_);
	self->priv->item = (_tmp7_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem0")), _g_object_unref0 (self->priv->item), _tmp7_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu0, (GtkWidget*) self->priv->item);
	self->priv->item = (_tmp8_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem1")), _g_object_unref0 (self->priv->item), _tmp8_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu0, (GtkWidget*) self->priv->item);
	self->priv->item = (_tmp9_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem2")), _g_object_unref0 (self->priv->item), _tmp9_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu0, (GtkWidget*) self->priv->item);
	self->priv->item = (_tmp10_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem3")), _g_object_unref0 (self->priv->item), _tmp10_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu0, (GtkWidget*) self->priv->item);
	self->entry0 = (_tmp11_ = indicator_object_entry_new (), _indicator_object_entry_free0 (self->entry0), _tmp11_);
	self->entry0->menu = self->priv->menu0;
	self->entry0->label = self->priv->label0;
	self->entry0->image = self->priv->image0;
	unity_tests_ui_fake_indicator_object_add_entry (indicator_model->indicator_object_0, self->entry0);
	self->priv->menu1 = (_tmp12_ = g_object_ref_sink ((GtkMenu*) gtk_menu_new ()), _g_object_unref0 (self->priv->menu1), _tmp12_);
	self->priv->label1 = (_tmp13_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Entry1")), _g_object_unref0 (self->priv->label1), _tmp13_);
	self->priv->image1 = (_tmp14_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_icon_name ("gtk-apply", GTK_ICON_SIZE_MENU)), _g_object_unref0 (self->priv->image1), _tmp14_);
	self->priv->item = (_tmp15_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem0")), _g_object_unref0 (self->priv->item), _tmp15_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu1, (GtkWidget*) self->priv->item);
	self->priv->item = (_tmp16_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem1")), _g_object_unref0 (self->priv->item), _tmp16_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu1, (GtkWidget*) self->priv->item);
	self->priv->item = (_tmp17_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem2")), _g_object_unref0 (self->priv->item), _tmp17_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu1, (GtkWidget*) self->priv->item);
	self->priv->item = (_tmp18_ = g_object_ref_sink ((GtkMenuItem*) gtk_menu_item_new_with_label ("MenuItem3")), _g_object_unref0 (self->priv->item), _tmp18_);
	gtk_widget_show ((GtkWidget*) self->priv->item);
	gtk_menu_shell_append ((GtkMenuShell*) self->priv->menu1, (GtkWidget*) self->priv->item);
	self->entry1 = (_tmp19_ = indicator_object_entry_new (), _indicator_object_entry_free0 (self->entry1), _tmp19_);
	self->entry1->menu = self->priv->menu1;
	self->entry1->label = self->priv->label1;
	self->entry1->image = self->priv->image1;
	unity_tests_ui_fake_indicator_object_add_entry (indicator_model->indicator_object_1, self->entry1);
	g_test_add_data_func (UNITY_TESTS_UI_INDICATOR_TEST_SUITE_DOMAIN "/IndicatorMouseEvent", self, _unity_tests_ui_indicator_test_suite_test_indicators_mouse_event_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UI_INDICATOR_TEST_SUITE_DOMAIN "/IndicatorKeyboardEvent", self, _unity_tests_ui_indicator_test_suite_test_indicators_keyboard_event_gdata_test_func);
	_g_object_unref0 (indicator_model);
	_g_object_unref0 (fake_indicator_model);
	return self;
}


UnityTestsUIIndicatorTestSuite* unity_tests_ui_indicator_test_suite_new (void) {
	return unity_tests_ui_indicator_test_suite_construct (UNITY_TESTS_UI_TYPE_INDICATOR_TEST_SUITE);
}


static void unity_tests_ui_indicator_test_suite_test_indicators_mouse_event (UnityTestsUIIndicatorTestSuite* self) {
	UnityTestingObjectRegistry* registry;
	UnityPanelIndicatorsIndicatorsModel* _tmp0_;
	UnityTestsUIFakeIndicatorsModel* indicator_model;
	GeeArrayList* _tmp1_;
	GObject* _tmp2_;
	UnityPanelIndicatorsIndicatorBar* _tmp3_;
	UnityPanelIndicatorsIndicatorBar* indicator_bar;
	UnityPanelIndicatorsIndicatorObjectView* indicator_object_view0;
	UnityPanelIndicatorsIndicatorObjectView* indicator_object_view1;
	UnityPanelIndicatorsIndicatorObjectEntryView* object_entry0;
	UnityPanelIndicatorsIndicatorObjectEntryView* object_entry1;
	g_return_if_fail (self != NULL);
	registry = unity_testing_object_registry_get_default ();
	unity_testing_logging_init_fatal_handler ();
	indicator_model = (_tmp0_ = unity_panel_indicators_indicators_model_get_default (), UNITY_TESTS_UI_IS_FAKE_INDICATORS_MODEL (_tmp0_) ? ((UnityTestsUIFakeIndicatorsModel*) _tmp0_) : NULL);
	indicator_bar = (_tmp3_ = (_tmp2_ = (GObject*) gee_abstract_list_get ((GeeAbstractList*) (_tmp1_ = unity_testing_object_registry_lookup (registry, "IndicatorBar")), 0), UNITY_PANEL_INDICATORS_IS_INDICATOR_BAR (_tmp2_) ? ((UnityPanelIndicatorsIndicatorBar*) _tmp2_) : NULL), _g_object_unref0 (_tmp1_), _tmp3_);
	g_assert (indicator_bar != NULL);
	indicator_object_view0 = unity_panel_indicators_indicator_bar_get_indicator_view_matching (indicator_bar, (IndicatorObject*) indicator_model->indicator_object_0);
	g_assert (indicator_object_view0 != NULL);
	indicator_object_view1 = unity_panel_indicators_indicator_bar_get_indicator_view_matching (indicator_bar, (IndicatorObject*) indicator_model->indicator_object_1);
	g_assert (indicator_object_view1 != NULL);
	unity_panel_indicators_indicator_object_view_remove_first_entry (indicator_object_view0);
	unity_panel_indicators_indicator_object_view_remove_first_entry (indicator_object_view1);
	clutter_actor_queue_redraw ((ClutterActor*) indicator_bar);
	object_entry0 = unity_panel_indicators_indicator_object_view_get_entry_view (indicator_object_view0, self->entry0);
	g_assert (object_entry0 != NULL);
	object_entry1 = unity_panel_indicators_indicator_object_view_get_entry_view (indicator_object_view1, self->entry1);
	g_assert (object_entry1 != NULL);
	unity_testing_director_button_press (self->priv->director, (ClutterActor*) object_entry0, (guint32) 1, TRUE, 1.0f, 1.0f, FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry0) == TRUE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry1) == FALSE);
	unity_testing_director_do_wait_for_timeout (self->priv->director, (guint32) 1000);
	unity_testing_director_button_press (self->priv->director, (ClutterActor*) object_entry1, (guint32) 1, TRUE, 1.0f, 1.0f, FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry0) == FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry1) == TRUE);
	unity_testing_director_do_wait_for_timeout (self->priv->director, (guint32) 1000);
	unity_testing_director_button_press (self->priv->director, (ClutterActor*) object_entry1, (guint32) 1, TRUE, 1.0f, 1.0f, FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry0) == FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry1) == FALSE);
	_g_object_unref0 (object_entry1);
	_g_object_unref0 (object_entry0);
	_g_object_unref0 (indicator_object_view1);
	_g_object_unref0 (indicator_object_view0);
	_g_object_unref0 (indicator_bar);
	_g_object_unref0 (indicator_model);
	_unity_testing_object_registry_unref0 (registry);
}


static void unity_tests_ui_indicator_test_suite_test_indicators_keyboard_event (UnityTestsUIIndicatorTestSuite* self) {
	UnityTestingObjectRegistry* registry;
	UnityPanelIndicatorsIndicatorsModel* _tmp0_;
	UnityTestsUIFakeIndicatorsModel* indicator_model;
	GeeArrayList* _tmp1_;
	GObject* _tmp2_;
	UnityPanelIndicatorsIndicatorBar* _tmp3_;
	UnityPanelIndicatorsIndicatorBar* indicator_bar;
	UnityPanelIndicatorsIndicatorObjectView* indicator_object_view0;
	UnityPanelIndicatorsIndicatorObjectView* indicator_object_view1;
	UnityPanelIndicatorsIndicatorObjectEntryView* object_entry0;
	UnityPanelIndicatorsIndicatorObjectEntryView* object_entry1;
	g_return_if_fail (self != NULL);
	registry = unity_testing_object_registry_get_default ();
	unity_testing_logging_init_fatal_handler ();
	indicator_model = (_tmp0_ = unity_panel_indicators_indicators_model_get_default (), UNITY_TESTS_UI_IS_FAKE_INDICATORS_MODEL (_tmp0_) ? ((UnityTestsUIFakeIndicatorsModel*) _tmp0_) : NULL);
	indicator_bar = (_tmp3_ = (_tmp2_ = (GObject*) gee_abstract_list_get ((GeeAbstractList*) (_tmp1_ = unity_testing_object_registry_lookup (registry, "IndicatorBar")), 0), UNITY_PANEL_INDICATORS_IS_INDICATOR_BAR (_tmp2_) ? ((UnityPanelIndicatorsIndicatorBar*) _tmp2_) : NULL), _g_object_unref0 (_tmp1_), _tmp3_);
	g_assert (indicator_bar != NULL);
	indicator_object_view0 = unity_panel_indicators_indicator_bar_get_indicator_view_matching (indicator_bar, (IndicatorObject*) indicator_model->indicator_object_0);
	g_assert (indicator_object_view0 != NULL);
	indicator_object_view1 = unity_panel_indicators_indicator_bar_get_indicator_view_matching (indicator_bar, (IndicatorObject*) indicator_model->indicator_object_1);
	g_assert (indicator_object_view1 != NULL);
	object_entry0 = unity_panel_indicators_indicator_object_view_get_entry_view (indicator_object_view0, self->entry0);
	g_assert (object_entry0 != NULL);
	object_entry1 = unity_panel_indicators_indicator_object_view_get_entry_view (indicator_object_view1, self->entry1);
	g_assert (object_entry1 != NULL);
	unity_testing_director_do_wait_for_timeout (self->priv->director, (guint32) 1000);
	unity_testing_director_button_press (self->priv->director, (ClutterActor*) object_entry0, (guint32) 1, TRUE, 1.0f, 1.0f, FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry0) == TRUE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry1) == FALSE);
	unity_testing_director_do_wait_for_timeout (self->priv->director, (guint32) 1000);
	g_signal_emit_by_name ((GtkMenuShell*) unity_panel_indicators_indicator_object_entry_view_get_entry (object_entry0)->menu, "move-current", GTK_MENU_DIR_CHILD);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry0) == FALSE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry1) == TRUE);
	unity_testing_director_do_wait_for_timeout (self->priv->director, (guint32) 1000);
	g_signal_emit_by_name ((GtkMenuShell*) unity_panel_indicators_indicator_object_entry_view_get_entry (object_entry1)->menu, "move-current", GTK_MENU_DIR_PARENT);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry0) == TRUE);
	g_assert (unity_panel_indicators_indicator_object_entry_view_is_open (object_entry1) == FALSE);
	unity_testing_director_do_wait_for_timeout (self->priv->director, (guint32) 1000);
	_g_object_unref0 (object_entry1);
	_g_object_unref0 (object_entry0);
	_g_object_unref0 (indicator_object_view1);
	_g_object_unref0 (indicator_object_view0);
	_g_object_unref0 (indicator_bar);
	_g_object_unref0 (indicator_model);
	_unity_testing_object_registry_unref0 (registry);
}


static void unity_tests_ui_indicator_test_suite_class_init (UnityTestsUIIndicatorTestSuiteClass * klass) {
	unity_tests_ui_indicator_test_suite_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUIIndicatorTestSuitePrivate));
	G_OBJECT_CLASS (klass)->finalize = unity_tests_ui_indicator_test_suite_finalize;
}


static void unity_tests_ui_indicator_test_suite_instance_init (UnityTestsUIIndicatorTestSuite * self) {
	self->priv = UNITY_TESTS_UI_INDICATOR_TEST_SUITE_GET_PRIVATE (self);
}


static void unity_tests_ui_indicator_test_suite_finalize (GObject* obj) {
	UnityTestsUIIndicatorTestSuite * self;
	self = UNITY_TESTS_UI_INDICATOR_TEST_SUITE (obj);
	_g_object_unref0 (self->priv->window);
	_g_object_unref0 (self->priv->stage);
	_g_object_unref0 (self->priv->director);
	_indicator_object_entry_free0 (self->entry0);
	_indicator_object_entry_free0 (self->entry1);
	_g_object_unref0 (self->priv->menu0);
	_g_object_unref0 (self->priv->label0);
	_g_object_unref0 (self->priv->image0);
	_g_object_unref0 (self->priv->menu1);
	_g_object_unref0 (self->priv->label1);
	_g_object_unref0 (self->priv->image1);
	_g_object_unref0 (self->priv->item);
	G_OBJECT_CLASS (unity_tests_ui_indicator_test_suite_parent_class)->finalize (obj);
}


GType unity_tests_ui_indicator_test_suite_get_type (void) {
	static volatile gsize unity_tests_ui_indicator_test_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_indicator_test_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUIIndicatorTestSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_indicator_test_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUIIndicatorTestSuite), 0, (GInstanceInitFunc) unity_tests_ui_indicator_test_suite_instance_init, NULL };
		GType unity_tests_ui_indicator_test_suite_type_id;
		unity_tests_ui_indicator_test_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUIIndicatorTestSuite", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_ui_indicator_test_suite_type_id__volatile, unity_tests_ui_indicator_test_suite_type_id);
	}
	return unity_tests_ui_indicator_test_suite_type_id__volatile;
}




