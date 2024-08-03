#pragma once

#include <gtk/gtk.h>


#define NOMAS_APP_TYPE (nomas_app_get_type ())
G_DECLARE_FINAL_TYPE (NomasApp, nomas_app, NOMAS, APP, GtkApplication)


NomasApp     *nomas_app_new         (void);
