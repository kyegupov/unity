/* unity-io.c generated by valac, the Vala compiler
 * generated from unity-io.vala, do not modify */

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
 * Authored by Mikkel Kamstrup Erlandsen <mikkel.kamstrup@canonical.com>
 *
 */
/*
 * IMPLEMENTATION NOTE:
 * We want the generatedd C API to be nice and not too Vala-ish. We must
 * anticipate that place daemons consuming libunity will be written in
 * both Vala and C.
 *
 */

#include <glib.h>
#include <glib-object.h>
#include <gio/gio.h>
#include <stdlib.h>
#include <string.h>

#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))
typedef struct _UnityIoReadStreamAsyncData UnityIoReadStreamAsyncData;
#define _g_free0(var) (var = (g_free (var), NULL))
#define _g_error_free0(var) ((var == NULL) ? NULL : (var = (g_error_free (var), NULL)))
typedef struct _UnityIoOpenFromDirsData UnityIoOpenFromDirsData;
typedef struct _UnityIoOpenFromDataDirsData UnityIoOpenFromDataDirsData;

struct _UnityIoReadStreamAsyncData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	GInputStream* input;
	guchar* buffer;
	gint buffer_length1;
	gsize buffer_lenght;
	gint io_priority;
	GCancellable* cancellable;
	void* data;
	gsize size;
	gsize numread;
	gsize numwritten;
	GMemoryOutputStream* output;
	gssize _tmp0_;
	GError * _inner_error_;
};

struct _UnityIoOpenFromDirsData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	char* filename;
	char** dirs;
	gint dirs_length1;
	GFileInputStream* result;
	char* path;
	GFile* datafile;
	char* _tmp0_;
	GFile* _tmp1_;
	GFileInputStream* _tmp2_;
	GError * ee;
	char** dir_collection;
	int dir_collection_length1;
	int dir_it;
	char* dir;
	GError * _inner_error_;
};

struct _UnityIoOpenFromDataDirsData {
	int _state_;
	GAsyncResult* _res_;
	GSimpleAsyncResult* _async_result;
	char* filename;
	GFileInputStream* result;
	char* path;
	GFile* f;
	GFileInputStream* _tmp0_;
	GError * e;
	char** dirs;
	gint _tmp1_;
	char** _tmp2_;
	gint _dirs_size_;
	gint dirs_length1;
	GFileInputStream* _tmp3_;
	GError * _inner_error_;
};


extern char** unity_io_system_data_dirs;
extern gint unity_io_system_data_dirs_length1;
char** unity_io_system_data_dirs = NULL;
gint unity_io_system_data_dirs_length1 = 0;
static gint _unity_io_system_data_dirs_size_ = 0;

static void unity_io_read_stream_async_data_free (gpointer _data);
static void unity_io_read_stream_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
static void* _g_realloc_grealloc_func (void* data, gsize size);
void unity_io_read_stream_async (GInputStream* input, guchar* buffer, int buffer_length1, gsize buffer_lenght, gint io_priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_);
void unity_io_read_stream_finish (GAsyncResult* _res_, void** data, gsize* size, GError** error);
static gboolean unity_io_read_stream_async_co (UnityIoReadStreamAsyncData* data);
static void unity_io_open_from_dirs_data_free (gpointer _data);
static char** _vala_array_dup2 (char** self, int length);
static void unity_io_open_from_dirs_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
void unity_io_open_from_dirs (const char* filename, char** dirs, int dirs_length1, GAsyncReadyCallback _callback_, gpointer _user_data_);
GFileInputStream* unity_io_open_from_dirs_finish (GAsyncResult* _res_, GError** error);
static gboolean unity_io_open_from_dirs_co (UnityIoOpenFromDirsData* data);
static void unity_io_open_from_data_dirs_data_free (gpointer _data);
static void unity_io_open_from_data_dirs_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_);
char** unity_io_get_system_data_dirs (int* result_length1);
void unity_io_open_from_data_dirs (const char* filename, GAsyncReadyCallback _callback_, gpointer _user_data_);
GFileInputStream* unity_io_open_from_data_dirs_finish (GAsyncResult* _res_, GError** error);
static gboolean unity_io_open_from_data_dirs_co (UnityIoOpenFromDataDirsData* data);
static char** _vala_array_dup3 (char** self, int length);
static void _vala_array_destroy (gpointer array, gint array_length, GDestroyNotify destroy_func);
static void _vala_array_free (gpointer array, gint array_length, GDestroyNotify destroy_func);
static gint _vala_array_length (gpointer array);



