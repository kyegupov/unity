/* unity-layered-bin.c generated by valac 0.9.8, the Vala compiler
 * generated from unity-layered-bin.vala, do not modify */

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
#include <clutk/clutk.h>
#include <clutter/clutter.h>
#include <string.h>
#include <float.h>
#include <math.h>


#define UNITY_TYPE_LAYERED_BIN (unity_layered_bin_get_type ())
#define UNITY_LAYERED_BIN(obj) (G_TYPE_CHECK_INSTANCE_CAST ((obj), UNITY_TYPE_LAYERED_BIN, UnityLayeredBin))
#define UNITY_LAYERED_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST ((klass), UNITY_TYPE_LAYERED_BIN, UnityLayeredBinClass))
#define UNITY_IS_LAYERED_BIN(obj) (G_TYPE_CHECK_INSTANCE_TYPE ((obj), UNITY_TYPE_LAYERED_BIN))
#define UNITY_IS_LAYERED_BIN_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), UNITY_TYPE_LAYERED_BIN))
#define UNITY_LAYERED_BIN_GET_CLASS(obj) (G_TYPE_INSTANCE_GET_CLASS ((obj), UNITY_TYPE_LAYERED_BIN, UnityLayeredBinClass))

typedef struct _UnityLayeredBin UnityLayeredBin;
typedef struct _UnityLayeredBinClass UnityLayeredBinClass;
typedef struct _UnityLayeredBinPrivate UnityLayeredBinPrivate;
#define __g_list_free_g_object_unref0(var) ((var == NULL) ? NULL : (var = (_g_list_free_g_object_unref (var), NULL)))
#define _g_object_unref0(var) ((var == NULL) ? NULL : (var = (g_object_unref (var), NULL)))

struct _UnityLayeredBin {
	CtkActor parent_instance;
	UnityLayeredBinPrivate * priv;
};

struct _UnityLayeredBinClass {
	CtkActorClass parent_class;
};

struct _UnityLayeredBinPrivate {
	GList* _children;
};


static gpointer unity_layered_bin_parent_class = NULL;
static ClutterContainerIface* unity_layered_bin_clutter_container_parent_iface = NULL;

GType unity_layered_bin_get_type (void) G_GNUC_CONST;
#define UNITY_LAYERED_BIN_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), UNITY_TYPE_LAYERED_BIN, UnityLayeredBinPrivate))
enum  {
	UNITY_LAYERED_BIN_DUMMY_PROPERTY,
	UNITY_LAYERED_BIN_CHILDREN
};
static void _g_list_free_g_object_unref (GList* self);
UnityLayeredBin* unity_layered_bin_new (void);
UnityLayeredBin* unity_layered_bin_construct (GType object_type);
static void unity_layered_bin_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags);
static void unity_layered_bin_real_get_preferred_width (ClutterActor* base, float for_height, float* mwidth, float* nwidth);
static void unity_layered_bin_real_get_preferred_height (ClutterActor* base, float for_width, float* mheight, float* nheight);
static void unity_layered_bin_real_paint (ClutterActor* base);
static void unity_layered_bin_real_pick (ClutterActor* base, const ClutterColor* color);
static void unity_layered_bin_real_add (ClutterContainer* base, ClutterActor* actor);
static void unity_layered_bin_real_remove (ClutterContainer* base, ClutterActor* actor);
static void unity_layered_bin_real_foreach (ClutterContainer* base, ClutterCallback callback, void* data);
static void unity_layered_bin_real_foreach_with_internals (ClutterContainer* base, ClutterCallback callback, void* data);
static void unity_layered_bin_real_raise (ClutterContainer* base, ClutterActor* actor, ClutterActor* sibling);
static void unity_layered_bin_real_lower (ClutterContainer* base, ClutterActor* actor, ClutterActor* sibling);
static void unity_layered_bin_real_sort_depth_order (ClutterContainer* base);
static void unity_layered_bin_real_create_child_meta (ClutterContainer* base, ClutterActor* actor);
static void unity_layered_bin_real_destroy_child_meta (ClutterContainer* base, ClutterActor* actor);
static ClutterChildMeta* unity_layered_bin_real_get_child_meta (ClutterContainer* base, ClutterActor* actor);
GList* unity_layered_bin_get_children (UnityLayeredBin* self);
static GObject * unity_layered_bin_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties);
static void unity_layered_bin_finalize (GObject* obj);
static void unity_layered_bin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec);



