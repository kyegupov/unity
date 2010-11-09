#if HAVE_CONFIG_H
#include <config.h>
#endif

#include "panel-service.h"

G_DEFINE_TYPE (PanelService, panel_service, G_TYPE_OBJECT);

#define GET_PRIVATE(o) \
  (G_TYPE_INSTANCE_GET_PRIVATE ((o), PANEL_TYPE_SERVICE, PanelServicePrivate))

struct _PanelServicePrivate
{
  gint margin;
};

/* Globals */

/* Forwards */

/*
 * GObject stuff
 */
static void
panel_service_class_init (PanelServiceClass *klass)
{
  GObjectClass *obj_class = G_OBJECT_CLASS (klass);

  g_type_class_add_private (obj_class, sizeof (PanelServicePrivate));
}


static void
panel_service_init (PanelService *self)
{
  PanelServicePrivate *priv;
  priv = GET_PRIVATE (self);
}

PanelService *
panel_service_new ()
{
  return g_object_new (PANEL_TYPE_SERVICE, NULL);
}
