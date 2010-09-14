/* unity-expanding-bin.c generated by valac 0.9.8, the Vala compiler
 * generated from unity-expanding-bin.vala, do not modify */

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
  <http://www.gnu.org/licenses/>.
 *
 * Authored by Neil Jagdish Patel <neil.patel@canonical.com>
 */

#include <glib.h>
#include <glib-object.h>
#include <clutk/clutk.h>
#include <float.h>
#include <math.h>
#include <clutter/clutter.h>
#include <string.h>


#define UNITY_TYPE_EXPANDING_BIN_STATE (unity_expanding_bin_state_get_type ())

#define UNITY_TYPE_EXPANDING_BIN (unity_expanding_bin_get_type ())
#define UNITY_EXPANDING_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_EXPANDING_BIN, UnityExpandingBin))
#define UNITY_EXPANDING_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_EXPANDING_BIN, UnityExpandingBinClass))
#define UNITY_IS_EXPANDING_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_EXPANDING_BIN))
#define UNITY_IS_EXPANDING_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_EXPANDING_BIN))
#define UNITY_EXPANDING_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_EXPANDING_BIN, UnityExpandingBinClass))

typedef struct _UnityExpandingBin UnityExpandingBin;
typedef struct _UnityExpandingBinClass UnityExpandingBinClass;
typedef struct _UnityExpandingBinPrivate UnityExpandingBinPrivate;
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

typedef enum  {
	UNITY_EXPANDING_BIN_STATE_CLOSED,
	UNITY_EXPANDING_BIN_STATE_UNEXPANDED,
	UNITY_EXPANDING_BIN_STATE_EXPANDED
} UnityExpandingBinState;

struct _UnityExpandingBin {
	CtkBin parent_instance;
	UnityExpandingBinPrivate * priv;
};

struct _UnityExpandingBinClass {
	CtkBinClass parent_class;
};

struct _UnityExpandingBinPrivate {
	float _size_factor;
	UnityExpandingBinState _state;
	UnityExpandingBinState _old_state;
	float _unexpanded_height;
	float _expanded_height;
	float _target_height;
	float last_height;
	float last_width;
};


static gpointer unity_expanding_bin_parent_class = NULL;

GType unity_expanding_bin_state_get_type (void) G_GNUC_CONST;
GType unity_expanding_bin_get_type (void) G_GNUC_CONST;
#define UNITY_EXPANDING_BIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_EXPANDING_BIN, UnityExpandingBinPrivate))
enum  {
	UNITY_EXPANDING_BIN_DUMMY_PROPERTY,
	UNITY_EXPANDING_BIN_SIZE_FACTOR,
	UNITY_EXPANDING_BIN_BIN_STATE,
	UNITY_EXPANDING_BIN_UNEXPANDED_HEIGHT
};
#define UNITY_EXPANDING_BIN_ANIMATION_TIME 500
UnityExpandingBin* unity_expanding_bin_new (void);
UnityExpandingBin* unity_expanding_bin_construct (GType object_type);
static void unity_expanding_bin_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_expanding_bin_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height);
static void _unity_expanding_bin_change_state (UnityExpandingBin* self, UnityExpandingBinState new_state);
static void _lambda2_ (UnityExpandingBin* self);
static void __lambda2__clutter_animation_completed (ClutterAnimation* _sender, gpointer self);
float unity_expanding_bin_get_size_factor (UnityExpandingBin* self);
void unity_expanding_bin_set_size_factor (UnityExpandingBin* self, float value);
UnityExpandingBinState unity_expanding_bin_get_bin_state (UnityExpandingBin* self);
void unity_expanding_bin_set_bin_state (UnityExpandingBin* self, UnityExpandingBinState value);
float unity_expanding_bin_get_unexpanded_height (UnityExpandingBin* self);
void unity_expanding_bin_set_unexpanded_height (UnityExpandingBin* self, float value);
static GObject * unity_expanding_bin_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_expanding_bin_finalize (GObject* obj);
static void unity_expanding_bin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);
static void unity_expanding_bin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec);



