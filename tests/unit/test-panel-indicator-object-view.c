/* test-panel-indicator-object-view.c generated by valac 0.9.8, the Vala compiler
 * generated from test-panel-indicator-object-view.vala, do not modify */

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
 * Authored by Neil Jay Taoko <jay.taoko.patel@canonical.com>
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


#define UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT (unity_tests_unit_fake_indicator_object_get_type ())
#define UNITY_TESTS_UNIT_FAKE_INDICATOR_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUnitFakeIndicatorObject))
#define UNITY_TESTS_UNIT_FAKE_INDICATOR_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUnitFakeIndicatorObjectClass))
#define UNITY_TESTS_UNIT_IS_FAKE_INDICATOR_OBJECT(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT))
#define UNITY_TESTS_UNIT_IS_FAKE_INDICATOR_OBJECT_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT))
#define UNITY_TESTS_UNIT_FAKE_INDICATOR_OBJECT_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT, UnityTestsUnitFakeIndicatorObjectClass))

typedef struct _UnityTestsUnitFakeIndicatorObject UnityTestsUnitFakeIndicatorObject;
typedef struct _UnityTestsUnitFakeIndicatorObjectClass UnityTestsUnitFakeIndicatorObjectClass;
typedef struct _UnityTestsUnitFakeIndicatorObjectPrivate UnityTestsUnitFakeIndicatorObjectPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _indicator_object_entry_free0(var) ((var == NULL) ? NULL : (var = (indicator_object_entry_free (var), NULL)))

#define UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE (unity_tests_unit_panel_indicator_object_view_suite_get_type ())
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuite))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuiteClass))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_VIEW_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE))
#define UNITY_TESTS_UNIT_IS_PANEL_INDICATOR_OBJECT_VIEW_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE))
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuiteClass))

typedef struct _UnityTestsUnitPanelIndicatorObjectViewSuite UnityTestsUnitPanelIndicatorObjectViewSuite;
typedef struct _UnityTestsUnitPanelIndicatorObjectViewSuiteClass UnityTestsUnitPanelIndicatorObjectViewSuiteClass;
typedef struct _UnityTestsUnitPanelIndicatorObjectViewSuitePrivate UnityTestsUnitPanelIndicatorObjectViewSuitePrivate;

struct _UnityTestsUnitFakeIndicatorObject {
	IndicatorObject parent_instance;
	UnityTestsUnitFakeIndicatorObjectPrivate * priv;
	GeeArrayList* indicator_entry_array;
	GtkLabel* _label;
	GtkImage* _image;
	GtkMenu* _menu;
};

struct _UnityTestsUnitFakeIndicatorObjectClass {
	IndicatorObjectClass parent_class;
};

struct _UnityTestsUnitPanelIndicatorObjectViewSuite {
	GObject parent_instance;
	UnityTestsUnitPanelIndicatorObjectViewSuitePrivate * priv;
};

struct _UnityTestsUnitPanelIndicatorObjectViewSuiteClass {
	GObjectClass parent_class;
};

struct _UnityTestsUnitPanelIndicatorObjectViewSuitePrivate {
	IndicatorObjectEntry* entry;
	GtkMenu* menu;
	GtkLabel* label;
	GtkImage* image;
};


static gpointer unity_tests_unit_fake_indicator_object_parent_class = NULL;
static gpointer unity_tests_unit_panel_indicator_object_view_suite_parent_class = NULL;

