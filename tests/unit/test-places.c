/* test-places.c generated by valac 0.9.7, the Vala compiler
 * generated from test-places.vala, do not modify */

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
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TESTS_UNIT_TYPE_PLACES_SUITE (unity_tests_unit_places_suite_get_type ())
#define UNITY_TESTS_UNIT_PLACES_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE, UnityTestsUnitPlacesSuite))
#define UNITY_TESTS_UNIT_PLACES_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE, UnityTestsUnitPlacesSuiteClass))
#define UNITY_TESTS_UNIT_IS_PLACES_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE))
#define UNITY_TESTS_UNIT_IS_PLACES_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE))
#define UNITY_TESTS_UNIT_PLACES_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_PLACES_SUITE, UnityTestsUnitPlacesSuiteClass))

typedef struct _UnityTestsUnitPlacesSuite UnityTestsUnitPlacesSuite;
typedef struct _UnityTestsUnitPlacesSuiteClass UnityTestsUnitPlacesSuiteClass;
typedef struct _UnityTestsUnitPlacesSuitePrivate UnityTestsUnitPlacesSuitePrivate;
typedef struct _UnityTestsUnitParamSpecPlacesSuite UnityTestsUnitParamSpecPlacesSuite;

struct _UnityTestsUnitPlacesSuite {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityTestsUnitPlacesSuitePrivate * priv;
};

struct _UnityTestsUnitPlacesSuiteClass {
	GTypeClass parent_class;
	void (*finalize) (UnityTestsUnitPlacesSuite *self);
};

struct _UnityTestsUnitParamSpecPlacesSuite {
	GParamSpec parent_instance;
};


static gpointer unity_tests_unit_places_suite_parent_class = NULL;

gpointer unity_tests_unit_places_suite_ref (gpointer instance);
void unity_tests_unit_places_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_places_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_places_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_places_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_places_suite (const GValue* value);
GType unity_tests_unit_places_suite_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_TESTS_UNIT_PLACES_SUITE_DUMMY_PROPERTY
};
UnityTestsUnitPlacesSuite* unity_tests_unit_places_suite_new (void);
UnityTestsUnitPlacesSuite* unity_tests_unit_places_suite_construct (GType object_type);
static void unity_tests_unit_places_suite_finalize (UnityTestsUnitPlacesSuite* obj);



UnityTestsUnitPlacesSuite* unity_tests_unit_places_suite_construct (GType object_type) {
	UnityTestsUnitPlacesSuite* self;
	self = (UnityTestsUnitPlacesSuite*) g_type_create_instance (object_type);
	return self;
}


UnityTestsUnitPlacesSuite* unity_tests_unit_places_suite_new (void) {
	return unity_tests_unit_places_suite_construct (UNITY_TESTS_UNIT_TYPE_PLACES_SUITE);
}


static void unity_tests_unit_value_places_suite_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_tests_unit_value_places_suite_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_tests_unit_places_suite_unref (value->data[0].v_pointer);
	}
}


static void unity_tests_unit_value_places_suite_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_tests_unit_places_suite_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_tests_unit_value_places_suite_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_tests_unit_value_places_suite_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityTestsUnitPlacesSuite* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_tests_unit_places_suite_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_tests_unit_value_places_suite_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityTestsUnitPlacesSuite** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags && G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_tests_unit_places_suite_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_tests_unit_param_spec_places_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityTestsUnitParamSpecPlacesSuite* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TESTS_UNIT_TYPE_PLACES_SUITE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_tests_unit_value_get_places_suite (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_PLACES_SUITE), NULL);
	return value->data[0].v_pointer;
}


void unity_tests_unit_value_set_places_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitPlacesSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_PLACES_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_PLACES_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_tests_unit_places_suite_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_places_suite_unref (old);
	}
}


void unity_tests_unit_value_take_places_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitPlacesSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_PLACES_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_PLACES_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_places_suite_unref (old);
	}
}


static void unity_tests_unit_places_suite_class_init (UnityTestsUnitPlacesSuiteClass * klass) {
	unity_tests_unit_places_suite_parent_class = g_type_class_peek_parent (klass);
	UNITY_TESTS_UNIT_PLACES_SUITE_CLASS (klass)->finalize = unity_tests_unit_places_suite_finalize;
}


static void unity_tests_unit_places_suite_instance_init (UnityTestsUnitPlacesSuite * self) {
	self->ref_count = 1;
}


static void unity_tests_unit_places_suite_finalize (UnityTestsUnitPlacesSuite* obj) {
	UnityTestsUnitPlacesSuite * self;
	self = UNITY_TESTS_UNIT_PLACES_SUITE (obj);
}


GType unity_tests_unit_places_suite_get_type (void) {
	static volatile gsize unity_tests_unit_places_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_places_suite_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_tests_unit_value_places_suite_init, unity_tests_unit_value_places_suite_free_value, unity_tests_unit_value_places_suite_copy_value, unity_tests_unit_value_places_suite_peek_pointer, "p", unity_tests_unit_value_places_suite_collect_value, "p", unity_tests_unit_value_places_suite_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitPlacesSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_places_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitPlacesSuite), 0, (GInstanceInitFunc) unity_tests_unit_places_suite_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_tests_unit_places_suite_type_id;
		unity_tests_unit_places_suite_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityTestsUnitPlacesSuite", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_tests_unit_places_suite_type_id__volatile, unity_tests_unit_places_suite_type_id);
	}
	return unity_tests_unit_places_suite_type_id__volatile;
}


gpointer unity_tests_unit_places_suite_ref (gpointer instance) {
	UnityTestsUnitPlacesSuite* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_tests_unit_places_suite_unref (gpointer instance) {
	UnityTestsUnitPlacesSuite* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_TESTS_UNIT_PLACES_SUITE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}




