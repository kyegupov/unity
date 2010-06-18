/* theme.c generated by valac, the Vala compiler
 * generated from theme.vala, do not modify */

/*
 * Copyright (C) 2010 Canonical, Ltd.
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License
 * version 3.0 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License version 3.0 for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gee.h>
#include <gtk/gtk.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>
#include <glib/gstdio.h>
#include <clutter/clutter.h>
#include <gdk-pixbuf/gdk-pixdata.h>


#define UNITY_TYPE_THEME_FILE_PATH (unity_theme_file_path_get_type ())
#define UNITY_THEME_FILE_PATH(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePath))
#define UNITY_THEME_FILE_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePathClass))
#define UNITY_IS_THEME_FILE_PATH(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_FILE_PATH))
#define UNITY_IS_THEME_FILE_PATH_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_FILE_PATH))
#define UNITY_THEME_FILE_PATH_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePathClass))

typedef struct _UnityThemeFilePath UnityThemeFilePath;
typedef struct _UnityThemeFilePathClass UnityThemeFilePathClass;
typedef struct _UnityThemeFilePathPrivate UnityThemeFilePathPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define _g_free0(var) (var = (g_free (var), NULL))
typedef struct _UnityThemeFilePathGetIconFilepathData UnityThemeFilePathGetIconFilepathData;
#define _gtk_icon_info_free0(var) ((var == NULL) ? NULL : (var = (gtk_icon_info_free (var), NULL)))
typedef struct _UnityThemeFilePathPathFromThemeData UnityThemeFilePathPathFromThemeData;

#define UNITY_TYPE_THEME_IMAGE (unity_theme_image_get_type ())
#define UNITY_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImage))
#define UNITY_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))
#define UNITY_IS_THEME_IMAGE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_THEME_IMAGE))
#define UNITY_IS_THEME_IMAGE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_THEME_IMAGE))
#define UNITY_THEME_IMAGE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_THEME_IMAGE, UnityThemeImageClass))

typedef struct _UnityThemeImage UnityThemeImage;
typedef struct _UnityThemeImageClass UnityThemeImageClass;
typedef struct _UnityThemeImagePrivate UnityThemeImagePrivate;
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))

struct _UnityThemeFilePath {
	GObject parent_instance;
	UnityThemeFilePathPrivate * priv;
};

struct _UnityThemeFilePathClass {
	GObjectClass parent_class;
};

struct _UnityThemeFilePathPrivate {
	GeePriorityQueue* themes;
};

struct _UnityThemeFilePathGetIconFilepathData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityThemeFilePath* self;
	char* icon_name;
	char* filepath;
	GeeIterator* _theme_it;
	GtkIconTheme* theme;
	char* _tmp0_;
};

struct _UnityThemeFilePathPathFromThemeData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityThemeFilePath* self;
	char* icon_name;
	GtkIconTheme* theme;
	char* result;
	GtkIconInfo* info;
	char* filename;
};

struct _UnityThemeImage {
	ClutterTexture parent_instance;
	UnityThemeImagePrivate * priv;
	GdkPixbuf* icon;
};

struct _UnityThemeImageClass {
	ClutterTextureClass parent_class;
};

struct _UnityThemeImagePrivate {
	UnityThemeFilePath* theme;
	char* _icon_name;
};


static gpointer unity_theme_file_path_parent_class = NULL;
static gpointer unity_theme_image_parent_class = NULL;

GType unity_theme_file_path_get_type (void);
#define UNITY_THEME_FILE_PATH_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_THEME_FILE_PATH, UnityThemeFilePathPrivate))
enum  {
	UNITY_THEME_FILE_PATH_DUMMY_PROPERTY
};
void unity_theme_file_path_add_icon_theme (UnityThemeFilePath* self, GtkIconTheme* theme);
static void unity_theme_file_path_get_icon_filepath_data_free (gpointer _data);
static void unity_theme_file_path_get_icon_filepath_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void unity_theme_file_path_path_from_theme (UnityThemeFilePath* self, const char* icon_name, GtkIconTheme* theme, GAsyncReadyCallback _callback_, gpointer _user_data_);
static char* unity_theme_file_path_path_from_theme_finish (UnityThemeFilePath* self, GAsyncResult* _res_);
void unity_theme_file_path_get_icon_filepath (UnityThemeFilePath* self, const char* icon_name, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_theme_file_path_get_icon_filepath_finish (UnityThemeFilePath* self, GAsyncResult* _res_);
static gboolean unity_theme_file_path_get_icon_filepath_co (UnityThemeFilePathGetIconFilepathData* data);
static void unity_theme_file_path_path_from_theme_data_free (gpointer _data);
static void unity_theme_file_path_path_from_theme_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static gboolean _unity_theme_file_path_path_from_theme_co_gsource_func (gpointer self);
static gboolean unity_theme_file_path_path_from_theme_co (UnityThemeFilePathPathFromThemeData* data);
UnityThemeFilePath* unity_theme_file_path_new (void);
UnityThemeFilePath* unity_theme_file_path_construct (GType object_type);
static GObject * unity_theme_file_path_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_theme_file_path_finalize (GObject* obj);
gboolean unity_icon_name_exists_in_theme (const char* icon_name, const char* theme);
GType unity_theme_image_get_type (void);
#define UNITY_THEME_IMAGE_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_THEME_IMAGE, UnityThemeImagePrivate))
enum  {
	UNITY_THEME_IMAGE_DUMMY_PROPERTY,
	UNITY_THEME_IMAGE_ICON_NAME
};
UnityThemeImage* unity_theme_image_new (const char* icon_name);
UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name);
static void _lambda0_ (UnityThemeFilePath* theme, const char* filepath, UnityThemeImage* self);
static void __lambda0__unity_theme_file_path_found_icon_path (UnityThemeFilePath* _sender, const char* filepath, gpointer self);
const char* unity_theme_image_get_icon_name (UnityThemeImage* self);
static gboolean unity_theme_image_try_load_icon_from_theme (UnityThemeImage* self);
static gboolean unity_theme_image_try_load_icon_from_dir (UnityThemeImage* self, const char* dir);
static gboolean unity_theme_image_try_load_icon_from_datadir (UnityThemeImage* self);
static void unity_theme_image_load_missing_icon (UnityThemeImage* self);
void unity_theme_image_set_icon_name (UnityThemeImage* self, const char* value);
static GObject * unity_theme_image_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_theme_image_finalize (GObject* obj);
static void unity_theme_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_theme_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);
static int _vala_strcmp0 (const char * str1, const char * str2);



void unity_theme_file_path_add_icon_theme (UnityThemeFilePath* self, GtkIconTheme* theme) {
	g_return_if_fail (self != NULL);
	g_return_if_fail (theme != NULL);
	gee_abstract_collection_add ((GeeAbstractCollection*) self->priv->themes, theme);
}


static void unity_theme_file_path_get_icon_filepath_data_free (gpointer _data) {
	UnityThemeFilePathGetIconFilepathData* data;
	data = _data;
	_g_free0 (data->icon_name);
	g_object_unref (data->self);
	g_slice_free (UnityThemeFilePathGetIconFilepathData, data);
}


void unity_theme_file_path_get_icon_filepath (UnityThemeFilePath* self, const char* icon_name, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityThemeFilePathGetIconFilepathData* _data_;
	_data_ = g_slice_new0 (UnityThemeFilePathGetIconFilepathData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_theme_file_path_get_icon_filepath);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_theme_file_path_get_icon_filepath_data_free);
	_data_->self = g_object_ref (self);
	_data_->icon_name = g_strdup (icon_name);
	unity_theme_file_path_get_icon_filepath_co (_data_);
}


void unity_theme_file_path_get_icon_filepath_finish (UnityThemeFilePath* self, GAsyncResult* _res_) {
	UnityThemeFilePathGetIconFilepathData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_theme_file_path_get_icon_filepath_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityThemeFilePathGetIconFilepathData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_theme_file_path_get_icon_filepath_co (data);
}


static gboolean unity_theme_file_path_get_icon_filepath_co (UnityThemeFilePathGetIconFilepathData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->filepath = g_strdup ("");
		{
			data->_theme_it = gee_abstract_collection_iterator ((GeeAbstractCollection*) data->self->priv->themes);
			while (TRUE) {
				if (!gee_iterator_next (data->_theme_it)) {
					break;
				}
				data->theme = (GtkIconTheme*) gee_iterator_get (data->_theme_it);
				data->_state_ = 1;
				unity_theme_file_path_path_from_theme (data->self, data->icon_name, data->theme, unity_theme_file_path_get_icon_filepath_ready, data);
				return FALSE;
				_state_1:
				data->filepath = (data->_tmp0_ = unity_theme_file_path_path_from_theme_finish (data->self, data->_res_), _g_free0 (data->filepath), data->_tmp0_);
				if (_vala_strcmp0 (data->filepath, "") != 0) {
					_g_object_unref0 (data->theme);
					break;
				}
				_g_object_unref0 (data->theme);
			}
			_g_object_unref0 (data->_theme_it);
		}
		if (_vala_strcmp0 (data->filepath, "") != 0) {
			g_signal_emit_by_name (data->self, "found-icon-path", data->filepath);
		} else {
			g_signal_emit_by_name (data->self, "failed");
		}
		_g_free0 (data->filepath);
	}
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


static void unity_theme_file_path_path_from_theme_data_free (gpointer _data) {
	UnityThemeFilePathPathFromThemeData* data;
	data = _data;
	_g_free0 (data->icon_name);
	_g_object_unref0 (data->theme);
	_g_free0 (data->result);
	g_object_unref (data->self);
	g_slice_free (UnityThemeFilePathPathFromThemeData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_theme_file_path_path_from_theme (UnityThemeFilePath* self, const char* icon_name, GtkIconTheme* theme, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityThemeFilePathPathFromThemeData* _data_;
	_data_ = g_slice_new0 (UnityThemeFilePathPathFromThemeData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_theme_file_path_path_from_theme);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_theme_file_path_path_from_theme_data_free);
	_data_->self = g_object_ref (self);
	_data_->icon_name = g_strdup (icon_name);
	_data_->theme = _g_object_ref0 (theme);
	unity_theme_file_path_path_from_theme_co (_data_);
}


static char* unity_theme_file_path_path_from_theme_finish (UnityThemeFilePath* self, GAsyncResult* _res_) {
	char* result;
	UnityThemeFilePathPathFromThemeData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void unity_theme_file_path_path_from_theme_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityThemeFilePathPathFromThemeData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_theme_file_path_path_from_theme_co (data);
}


static gboolean _unity_theme_file_path_path_from_theme_co_gsource_func (gpointer self) {
	gboolean result;
	result = unity_theme_file_path_path_from_theme_co (self);
	return result;
}


static gboolean unity_theme_file_path_path_from_theme_co (UnityThemeFilePathPathFromThemeData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		g_idle_add_full (G_PRIORITY_DEFAULT_IDLE, _unity_theme_file_path_path_from_theme_co_gsource_func, data, NULL);
		data->_state_ = 2;
		return FALSE;
		_state_2:
		;
		if (gtk_icon_theme_has_icon (data->theme, data->icon_name)) {
			data->info = gtk_icon_theme_lookup_icon (data->theme, data->icon_name, 48, 0);
			if (data->info != NULL) {
				data->filename = g_strdup (gtk_icon_info_get_filename (data->info));
				if (g_file_test (data->filename, G_FILE_TEST_IS_REGULAR)) {
					data->result = data->filename;
					_gtk_icon_info_free0 (data->info);
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
				_g_free0 (data->filename);
			}
			_gtk_icon_info_free0 (data->info);
		}
		data->result = g_strdup ("");
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


UnityThemeFilePath* unity_theme_file_path_construct (GType object_type) {
	UnityThemeFilePath * self;
	self = g_object_newv (object_type, 0, NULL);
	return self;
}


UnityThemeFilePath* unity_theme_file_path_new (void) {
	return unity_theme_file_path_construct (UNITY_TYPE_THEME_FILE_PATH);
}


static GObject * unity_theme_file_path_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityThemeFilePath * self;
	parent_class = G_OBJECT_CLASS (unity_theme_file_path_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_THEME_FILE_PATH (obj);
	{
		GeePriorityQueue* _tmp0_;
		self->priv->themes = (_tmp0_ = gee_priority_queue_new (GTK_TYPE_ICON_THEME, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->priv->themes), _tmp0_);
	}
	return obj;
}


static void unity_theme_file_path_class_init (UnityThemeFilePathClass * klass) {
	unity_theme_file_path_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityThemeFilePathPrivate));
	G_OBJECT_CLASS (klass)->constructor = unity_theme_file_path_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_theme_file_path_finalize;
	g_signal_new ("found_icon_path", UNITY_TYPE_THEME_FILE_PATH, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__STRING, G_TYPE_NONE, 1, G_TYPE_STRING);
	g_signal_new ("failed", UNITY_TYPE_THEME_FILE_PATH, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__VOID, G_TYPE_NONE, 0);
}


static void unity_theme_file_path_instance_init (UnityThemeFilePath * self) {
	self->priv = UNITY_THEME_FILE_PATH_GET_PRIVATE (self);
}


static void unity_theme_file_path_finalize (GObject* obj) {
	UnityThemeFilePath * self;
	self = UNITY_THEME_FILE_PATH (obj);
	_g_object_unref0 (self->priv->themes);
	G_OBJECT_CLASS (unity_theme_file_path_parent_class)->finalize (obj);
}


GType unity_theme_file_path_get_type (void) {
	static volatile gsize unity_theme_file_path_type_id__volatile = 0;
	if (g_once_init_enter (&unity_theme_file_path_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityThemeFilePathClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_theme_file_path_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityThemeFilePath), 0, (GInstanceInitFunc) unity_theme_file_path_instance_init, NULL };
		GType unity_theme_file_path_type_id;
		unity_theme_file_path_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityThemeFilePath", &g_define_type_info, 0);
		g_once_init_leave (&unity_theme_file_path_type_id__volatile, unity_theme_file_path_type_id);
	}
	return unity_theme_file_path_type_id__volatile;
}


gboolean unity_icon_name_exists_in_theme (const char* icon_name, const char* theme) {
	gboolean result = FALSE;
	GtkIconTheme* icontheme;
	g_return_val_if_fail (icon_name != NULL, FALSE);
	g_return_val_if_fail (theme != NULL, FALSE);
	icontheme = gtk_icon_theme_new ();
	gtk_icon_theme_set_custom_theme (icontheme, theme);
	result = gtk_icon_theme_has_icon (icontheme, icon_name);
	_g_object_unref0 (icontheme);
	return result;
}


UnityThemeImage* unity_theme_image_construct (GType object_type, const char* icon_name) {
	UnityThemeImage * self;
	g_return_val_if_fail (icon_name != NULL, NULL);
	self = (UnityThemeImage*) g_object_new (object_type, "icon-name", icon_name, NULL);
	return self;
}


UnityThemeImage* unity_theme_image_new (const char* icon_name) {
	return unity_theme_image_construct (UNITY_TYPE_THEME_IMAGE, icon_name);
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static void _lambda0_ (UnityThemeFilePath* theme, const char* filepath, UnityThemeImage* self) {
	GError * _inner_error_;
	g_return_if_fail (theme != NULL);
	g_return_if_fail (filepath != NULL);
	_inner_error_ = NULL;
	{
		clutter_texture_set_from_file ((ClutterTexture*) self, filepath, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch7_g_error;
		}
	}
	goto __finally7;
	__catch7_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning ("theme.vala:134: %s", _tmp0_ = g_strconcat ("could not load theme image ", string_to_string (filepath), NULL));
			_g_free0 (_tmp0_);
			_g_error_free0 (e);
		}
	}
	__finally7:
	if (_inner_error_ != NULL) {
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
}


static void __lambda0__unity_theme_file_path_found_icon_path (UnityThemeFilePath* _sender, const char* filepath, gpointer self) {
	_lambda0_ (_sender, filepath, self);
}


static gboolean unity_theme_image_try_load_icon_from_theme (UnityThemeImage* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	g_signal_connect_object (self->priv->theme, "found-icon-path", (GCallback) __lambda0__unity_theme_file_path_found_icon_path, self, 0);
	unity_theme_file_path_get_icon_filepath (self->priv->theme, self->priv->_icon_name, NULL, NULL);
	result = TRUE;
	return result;
}


static gboolean unity_theme_image_try_load_icon_from_dir (UnityThemeImage* self, const char* dir) {
	gboolean result = FALSE;
	GError * _inner_error_;
	char* filename;
	char* _tmp1_;
	char* _tmp0_;
	g_return_val_if_fail (self != NULL, FALSE);
	g_return_val_if_fail (dir != NULL, FALSE);
	_inner_error_ = NULL;
	filename = NULL;
	filename = (_tmp1_ = g_build_filename (dir, _tmp0_ = g_strconcat (self->priv->_icon_name, ".png", NULL), NULL), _g_free0 (filename), _tmp1_);
	_g_free0 (_tmp0_);
	{
		clutter_texture_set_from_file ((ClutterTexture*) self, filename, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch8_g_error;
		}
		result = TRUE;
		_g_free0 (filename);
		return result;
	}
	goto __finally8;
	__catch8_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			result = FALSE;
			_g_error_free0 (e);
			_g_free0 (filename);
			return result;
		}
	}
	__finally8:
	{
		_g_free0 (filename);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return FALSE;
	}
	_g_free0 (filename);
}


static gboolean unity_theme_image_try_load_icon_from_datadir (UnityThemeImage* self) {
	gboolean result = FALSE;
	g_return_val_if_fail (self != NULL, FALSE);
	if (!unity_theme_image_try_load_icon_from_dir (self, PKGDATADIR)) {
		if (!unity_theme_image_try_load_icon_from_dir (self, "/usr/share/unity/themes")) {
			if (!unity_theme_image_try_load_icon_from_dir (self, "/usr/share/unity/themes/launcher")) {
				result = FALSE;
				return result;
			}
		}
	}
	result = TRUE;
	return result;
}


static void unity_theme_image_load_missing_icon (UnityThemeImage* self) {
	g_return_if_fail (self != NULL);
	;
	g_warning ("theme.vala:186: Unable to load '%s' from Unity icon theme or Unity the" \
"me", self->priv->_icon_name);
}


const char* unity_theme_image_get_icon_name (UnityThemeImage* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_icon_name;
	return result;
}


void unity_theme_image_set_icon_name (UnityThemeImage* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_icon_name = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_icon_name), _tmp0_);
	g_object_notify ((GObject *) self, "icon-name");
}


static GObject * unity_theme_image_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityThemeImage * self;
	parent_class = G_OBJECT_CLASS (unity_theme_image_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_THEME_IMAGE (obj);
	{
		if (self->priv->theme == NULL) {
			UnityThemeFilePath* _tmp1_;
			GtkIconTheme* gtktheme;
			self->priv->theme = (_tmp1_ = unity_theme_file_path_new (), _g_object_unref0 (self->priv->theme), _tmp1_);
			gtktheme = gtk_icon_theme_new ();
			gtk_icon_theme_set_custom_theme (gtktheme, "unity-icon-theme");
			unity_theme_file_path_add_icon_theme (self->priv->theme, gtktheme);
			_g_object_unref0 (gtktheme);
		}
		if (!unity_theme_image_try_load_icon_from_datadir (self)) {
			if (!unity_theme_image_try_load_icon_from_theme (self)) {
				unity_theme_image_load_missing_icon (self);
			}
		}
	}
	return obj;
}


static void unity_theme_image_class_init (UnityThemeImageClass * klass) {
	unity_theme_image_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityThemeImagePrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_theme_image_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_theme_image_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_theme_image_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_theme_image_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_THEME_IMAGE_ICON_NAME, g_param_spec_string ("icon-name", "icon-name", "icon-name", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT));
}


static void unity_theme_image_instance_init (UnityThemeImage * self) {
	self->priv = UNITY_THEME_IMAGE_GET_PRIVATE (self);
	self->priv->theme = NULL;
}


static void unity_theme_image_finalize (GObject* obj) {
	UnityThemeImage * self;
	self = UNITY_THEME_IMAGE (obj);
	_g_object_unref0 (self->priv->theme);
	_g_free0 (self->priv->_icon_name);
	_g_object_unref0 (self->icon);
	G_OBJECT_CLASS (unity_theme_image_parent_class)->finalize (obj);
}


GType unity_theme_image_get_type (void) {
	static volatile gsize unity_theme_image_type_id__volatile = 0;
	if (g_once_init_enter (&unity_theme_image_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityThemeImageClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_theme_image_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityThemeImage), 0, (GInstanceInitFunc) unity_theme_image_instance_init, NULL };
		GType unity_theme_image_type_id;
		unity_theme_image_type_id = g_type_register_static (CLUTTER_TYPE_TEXTURE, "UnityThemeImage", &g_define_type_info, 0);
		g_once_init_leave (&unity_theme_image_type_id__volatile, unity_theme_image_type_id);
	}
	return unity_theme_image_type_id__volatile;
}


static void unity_theme_image_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityThemeImage * self;
	self = UNITY_THEME_IMAGE (object);
	switch (property_id) {
		case UNITY_THEME_IMAGE_ICON_NAME:
		g_value_set_string (value, unity_theme_image_get_icon_name (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_theme_image_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityThemeImage * self;
	self = UNITY_THEME_IMAGE (object);
	switch (property_id) {
		case UNITY_THEME_IMAGE_ICON_NAME:
		unity_theme_image_set_icon_name (self, g_value_get_string (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
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