GType unity_tests_unit_fake_indicator_object_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_TESTS_UNIT_FAKE_INDICATOR_OBJECT_DUMMY_PROPERTY
};
UnityTestsUnitFakeIndicatorObject* unity_tests_unit_fake_indicator_object_new (void);
UnityTestsUnitFakeIndicatorObject* unity_tests_unit_fake_indicator_object_construct (GType object_type);
void unity_tests_unit_fake_indicator_object_add_entry (UnityTestsUnitFakeIndicatorObject* self, IndicatorObjectEntry* entry);
void unity_tests_unit_fake_indicator_object_remove_entry (UnityTestsUnitFakeIndicatorObject* self, IndicatorObjectEntry* entry);
static GtkLabel* unity_tests_unit_fake_indicator_object_real_get_label (IndicatorObject* base);
static GtkImage* unity_tests_unit_fake_indicator_object_real_get_image (IndicatorObject* base);
static GtkMenu* unity_tests_unit_fake_indicator_object_real_get_menu (IndicatorObject* base);
static GObject * unity_tests_unit_fake_indicator_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_tests_unit_fake_indicator_object_finalize (GObject* obj);
GType unity_tests_unit_panel_indicator_object_view_suite_get_type (void) G_GNUC_CONST;
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE, UnityTestsUnitPanelIndicatorObjectViewSuitePrivate))
enum  {
	UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_DUMMY_PROPERTY
};
#define UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_DOMAIN "/Unit/Panel/Indicator/ObjectView"
UnityTestsUnitPanelIndicatorObjectViewSuite* unity_tests_unit_panel_indicator_object_view_suite_new (void);
UnityTestsUnitPanelIndicatorObjectViewSuite* unity_tests_unit_panel_indicator_object_view_suite_construct (GType object_type);
static void unity_tests_unit_panel_indicator_object_view_suite_test_fake_indicator_object (UnityTestsUnitPanelIndicatorObjectViewSuite* self);
static void _unity_tests_unit_panel_indicator_object_view_suite_test_fake_indicator_object_gdata_test_func (gpointer self);
static void unity_tests_unit_panel_indicator_object_view_suite_test_indicator_add_entry (UnityTestsUnitPanelIndicatorObjectViewSuite* self);
static void _unity_tests_unit_panel_indicator_object_view_suite_test_indicator_add_entry_gdata_test_func (gpointer self);
static void unity_tests_unit_panel_indicator_object_view_suite_test_indicator_enty_view (UnityTestsUnitPanelIndicatorObjectViewSuite* self);
static void _unity_tests_unit_panel_indicator_object_view_suite_test_indicator_enty_view_gdata_test_func (gpointer self);
static void unity_tests_unit_panel_indicator_object_view_suite_finalize (GObject* obj);



UnityTestsUnitFakeIndicatorObject* unity_tests_unit_fake_indicator_object_construct (GType object_type) {
	UnityTestsUnitFakeIndicatorObject * self;
	self = (UnityTestsUnitFakeIndicatorObject*) g_object_new (object_type, NULL);
	return self;
}


UnityTestsUnitFakeIndicatorObject* unity_tests_unit_fake_indicator_object_new (void) {
	return unity_tests_unit_fake_indicator_object_construct (UNITY_TESTS_UNIT_TYPE_FAKE_INDICATOR_OBJECT);
}