static void unity_io_read_stream_async_data_free (gpointer _data) {
	UnityIoReadStreamAsyncData* data;
	data = _data;
	_g_object_unref0 (data->input);
	data->buffer = (g_free (data->buffer), NULL);
	_g_object_unref0 (data->cancellable);
	g_slice_free (UnityIoReadStreamAsyncData, data);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


void unity_io_read_stream_async (GInputStream* input, guchar* buffer, int buffer_length1, gsize buffer_lenght, gint io_priority, GCancellable* cancellable, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityIoReadStreamAsyncData* _data_;
	_data_ = g_slice_new0 (UnityIoReadStreamAsyncData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, unity_io_read_stream_async);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_io_read_stream_async_data_free);
	_data_->input = _g_object_ref0 (input);
	_data_->buffer = buffer;
	_data_->buffer_length1 = buffer_length1;
	_data_->buffer_lenght = buffer_lenght;
	_data_->io_priority = io_priority;
	_data_->cancellable = _g_object_ref0 (cancellable);
	unity_io_read_stream_async_co (_data_);
}


void unity_io_read_stream_finish (GAsyncResult* _res_, void** data, gsize* size, GError** error) {
	UnityIoReadStreamAsyncData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	*data = _data_->data;
	_data_->data = NULL;
	*size = _data_->size;
}


static void unity_io_read_stream_async_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityIoReadStreamAsyncData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_io_read_stream_async_co (data);
}


static void* _g_realloc_grealloc_func (void* data, gsize size) {
	void* result;
	result = g_realloc (data, size);
	return result;
}


