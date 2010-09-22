/* test-io.c generated by valac 0.9.8, the Vala compiler
 * generated from test-io.vala, do not modify */

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
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <stdlib.h>
#include <string.h>
#include <gio/gio.h>
#include <config.h>
#include <unity.h>
#include <gobject/gvaluecollector.h>


#define UNITY_TESTS_UNIT_TYPE_IO_SUITE (unity_tests_unit_io_suite_get_type ())
#define UNITY_TESTS_UNIT_IO_SUITE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TESTS_UNIT_TYPE_IO_SUITE, UnityTestsUnitIOSuite))
#define UNITY_TESTS_UNIT_IO_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TESTS_UNIT_TYPE_IO_SUITE, UnityTestsUnitIOSuiteClass))
#define UNITY_TESTS_UNIT_IS_IO_SUITE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TESTS_UNIT_TYPE_IO_SUITE))
#define UNITY_TESTS_UNIT_IS_IO_SUITE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TESTS_UNIT_TYPE_IO_SUITE))
#define UNITY_TESTS_UNIT_IO_SUITE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TESTS_UNIT_TYPE_IO_SUITE, UnityTestsUnitIOSuiteClass))

typedef struct _UnityTestsUnitIOSuite UnityTestsUnitIOSuite;
typedef struct _UnityTestsUnitIOSuiteClass UnityTestsUnitIOSuiteClass;
typedef struct _UnityTestsUnitIOSuitePrivate UnityTestsUnitIOSuitePrivate;
#define _g_main_loop_unref0(var) ((var == NULL) ? NULL : (var = (g_main_loop_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData;
typedef struct _UnityTestsUnitParamSpecIOSuite UnityTestsUnitParamSpecIOSuite;

struct _UnityTestsUnitIOSuite {
	GTypeInstance parent_instance;
	volatile int ref_count;
	UnityTestsUnitIOSuitePrivate * priv;
};

struct _UnityTestsUnitIOSuiteClass {
	GTypeClass parent_class;
	void (*finalize) (UnityTestsUnitIOSuite *self);
};

struct _UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GMainLoop* mainloop;
	char** dirs;
	gint dirs_length1;
	gint _dirs_size_;
	char** _tmp0_;
	char* _tmp1_;
	GFileInputStream* input;
	guchar* buf;
	gint buf_length1;
	gint _buf_size_;
	guchar* _tmp2_;
	void* data;
	gsize data_size;
	char* sdata;
	GError * e;
	GError * _inner_error_;
};

struct _UnityTestsUnitParamSpecIOSuite {
	GParamSpec parent_instance;
};


static char* unity_tests_unit_io_suite_TEST_DATA;
static char* unity_tests_unit_io_suite_TEST_DATA = NULL;
static gpointer unity_tests_unit_io_suite_parent_class = NULL;