void unity_tests_unit_fake_indicator_object_add_entry (UnityTestsUnitFakeIndicatorObject* self, IndicatorObjectEntry* entry) {
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


void unity_tests_unit_fake_indicator_object_remove_entry (UnityTestsUnitFakeIndicatorObject* self, IndicatorObjectEntry* entry) {
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


static GtkLabel* unity_tests_unit_fake_indicator_object_real_get_label (IndicatorObject* base) {
	UnityTestsUnitFakeIndicatorObject * self;
	GtkLabel* result = NULL;
	self = (UnityTestsUnitFakeIndicatorObject*) base;
	result = self->_label;
	return result;
}


static GtkImage* unity_tests_unit_fake_indicator_object_real_get_image (IndicatorObject* base) {
	UnityTestsUnitFakeIndicatorObject * self;
	GtkImage* result = NULL;
	self = (UnityTestsUnitFakeIndicatorObject*) base;
	result = self->_image;
	return result;
}


static GtkMenu* unity_tests_unit_fake_indicator_object_real_get_menu (IndicatorObject* base) {
	UnityTestsUnitFakeIndicatorObject * self;
	GtkMenu* result = NULL;
	self = (UnityTestsUnitFakeIndicatorObject*) base;
	result = self->_menu;
	return result;
}


static GObject * unity_tests_unit_fake_indicator_object_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityTestsUnitFakeIndicatorObject * self;
	parent_class = G_OBJECT_CLASS (unity_tests_unit_fake_indicator_object_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_TESTS_UNIT_FAKE_INDICATOR_OBJECT (obj);
	{
		GeeArrayList* _tmp0_;
		GtkLabel* _tmp1_;
		GtkImage* _tmp2_;
		GtkMenu* _tmp3_;
		START_FUNCTION ();
		self->indicator_entry_array = (_tmp0_ = gee_array_list_new (G_TYPE_POINTER, NULL, NULL, NULL), _g_object_unref0 (self->indicator_entry_array), _tmp0_);
		self->_label = (_tmp1_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Test Label")), _g_object_unref0 (self->_label), _tmp1_);
		self->_image = (_tmp2_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_icon_name ("gtk-apply", GTK_ICON_SIZE_MENU)), _g_object_unref0 (self->_image), _tmp2_);
		self->_menu = (_tmp3_ = g_object_ref_sink ((GtkMenu*) gtk_menu_new ()), _g_object_unref0 (self->_menu), _tmp3_);
		END_FUNCTION ();
	}
	return obj;
}


static void unity_tests_unit_fake_indicator_object_class_init (UnityTestsUnitFakeIndicatorObjectClass * klass) {
	unity_tests_unit_fake_indicator_object_parent_class = g_type_class_peek_parent (klass);
	INDICATOR_OBJECT_CLASS (klass)->get_label = unity_tests_unit_fake_indicator_object_real_get_label;
	INDICATOR_OBJECT_CLASS (klass)->get_image = unity_tests_unit_fake_indicator_object_real_get_image;
	INDICATOR_OBJECT_CLASS (klass)->get_menu = unity_tests_unit_fake_indicator_object_real_get_menu;
	G_OBJECT_CLASS (klass)->constructor = unity_tests_unit_fake_indicator_object_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_tests_unit_fake_indicator_object_finalize;
}


static void unity_tests_unit_fake_indicator_object_instance_init (UnityTestsUnitFakeIndicatorObject * self) {
}


static void unity_tests_unit_fake_indicator_object_finalize (GObject* obj) {
	UnityTestsUnitFakeIndicatorObject * self;
	self = UNITY_TESTS_UNIT_FAKE_INDICATOR_OBJECT (obj);
	_g_object_unref0 (self->indicator_entry_array);
	_g_object_unref0 (self->_label);
	_g_object_unref0 (self->_image);
	_g_object_unref0 (self->_menu);
	G_OBJECT_CLASS (unity_tests_unit_fake_indicator_object_parent_class)->finalize (obj);
}


GType unity_tests_unit_fake_indicator_object_get_type (void) {
	static volatile gsize unity_tests_unit_fake_indicator_object_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_fake_indicator_object_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitFakeIndicatorObjectClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_fake_indicator_object_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitFakeIndicatorObject), 0, (GInstanceInitFunc) unity_tests_unit_fake_indicator_object_instance_init, NULL };
		GType unity_tests_unit_fake_indicator_object_type_id;
		unity_tests_unit_fake_indicator_object_type_id = g_type_register_static (INDICATOR_TYPE_OBJECT, "UnityTestsUnitFakeIndicatorObject", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_unit_fake_indicator_object_type_id__volatile, unity_tests_unit_fake_indicator_object_type_id);
	}
	return unity_tests_unit_fake_indicator_object_type_id__volatile;
}