static gboolean unity_io_read_stream_async_co (UnityIoReadStreamAsyncData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 5:
		goto _state_5;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->output = (GMemoryOutputStream*) g_memory_output_stream_new (NULL, (gsize) 0, _g_realloc_grealloc_func, NULL);
		while (TRUE) {
			data->_state_ = 5;
			g_input_stream_read_async (data->input, data->buffer, data->buffer_lenght, data->io_priority, data->cancellable, unity_io_read_stream_async_ready, data);
			return FALSE;
			_state_5:
			data->_tmp0_ = g_input_stream_read_finish (data->input, data->_res_, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
				g_error_free (data->_inner_error_);
				_g_object_unref0 (data->output);
				data->buffer = (g_free (data->buffer), NULL);
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
			data->numread = (gsize) data->_tmp0_;
			if (data->numread <= 0) {
				break;
			}
			g_output_stream_write_all ((GOutputStream*) data->output, data->buffer, data->numread, &data->numwritten, NULL, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
				g_error_free (data->_inner_error_);
				_g_object_unref0 (data->output);
				data->buffer = (g_free (data->buffer), NULL);
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
		}
		data->data = g_memory_output_stream_get_data (data->output);
		data->size = g_memory_output_stream_get_data_size (data->output);
		g_input_stream_close_async (data->input, G_PRIORITY_DEFAULT, NULL, NULL, NULL);
		g_output_stream_close ((GOutputStream*) data->output, NULL, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_object_unref0 (data->output);
			data->buffer = (g_free (data->buffer), NULL);
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
		_g_object_unref0 (data->output);
		data->buffer = (g_free (data->buffer), NULL);
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


static void unity_io_open_from_dirs_data_free (gpointer _data) {
	UnityIoOpenFromDirsData* data;
	data = _data;
	_g_free0 (data->filename);
	data->dirs = (_vala_array_free (data->dirs, data->dirs_length1, (GDestroyNotify) g_free), NULL);
	_g_object_unref0 (data->result);
	g_slice_free (UnityIoOpenFromDirsData, data);
}


static char** _vala_array_dup2 (char** self, int length) {
	char** result;
	int i;
	result = g_new0 (char*, length + 1);
	for (i = 0; i < length; i++) {
		result[i] = g_strdup (self[i]);
	}
	return result;
}


void unity_io_open_from_dirs (const char* filename, char** dirs, int dirs_length1, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityIoOpenFromDirsData* _data_;
	char** _tmp0_;
	_data_ = g_slice_new0 (UnityIoOpenFromDirsData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, unity_io_open_from_dirs);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_io_open_from_dirs_data_free);
	_data_->filename = g_strdup (filename);
	_data_->dirs = (_tmp0_ = dirs, (_tmp0_ == NULL) ? ((gpointer) _tmp0_) : _vala_array_dup2 (_tmp0_, dirs_length1));
	_data_->dirs_length1 = dirs_length1;
	unity_io_open_from_dirs_co (_data_);
}


GFileInputStream* unity_io_open_from_dirs_finish (GAsyncResult* _res_, GError** error) {
	GFileInputStream* result;
	UnityIoOpenFromDirsData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void unity_io_open_from_dirs_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityIoOpenFromDirsData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_io_open_from_dirs_co (data);
}


static gpointer _g_error_copy0 (gpointer self) {
	return self ? g_error_copy (self) : NULL;
}


static gboolean unity_io_open_from_dirs_co (UnityIoOpenFromDirsData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 6:
		goto _state_6;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		{
			data->dir_collection = data->dirs;
			data->dir_collection_length1 = data->dirs_length1;
			for (data->dir_it = 0; data->dir_it < data->dirs_length1; data->dir_it = data->dir_it + 1) {
				data->dir = g_strdup (data->dir_collection[data->dir_it]);
				{
					data->path = (data->_tmp0_ = g_build_filename (data->dir, data->filename, NULL, NULL), _g_free0 (data->path), data->_tmp0_);
					data->datafile = (data->_tmp1_ = g_file_new_for_path (data->path), _g_object_unref0 (data->datafile), data->_tmp1_);
					{
						data->_state_ = 6;
						g_file_read_async (data->datafile, G_PRIORITY_DEFAULT, NULL, unity_io_open_from_dirs_ready, data);
						return FALSE;
						_state_6:
						data->_tmp2_ = g_file_read_finish (data->datafile, data->_res_, &data->_inner_error_);
						if (data->_inner_error_ != NULL) {
							goto __catch25_g_error;
						}
						data->result = data->_tmp2_;
						_g_free0 (data->dir);
						_g_free0 (data->path);
						_g_object_unref0 (data->datafile);
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
					goto __finally25;
					__catch25_g_error:
					{
						data->ee = data->_inner_error_;
						data->_inner_error_ = NULL;
						{
							if (!g_error_matches (data->ee, G_IO_ERROR, G_IO_ERROR_NOT_FOUND)) {
								data->_inner_error_ = _g_error_copy0 (data->ee);
								{
									_g_error_free0 (data->ee);
									_g_free0 (data->dir);
									_g_free0 (data->path);
									_g_object_unref0 (data->datafile);
									goto __finally25;
								}
							}
							_g_error_free0 (data->ee);
						}
					}
					__finally25:
					if (data->_inner_error_ != NULL) {
						g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
						g_error_free (data->_inner_error_);
						_g_free0 (data->dir);
						_g_free0 (data->path);
						_g_object_unref0 (data->datafile);
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
					_g_free0 (data->dir);
				}
			}
		}
		data->result = NULL;
		_g_free0 (data->path);
		_g_object_unref0 (data->datafile);
		{
			if (data->_state_ == 0) {
				g_simple_async_result_complete_in_idle (data->_async_result);
			} else {
				g_simple_async_result_complete (data->_async_result);
			}
			g_object_unref (data->_async_result);
			return FALSE;
		}
		_g_free0 (data->path);
		_g_object_unref0 (data->datafile);
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


static void unity_io_open_from_data_dirs_data_free (gpointer _data) {
	UnityIoOpenFromDataDirsData* data;
	data = _data;
	_g_free0 (data->filename);
	_g_object_unref0 (data->result);
	g_slice_free (UnityIoOpenFromDataDirsData, data);
}


void unity_io_open_from_data_dirs (const char* filename, GAsyncReadyCallback _callback_, gpointer _user_data_) {
	UnityIoOpenFromDataDirsData* _data_;
	_data_ = g_slice_new0 (UnityIoOpenFromDataDirsData);
	_data_->_async_result = g_simple_async_result_new (g_object_newv (G_TYPE_OBJECT, 0, NULL), _callback_, _user_data_, unity_io_open_from_data_dirs);
	g_simple_async_result_set_op_res_gpointer (_data_->_async_result, _data_, unity_io_open_from_data_dirs_data_free);
	_data_->filename = g_strdup (filename);
	unity_io_open_from_data_dirs_co (_data_);
}


GFileInputStream* unity_io_open_from_data_dirs_finish (GAsyncResult* _res_, GError** error) {
	GFileInputStream* result;
	UnityIoOpenFromDataDirsData* _data_;
	if (g_simple_async_result_propagate_error (G_SIMPLE_ASYNC_RESULT (_res_), error)) {
		return NULL;
	}
	_data_ = g_simple_async_result_get_op_res_gpointer (G_SIMPLE_ASYNC_RESULT (_res_));
	result = _data_->result;
	_data_->result = NULL;
	return result;
}


static void unity_io_open_from_data_dirs_ready (GObject* source_object, GAsyncResult* _res_, gpointer _user_data_) {
	UnityIoOpenFromDataDirsData* data;
	data = _user_data_;
	data->_res_ = _res_;
	unity_io_open_from_data_dirs_co (data);
}


static gboolean unity_io_open_from_data_dirs_co (UnityIoOpenFromDataDirsData* data) {
	switch (data->_state_) {
		case 0:
		goto _state_0;
		case 7:
		goto _state_7;
		case 8:
		goto _state_8;
		default:
		g_assert_not_reached ();
	}
	_state_0:
	{
		data->path = g_build_filename (g_get_user_data_dir (), data->filename, NULL, NULL);
		data->f = g_file_new_for_path (data->path);
		{
			data->_state_ = 7;
			g_file_read_async (data->f, G_PRIORITY_DEFAULT, NULL, unity_io_open_from_data_dirs_ready, data);
			return FALSE;
			_state_7:
			data->_tmp0_ = g_file_read_finish (data->f, data->_res_, &data->_inner_error_);
			if (data->_inner_error_ != NULL) {
				goto __catch26_g_error;
			}
			data->result = data->_tmp0_;
			_g_free0 (data->path);
			_g_object_unref0 (data->f);
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
		goto __finally26;
		__catch26_g_error:
		{
			data->e = data->_inner_error_;
			data->_inner_error_ = NULL;
			{
				if (!g_error_matches (data->e, G_IO_ERROR, G_IO_ERROR_NOT_FOUND)) {
					data->_inner_error_ = _g_error_copy0 (data->e);
					{
						_g_error_free0 (data->e);
						_g_free0 (data->path);
						_g_object_unref0 (data->f);
						goto __finally26;
					}
				}
				_g_error_free0 (data->e);
			}
		}
		__finally26:
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_free0 (data->path);
			_g_object_unref0 (data->f);
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
		data->dirs = (data->_tmp2_ = unity_io_get_system_data_dirs (&data->_tmp1_), data->dirs_length1 = data->_tmp1_, data->_dirs_size_ = data->dirs_length1, data->_tmp2_);
		data->_state_ = 8;
		unity_io_open_from_dirs (data->filename, data->dirs, data->dirs_length1, unity_io_open_from_data_dirs_ready, data);
		return FALSE;
		_state_8:
		data->_tmp3_ = unity_io_open_from_dirs_finish (data->_res_, &data->_inner_error_);
		if (data->_inner_error_ != NULL) {
			g_simple_async_result_set_from_error (data->_async_result, data->_inner_error_);
			g_error_free (data->_inner_error_);
			_g_free0 (data->path);
			_g_object_unref0 (data->f);
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
		data->result = data->_tmp3_;
		_g_free0 (data->path);
		_g_object_unref0 (data->f);
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
		_g_free0 (data->path);
		_g_object_unref0 (data->f);
		data->dirs = (_vala_array_free (data->dirs, data->dirs_length1, (GDestroyNotify) g_free), NULL);
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


static char** _vala_array_dup3 (char** self, int length) {
	char** result;
	int i;
	result = g_new0 (char*, length + 1);
	for (i = 0; i < length; i++) {
		result[i] = g_strdup (self[i]);
	}
	return result;
}


char** unity_io_get_system_data_dirs (int* result_length1) {
	char** result = NULL;
	char** _tmp2_;
	char** _tmp3_;
	if (unity_io_system_data_dirs == NULL) {
		char** _tmp1_;
		char** _tmp0_;
		unity_io_system_data_dirs = (_tmp1_ = _tmp0_ = g_strsplit (g_getenv ("XDG_DATA_DIRS"), ":", 0), unity_io_system_data_dirs = (_vala_array_free (unity_io_system_data_dirs, unity_io_system_data_dirs_length1, (GDestroyNotify) g_free), NULL), unity_io_system_data_dirs_length1 = _vala_array_length (_tmp0_), _unity_io_system_data_dirs_size_ = unity_io_system_data_dirs_length1, _tmp1_);
	}
	result = (_tmp3_ = (_tmp2_ = unity_io_system_data_dirs, (_tmp2_ == NULL) ? ((gpointer) _tmp2_) : _vala_array_dup3 (_tmp2_, unity_io_system_data_dirs_length1)), *result_length1 = unity_io_system_data_dirs_length1, _tmp3_);
	return result;
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


static gint _vala_array_length (gpointer array) {
	int length;
	length = 0;
	if (array) {
		while (((gpointer*) array)[length]) {
			length++;
		}
	}
	return length;
}