gpointer unity_tests_unit_io_suite_ref (gpointer instance);
void unity_tests_unit_io_suite_unref (gpointer instance);
GParamSpec* unity_tests_unit_param_spec_io_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags);
void unity_tests_unit_value_set_io_suite (GValue* value, gpointer v_object);
void unity_tests_unit_value_take_io_suite (GValue* value, gpointer v_object);
gpointer unity_tests_unit_value_get_io_suite (const GValue* value);
GType unity_tests_unit_io_suite_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_TESTS_UNIT_IO_SUITE_DUMMY_PROPERTY
};
UnityTestsUnitIOSuite* unity_tests_unit_io_suite_new (void);
UnityTestsUnitIOSuite* unity_tests_unit_io_suite_construct (GType object_type);
void unity_tests_unit_io_suite_test_async_find_and_load (void);
static void _unity_tests_unit_io_suite_test_async_find_and_load_gdata_test_func (gpointer self);
void unity_tests_unit_io_suite_do_test_async_find_and_load (GMainLoop* mainloop, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_tests_unit_io_suite_do_test_async_find_and_load_finish (GAsyncResult* _res_);
static void unity_tests_unit_io_suite_do_test_async_find_and_load_data_free (gpointer _data);
static void unity_tests_unit_io_suite_do_test_async_find_and_load_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean unity_tests_unit_io_suite_do_test_async_find_and_load_co (UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData* data);
static void unity_tests_unit_io_suite_finalize (UnityTestsUnitIOSuite* obj);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static int _vala_strcmp0 (const char * str1, const char * str2);



static void _unity_tests_unit_io_suite_test_async_find_and_load_gdata_test_func (gpointer self) {
	unity_tests_unit_io_suite_test_async_find_and_load ();
}


UnityTestsUnitIOSuite* unity_tests_unit_io_suite_construct (GType object_type) {
	UnityTestsUnitIOSuite* self;
	self = (UnityTestsUnitIOSuite*) g_type_create_instance (object_type);
	g_test_add_data_func ("/Unit/IO/AsyncDektopFile", NULL, _unity_tests_unit_io_suite_test_async_find_and_load_gdata_test_func);
	return self;
}


UnityTestsUnitIOSuite* unity_tests_unit_io_suite_new (void) {
	return unity_tests_unit_io_suite_construct (UNITY_TESTS_UNIT_TYPE_IO_SUITE);
}


void unity_tests_unit_io_suite_test_async_find_and_load (void) {
	GMainLoop* mainloop;
	mainloop = g_main_loop_new (NULL, FALSE);
	unity_tests_unit_io_suite_do_test_async_find_and_load (mainloop, NULL, NULL);
	g_main_loop_run (mainloop);
	_g_main_loop_unref0 (mainloop);
}


static void unity_tests_unit_io_suite_do_test_async_find_and_load_data_free (gpointer _data) {
	UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData* data;
	data = _data;
	_g_main_loop_unref0 (data->mainloop);
	g_slice_free (UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData, data);
}


static gpointer _g_main_loop_ref0 (gpointer self) {
	return self ? g_main_loop_ref (self) : NULL;
}


void unity_tests_unit_io_suite_do_test_async_find_and_load (GMainLoop* mainloop, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData* _data_;
	_data_ = g_slice_new0 (UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, unity_tests_unit_io_suite_do_test_async_find_and_load);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_tests_unit_io_suite_do_test_async_find_and_load_data_free);
	_data_->mainloop = _g_main_loop_ref0 (mainloop);
	unity_tests_unit_io_suite_do_test_async_find_and_load_co (_data_);
}


void unity_tests_unit_io_suite_do_test_async_find_and_load_finish (GAsyncResult* _res_) {
	UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_tests_unit_io_suite_do_test_async_find_and_load_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_tests_unit_io_suite_do_test_async_find_and_load_co (data);
}


static gboolean unity_tests_unit_io_suite_do_test_async_find_and_load_co (UnityTestsUnitIoSuiteDoTestAsyncFindAndLoadData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		default:
		g_assert_not_reached ();
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
	}
	_state_0:
	data->dirs = (data->_tmp0_ = g_new0 (char*, 1 + 1), data->dirs_length1 = 1, data->_dirs_size_ = data->dirs_length1, data->_tmp0_);
	data->dirs[0] = (data->_tmp1_ = g_build_filename (TESTUNITDIR, "data", NULL, NULL), _g_free0 (data->dirs[0]), data->_tmp1_);
	{
		data->_state_ = 1;
		unity_io_open_from_dirs ("test_desktop_file.desktop", data->dirs, data->dirs_length1, unity_tests_unit_io_suite_do_test_async_find_and_load_ready, data);
		return FALSE;
		_state_1:
		data->input = unity_io_open_from_dirs_finish (data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			goto __catch4_g_error;
		}
		g_assert (G_IS_FILE_INPUT_STREAM (data->input));
		data->buf = (data->_tmp2_ = g_new0 (guchar, 16), data->buf_length1 = 16, data->_buf_size_ = data->buf_length1, data->_tmp2_);
		data->_state_ = 2;
		unity_io_read_stream_async ((GInputStream*) data->input, data->buf, (gsize) 16, G_PRIORITY_DEFAULT, NULL, unity_tests_unit_io_suite_do_test_async_find_and_load_ready, data);
		return FALSE;
		_state_2:
		unity_io_read_stream_finish (data->_res_, &data->data, &data->data_size, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			data->buf = (g_free (data->buf), NULL);
			_g_object_unref0 (data->input);
			goto __catch4_g_error;
		}
		g_assert (data->data_size == 177);
		data->sdata = g_strndup ((const char*) data->data, data->data_size);
		g_assert (_vala_strcmp0 (data->sdata, unity_tests_unit_io_suite_TEST_DATA) == 0);
		_g_free0 (data->sdata);
		data->buf = (g_free (data->buf), NULL);
		_g_object_unref0 (data->input);
	}
	goto __finally4;
	__catch4_g_error:
	{
		data->e = data->_inner_error_;
		data->_inner_error_ = NULL;
		{
			g_error ("test-io.vala:79: Failed read test file: %s", data->e->message);
			_g_error_free0 (data->e);
		}
	}
	__finally4:
	if (data->_inner_error_ != NULL) {
		data->dirs = (_vala_array_free (data->dirs, data->dirs_length1, (GDestroyNotify) g_free), NULL);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
		g_clear_error (&data->_inner_error_);
		return FALSE;
	}
	g_main_loop_quit (data->mainloop);
	data->dirs = (_vala_array_free (data->dirs, data->dirs_length1, (GDestroyNotify) g_free), NULL);
	{
		if (data->_state_ == 0) {
			g_simple_async_result_complete_in_idle (data->_async_result);
		} else {
			g_simple_async_result_complete (data->_async_result);
		}
		g_object_unref (data->_async_result);
		return FALSE;
	}
}