static void _unity_tests_unit_panel_indicator_object_view_suite_test_fake_indicator_object_gdata_test_func (gpointer self) {
	unity_tests_unit_panel_indicator_object_view_suite_test_fake_indicator_object (self);
}


static void _unity_tests_unit_panel_indicator_object_view_suite_test_indicator_add_entry_gdata_test_func (gpointer self) {
	unity_tests_unit_panel_indicator_object_view_suite_test_indicator_add_entry (self);
}


static void _unity_tests_unit_panel_indicator_object_view_suite_test_indicator_enty_view_gdata_test_func (gpointer self) {
	unity_tests_unit_panel_indicator_object_view_suite_test_indicator_enty_view (self);
}


UnityTestsUnitPanelIndicatorObjectViewSuite* unity_tests_unit_panel_indicator_object_view_suite_construct (GType object_type) {
	UnityTestsUnitPanelIndicatorObjectViewSuite * self;
	IndicatorObjectEntry* _tmp0_;
	GtkMenu* _tmp1_;
	GtkLabel* _tmp2_;
	GtkImage* _tmp3_;
	self = (UnityTestsUnitPanelIndicatorObjectViewSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	self->priv->entry = (_tmp0_ = indicator_object_entry_new (), _indicator_object_entry_free0 (self->priv->entry), _tmp0_);
	self->priv->menu = (_tmp1_ = g_object_ref_sink ((GtkMenu*) gtk_menu_new ()), _g_object_unref0 (self->priv->menu), _tmp1_);
	self->priv->entry->menu = self->priv->menu;
	self->priv->label = (_tmp2_ = g_object_ref_sink ((GtkLabel*) gtk_label_new ("Test Label")), _g_object_unref0 (self->priv->label), _tmp2_);
	self->priv->entry->label = self->priv->label;
	self->priv->image = (_tmp3_ = g_object_ref_sink ((GtkImage*) gtk_image_new_from_icon_name ("gtk-apply", GTK_ICON_SIZE_MENU)), _g_object_unref0 (self->priv->image), _tmp3_);
	self->priv->entry->image = self->priv->image;
	g_test_add_data_func (UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_DOMAIN "/FakeIndicator", self, _unity_tests_unit_panel_indicator_object_view_suite_test_fake_indicator_object_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_DOMAIN "/FakeIndicatorAddEntry", self, _unity_tests_unit_panel_indicator_object_view_suite_test_indicator_add_entry_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_DOMAIN "/TestEntryView", self, _unity_tests_unit_panel_indicator_object_view_suite_test_indicator_enty_view_gdata_test_func);
	return self;
}


UnityTestsUnitPanelIndicatorObjectViewSuite* unity_tests_unit_panel_indicator_object_view_suite_new (void) {
	return unity_tests_unit_panel_indicator_object_view_suite_construct (UNITY_TESTS_UNIT_TYPE_PANEL_INDICATOR_OBJECT_VIEW_SUITE);
}


static void unity_tests_unit_panel_indicator_object_view_suite_test_fake_indicator_object (UnityTestsUnitPanelIndicatorObjectViewSuite* self) {
	UnityTestsUnitFakeIndicatorObject* fakeobject;
	g_return_if_fail (self != NULL);
	fakeobject = unity_tests_unit_fake_indicator_object_new ();
	g_assert (UNITY_TESTS_UNIT_IS_FAKE_INDICATOR_OBJECT (fakeobject));
	_g_object_unref0 (fakeobject);
}


static void unity_tests_unit_panel_indicator_object_view_suite_test_indicator_add_entry (UnityTestsUnitPanelIndicatorObjectViewSuite* self) {
	UnityTestsUnitFakeIndicatorObject* fakeobject;
	UnityPanelIndicatorsIndicatorObjectView* e;
	g_return_if_fail (self != NULL);
	fakeobject = unity_tests_unit_fake_indicator_object_new ();
	e = g_object_ref_sink (unity_panel_indicators_indicator_object_view_new ((IndicatorObject*) fakeobject));
	unity_tests_unit_fake_indicator_object_add_entry (fakeobject, self->priv->entry);
	g_assert (unity_panel_indicators_indicator_object_view_find_entry (e, self->priv->entry));
	_g_object_unref0 (e);
	_g_object_unref0 (fakeobject);
}


static void unity_tests_unit_panel_indicator_object_view_suite_test_indicator_enty_view (UnityTestsUnitPanelIndicatorObjectViewSuite* self) {
	UnityTestsUnitFakeIndicatorObject* fakeobject;
	UnityPanelIndicatorsIndicatorObjectView* e;
	UnityPanelIndicatorsIndicatorObjectEntryView* entry_view;
	g_return_if_fail (self != NULL);
	fakeobject = unity_tests_unit_fake_indicator_object_new ();
	e = g_object_ref_sink (unity_panel_indicators_indicator_object_view_new ((IndicatorObject*) fakeobject));
	unity_tests_unit_fake_indicator_object_add_entry (fakeobject, self->priv->entry);
	entry_view = unity_panel_indicators_indicator_object_view_get_entry_view (e, self->priv->entry);
	g_assert (unity_panel_indicators_indicator_object_entry_view_get_entry (entry_view) == self->priv->entry);
	g_assert (unity_panel_indicators_indicator_object_entry_view_get_entry (entry_view)->label == self->priv->entry->label);
	g_assert (unity_panel_indicators_indicator_object_entry_view_get_entry (entry_view)->image == self->priv->entry->image);
	g_assert (unity_panel_indicators_indicator_object_entry_view_get_entry (entry_view)->menu == self->priv->entry->menu);
	_g_object_unref0 (entry_view);
	_g_object_unref0 (e);
	_g_object_unref0 (fakeobject);
}


static void unity_tests_unit_panel_indicator_object_view_suite_class_init (UnityTestsUnitPanelIndicatorObjectViewSuiteClass * klass) {
	unity_tests_unit_panel_indicator_object_view_suite_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUnitPanelIndicatorObjectViewSuitePrivate));
	G_OBJECT_CLASS (klass)->finalize = unity_tests_unit_panel_indicator_object_view_suite_finalize;
}


