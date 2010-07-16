/* test-launcher.c generated by valac, the Vala compiler
 * generated from test-launcher.vala, do not modify */

/*
 *      test-launcher.vala
 *      Copyright (C) 2010 Canonical Ltd
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 3 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 *
 *
 *      Authored by Gordon Allott <gord.allott@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <libbamf/libbamf.h>
#include <stdlib.h>
#include <string.h>
#include <unity-private.h>
#include <float.h>
#include <math.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION (unity_tests_unit_test_bamf_application_get_type ())
#define UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION, UnityTestsUnitTestBamfApplication))
#define UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION, UnityTestsUnitTestBamfApplicationClass))
#define UNITY_TESTS_UNIT_IS_TEST_BAMF_APPLICATION(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION))
#define UNITY_TESTS_UNIT_IS_TEST_BAMF_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION))
#define UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION, UnityTestsUnitTestBamfApplicationClass))

typedef struct _UnityTestsUnitTestBamfApplication UnityTestsUnitTestBamfApplication;
typedef struct _UnityTestsUnitTestBamfApplicationClass UnityTestsUnitTestBamfApplicationClass;
typedef struct _UnityTestsUnitTestBamfApplicationPrivate UnityTestsUnitTestBamfApplicationPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_array_free0(var) ((var == NULL) ? NULL : (var = (g_array_free (var, TRUE), NULL)))

#define UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD (unity_tests_unit_test_scroller_child_get_type ())
#define UNITY_TESTS_UNIT_TEST_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD, UnityTestsUnitTestScrollerChild))
#define UNITY_TESTS_UNIT_TEST_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD, UnityTestsUnitTestScrollerChildClass))
#define UNITY_TESTS_UNIT_IS_TEST_SCROLLER_CHILD(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD))
#define UNITY_TESTS_UNIT_IS_TEST_SCROLLER_CHILD_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD))
#define UNITY_TESTS_UNIT_TEST_SCROLLER_CHILD_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD, UnityTestsUnitTestScrollerChildClass))

typedef struct _UnityTestsUnitTestScrollerChild UnityTestsUnitTestScrollerChild;
typedef struct _UnityTestsUnitTestScrollerChildClass UnityTestsUnitTestScrollerChildClass;
typedef struct _UnityTestsUnitTestScrollerChildPrivate UnityTestsUnitTestScrollerChildPrivate;

#define UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE (unity_tests_unit_launcher_suite_get_type ())
#define UNITY_TESTS_UNIT_LAUNCHER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE, UnityTestsUnitLauncherSuite))
#define UNITY_TESTS_UNIT_LAUNCHER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE, UnityTestsUnitLauncherSuiteClass))
#define UNITY_TESTS_UNIT_IS_LAUNCHER_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE))
#define UNITY_TESTS_UNIT_IS_LAUNCHER_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE))
#define UNITY_TESTS_UNIT_LAUNCHER_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE, UnityTestsUnitLauncherSuiteClass))

typedef struct _UnityTestsUnitLauncherSuite UnityTestsUnitLauncherSuite;
typedef struct _UnityTestsUnitLauncherSuiteClass UnityTestsUnitLauncherSuiteClass;
typedef struct _UnityTestsUnitLauncherSuitePrivate UnityTestsUnitLauncherSuitePrivate;
#define _unity_launcher_scroller_model_iterator_unref0(var) ((var == NULL) ? NULL : (var = (unity_launcher_scroller_model_iterator_unref (var), NULL)))
typedef struct _UnityTestsUnitParamSpecLauncherSuite UnityTestsUnitParamSpecLauncherSuite;

struct _UnityTestsUnitTestBamfApplication {
	BamfApplication parent_instance;
	UnityTestsUnitTestBamfApplicationPrivate * priv;
	gboolean test_is_active;
	gboolean test_is_urgent;
	gboolean test_user_visible;
	gboolean test_is_running;
	char* desktop_file;
	char* name;
	char* icon;
};

struct _UnityTestsUnitTestBamfApplicationClass {
	BamfApplicationClass parent_class;
};

struct _UnityTestsUnitTestBamfApplicationPrivate {
	GList* children;
	GList* temp_list;
};

struct _UnityTestsUnitTestScrollerChild {
	UnityLauncherScrollerChild parent_instance;
	UnityTestsUnitTestScrollerChildPrivate * priv;
};

struct _UnityTestsUnitTestScrollerChildClass {
	UnityLauncherScrollerChildClass parent_class;
};

struct _UnityTestsUnitLauncherSuite {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityTestsUnitLauncherSuitePrivate * priv;
};

struct _UnityTestsUnitLauncherSuiteClass {
	GTypeClass parent_class;
	void (*finalize) (UnityTestsUnitLauncherSuite *self);
};

struct _UnityTestsUnitParamSpecLauncherSuite {
	GParamSpec parent_instance;
};


static gpointer unity_tests_unit_test_bamf_application_parent_class = NULL;
static gpointer unity_tests_unit_test_scroller_child_parent_class = NULL;
static gpointer unity_tests_unit_launcher_suite_parent_class = NULL;

GType unity_tests_unit_test_bamf_application_get_type (void);
#define UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION, UnityTestsUnitTestBamfApplicationPrivate))
enum  {
	UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION_DUMMY_PROPERTY
};
static void _g_list_free_g_object_unref (GList* self);
UnityTestsUnitTestBamfApplication* unity_tests_unit_test_bamf_application_new (void);
UnityTestsUnitTestBamfApplication* unity_tests_unit_test_bamf_application_construct (GType object_type);
const char* unity_tests_unit_test_bamf_application_get_desktop_file (UnityTestsUnitTestBamfApplication* self);
GList* unity_tests_unit_test_bamf_application_get_windows (UnityTestsUnitTestBamfApplication* self);
static GList* unity_tests_unit_test_bamf_application_real_get_children (BamfView* base);
GArray* unity_tests_unit_test_bamf_application_get_xids (UnityTestsUnitTestBamfApplication* self);
static char* unity_tests_unit_test_bamf_application_real_get_icon (BamfView* base);
static char* unity_tests_unit_test_bamf_application_real_get_name (BamfView* base);
static gboolean unity_tests_unit_test_bamf_application_real_is_active (BamfView* base);
static gboolean unity_tests_unit_test_bamf_application_real_is_running (BamfView* base);
static gboolean unity_tests_unit_test_bamf_application_real_is_urgent (BamfView* base);
gboolean unity_tests_unit_test_bamf_application_user_visible (UnityTestsUnitTestBamfApplication* self);
static const char* unity_tests_unit_test_bamf_application_real_view_type (BamfView* base);
static GObject * unity_tests_unit_test_bamf_application_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_tests_unit_test_bamf_application_finalize (GObject* obj);
GType unity_tests_unit_test_scroller_child_get_type (void);
enum  {
	UNITY_TESTS_UNIT_TEST_SCROLLER_CHILD_DUMMY_PROPERTY
};
static void unity_tests_unit_test_scroller_child_real_force_rotation_jump (UnityLauncherScrollerChild* base, float degrees);
UnityTestsUnitTestScrollerChild* unity_tests_unit_test_scroller_child_new (void);
UnityTestsUnitTestScrollerChild* unity_tests_unit_test_scroller_child_construct (GType object_type);
gpointer unity_tests_unit_launcher_suite_ref (gpointer instance);
void unity_tests_unit_launcher_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_launcher_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_launcher_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_launcher_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_launcher_suite (const GValue* value);
GType unity_tests_unit_launcher_suite_get_type (void);
enum  {
	UNITY_TESTS_UNIT_LAUNCHER_SUITE_DUMMY_PROPERTY
};
static void unity_tests_unit_launcher_suite_test_scroller_model (UnityTestsUnitLauncherSuite* self);
static void _unity_tests_unit_launcher_suite_test_scroller_model_gdata_test_func (gpointer self);
static void unity_tests_unit_launcher_suite_test_scroller_child_controller (UnityTestsUnitLauncherSuite* self);
static void _unity_tests_unit_launcher_suite_test_scroller_child_controller_gdata_test_func (gpointer self);
UnityTestsUnitLauncherSuite* unity_tests_unit_launcher_suite_new (void);
UnityTestsUnitLauncherSuite* unity_tests_unit_launcher_suite_construct (GType object_type);
static void unity_tests_unit_launcher_suite_finalize (UnityTestsUnitLauncherSuite* obj);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


UnityTestsUnitTestBamfApplication* unity_tests_unit_test_bamf_application_construct (GType object_type) {
	UnityTestsUnitTestBamfApplication * self;
	self = (UnityTestsUnitTestBamfApplication*) g_object_new (object_type, "path", "/null", NULL);
	return self;
}


UnityTestsUnitTestBamfApplication* unity_tests_unit_test_bamf_application_new (void) {
	return unity_tests_unit_test_bamf_application_construct (UNITY_TESTS_UNIT_TYPE_TEST_BAMF_APPLICATION);
}


const char* unity_tests_unit_test_bamf_application_get_desktop_file (UnityTestsUnitTestBamfApplication* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->desktop_file;
	return result;
}


GList* unity_tests_unit_test_bamf_application_get_windows (UnityTestsUnitTestBamfApplication* self) {
	GList* result = NULL;
	GList* _tmp0_;
	g_return_val_if_fail (self != NULL, NULL);
	self->priv->temp_list = (_tmp0_ = NULL, __g_list_free_g_object_unref0 (self->priv->temp_list), _tmp0_);
	result = self->priv->temp_list;
	return result;
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static GList* unity_tests_unit_test_bamf_application_real_get_children (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	GList* result = NULL;
	GList* tmplist;
	self = (UnityTestsUnitTestBamfApplication*) base;
	tmplist = NULL;
	{
		GList* child_collection;
		GList* child_it;
		child_collection = self->priv->children;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			BamfView* child;
			child = _g_object_ref0 ((BamfView*) child_it->data);
			{
				tmplist = g_list_append (tmplist, _g_object_ref0 (child));
				_g_object_unref0 (child);
			}
		}
	}
	result = tmplist;
	return result;
}


GArray* unity_tests_unit_test_bamf_application_get_xids (UnityTestsUnitTestBamfApplication* self) {
	GArray* result = NULL;
	GArray* retarray;
	g_return_val_if_fail (self != NULL, NULL);
	retarray = g_array_new (TRUE, FALSE, (guint) sizeof (guint32));
	result = retarray;
	return result;
}


static char* unity_tests_unit_test_bamf_application_real_get_icon (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	char* result = NULL;
	self = (UnityTestsUnitTestBamfApplication*) base;
	result = g_strdup (self->icon);
	return result;
}


static char* unity_tests_unit_test_bamf_application_real_get_name (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	char* result = NULL;
	self = (UnityTestsUnitTestBamfApplication*) base;
	result = g_strdup (self->name);
	return result;
}


static gboolean unity_tests_unit_test_bamf_application_real_is_active (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	gboolean result = FALSE;
	self = (UnityTestsUnitTestBamfApplication*) base;
	result = self->test_is_active;
	return result;
}


static gboolean unity_tests_unit_test_bamf_application_real_is_running (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	gboolean result = FALSE;
	self = (UnityTestsUnitTestBamfApplication*) base;
	result = self->test_is_running;
	return result;
}


static gboolean unity_tests_unit_test_bamf_application_real_is_urgent (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	gboolean result = FALSE;
	self = (UnityTestsUnitTestBamfApplication*) base;
	result = self->test_is_urgent;
	return result;
}


gboolean unity_tests_unit_test_bamf_application_user_visible (UnityTestsUnitTestBamfApplication* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->test_user_visible;
	return result;
}


static const char* unity_tests_unit_test_bamf_application_real_view_type (BamfView* base) {
	UnityTestsUnitTestBamfApplication * self;
	const char* result = NULL;
	self = (UnityTestsUnitTestBamfApplication*) base;
	result = "test";
	return result;
}


static GObject * unity_tests_unit_test_bamf_application_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityTestsUnitTestBamfApplication * self;
	parent_class = G_OBJECT_CLASS (unity_tests_unit_test_bamf_application_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION (obj);
	{
		GList* _tmp0_;
		self->priv->children = (_tmp0_ = NULL, __g_list_free_g_object_unref0 (self->priv->children), _tmp0_);
	}
	return obj;
}


static void unity_tests_unit_test_bamf_application_class_init (UnityTestsUnitTestBamfApplicationClass * klass) {
	unity_tests_unit_test_bamf_application_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityTestsUnitTestBamfApplicationPrivate));
	BAMF_VIEW_CLASS (klass)->get_children = unity_tests_unit_test_bamf_application_real_get_children;
	BAMF_VIEW_CLASS (klass)->get_icon = unity_tests_unit_test_bamf_application_real_get_icon;
	BAMF_VIEW_CLASS (klass)->get_name = unity_tests_unit_test_bamf_application_real_get_name;
	BAMF_VIEW_CLASS (klass)->is_active = unity_tests_unit_test_bamf_application_real_is_active;
	BAMF_VIEW_CLASS (klass)->is_running = unity_tests_unit_test_bamf_application_real_is_running;
	BAMF_VIEW_CLASS (klass)->is_urgent = unity_tests_unit_test_bamf_application_real_is_urgent;
	BAMF_VIEW_CLASS (klass)->view_type = unity_tests_unit_test_bamf_application_real_view_type;
	G_OBJECT_CLASS (klass)->constructor = unity_tests_unit_test_bamf_application_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_tests_unit_test_bamf_application_finalize;
}


static void unity_tests_unit_test_bamf_application_instance_init (UnityTestsUnitTestBamfApplication * self) {
	self->priv = UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION_GET_PRIVATE (self);
	self->test_is_active = TRUE;
	self->test_is_urgent = FALSE;
	self->test_user_visible = TRUE;
	self->test_is_running = TRUE;
	self->desktop_file = g_strdup ("firefox.desktop");
	self->name = g_strdup ("firefox");
	self->icon = g_strdup ("firefox");
}


static void unity_tests_unit_test_bamf_application_finalize (GObject* obj) {
	UnityTestsUnitTestBamfApplication * self;
	self = UNITY_TESTS_UNIT_TEST_BAMF_APPLICATION (obj);
	_g_free0 (self->desktop_file);
	_g_free0 (self->name);
	_g_free0 (self->icon);
	__g_list_free_g_object_unref0 (self->priv->children);
	__g_list_free_g_object_unref0 (self->priv->temp_list);
	G_OBJECT_CLASS (unity_tests_unit_test_bamf_application_parent_class)->finalize (obj);
}


GType unity_tests_unit_test_bamf_application_get_type (void) {
	static volatile gsize unity_tests_unit_test_bamf_application_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_test_bamf_application_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitTestBamfApplicationClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_test_bamf_application_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitTestBamfApplication), 0, (GInstanceInitFunc) unity_tests_unit_test_bamf_application_instance_init, NULL };
		GType unity_tests_unit_test_bamf_application_type_id;
		unity_tests_unit_test_bamf_application_type_id = g_type_register_static (BAMF_TYPE_APPLICATION, "UnityTestsUnitTestBamfApplication", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_unit_test_bamf_application_type_id__volatile, unity_tests_unit_test_bamf_application_type_id);
	}
	return unity_tests_unit_test_bamf_application_type_id__volatile;
}


static void unity_tests_unit_test_scroller_child_real_force_rotation_jump (UnityLauncherScrollerChild* base, float degrees) {
	UnityTestsUnitTestScrollerChild * self;
	self = (UnityTestsUnitTestScrollerChild*) base;
}


UnityTestsUnitTestScrollerChild* unity_tests_unit_test_scroller_child_construct (GType object_type) {
	UnityTestsUnitTestScrollerChild * self;
	self = (UnityTestsUnitTestScrollerChild*) unity_launcher_scroller_child_construct (object_type);
	return self;
}


UnityTestsUnitTestScrollerChild* unity_tests_unit_test_scroller_child_new (void) {
	return unity_tests_unit_test_scroller_child_construct (UNITY_TESTS_UNIT_TYPE_TEST_SCROLLER_CHILD);
}


static void unity_tests_unit_test_scroller_child_class_init (UnityTestsUnitTestScrollerChildClass * klass) {
	unity_tests_unit_test_scroller_child_parent_class = g_type_class_peek_parent (klass);
	UNITY_LAUNCHER_SCROLLER_CHILD_CLASS (klass)->force_rotation_jump = unity_tests_unit_test_scroller_child_real_force_rotation_jump;
}


static void unity_tests_unit_test_scroller_child_instance_init (UnityTestsUnitTestScrollerChild * self) {
}


GType unity_tests_unit_test_scroller_child_get_type (void) {
	static volatile gsize unity_tests_unit_test_scroller_child_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_test_scroller_child_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitTestScrollerChildClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_test_scroller_child_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitTestScrollerChild), 0, (GInstanceInitFunc) unity_tests_unit_test_scroller_child_instance_init, NULL };
		GType unity_tests_unit_test_scroller_child_type_id;
		unity_tests_unit_test_scroller_child_type_id = g_type_register_static (UNITY_LAUNCHER_TYPE_SCROLLER_CHILD, "UnityTestsUnitTestScrollerChild", &g_define_type_info, 0);
		g_once_init_leave (&unity_tests_unit_test_scroller_child_type_id__volatile, unity_tests_unit_test_scroller_child_type_id);
	}
	return unity_tests_unit_test_scroller_child_type_id__volatile;
}


static void _unity_tests_unit_launcher_suite_test_scroller_model_gdata_test_func (gpointer self) {
	unity_tests_unit_launcher_suite_test_scroller_model (self);
}


static void _unity_tests_unit_launcher_suite_test_scroller_child_controller_gdata_test_func (gpointer self) {
	unity_tests_unit_launcher_suite_test_scroller_child_controller (self);
}


UnityTestsUnitLauncherSuite* unity_tests_unit_launcher_suite_construct (GType object_type) {
	UnityTestsUnitLauncherSuite* self;
	self = (UnityTestsUnitLauncherSuite*) g_type_create_instance (object_type);
	g_test_add_data_func ("/Unity/Launcher/TestScrollerModel", self, _unity_tests_unit_launcher_suite_test_scroller_model_gdata_test_func);
	g_test_add_data_func ("/Unity/Launcher/TestScrollerChildController", self, _unity_tests_unit_launcher_suite_test_scroller_child_controller_gdata_test_func);
	return self;
}


UnityTestsUnitLauncherSuite* unity_tests_unit_launcher_suite_new (void) {
	return unity_tests_unit_launcher_suite_construct (UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE);
}


static void unity_tests_unit_launcher_suite_test_scroller_model (UnityTestsUnitLauncherSuite* self) {
	UnityLauncherScrollerModel* model;
	UnityLauncherScrollerChild* child_a;
	UnityLauncherScrollerChild* child_b;
	UnityLauncherScrollerChild* child_c;
	UnityLauncherScrollerChild* _tmp0_;
	UnityLauncherScrollerChild* _tmp1_;
	UnityLauncherScrollerChild* _tmp2_;
	g_return_if_fail (self != NULL);
	model = unity_launcher_scroller_model_new ();
	child_a = (UnityLauncherScrollerChild*) g_object_ref_sink (unity_tests_unit_test_scroller_child_new ());
	child_b = (UnityLauncherScrollerChild*) g_object_ref_sink (unity_tests_unit_test_scroller_child_new ());
	child_c = (UnityLauncherScrollerChild*) g_object_ref_sink (unity_tests_unit_test_scroller_child_new ());
	unity_launcher_scroller_model_add (model, child_a);
	unity_launcher_scroller_model_add (model, child_c);
	unity_launcher_scroller_model_insert (model, child_b, 1);
	g_assert ((_tmp0_ = unity_launcher_scroller_model_get (model, 1)) == child_b);
	_g_object_unref0 (_tmp0_);
	g_assert ((_tmp1_ = unity_launcher_scroller_model_get (model, 2)) == child_c);
	_g_object_unref0 (_tmp1_);
	{
		UnityLauncherScrollerModelIterator* _child_it;
		_child_it = unity_launcher_scroller_model_iterator (model);
		while (TRUE) {
			UnityLauncherScrollerChild* child;
			if (!unity_launcher_scroller_model_iterator_next (_child_it)) {
				break;
			}
			child = unity_launcher_scroller_model_iterator_get (_child_it);
			g_assert (UNITY_LAUNCHER_IS_SCROLLER_CHILD (child));
			_g_object_unref0 (child);
		}
		_unity_launcher_scroller_model_iterator_unref0 (_child_it);
	}
	g_assert (unity_launcher_scroller_model_contains (model, child_a));
	unity_launcher_scroller_model_remove (model, child_b);
	g_assert ((_tmp2_ = unity_launcher_scroller_model_get (model, 1)) == child_c);
	_g_object_unref0 (_tmp2_);
	_g_object_unref0 (model);
	_g_object_unref0 (child_a);
	_g_object_unref0 (child_b);
	_g_object_unref0 (child_c);
}


static void unity_tests_unit_launcher_suite_test_scroller_child_controller (UnityTestsUnitLauncherSuite* self) {
	UnityTestsUnitTestBamfApplication* test_app;
	UnityLauncherScrollerChild* child;
	UnityLauncherApplicationController* controller;
	char* _tmp0_;
	char* _tmp1_;
	char* _tmp2_;
	g_return_if_fail (self != NULL);
	test_app = unity_tests_unit_test_bamf_application_new ();
	child = (UnityLauncherScrollerChild*) g_object_ref_sink (unity_tests_unit_test_scroller_child_new ());
	controller = unity_launcher_application_controller_new (TESTDIR "/data/test_desktop_file.desktop", child);
	test_app->name = (_tmp0_ = g_strdup ("Test Application-New"), _g_free0 (test_app->name), _tmp0_);
	test_app->desktop_file = (_tmp1_ = g_strdup (TESTDIR "/data/test_desktop_file.desktop"), _g_free0 (test_app->desktop_file), _tmp1_);
	test_app->icon = (_tmp2_ = g_strdup (TESTDIR "/data/test_desktop_icon.png"), _g_free0 (test_app->icon), _tmp2_);
	test_app->test_is_active = TRUE;
	test_app->test_is_urgent = FALSE;
	test_app->test_user_visible = TRUE;
	test_app->test_is_running = TRUE;
	g_assert (unity_launcher_scroller_child_get_running (child) == FALSE);
	g_assert (unity_launcher_scroller_child_get_active (child) == FALSE);
	g_assert (unity_launcher_scroller_child_get_needs_attention (child) == FALSE);
	g_assert (_vala_strcmp0 (((UnityLauncherScrollerChildController*) controller)->name, "Test Application") == 0);
	_g_object_unref0 (test_app);
	_g_object_unref0 (child);
	_g_object_unref0 (controller);
}


static void unity_tests_unit_value_launcher_suite_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_tests_unit_value_launcher_suite_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_tests_unit_launcher_suite_unref (value->data[0].v_pointer);
	}
}


static void unity_tests_unit_value_launcher_suite_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_tests_unit_launcher_suite_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_tests_unit_value_launcher_suite_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_tests_unit_value_launcher_suite_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityTestsUnitLauncherSuite* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_tests_unit_launcher_suite_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_tests_unit_value_launcher_suite_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityTestsUnitLauncherSuite** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_tests_unit_launcher_suite_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_tests_unit_param_spec_launcher_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityTestsUnitParamSpecLauncherSuite* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_tests_unit_value_get_launcher_suite (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE), NULL);
	return value->data[0].v_pointer;
}


void unity_tests_unit_value_set_launcher_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitLauncherSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_tests_unit_launcher_suite_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_launcher_suite_unref (old);
	}
}


void unity_tests_unit_value_take_launcher_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitLauncherSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_LAUNCHER_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_launcher_suite_unref (old);
	}
}


static void unity_tests_unit_launcher_suite_class_init (UnityTestsUnitLauncherSuiteClass * klass) {
	unity_tests_unit_launcher_suite_parent_class = g_type_class_peek_parent (klass);
	UNITY_TESTS_UNIT_LAUNCHER_SUITE_CLASS (klass)->finalize = unity_tests_unit_launcher_suite_finalize;
}


static void unity_tests_unit_launcher_suite_instance_init (UnityTestsUnitLauncherSuite * self) {
	self->ref_count = 1;
}


static void unity_tests_unit_launcher_suite_finalize (UnityTestsUnitLauncherSuite* obj) {
	UnityTestsUnitLauncherSuite * self;
	self = UNITY_TESTS_UNIT_LAUNCHER_SUITE (obj);
}


GType unity_tests_unit_launcher_suite_get_type (void) {
	static volatile gsize unity_tests_unit_launcher_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_launcher_suite_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_tests_unit_value_launcher_suite_init, unity_tests_unit_value_launcher_suite_free_value, unity_tests_unit_value_launcher_suite_copy_value, unity_tests_unit_value_launcher_suite_peek_pointer, "p", unity_tests_unit_value_launcher_suite_collect_value, "p", unity_tests_unit_value_launcher_suite_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitLauncherSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_launcher_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitLauncherSuite), 0, (GInstanceInitFunc) unity_tests_unit_launcher_suite_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_tests_unit_launcher_suite_type_id;
		unity_tests_unit_launcher_suite_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityTestsUnitLauncherSuite", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_tests_unit_launcher_suite_type_id__volatile, unity_tests_unit_launcher_suite_type_id);
	}
	return unity_tests_unit_launcher_suite_type_id__volatile;
}


gpointer unity_tests_unit_launcher_suite_ref (gpointer instance) {
	UnityTestsUnitLauncherSuite* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_tests_unit_launcher_suite_unref (gpointer instance) {
	UnityTestsUnitLauncherSuite* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_TESTS_UNIT_LAUNCHER_SUITE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
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