static void _g_list_free_g_object_unref (GList* self) {
	g_list_foreach (self, (GFunc) g_object_unref, NULL);
	g_list_free (self);
}


UnityLayeredBin* unity_layered_bin_construct (GType object_type) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) g_object_new (object_type, NULL);
	return self;
}


UnityLayeredBin* unity_layered_bin_new (void) {
	return unity_layered_bin_construct (UNITY_TYPE_LAYERED_BIN);
}


static gpointer _g_object_ref0 (gpointer self) {
	return self ? g_object_ref (self) : NULL;
}


static void unity_layered_bin_real_allocate (ClutterActor* base, const ClutterActorBox* box, ClutterAllocationFlags flags) {
	UnityLayeredBin * self;
	ClutterActorBox child_box = {0};
	CtkPadding _tmp0_ = {0};
	CtkPadding _tmp1_ = {0};
	CtkPadding _tmp2_ = {0};
	CtkPadding _tmp3_ = {0};
	CtkPadding _tmp4_ = {0};
	CtkPadding _tmp5_ = {0};
	self = (UnityLayeredBin*) base;
	memset (&child_box, 0, sizeof (ClutterActorBox));
	child_box.x1 = (ctk_actor_get_padding ((CtkActor*) self, &_tmp0_), _tmp0_.left);
	child_box.x2 = (((*box).x2 - (*box).x1) - (ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_.left)) - (ctk_actor_get_padding ((CtkActor*) self, &_tmp2_), _tmp2_.right);
	child_box.y1 = (ctk_actor_get_padding ((CtkActor*) self, &_tmp3_), _tmp3_.top);
	child_box.y2 = (((*box).y2 - (*box).y1) - (ctk_actor_get_padding ((CtkActor*) self, &_tmp4_), _tmp4_.top)) - (ctk_actor_get_padding ((CtkActor*) self, &_tmp5_), _tmp5_.bottom);
	CLUTTER_ACTOR_CLASS (unity_layered_bin_parent_class)->allocate ((ClutterActor*) CTK_ACTOR (self), box, flags);
	{
		GList* child_collection;
		GList* child_it;
		child_collection = self->priv->_children;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			ClutterActor* child;
			child = _g_object_ref0 ((ClutterActor*) child_it->data);
			{
				clutter_actor_allocate (child, &child_box, flags);
				_g_object_unref0 (child);
			}
		}
	}
}


static void unity_layered_bin_real_get_preferred_width (ClutterActor* base, float for_height, float* mwidth, float* nwidth) {
	UnityLayeredBin * self;
	CtkPadding _tmp0_ = {0};
	CtkPadding _tmp1_ = {0};
	CtkPadding _tmp2_ = {0};
	CtkPadding _tmp3_ = {0};
	self = (UnityLayeredBin*) base;
	{
		GList* child_collection;
		GList* child_it;
		child_collection = self->priv->_children;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			ClutterActor* child;
			child = _g_object_ref0 ((ClutterActor*) child_it->data);
			{
				float m;
				float n;
				m = 0.0f;
				n = 0.0f;
				clutter_actor_get_preferred_width (child, for_height, &m, &n);
				*mwidth = fmaxf (m, *mwidth);
				*nwidth = fmaxf (n, *nwidth);
				_g_object_unref0 (child);
			}
		}
	}
	*mwidth = (*mwidth) + ((ctk_actor_get_padding ((CtkActor*) self, &_tmp0_), _tmp0_.left) + (ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_.right));
	*nwidth = (*nwidth) + ((ctk_actor_get_padding ((CtkActor*) self, &_tmp2_), _tmp2_.left) + (ctk_actor_get_padding ((CtkActor*) self, &_tmp3_), _tmp3_.right));
}