GType unity_expanding_bin_state_get_type (void) {
	static volatile gsize unity_expanding_bin_state_type_id__volatile = 0;
	if (g_once_init_enter (&unity_expanding_bin_state_type_id__volatile)) {
		static const GEnumValue values[] = {{UNITY_EXPANDING_BIN_STATE_CLOSED, "UNITY_EXPANDING_BIN_STATE_CLOSED", "closed"}, {UNITY_EXPANDING_BIN_STATE_UNEXPANDED, "UNITY_EXPANDING_BIN_STATE_UNEXPANDED", "unexpanded"}, {UNITY_EXPANDING_BIN_STATE_EXPANDED, "UNITY_EXPANDING_BIN_STATE_EXPANDED", "expanded"}, {0, NULL, NULL}};
		GType unity_expanding_bin_state_type_id;
		unity_expanding_bin_state_type_id = g_enum_register_static ("UnityExpandingBinState", values);
		g_once_init_leave (&unity_expanding_bin_state_type_id__volatile, unity_expanding_bin_state_type_id);
	}
	return unity_expanding_bin_state_type_id__volatile;
}


UnityExpandingBin* unity_expanding_bin_construct (GType object_type) {
	UnityExpandingBin * self;
	self = (UnityExpandingBin*) g_object_new (object_type, NULL);
	return self;
}


UnityExpandingBin* unity_expanding_bin_new (void) {
	return unity_expanding_bin_construct (UNITY_TYPE_EXPANDING_BIN);
}


static void unity_expanding_bin_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityExpandingBin * self;
	CtkPadding _tmp0_ = {0};
	float x;
	CtkPadding _tmp1_ = {0};
	float y;
	CtkPadding _tmp2_ = {0};
	CtkPadding _tmp3_ = {0};
	float width;
	ClutterActorBox child_box = {0};
	CtkPadding _tmp4_ = {0};
	self = (UnityExpandingBin*) base;
	x = (ctk_actor_get_padding ((CtkActor*) self, &_tmp0_), _tmp0_.left);
	y = (ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_.top);
	width = (floorf ((*box).x2 - (*box).x1) - (ctk_actor_get_padding ((CtkActor*) self, &_tmp2_), _tmp2_.left)) - (ctk_actor_get_padding ((CtkActor*) self, &_tmp3_), _tmp3_.right);
	memset (&child_box, 0, sizeof (ClutterActorBox));
	child_box.x1 = x;
	child_box.x2 = x + width;
	child_box.y1 = y;
	child_box.y2 = (y + self->priv->last_height) + (((self->priv->_target_height - self->priv->last_height) + (ctk_actor_get_padding ((CtkActor*) self, &_tmp4_), _tmp4_.bottom)) * self->priv->_size_factor);
	if (child_box.y2 < 0.0f) {
		child_box.y2 = 0.0f;
	}
	CLUTTER_ACTOR_CLASS (unity_expanding_bin_parent_class)->allocate ((ClutterActor*) CTK_BIN (self), box, flags);
	clutter_actor_allocate (ctk_bin_get_child ((CtkBin*) self), &child_box, flags);
	self->priv->last_height = child_box.y2 - child_box.y1;
	self->priv->last_width = child_box.x2 - child_box.x1;
}


