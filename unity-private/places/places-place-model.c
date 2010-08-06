/* places-place-model.c generated by valac, the Vala compiler
 * generated from places-place-model.vala, do not modify */

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
#include <gee.h>
#include <stdlib.h>
#include <string.h>
#include <config.h>
#include <gio/gio.h>


#define UNITY_PLACES_TYPE_PLACE_MODEL (unity_places_place_model_get_type ())
#define UNITY_PLACES_PLACE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModel))
#define UNITY_PLACES_PLACE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModelClass))
#define UNITY_PLACES_IS_PLACE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_MODEL))
#define UNITY_PLACES_IS_PLACE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_MODEL))
#define UNITY_PLACES_PLACE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_MODEL, UnityPlacesPlaceModelClass))

typedef struct _UnityPlacesPlaceModel UnityPlacesPlaceModel;
typedef struct _UnityPlacesPlaceModelClass UnityPlacesPlaceModelClass;
typedef struct _UnityPlacesPlaceModelPrivate UnityPlacesPlaceModelPrivate;

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;

#define UNITY_PLACES_TYPE_PLACE_FILE_MODEL (unity_places_place_file_model_get_type ())
#define UNITY_PLACES_PLACE_FILE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModel))
#define UNITY_PLACES_PLACE_FILE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModelClass))
#define UNITY_PLACES_IS_PLACE_FILE_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE_FILE_MODEL))
#define UNITY_PLACES_IS_PLACE_FILE_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE_FILE_MODEL))
#define UNITY_PLACES_PLACE_FILE_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModelClass))

typedef struct _UnityPlacesPlaceFileModel UnityPlacesPlaceFileModel;
typedef struct _UnityPlacesPlaceFileModelClass UnityPlacesPlaceFileModelClass;
typedef struct _UnityPlacesPlaceFileModelPrivate UnityPlacesPlaceFileModelPrivate;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityPlacesPlaceFileModelLoadPlaceFilesData UnityPlacesPlaceFileModelLoadPlaceFilesData;
#define _g_key_file_free0(var) ((var == NULL) ? NULL : (var = (g_key_file_free (var), NULL)))

struct _UnityPlacesPlaceModel {
	GeeArrayList parent_instance;
	UnityPlacesPlaceModelPrivate * priv;
};

struct _UnityPlacesPlaceModelClass {
	GeeArrayListClass parent_class;
};

struct _UnityPlacesPlaceFileModel {
	UnityPlacesPlaceModel parent_instance;
	UnityPlacesPlaceFileModelPrivate * priv;
};

struct _UnityPlacesPlaceFileModelClass {
	UnityPlacesPlaceModelClass parent_class;
};

struct _UnityPlacesPlaceFileModelPrivate {
	char* _directory;
	gboolean _async;
};

struct _UnityPlacesPlaceFileModelLoadPlaceFilesData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	UnityPlacesPlaceFileModel* self;
	GFile* dir;
	GFileEnumerator* e;
	GList* files;
	UnityPlacesPlace* place;
	char* _tmp0_;
	UnityPlacesPlace* _tmp1_;
	UnityPlacesPlace* _tmp2_;
	GList* info_collection;
	GList* info_it;
	GFileInfo* info;
	char* _tmp3_;
	GError * _error_;
	GError * _inner_error_;
};


static gpointer unity_places_place_model_parent_class = NULL;
static gpointer unity_places_place_file_model_parent_class = NULL;

