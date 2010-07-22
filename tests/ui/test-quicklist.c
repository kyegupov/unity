/* test-quicklist.c generated by valac, the Vala compiler
 * generated from test-quicklist.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <unity-private.h>
#include <clutter/clutter.h>
#include <stdlib.h>
#include <string.h>
#include <unity.h>
#include <gtk/gtk.h>


#define UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE (unity_tests_ui_quicklist_suite_get_type ())
#define UNITY_TESTS_UI_QUICKLIST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuite))
#define UNITY_TESTS_UI_QUICKLIST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuiteClass))
#define UNITY_TESTS_UI_IS_QUICKLIST_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE))
#define UNITY_TESTS_UI_IS_QUICKLIST_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE))
#define UNITY_TESTS_UI_QUICKLIST_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuiteClass))

typedef struct _UnityTestsUIQuicklistSuite UnityTestsUIQuicklistSuite;
typedef struct _UnityTestsUIQuicklistSuiteClass UnityTestsUIQuicklistSuiteClass;
typedef struct _UnityTestsUIQuicklistSuitePrivate UnityTestsUIQuicklistSuitePrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

#define UNITY_TESTS_UI_TYPE_TEST_FAVORITES (unity_tests_ui_test_favorites_get_type ())
#define UNITY_TESTS_UI_TEST_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UI_TYPE_TEST_FAVORITES, UnityTestsUITestFavorites))
#define UNITY_TESTS_UI_TEST_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UI_TYPE_TEST_FAVORITES, UnityTestsUITestFavoritesClass))
#define UNITY_TESTS_UI_IS_TEST_FAVORITES(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UI_TYPE_TEST_FAVORITES))
#define UNITY_TESTS_UI_IS_TEST_FAVORITES_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UI_TYPE_TEST_FAVORITES))
#define UNITY_TESTS_UI_TEST_FAVORITES_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UI_TYPE_TEST_FAVORITES, UnityTestsUITestFavoritesClass))

typedef struct _UnityTestsUITestFavorites UnityTestsUITestFavorites;
typedef struct _UnityTestsUITestFavoritesClass UnityTestsUITestFavoritesClass;

struct _UnityTestsUIQuicklistSuite {
	GObject parent_instance;
	UnityTestsUIQuicklistSuitePrivate * priv;
};

struct _UnityTestsUIQuicklistSuiteClass {
	GObjectClass parent_class;
};

struct _UnityTestsUIQuicklistSuitePrivate {
	UnityTestingWindow* window;
	ClutterStage* stage;
};


static gpointer unity_tests_ui_quicklist_suite_parent_class = NULL;

GType unity_tests_ui_quicklist_suite_get_type (void) G_GNUC_CONST;
#define UNITY_TESTS_UI_QUICKLIST_SUITE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE, UnityTestsUIQuicklistSuitePrivate))
enum  {
	UNITY_TESTS_UI_QUICKLIST_SUITE_DUMMY_PROPERTY
};
#define UNITY_TESTS_UI_QUICKLIST_SUITE_DOMAIN "/UI/Quicklist"
UnityTestsUITestFavorites* unity_tests_ui_test_favorites_new (void);
UnityTestsUITestFavorites* unity_tests_ui_test_favorites_construct (GType object_type);
GType unity_tests_ui_test_favorites_get_type (void) G_GNUC_CONST;
static void unity_tests_ui_quicklist_suite_test_controller_show_label (UnityTestsUIQuicklistSuite* self);
static void _unity_tests_ui_quicklist_suite_test_controller_show_label_gdata_test_func (gpointer self);
static void unity_tests_ui_quicklist_suite_test_teardown (UnityTestsUIQuicklistSuite* self);
static void _unity_tests_ui_quicklist_suite_test_teardown_gdata_test_func (gpointer self);
UnityTestsUIQuicklistSuite* unity_tests_ui_quicklist_suite_new (void);
UnityTestsUIQuicklistSuite* unity_tests_ui_quicklist_suite_construct (GType object_type);
static void unity_tests_ui_quicklist_suite_finalize (GObject* obj);



static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _unity_tests_ui_quicklist_suite_test_controller_show_label_gdata_test_func (gpointer self) {
	unity_tests_ui_quicklist_suite_test_controller_show_label (self);
}


static void _unity_tests_ui_quicklist_suite_test_teardown_gdata_test_func (gpointer self) {
	unity_tests_ui_quicklist_suite_test_teardown (self);
}


UnityTestsUIQuicklistSuite* unity_tests_ui_quicklist_suite_construct (GType object_type) {
	UnityTestsUIQuicklistSuite * self;
	UnityFavorites* _tmp0_;
	UnityTestingWindow* _tmp1_;
	ClutterStage* _tmp2_;
	self = (UnityTestsUIQuicklistSuite*) g_object_new (object_type, NULL);
	unity_testing_logging_init_fatal_handler ();
	unity_favorites_singleton = (_tmp0_ = (UnityFavorites*) unity_tests_ui_test_favorites_new (), _g_object_unref0 (unity_favorites_singleton), _tmp0_);
	self->priv->window = (_tmp1_ = g_object_ref_sink (unity_testing_window_new (TRUE, 1024, 600)), _g_object_unref0 (self->priv->window), _tmp1_);
	unity_testing_window_init_test_mode (self->priv->window);
	self->priv->stage = (_tmp2_ = _g_object_ref0 (self->priv->window->stage), _g_object_unref0 (self->priv->stage), _tmp2_);
	gtk_window_set_title ((GtkWindow*) self->priv->window, "Quicklist Tests");
	gtk_widget_show_all ((GtkWidget*) self->priv->window);
	g_test_add_data_func (UNITY_TESTS_UI_QUICKLIST_SUITE_DOMAIN "/ControllerShowLabel", self, _unity_tests_ui_quicklist_suite_test_controller_show_label_gdata_test_func);
	g_test_add_data_func (UNITY_TESTS_UI_QUICKLIST_SUITE_DOMAIN "/Teardown", self, _unity_tests_ui_quicklist_suite_test_teardown_gdata_test_func);
	return self;
}


UnityTestsUIQuicklistSuite* unity_tests_ui_quicklist_suite_new (void) {
	return unity_tests_ui_quicklist_suite_construct (UNITY_TESTS_UI_TYPE_QUICKLIST_SUITE);
}


static void unity_tests_ui_quicklist_suite_test_teardown (UnityTestsUIQuicklistSuite* self) {
	ClutterStage* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->stage = (_tmp0_ = NULL, _g_object_unref0 (self->priv->stage), _tmp0_);
}


static void unity_tests_ui_quicklist_suite_test_controller_show_label (UnityTestsUIQuicklistSuite* self) {
	g_return_if_fail (self != NULL);
}


static void unity_tests_ui_quicklist_suite_class_init (UnityTestsUIQuicklistSuiteClass * klass) {
	unity_tests_ui_quicklist_suite_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUIQuicklistSuitePrivate));
	G_OBJECT_CLASS (klass)->finalize = unity_tests_ui_quicklist_suite_finalize;
}


static void unity_tests_ui_quicklist_suite_instance_init (UnityTestsUIQuicklistSuite * self) {
	self->priv = UNITY_TESTS_UI_QUICKLIST_SUITE_GET_PRIVATE (self);
}


static void unity_tests_ui_quicklist_suite_finalize (GObject* obj) {
	UnityTestsUIQuicklistSuite * self;
	self = UNITY_TESTS_UI_QUICKLIST_SUITE (obj);
	_g_object_unref0 (self->priv->window);
	_g_object_unref0 (self->priv->stage);
	G_OBJECT_CLASS (unity_tests_ui_quicklist_suite_parent_class)->finalize (obj);
}


GType unity_tests_ui_quicklist_suite_get_type (void) {
	static volatile gsize unity_tests_ui_quicklist_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_ui_quicklist_suite_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUIQuicklistSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_ui_quicklist_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUIQuicklistSuite), 0, (GInstanceInitFunc) unity_tests_ui_quicklist_suite_instance_init, NULL };
		GType unity_tests_ui_quicklist_suite_type_id;
		unity_tests_ui_quicklist_suite_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityTestsUIQuicklistSuite", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_ui_quicklist_suite_type_id__volatile, unity_tests_ui_quicklist_suite_type_id);
	}
	return unity_tests_ui_quicklist_suite_type_id__volatile;
}