static void unity_tests_unit_panel_indicator_object_view_suite_instance_init (UnityTestsUnitPanelIndicatorObjectViewSuite * self) {
	self->priv = UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE_GET_PRIVATE (self);
}


static void unity_tests_unit_panel_indicator_object_view_suite_finalize (GObject* obj) {
	UnityTestsUnitPanelIndicatorObjectViewSuite * self;
	self = UNITY_TESTS_UNIT_PANEL_INDICATOR_OBJECT_VIEW_SUITE (obj);
	_indicator_object_entry_free0 (self->priv->entry);
	_g_object_unref0 (self->priv->menu);
	_g_object_unref0 (self->priv->label);
	_g_object_unref0 (self->priv->image);
	G_OBJECT_CLASS (unity_tests_unit_panel_indicator_object_view_suite_parent_class)->finalize (obj);
}


GType unity_tests_unit_panel_indicator_object_view_suite_get_type (void) {
	static volatile gsize unity_tests_unit_panel_indicator_object_view_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_panel_indicator_object_view_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitPanelIndicatorObjectViewSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_panel_indicator_object_view_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitPanelIndicatorObjectViewSuite), 0, (GInstanceInitFunc) unity_tests_unit_panel_indicator_object_view_suite_instance_init, NULL };
		GType unity_tests_unit_panel_indicator_object_view_suite_type_id;
		unity_tests_unit_panel_indicator_object_view_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUnitPanelIndicatorObjectViewSuite", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_unit_panel_indicator_object_view_suite_type_id__volatile, unity_tests_unit_panel_indicator_object_view_suite_type_id);
	}
	return unity_tests_unit_panel_indicator_object_view_suite_type_id__volatile;
}