GType unity_places_place_model_get_type (void) G_GNUC_CONST;
enum  {
	UNITY_PLACES_PLACE_MODEL_DUMMY_PROPERTY
};
GType unity_places_place_get_type (void) G_GNUC_CONST;
UnityPlacesPlaceModel* unity_places_place_model_construct (GType object_type);
GType unity_places_place_file_model_get_type (void) G_GNUC_CONST;
#define UNITY_PLACES_PLACE_FILE_MODEL_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_PLACES_TYPE_PLACE_FILE_MODEL, UnityPlacesPlaceFileModelPrivate))
enum  {
	UNITY_PLACES_PLACE_FILE_MODEL_DUMMY_PROPERTY,
	UNITY_PLACES_PLACE_FILE_MODEL_DIRECTORY,
	UNITY_PLACES_PLACE_FILE_MODEL_ASYNC
};
UnityPlacesPlaceFileModel* unity_places_place_file_model_new (void);
UnityPlacesPlaceFileModel* unity_places_place_file_model_construct (GType object_type);
UnityPlacesPlaceFileModel* unity_places_place_file_model_new_with_directory (const char* _directory);
UnityPlacesPlaceFileModel* unity_places_place_file_model_construct_with_directory (GType object_type, const char* _directory);
static void unity_places_place_file_model_load_place_files_data_free (gpointer _data);
static void unity_places_place_file_model_load_place_files_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
const char* unity_places_place_file_model_get_directory (UnityPlacesPlaceFileModel* self);
static void _g_list_free_g_object_unref (GList* self);
static UnityPlacesPlace* unity_places_place_file_model_load_place (UnityPlacesPlaceFileModel* self, const char* path);
void unity_places_place_connect (UnityPlacesPlace* self);
gboolean unity_places_place_get_online (UnityPlacesPlace* self);
static void unity_places_place_file_model_load_place_files (UnityPlacesPlaceFileModel* self, GAsyncReadyCallback _callback_, gpointer _user_data_);
static void unity_places_place_file_model_load_place_files_finish (UnityPlacesPlaceFileModel* self, GAsyncResult* _res_);
static gboolean unity_places_place_file_model_load_place_files_co (UnityPlacesPlaceFileModelLoadPlaceFilesData* data);
static void unity_places_place_file_model_load_place_files_sync (UnityPlacesPlaceFileModel* self);
UnityPlacesPlace* unity_places_place_new_from_keyfile (GKeyFile* file, const char* id);
static void unity_places_place_file_model_set_directory (UnityPlacesPlaceFileModel* self, const char* value);
gboolean unity_places_place_file_model_get_async (UnityPlacesPlaceFileModel* self);
static void unity_places_place_file_model_set_async (UnityPlacesPlaceFileModel* self, gboolean value);
static GObject * unity_places_place_file_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_place_file_model_finalize (GObject* obj);
static void unity_places_place_file_model_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_places_place_file_model_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



UnityPlacesPlaceModel* unity_places_place_model_construct (GType object_type) {
	UnityPlacesPlaceModel * self;
	self = (UnityPlacesPlaceModel*) gee_array_list_construct (object_type, UNITY_PLACES_TYPE_PLACE, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL);
	return self;
}


static void unity_places_place_model_class_init (UnityPlacesPlaceModelClass * klass) {
	unity_places_place_model_parent_class = g_type_class_peek_parent (klass);
	g_signal_new ("place_added", UNITY_PLACES_TYPE_PLACE_MODEL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE);
}


static void unity_places_place_model_instance_init (UnityPlacesPlaceModel * self) {
}


/**
   * PlaceModel:
   *
   * Contains the loaded Place objects. Abstract class so views can be
   * tested with fake model
   **/
GType unity_places_place_model_get_type (void) {
	static volatile gsize unity_places_place_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceModel), 0, (GInstanceInitFunc) unity_places_place_model_instance_init, NULL };
		GType unity_places_place_model_type_id;
		unity_places_place_model_type_id = g_type_register_static (GEE_TYPE_ARRAY_LIST, "UnityPlacesPlaceModel", &g_define_type_info, G_TYPE_FLAG_ABSTRACT);
		g_once_init_leave (&unity_places_place_model_type_id__volatile, unity_places_place_model_type_id);
	}
	return unity_places_place_model_type_id__volatile;
}


UnityPlacesPlaceFileModel* unity_places_place_file_model_construct (GType object_type) {
	UnityPlacesPlaceFileModel * self;
	self = (UnityPlacesPlaceFileModel*) g_object_new (object_type, "directory", PKGDATADIR "/places", "async", TRUE, NULL);
	return self;
}


UnityPlacesPlaceFileModel* unity_places_place_file_model_new (void) {
	return unity_places_place_file_model_construct (UNITY_PLACES_TYPE_PLACE_FILE_MODEL);
}


UnityPlacesPlaceFileModel* unity_places_place_file_model_construct_with_directory (GType object_type, const char* _directory) {
	UnityPlacesPlaceFileModel * self;
	g_return_val_if_fail (_directory != NULL, NULL);
	self = (UnityPlacesPlaceFileModel*) g_object_new (object_type, "directory", _directory, "async", FALSE, NULL);
	return self;
}


UnityPlacesPlaceFileModel* unity_places_place_file_model_new_with_directory (const char* _directory) {
	return unity_places_place_file_model_construct_with_directory (UNITY_PLACES_TYPE_PLACE_FILE_MODEL, _directory);
}