static void unity_layered_bin_real_get_preferred_height (ClutterActor* base, float for_width, float* mheight, float* nheight) {
	UnityLayeredBin * self;
	CtkPadding _tmp0_ = {0};
	CtkPadding _tmp1_ = {0};
	CtkPadding _tmp2_ = {0};
	CtkPadding _tmp3_ = {0};
	self = (UnityLayeredBin*) base;
	{
		GList* child_collection;
		GList* child_it;
		child_collection = self->priv->_children;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			ClutterActor* child;
			child = _g_object_ref0 ((ClutterActor*) child_it->data);
			{
				float m;
				float n;
				m = 0.0f;
				n = 0.0f;
				clutter_actor_get_preferred_height (child, for_width, &m, &n);
				*mheight = fmaxf (m, *mheight);
				*nheight = fmaxf (n, *nheight);
				_g_object_unref0 (child);
			}
		}
	}
	*mheight = (*mheight) + ((ctk_actor_get_padding ((CtkActor*) self, &_tmp0_), _tmp0_.top) + (ctk_actor_get_padding ((CtkActor*) self, &_tmp1_), _tmp1_.bottom));
	*nheight = (*nheight) + ((ctk_actor_get_padding ((CtkActor*) self, &_tmp2_), _tmp2_.top) + (ctk_actor_get_padding ((CtkActor*) self, &_tmp3_), _tmp3_.bottom));
}


static void unity_layered_bin_real_paint (ClutterActor* base) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	CLUTTER_ACTOR_CLASS (unity_layered_bin_parent_class)->paint ((ClutterActor*) CTK_ACTOR (self));
	{
		GList* child_collection;
		GList* child_it;
		child_collection = self->priv->_children;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			ClutterActor* child;
			child = _g_object_ref0 ((ClutterActor*) child_it->data);
			{
				clutter_actor_paint (child);
				_g_object_unref0 (child);
			}
		}
	}
}


static void unity_layered_bin_real_pick (ClutterActor* base, const ClutterColor* color) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	CLUTTER_ACTOR_CLASS (unity_layered_bin_parent_class)->pick ((ClutterActor*) CTK_ACTOR (self), color);
	{
		GList* child_collection;
		GList* child_it;
		child_collection = self->priv->_children;
		for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
			ClutterActor* child;
			child = _g_object_ref0 ((ClutterActor*) child_it->data);
			{
				clutter_actor_paint (child);
				_g_object_unref0 (child);
			}
		}
	}
}


static void unity_layered_bin_real_add (ClutterContainer* base, ClutterActor* actor) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	g_return_if_fail (actor != NULL);
	clutter_actor_set_parent (actor, (ClutterActor*) self);
	self->priv->_children = g_list_append (self->priv->_children, _g_object_ref0 (actor));
	clutter_actor_queue_relayout ((ClutterActor*) self);
	g_signal_emit_by_name ((ClutterContainer*) self, "actor-added", actor);
}


static void unity_layered_bin_real_remove (ClutterContainer* base, ClutterActor* actor) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	g_return_if_fail (actor != NULL);
	clutter_actor_unparent (actor);
	self->priv->_children = g_list_remove (self->priv->_children, actor);
	clutter_actor_queue_relayout ((ClutterActor*) self);
	g_signal_emit_by_name ((ClutterContainer*) self, "actor-removed", actor);
}


static void unity_layered_bin_real_foreach (ClutterContainer* base, ClutterCallback callback, void* data) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	{
		GList* actor_collection;
		GList* actor_it;
		actor_collection = self->priv->_children;
		for (actor_it = actor_collection; actor_it != NULL; actor_it = actor_it->next) {
			ClutterActor* actor;
			actor = _g_object_ref0 ((ClutterActor*) actor_it->data);
			{
				callback (actor, data);
				_g_object_unref0 (actor);
			}
		}
	}
}


static void unity_layered_bin_real_foreach_with_internals (ClutterContainer* base, ClutterCallback callback, void* data) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	clutter_container_foreach ((ClutterContainer*) self, callback, data);
}


