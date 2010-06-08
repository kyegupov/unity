/* places-model.c generated by valac, the Vala compiler
 * generated from places-model.vala, do not modify */

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
#include <gee.h>


#define UNITY_PLACES_TYPE_MODEL (unity_places_model_get_type ())
#define UNITY_PLACES_MODEL(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModel))
#define UNITY_PLACES_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))
#define UNITY_PLACES_IS_MODEL(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_IS_MODEL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_MODEL))
#define UNITY_PLACES_MODEL_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_MODEL, UnityPlacesModelClass))

typedef struct _UnityPlacesModel UnityPlacesModel;
typedef struct _UnityPlacesModelClass UnityPlacesModelClass;
typedef struct _UnityPlacesModelPrivate UnityPlacesModelPrivate;

#define UNITY_PLACES_TYPE_PLACE (unity_places_place_get_type ())
#define UNITY_PLACES_PLACE(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlace))
#define UNITY_PLACES_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))
#define UNITY_PLACES_IS_PLACE(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_IS_PLACE_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_PLACES_TYPE_PLACE))
#define UNITY_PLACES_PLACE_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_PLACES_TYPE_PLACE, UnityPlacesPlaceClass))

typedef struct _UnityPlacesPlace UnityPlacesPlace;
typedef struct _UnityPlacesPlaceClass UnityPlacesPlaceClass;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityPlacesModel {
	GObject parent_instance;
	UnityPlacesModelPrivate * priv;
	GeeArrayList* list;
};

struct _UnityPlacesModelClass {
	GObjectClass parent_class;
};


static gpointer unity_places_model_parent_class = NULL;

GType unity_places_model_get_type (void);
GType unity_places_place_get_type (void);
enum  {
	UNITY_PLACES_MODEL_DUMMY_PROPERTY
};
UnityPlacesModel* unity_places_model_new (void);
UnityPlacesModel* unity_places_model_construct (GType object_type);
void unity_places_model_add (UnityPlacesModel* self, UnityPlacesPlace* place);
void unity_places_model_remove (UnityPlacesModel* self, UnityPlacesPlace* place);
static GObject * unity_places_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_places_model_finalize (GObject* obj);



#line 38 "places-model.vala"
UnityPlacesModel* unity_places_model_construct (GType object_type) {
#line 80 "places-model.c"
	UnityPlacesModel * self;
#line 40 "places-model.vala"
	self = (UnityPlacesModel*) g_object_new (object_type, NULL);
#line 84 "places-model.c"
	return self;
}


#line 38 "places-model.vala"
UnityPlacesModel* unity_places_model_new (void) {
#line 38 "places-model.vala"
	return unity_places_model_construct (UNITY_PLACES_TYPE_MODEL);
#line 93 "places-model.c"
}


#line 48 "places-model.vala"
void unity_places_model_add (UnityPlacesModel* self, UnityPlacesPlace* place) {
#line 48 "places-model.vala"
	g_return_if_fail (self != NULL);
#line 48 "places-model.vala"
	g_return_if_fail (place != NULL);
#line 50 "places-model.vala"
	gee_abstract_collection_add ((GeeAbstractCollection*) self->list, place);
#line 52 "places-model.vala"
	g_signal_emit_by_name (self, "place-added", place);
#line 107 "places-model.c"
}


#line 55 "places-model.vala"
void unity_places_model_remove (UnityPlacesModel* self, UnityPlacesPlace* place) {
#line 55 "places-model.vala"
	g_return_if_fail (self != NULL);
#line 55 "places-model.vala"
	g_return_if_fail (place != NULL);
#line 57 "places-model.vala"
	gee_abstract_collection_remove ((GeeAbstractCollection*) self->list, place);
#line 59 "places-model.vala"
	g_signal_emit_by_name (self, "place-removed", place);
#line 121 "places-model.c"
}


static GObject * unity_places_model_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityPlacesModel * self;
	parent_class = G_OBJECT_CLASS (unity_places_model_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_PLACES_MODEL (obj);
	{
		GeeArrayList* _tmp0_;
#line 45 "places-model.vala"
		self->list = (_tmp0_ = gee_array_list_new (UNITY_PLACES_TYPE_PLACE, (GBoxedCopyFunc) g_object_ref, g_object_unref, NULL), _g_object_unref0 (self->list), _tmp0_);
#line 136 "places-model.c"
	}
	return obj;
}


static void unity_places_model_class_init (UnityPlacesModelClass * klass) {
	unity_places_model_parent_class = g_type_class_peek_parent (klass);
	G_OBJECT_CLASS (klass)->constructor = unity_places_model_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_places_model_finalize;
	g_signal_new ("place_added", UNITY_PLACES_TYPE_MODEL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE);
	g_signal_new ("place_removed", UNITY_PLACES_TYPE_MODEL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE);
	g_signal_new ("place_changed", UNITY_PLACES_TYPE_MODEL, G_SIGNAL_RUN_LAST, 0, NULL, NULL, g_cclosure_marshal_VOID__OBJECT, G_TYPE_NONE, 1, UNITY_PLACES_TYPE_PLACE);
}


static void unity_places_model_instance_init (UnityPlacesModel * self) {
}


static void unity_places_model_finalize (GObject* obj) {
	UnityPlacesModel * self;
	self = UNITY_PLACES_MODEL (obj);
	_g_object_unref0 (self->list);
	G_OBJECT_CLASS (unity_places_model_parent_class)->finalize (obj);
}


GType unity_places_model_get_type (void) {
	static volatile gsize unity_places_model_type_id__volatile = 0;
	if (g_once_init_enter (&unity_places_model_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityPlacesModelClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_places_model_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityPlacesModel), 0, (GInstanceInitFunc) unity_places_model_instance_init, NULL };
		GType unity_places_model_type_id;
		unity_places_model_type_id = g_type_register_static (G_TYPE_OBJECT, "UnityPlacesModel", &g_define_type_info, 0);
		g_once_init_leave (&unity_places_model_type_id__volatile, unity_places_model_type_id);
	}
	return unity_places_model_type_id__volatile;
}