static void unity_places_place_file_model_load_place_files_data_free (gpointer _data) {
	UnityPlacesPlaceFileModelLoadPlaceFilesData* data;
	data = _data;
	g_object_unref (data->self);
	g_slice_free (UnityPlacesPlaceFileModelLoadPlaceFilesData, data);
}


static void unity_places_place_file_model_load_place_files (UnityPlacesPlaceFileModel* self, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityPlacesPlaceFileModelLoadPlaceFilesData* _data_;
	_data_ = g_slice_new0 (UnityPlacesPlaceFileModelLoadPlaceFilesData);
	_data_->_async_result = g_simple_async_result_new (G_OBJECT (self), _callback_, _user_data_, unity_places_place_file_model_load_place_files);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_places_place_file_model_load_place_files_data_free);
	_data_->self = g_object_ref (self);
	unity_places_place_file_model_load_place_files_co (_data_);
}


static void unity_places_place_file_model_load_place_files_finish (UnityPlacesPlaceFileModel* self, GAsyncResult* _res_) {
	UnityPlacesPlaceFileModelLoadPlaceFilesData* _data_;
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
}


static void unity_places_place_file_model_load_place_files_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityPlacesPlaceFileModelLoadPlaceFilesData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_places_place_file_model_load_place_files_co (data);
}


static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static const char* string_to_string (const char* self) {
	const char* result = NULL;
	g_return_val_if_fail (self != NULL, NULL);
	result = self;
	return result;
}


static gboolean unity_places_place_file_model_load_place_files_co (UnityPlacesPlaceFileModelLoadPlaceFilesData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 1:
		goto _state_1;
		case 2:
		goto _state_2;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->dir = g_file_new_for_path (data->self->priv->_directory);
		{
			data->_state_ = 1;
			g_file_enumerate_children_async (data->dir, G_FILE_ATTRIBUTE_STANDARD_NAME, 0, G_PRIORITY_DEFAULT, NULL, unity_places_place_file_model_load_place_files_ready, data);
			return FALSE;
			_state_1:
			data->e = g_file_enumerate_children_finish (data->dir, data->_res_, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				goto __catch14_g_error;
			}
			while (TRUE) {
				data->_state_ = 2;
				g_file_enumerator_next_files_async (data->e, 10, G_PRIORITY_DEFAULT, NULL, unity_places_place_file_model_load_place_files_ready, data);
				return FALSE;
				_state_2:
				data->files = g_file_enumerator_next_files_finish (data->e, data->_res_, &data->_inner_error_);
				if (data->_inner_error_ != NULL) {
					_g_object_unref0 (data->e);
					goto __catch14_g_error;
				}
				if (data->files == NULL) {
					__g_list_free_g_object_unref0 (data->files);
					break;
				}
				{
					data->info_collection = data->files;
					for (data->info_it = data->info_collection; data->info_it != NULL; data->info_it = data->info_it->next) {
						data->info = _g_object_ref0 ((GFileInfo*) data->info_it->data);
						{
							if (g_str_has_suffix (g_file_info_get_name (data->info), ".place") == FALSE) {
								_g_object_unref0 (data->info);
								continue;
							}
							data->place = (data->_tmp1_ = unity_places_place_file_model_load_place (data->self, data->_tmp0_ = g_build_filename (data->self->priv->_directory, g_file_info_get_name (data->info), NULL)), _g_free0 (data->_tmp0_), data->_tmp1_);
							if (UNITY_PLACES_IS_PLACE (data->place)) {
								unity_places_place_connect (data->place);
								if (unity_places_place_get_online (data->place) == TRUE) {
									g_object_ref ((data->_tmp2_ = data->place, G_IS_OBJECT (data->_tmp2_) ? ((GObject*) data->_tmp2_) : NULL));
									gee_abstract_collection_add ((GeeAbstractCollection*) data->self, data->place);
									g_signal_emit_by_name ((UnityPlacesPlaceModel*) data->self, "place-added", data->place);
								}
							}
							_g_object_unref0 (data->place);
							_g_object_unref0 (data->info);
						}
					}
				}
				__g_list_free_g_object_unref0 (data->files);
			}
			_g_object_unref0 (data->e);
		}
		goto __finally14;
		__catch14_g_error:
		{
			data->_error_ = data->_inner_error_;
			data->_inner_error_ = NULL;
			{
				g_warning (data->_tmp3_ = g_strconcat ("Unable to read place files from directory '", string_to_string (data->self->priv->_directory), "': %s", NULL), data->_error_->message);
				_g_free0 (data->_tmp3_);
				_g_error_free0 (data->_error_);
			}
		}
		__finally14:
		if (data->_inner_error_ != NULL) {
			_g_object_unref0 (data->dir);
			g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, data->_inner_error_->message, g_quark_to_string (data->_inner_error_->domain), data->_inner_error_->code);
			g_clear_error (&data->_inner_error_);
			return FALSE;
		}
		_g_object_unref0 (data->dir);
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