static void unity_tests_unit_value_io_suite_init (GValue* value) {
	value->data[0].v_pointer = NULL;
}


static void unity_tests_unit_value_io_suite_free_value (GValue* value) {
	if (value->data[0].v_pointer) {
		unity_tests_unit_io_suite_unref (value->data[0].v_pointer);
	}
}


static void unity_tests_unit_value_io_suite_copy_value (const GValue* src_value, GValue* dest_value) {
	if (src_value->data[0].v_pointer) {
		dest_value->data[0].v_pointer = unity_tests_unit_io_suite_ref (src_value->data[0].v_pointer);
	} else {
		dest_value->data[0].v_pointer = NULL;
	}
}


static gpointer unity_tests_unit_value_io_suite_peek_pointer (const GValue* value) {
	return value->data[0].v_pointer;
}


static gchar* unity_tests_unit_value_io_suite_collect_value (GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	if (collect_values[0].v_pointer) {
		UnityTestsUnitIOSuite* object;
		object = collect_values[0].v_pointer;
		if (object->parent_instance.g_class == NULL) {
			return g_strconcat ("invalid unclassed object pointer for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		} else if (!g_value_type_compatible (G_TYPE_FROM_INSTANCE (object), G_VALUE_TYPE (value))) {
			return g_strconcat ("invalid object type `", g_type_name (G_TYPE_FROM_INSTANCE (object)), "' for value type `", G_VALUE_TYPE_NAME (value), "'", NULL);
		}
		value->data[0].v_pointer = unity_tests_unit_io_suite_ref (object);
	} else {
		value->data[0].v_pointer = NULL;
	}
	return NULL;
}


static gchar* unity_tests_unit_value_io_suite_lcopy_value (const GValue* value, guint n_collect_values, GTypeCValue* collect_values, guint collect_flags) {
	UnityTestsUnitIOSuite** object_p;
	object_p = collect_values[0].v_pointer;
	if (!object_p) {
		return g_strdup_printf ("value location for `%s' passed as NULL", G_VALUE_TYPE_NAME (value));
	}
	if (!value->data[0].v_pointer) {
		*object_p = NULL;
	} else if (collect_flags & G_VALUE_NOCOPY_CONTENTS) {
		*object_p = value->data[0].v_pointer;
	} else {
		*object_p = unity_tests_unit_io_suite_ref (value->data[0].v_pointer);
	}
	return NULL;
}


GParamSpec* unity_tests_unit_param_spec_io_suite (const gchar* name, const gchar* nick, const gchar* blurb, GType object_type, GParamFlags flags) {
	UnityTestsUnitParamSpecIOSuite* spec;
	g_return_val_if_fail (g_type_is_a (object_type, UNITY_TESTS_UNIT_TYPE_IO_SUITE), NULL);
	spec = g_param_spec_internal (G_TYPE_PARAM_OBJECT, name, nick, blurb, flags);
	G_PARAM_SPEC (spec)->value_type = object_type;
	return G_PARAM_SPEC (spec);
}


gpointer unity_tests_unit_value_get_io_suite (const GValue* value) {
	g_return_val_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_IO_SUITE), NULL);
	return value->data[0].v_pointer;
}


void unity_tests_unit_value_set_io_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitIOSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_IO_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_IO_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
		unity_tests_unit_io_suite_ref (value->data[0].v_pointer);
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_io_suite_unref (old);
	}
}