static void unity_layered_bin_real_raise (ClutterContainer* base, ClutterActor* actor, ClutterActor* sibling) {
	UnityLayeredBin * self;
	gboolean _tmp0_ = FALSE;
	self = (UnityLayeredBin*) base;
	g_return_if_fail (actor != NULL);
	g_return_if_fail (sibling != NULL);
	if (CLUTTER_IS_ACTOR (sibling)) {
		_tmp0_ = g_list_index (self->priv->_children, sibling) != (-1);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		self->priv->_children = g_list_remove (self->priv->_children, actor);
		self->priv->_children = g_list_insert (self->priv->_children, _g_object_ref0 (actor), g_list_index (self->priv->_children, sibling) + 1);
	} else {
		self->priv->_children = g_list_remove (self->priv->_children, actor);
		self->priv->_children = g_list_append (self->priv->_children, _g_object_ref0 (actor));
	}
}


static void unity_layered_bin_real_lower (ClutterContainer* base, ClutterActor* actor, ClutterActor* sibling) {
	UnityLayeredBin * self;
	gboolean _tmp0_ = FALSE;
	self = (UnityLayeredBin*) base;
	g_return_if_fail (actor != NULL);
	g_return_if_fail (sibling != NULL);
	if (CLUTTER_IS_ACTOR (sibling)) {
		_tmp0_ = g_list_index (self->priv->_children, sibling) != (-1);
	} else {
		_tmp0_ = FALSE;
	}
	if (_tmp0_) {
		self->priv->_children = g_list_remove (self->priv->_children, actor);
		self->priv->_children = g_list_insert (self->priv->_children, _g_object_ref0 (actor), g_list_index (self->priv->_children, sibling) - 1);
	} else {
		self->priv->_children = g_list_remove (self->priv->_children, actor);
		self->priv->_children = g_list_prepend (self->priv->_children, _g_object_ref0 (actor));
	}
}


static void unity_layered_bin_real_sort_depth_order (ClutterContainer* base) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
}


static void unity_layered_bin_real_create_child_meta (ClutterContainer* base, ClutterActor* actor) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	g_return_if_fail (actor != NULL);
	;
}


static void unity_layered_bin_real_destroy_child_meta (ClutterContainer* base, ClutterActor* actor) {
	UnityLayeredBin * self;
	self = (UnityLayeredBin*) base;
	g_return_if_fail (actor != NULL);
	;
}


static ClutterChildMeta* unity_layered_bin_real_get_child_meta (ClutterContainer* base, ClutterActor* actor) {
	UnityLayeredBin * self;
	ClutterChildMeta* result = NULL;
	self = (UnityLayeredBin*) base;
	g_return_val_if_fail (actor != NULL, NULL);
	result = NULL;
	return result;
}


GList* unity_layered_bin_get_children (UnityLayeredBin* self) {
	GList* result;
	g_return_val_if_fail (self != NULL, NULL);
	result = self->priv->_children;
	return result;
}


static GObject * unity_layered_bin_constructor (GType type, guint n_construct_properties, GObjectConstructParam * construct_properties) {
	GObject * obj;
	GObjectClass * parent_class;
	UnityLayeredBin * self;
	parent_class = G_OBJECT_CLASS (unity_layered_bin_parent_class);
	obj = parent_class->constructor (type, n_construct_properties, construct_properties);
	self = UNITY_LAYERED_BIN (obj);
	{
	}
	return obj;
}


static void unity_layered_bin_class_init (UnityLayeredBinClass * klass) {
	unity_layered_bin_parent_class = g_type_class_peek_parent (klass);
	g_type_class_add_private (klass, sizeof (UnityLayeredBinPrivate));
	CLUTTER_ACTOR_CLASS (klass)->allocate = unity_layered_bin_real_allocate;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_width = unity_layered_bin_real_get_preferred_width;
	CLUTTER_ACTOR_CLASS (klass)->get_preferred_height = unity_layered_bin_real_get_preferred_height;
	CLUTTER_ACTOR_CLASS (klass)->paint = unity_layered_bin_real_paint;
	CLUTTER_ACTOR_CLASS (klass)->pick = unity_layered_bin_real_pick;
	G_OBJECT_CLASS (klass)->get_property = unity_layered_bin_get_property;
	G_OBJECT_CLASS (klass)->constructor = unity_layered_bin_constructor;
	G_OBJECT_CLASS (klass)->finalize = unity_layered_bin_finalize;
	g_object_class_install_property (G_OBJECT_CLASS (klass), UNITY_LAYERED_BIN_CHILDREN, g_param_spec_pointer ("children", "children", "children", G_PARAM_STATIC_NAME | G_PARAM_STATIC_NICK | G_PARAM_STATIC_BLURB | G_PARAM_READABLE));
}