static void unity_places_place_file_model_load_place_files_sync (UnityPlacesPlaceFileModel* self) {
	GError * _inner_error_;
	GFile* dir;
	g_return_if_fail (self != NULL);
	_inner_error_ = NULL;
	dir = g_file_new_for_path (self->priv->_directory);
	{
		GFileEnumerator* e;
		GFileInfo* info;
		e = g_file_enumerate_children (dir, G_FILE_ATTRIBUTE_STANDARD_NAME, 0, NULL, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch15_g_error;
		}
		info = NULL;
		while (TRUE) {
			GFileInfo* _tmp0_;
			GFileInfo* _tmp1_;
			char* leaf;
			char* _tmp2_;
			UnityPlacesPlace* _tmp3_;
			UnityPlacesPlace* place;
			_tmp0_ = g_file_enumerator_next_file (e, NULL, &_inner_error_);
			if (_inner_error_ != NULL) {
				_g_object_unref0 (info);
				_g_object_unref0 (e);
				goto __catch15_g_error;
			}
			if (!((info = (_tmp1_ = _tmp0_, _g_object_unref0 (info), _tmp1_)) != NULL)) {
				break;
			}
			leaf = g_strdup (g_file_info_get_name (info));
			if (g_str_has_suffix (leaf, ".place") == FALSE) {
				_g_free0 (leaf);
				continue;
			}
			place = (_tmp3_ = unity_places_place_file_model_load_place (self, _tmp2_ = g_build_filename (self->priv->_directory, leaf, NULL)), _g_free0 (_tmp2_), _tmp3_);
			if (UNITY_PLACES_IS_PLACE (place)) {
				gee_abstract_collection_add ((GeeAbstractCollection*) self, place);
				g_signal_emit_by_name ((UnityPlacesPlaceModel*) self, "place-added", place);
			}
			_g_object_unref0 (place);
			_g_free0 (leaf);
		}
		_g_object_unref0 (info);
		_g_object_unref0 (e);
	}
	goto __finally15;
	__catch15_g_error:
	{
		GError * _error_;
		_error_ = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp4_;
			g_warning (_tmp4_ = g_strconcat ("Unable to read place files from directory '", string_to_string (self->priv->_directory), "': %s", NULL), _error_->message);
			_g_free0 (_tmp4_);
			_g_error_free0 (_error_);
		}
	}
	__finally15:
	if (_inner_error_ != NULL) {
		_g_object_unref0 (dir);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return;
	}
	_g_object_unref0 (dir);
}


static UnityPlacesPlace* unity_places_place_file_model_load_place (UnityPlacesPlaceFileModel* self, const char* path) {
	UnityPlacesPlace* result = NULL;
	GError * _inner_error_;
	GKeyFile* file;
	g_return_val_if_fail (self != NULL, NULL);
	g_return_val_if_fail (path != NULL, NULL);
	_inner_error_ = NULL;
	file = g_key_file_new ();
	{
		g_key_file_load_from_file (file, path, G_KEY_FILE_NONE, &_inner_error_);
		if (_inner_error_ != NULL) {
			goto __catch16_g_error;
		}
		result = unity_places_place_new_from_keyfile (file, path);
		_g_key_file_free0 (file);
		return result;
	}
	goto __finally16;
	__catch16_g_error:
	{
		GError * e;
		e = _inner_error_;
		_inner_error_ = NULL;
		{
			char* _tmp0_;
			g_warning (_tmp0_ = g_strconcat ("Unable to load place file '", string_to_string (path), "': %s", NULL), e->message);
			_g_free0 (_tmp0_);
			result = NULL;
			_g_error_free0 (e);
			_g_key_file_free0 (file);
			return result;
		}
	}
	__finally16:
	{
		_g_key_file_free0 (file);
		g_critical ("file %s: line %d: uncaught error: %s (%s, %d)", __FILE__, __LINE__, _inner_error_->message, g_quark_to_string (_inner_error_->domain), _inner_error_->code);
		g_clear_error (&_inner_error_);
		return NULL;
	}
	_g_key_file_free0 (file);
}