static void unity_expanding_bin_real_get_preferred_height (ClutterActor* base, float for_width, float* min_height, float* nat_height) {
	UnityExpandingBin * self;
	CtkPadding _tmp0_ = {0};
	CtkPadding _tmp1_ = {0};
	float vpadding;
	self = (UnityExpandingBin*) base;
	vpadding = (ctk_actor_get_padding ((CtkActor*) self, &_tmp0_), _tmp0_.top) + (ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_.bottom);
	clutter_actor_get_preferred_height (ctk_bin_get_child ((CtkBin*) self), self->priv->last_width, NULL, &self->priv->_expanded_height);
	if (self->priv->_state == UNITY_EXPANDING_BIN_STATE_CLOSED) {
		self->priv->_target_height = 0.0f;
	} else {
		if (self->priv->_state == UNITY_EXPANDING_BIN_STATE_UNEXPANDED) {
			self->priv->_target_height = self->priv->_unexpanded_height + vpadding;
		} else {
			self->priv->_target_height = self->priv->_expanded_height + vpadding;
		}
	}
	*min_height = self->priv->last_height + ((self->priv->_target_height - self->priv->last_height) * self->priv->_size_factor);
	*nat_height = self->priv->last_height + ((self->priv->_target_height - self->priv->last_height) * self->priv->_size_factor);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void _lambda2_ (UnityExpandingBin* self) {
	if (self->priv->_state == UNITY_EXPANDING_BIN_STATE_CLOSED) {
		clutter_actor_hide ((ClutterActor*) self);
	}
}


static void __lambda2__clutter_animation_completed (ClutterAnimation* _sender, gpointer self) {
	_lambda2_ (self);
}


static void _unity_expanding_bin_change_state (UnityExpandingBin* self, UnityExpandingBinState new_state) {
	g_return_if_fail (self != NULL);
	if (self->priv->_state == new_state) {
		return;
	}
	self->priv->_old_state = self->priv->_state;
	self->priv->_state = new_state;
	self->priv->_size_factor = 0.0f;
	switch (self->priv->_state) {
		case UNITY_EXPANDING_BIN_STATE_CLOSED:
		{
			ClutterAnimation* anim;
			anim = _g_object_ref0 (clutter_actor_animate ((ClutterActor*) self, (gulong) CLUTTER_EASE_OUT_QUAD, (guint) UNITY_EXPANDING_BIN_ANIMATION_TIME, "size_factor", 1.0f, "opacity", 0, NULL));
			self->priv->_target_height = 0.0f;
			g_signal_connect_object (anim, "completed", (GCallback) __lambda2__clutter_animation_completed, self, 0);
			_g_object_unref0 (anim);
			break;
		}
		case UNITY_EXPANDING_BIN_STATE_UNEXPANDED:
		{
			ClutterAnimationMode _tmp0_ = 0;
			if (self->priv->_old_state == UNITY_EXPANDING_BIN_STATE_CLOSED) {
				_tmp0_ = CLUTTER_EASE_IN_QUAD;
			} else {
				_tmp0_ = CLUTTER_EASE_OUT_QUAD;
			}
			clutter_actor_animate ((ClutterActor*) self, (gulong) _tmp0_, (guint) UNITY_EXPANDING_BIN_ANIMATION_TIME, "size_factor", 1.0f, "opacity", 255, NULL);
			self->priv->_target_height = self->priv->_unexpanded_height;
			clutter_actor_show ((ClutterActor*) self);
			break;
		}
		case UNITY_EXPANDING_BIN_STATE_EXPANDED:
		{
			clutter_actor_animate ((ClutterActor*) self, (gulong) CLUTTER_EASE_IN_QUAD, (guint) UNITY_EXPANDING_BIN_ANIMATION_TIME, "size_factor", 1.0f, "opacity", 255, NULL);
			clutter_actor_get_preferred_height (ctk_bin_get_child ((CtkBin*) self), clutter_actor_get_width ((ClutterActor*) self), NULL, &self->priv->_expanded_height);
			self->priv->_target_height = self->priv->_expanded_height;
			clutter_actor_show ((ClutterActor*) self);
			break;
		}
		default:
		{
			g_warning ("unity-expanding-bin.vala:177: ExpandingBinState %d not supported", (gint) self->priv->_state);
			break;
		}
	}
}


float unity_expanding_bin_get_size_factor (UnityExpandingBin* self) {
	float result;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = self->priv->_size_factor;
	return result;
}


void unity_expanding_bin_set_size_factor (UnityExpandingBin* self, float value) {
	g_return_if_fail (self != NULL);
	self->priv->_size_factor = value;
	clutter_actor_queue_relayout ((ClutterActor*) self);
	g_object_notify ((GObject *) self, "size-factor");
}


UnityExpandingBinState unity_expanding_bin_get_bin_state (UnityExpandingBin* self) {
	UnityExpandingBinState result;
	g_return_val_if_fail (self != NULL, 0);
	result = self->priv->_state;
	return result;
}


void unity_expanding_bin_set_bin_state (UnityExpandingBin* self, UnityExpandingBinState value) {
	g_return_if_fail (self != NULL);
	_unity_expanding_bin_change_state (self, value);
	g_object_notify ((GObject *) self, "bin-state");
}


float unity_expanding_bin_get_unexpanded_height (UnityExpandingBin* self) {
	float result;
	g_return_val_if_fail (self != NULL, 0.0F);
	result = self->priv->_unexpanded_height;
	return result;
}


void unity_expanding_bin_set_unexpanded_height (UnityExpandingBin* self, float value) {
	g_return_if_fail (self != NULL);
	if (self->priv->_unexpanded_height != value) {
		self->priv->_unexpanded_height = value;
		if (self->priv->_state == UNITY_EXPANDING_BIN_STATE_UNEXPANDED) {
			self->priv->_state = UNITY_EXPANDING_BIN_STATE_CLOSED;
			_unity_expanding_bin_change_state (self, UNITY_EXPANDING_BIN_STATE_UNEXPANDED);
		}
	}
	g_object_notify ((GObject *) self, "unexpanded-height");
}


static GObject * unity_expanding_bin_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityExpandingBin * self;
	parent_class = G_OBJECT_CLASS (unity_expanding_bin_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_EXPANDING_BIN (obj);
	{
	}
	return obj;
}


static void unity_expanding_bin_class_init (UnityExpandingBinClass * klass) {
	unity_expanding_bin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityExpandingBinPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_expanding_bin_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_expanding_bin_real_get_preferred_height;
	G_OBJECT_CLASS (klass)->get_property = unity_expanding_bin_get_property;
	G_OBJECT_CLASS (klass)->set_property = unity_expanding_bin_set_property;
	G_OBJECT_CLASS (klass)->constructor = unity_expanding_bin_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_expanding_bin_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_EXPANDING_BIN_SIZE_FACTOR, g_param_spec_float ("size-factor", "size-factor", "size-factor", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_EXPANDING_BIN_BIN_STATE, g_param_spec_enum ("bin-state", "bin-state", "bin-state", UNITY_TYPE_EXPANDING_BIN_STATE, 0, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_EXPANDING_BIN_UNEXPANDED_HEIGHT, g_param_spec_float ("unexpanded-height", "unexpanded-height", "unexpanded-height", -G_MAXFLOAT, G_MAXFLOAT, 0.0F, G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE | G_PARAM_WRITABLE));
}


static void unity_expanding_bin_instance_init (UnityExpandingBin * self) {
	self->priv = UNITY_EXPANDING_BIN_GET_PRIVATE (self);
	self->priv->_size_factor = 0.0f;
	self->priv->_state = UNITY_EXPANDING_BIN_STATE_CLOSED;
	self->priv->_old_state = UNITY_EXPANDING_BIN_STATE_CLOSED;
	self->priv->_unexpanded_height = 100.0f;
	self->priv->_expanded_height = 0.0f;
	self->priv->_target_height = 0.0f;
}


static void unity_expanding_bin_finalize (GObject* obj) {
	UnityExpandingBin * self;
	self = UNITY_EXPANDING_BIN (obj);
	G_OBJECT_CLASS (unity_expanding_bin_parent_class)->finalize (obj);
}


GType unity_expanding_bin_get_type (void) {
	static volatile gsize unity_expanding_bin_type_id__volatile = 0;
	if (g_once_init_enter (&unity_expanding_bin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityExpandingBinClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_expanding_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityExpandingBin), 0, (GInstanceInitFunc) unity_expanding_bin_instance_init, NULL };
		GType unity_expanding_bin_type_id;
		unity_expanding_bin_type_id = g_type_register_static (CTK_TYPE_BIN, "UnityExpandingBin", &g_define_type_info, 0);
		g_once_init_leave (&unity_expanding_bin_type_id__volatile, unity_expanding_bin_type_id);
	}
	return unity_expanding_bin_type_id__volatile;
}


static void unity_expanding_bin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityExpandingBin * self;
	self = UNITY_EXPANDING_BIN (object);
	switch (property_id) {
		case UNITY_EXPANDING_BIN_SIZE_FACTOR:
		g_value_set_float (value, unity_expanding_bin_get_size_factor (self));
		break;
		case UNITY_EXPANDING_BIN_BIN_STATE:
		g_value_set_enum (value, unity_expanding_bin_get_bin_state (self));
		break;
		case UNITY_EXPANDING_BIN_UNEXPANDED_HEIGHT:
		g_value_set_float (value, unity_expanding_bin_get_unexpanded_height (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}


static void unity_expanding_bin_set_property (GObject * object, guint property_id, const GValue * value, GParamSpec * pspec) {
	UnityExpandingBin * self;
	self = UNITY_EXPANDING_BIN (object);
	switch (property_id) {
		case UNITY_EXPANDING_BIN_SIZE_FACTOR:
		unity_expanding_bin_set_size_factor (self, g_value_get_float (value));
		break;
		case UNITY_EXPANDING_BIN_BIN_STATE:
		unity_expanding_bin_set_bin_state (self, g_value_get_enum (value));
		break;
		case UNITY_EXPANDING_BIN_UNEXPANDED_HEIGHT:
		unity_expanding_bin_set_unexpanded_height (self, g_value_get_float (value));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