void unity_tests_unit_value_take_io_suite (GValue* value, gpointer v_object) {
	UnityTestsUnitIOSuite* old;
	g_return_if_fail (G_TYPE_CHECK_VALUE_TYPE (value, UNITY_TESTS_UNIT_TYPE_IO_SUITE));
	old = value->data[0].v_pointer;
	if (v_object) {
		g_return_if_fail (G_TYPE_CHECK_INSTANCE_TYPE (v_object, UNITY_TESTS_UNIT_TYPE_IO_SUITE));
		g_return_if_fail (g_value_type_compatible (G_TYPE_FROM_INSTANCE (v_object), G_VALUE_TYPE (value)));
		value->data[0].v_pointer = v_object;
	} else {
		value->data[0].v_pointer = NULL;
	}
	if (old) {
		unity_tests_unit_io_suite_unref (old);
	}
}


static void unity_tests_unit_io_suite_class_init (UnityTestsUnitIOSuiteClass * klass) {
	unity_tests_unit_io_suite_parent_class = g_type_class_peek_parent (klass);
	UNITY_TESTS_UNIT_IO_SUITE_CLASS (klass)->finalize = unity_tests_unit_io_suite_finalize;
	unity_tests_unit_io_suite_TEST_DATA = g_strdup ("[Desktop Entry]\n" \
"Name=Test Application\n" \
"Comment=This is a test application desktop file\n" \
"Exec=xclock\n" \
"Terminal=false\n" \
"Type=Application\n" \
"StartupNotify=false\n" \
"Icon=test_desktop_icon.png\n");
}


static void unity_tests_unit_io_suite_instance_init (UnityTestsUnitIOSuite * self) {
	self->ref_count = 1;
}


static void unity_tests_unit_io_suite_finalize (UnityTestsUnitIOSuite* obj) {
	UnityTestsUnitIOSuite * self;
	self = UNITY_TESTS_UNIT_IO_SUITE (obj);
}


GType unity_tests_unit_io_suite_get_type (void) {
	static volatile gsize unity_tests_unit_io_suite_type_id__volatile = 0;
	if (g_once_init_enter (&unity_tests_unit_io_suite_type_id__volatile)) {
		static const GTypeValueTable g_define_type_value_table = { unity_tests_unit_value_io_suite_init, unity_tests_unit_value_io_suite_free_value, unity_tests_unit_value_io_suite_copy_value, unity_tests_unit_value_io_suite_peek_pointer, "p", unity_tests_unit_value_io_suite_collect_value, "p", unity_tests_unit_value_io_suite_lcopy_value };
		static const GTypeInfo g_define_type_info = { sizeof (UnityTestsUnitIOSuiteClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_tests_unit_io_suite_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityTestsUnitIOSuite), 0, (GInstanceInitFunc) unity_tests_unit_io_suite_instance_init, &g_define_type_value_table };
		static const GTypeFundamentalInfo g_define_type_fundamental_info = { (G_TYPE_FLAG_CLASSED | G_TYPE_FLAG_INSTANTIATABLE | G_TYPE_FLAG_DERIVABLE | G_TYPE_FLAG_DEEP_DERIVABLE) };
		GType unity_tests_unit_io_suite_type_id;
		unity_tests_unit_io_suite_type_id = g_type_register_fundamental (g_type_fundamental_next (), "UnityTestsUnitIOSuite", &g_define_type_info, &g_define_type_fundamental_info, 0);
		g_once_init_leave (&unity_tests_unit_io_suite_type_id__volatile, unity_tests_unit_io_suite_type_id);
	}
	return unity_tests_unit_io_suite_type_id__volatile;
}


gpointer unity_tests_unit_io_suite_ref (gpointer instance) {
	UnityTestsUnitIOSuite* self;
	self = instance;
	g_atomic_int_inc (&self->ref_count);
	return instance;
}


void unity_tests_unit_io_suite_unref (gpointer instance) {
	UnityTestsUnitIOSuite* self;
	self = instance;
	if (g_atomic_int_dec_and_test (&self->ref_count)) {
		UNITY_TESTS_UNIT_IO_SUITE_GET_CLASS (self)->finalize (self);
		g_type_free_instance ((GTypeInstance *) self);
	}
}


static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	if ((array != NULL) && (destroy_func != NULL)) {
		int i;
		for (i = 0; i < array_length; i = i + 1) {
			if (((gpointer*) array)[i] != NULL) {
				destroy_func (((gpointer*) array)[i]);
			}
		}
	}
}


static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func) {
	_vala_array_destroy (array, array_length, destroy_func);
	g_free (array);
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