static void unity_layered_bin_clutter_container_interface_init (ClutterContainerIface * iface) {
	unity_layered_bin_clutter_container_parent_iface = g_type_interface_peek_parent (iface);
	iface->add = unity_layered_bin_real_add;
	iface->remove = unity_layered_bin_real_remove;
	iface->foreach = unity_layered_bin_real_foreach;
	iface->foreach_with_internals = unity_layered_bin_real_foreach_with_internals;
	iface->raise = unity_layered_bin_real_raise;
	iface->lower = unity_layered_bin_real_lower;
	iface->sort_depth_order = unity_layered_bin_real_sort_depth_order;
	iface->create_child_meta = unity_layered_bin_real_create_child_meta;
	iface->destroy_child_meta = unity_layered_bin_real_destroy_child_meta;
	iface->get_child_meta = unity_layered_bin_real_get_child_meta;
}


static void unity_layered_bin_instance_init (UnityLayeredBin * self) {
	self->priv = UNITY_LAYERED_BIN_GET_PRIVATE (self);
	self->priv->_children = NULL;
}


static void unity_layered_bin_finalize (GObject* obj) {
	UnityLayeredBin * self;
	self = UNITY_LAYERED_BIN (obj);
	{
		GList* _tmp0_;
		{
			GList* child_collection;
			GList* child_it;
			child_collection = self->priv->_children;
			for (child_it = child_collection; child_it != NULL; child_it = child_it->next) {
				ClutterActor* child;
				child = _g_object_ref0 ((ClutterActor*) child_it->data);
				{
					clutter_actor_unparent (child);
					_g_object_unref0 (child);
				}
			}
		}
		self->priv->_children = (_tmp0_ = NULL, __g_list_free_g_object_unref0 (self->priv->_children), _tmp0_);
	}
	__g_list_free_g_object_unref0 (self->priv->_children);
	G_OBJECT_CLASS (unity_layered_bin_parent_class)->finalize (obj);
}


GType unity_layered_bin_get_type (void) {
	static volatile gsize unity_layered_bin_type_id__volatile = 0;
	if (g_once_init_enter (&unity_layered_bin_type_id__volatile)) {
		static const GTypeInfo g_define_type_info = { sizeof (UnityLayeredBinClass), (GBaseInitFunc) NULL, (GBaseFinalizeFunc) NULL, (GClassInitFunc) unity_layered_bin_class_init, (GClassFinalizeFunc) NULL, NULL, sizeof (UnityLayeredBin), 0, (GInstanceInitFunc) unity_layered_bin_instance_init, NULL };
		static const GInterfaceInfo clutter_container_info = { (GInterfaceInitFunc) unity_layered_bin_clutter_container_interface_init, (GInterfaceFinalizeFunc) NULL, NULL};
		GType unity_layered_bin_type_id;
		unity_layered_bin_type_id = g_type_register_static (CTK_TYPE_ACTOR, "UnityLayeredBin", &g_define_type_info, 0);
		g_type_add_interface_static (unity_layered_bin_type_id, CLUTTER_TYPE_CONTAINER, &clutter_container_info);
		g_once_init_leave (&unity_layered_bin_type_id__volatile, unity_layered_bin_type_id);
	}
	return unity_layered_bin_type_id__volatile;
}


static void unity_layered_bin_get_property (GObject * object, guint property_id, GValue * value, GParamSpec * pspec) {
	UnityLayeredBin * self;
	self = UNITY_LAYERED_BIN (object);
	switch (property_id) {
		case UNITY_LAYERED_BIN_CHILDREN:
		g_value_set_pointer (value, unity_layered_bin_get_children (self));
		break;
		default:
		G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
		break;
	}
}




