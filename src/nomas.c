#include <gtk/gtk.h>

#include "app/nomasapp.h"
#include "config.h"

int
main (int argc, char *argv[])
{

#ifdef NOMAS_PRODUCTION
  GError *error = NULL;
  GResource *resource;

  resource = g_resource_load ("/usr/share/nomas/nomas.gresource", &error);
  if (error != NULL)
    {
      g_printerr ("Error loading resource: %s\n", error->message);
      g_error_free (error);
      return 1;
    }

  g_resources_register (resource);
#else
  g_setenv ("GSETTINGS_SCHEMA_DIR", "../build/src", FALSE);
#endif

  return g_application_run (G_APPLICATION (nomas_app_new ()), argc, argv);
}