const char* unity_places_place_file_model_get_directory (UnityPlacesPlaceFileModel* self) {
	const char* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_directory;
	return result;
}


static void unity_places_place_file_model_set_directory (UnityPlacesPlaceFileModel* self, const char* value) {
	char* _tmp0_;
	g_return_if_fail (self != NULL);
	self->priv->_directory = (_tmp0_ = g_strdup (value), _g_free0 (self->priv->_directory), _tmp0_);
	g_object_notify ((GObject *) self, "directory");
}


gboolean unity_places_place_file_model_get_async (UnityPlacesPlaceFileModel* self) {
	gboolean result;
	g_return_val_if_fail (self != NULL, FALSE);
	result = self->priv->_async;
	return result;
}


static void unity_places_place_file_model_set_async (UnityPlacesPlaceFileModel* self, gboolean value) {
	g_return_if_fail (self != NULL);
	self->priv->_async = value;
	g_object_notify ((GObject *) self, "async");
}


static GObject * unity_places_place_file_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesPlaceFileModel * self;
	parent_class = G_OBJECT_CLASS (unity_places_place_file_model_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_PLACE_FILE_MODEL (obj);
	{
		if (self->priv->_async) {
			unity_places_place_file_model_load_place_files (self, NULL, NULL);
		} else {
			unity_places_place_file_model_load_place_files_sync (self);
		}
	}
	return obj;
}


static void unity_places_place_file_model_class_init (UnityPlacesPlaceFileModelClass * klass) {
	unity_places_place_file_model_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityPlacesPlaceFileModelPrivate));
	G_OBJECT_CLASS (klass)->get_property = unity_places_place_file_model_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_places_place_file_model_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_places_place_file_model_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_place_file_model_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_FILE_MODEL_DIRECTORY, g_param_spec_string ("directory", "directory", "directory", NULL, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_PLACES_PLACE_FILE_MODEL_ASYNC, g_param_spec_boolean ("async", "async", "async", FALSE, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY));
}


static void unity_places_place_file_model_instance_init (UnityPlacesPlaceFileModel * self) {
	self->priv = UNITY_PLACES_PLACE_FILE_MODEL_GET_PRIVATE (self);
}


static void unity_places_place_file_model_finalize (GObject* obj) {
	UnityPlacesPlaceFileModel * self;
	self = UNITY_PLACES_PLACE_FILE_MODEL (obj);
	_g_free0 (self->priv->_directory);
	G_OBJECT_CLASS (unity_places_place_file_model_parent_class)->finalize (obj);
}


/**
   * PlaceFileModel:
   *
   * Reads in .place files and creates the offline model, ready for representing
   * to the user without actually initing any of the places
   **/
GType unity_places_place_file_model_get_type (void) {
	static volatile gsize unity_places_place_file_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_place_file_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesPlaceFileModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_place_file_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesPlaceFileModel), 0, (GInstanceInitFunc) unity_places_place_file_model_instance_init, NULL };
		GType unity_places_place_file_model_type_id;
		unity_places_place_file_model_type_id = g_type_register_static (UNITY_PLACES_TYPE_PLACE_MODEL, "UnityPlacesPlaceFileModel", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_place_file_model_type_id__volatile, unity_places_place_file_model_type_id);
	}
	return unity_places_place_file_model_type_id__volatile;
}


static void unity_places_place_file_model_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceFileModel * self;
	self = UNITY_PLACES_PLACE_FILE_MODEL (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_FILE_MODEL_DIRECTORY:
		g_value_set_string (value, unity_places_place_file_model_get_directory (self));
		break;
		case UNITY_PLACES_PLACE_FILE_MODEL_ASYNC:
		g_value_set_boolean (value, unity_places_place_file_model_get_async (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_places_place_file_model_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityPlacesPlaceFileModel * self;
	self = UNITY_PLACES_PLACE_FILE_MODEL (object);
	switch (property_id) {
		case UNITY_PLACES_PLACE_FILE_MODEL_DIRECTORY:
		unity_places_place_file_model_set_directory (self, g_value_get_string (value));
		break;
		case UNITY_PLACES_PLACE_FILE_MODEL_ASYNC:
		unity_places_place_file_model_set_async (self, g_value_get_boolean (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




