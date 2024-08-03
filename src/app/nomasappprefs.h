#pragma once

#include <gtk/gtk.h>
#include "nomasappwin.h"


#define NOMAS_APP_PREFS_TYPE (nomas_app_prefs_get_type ())
G_DECLARE_FINAL_TYPE (NomasAppPrefs, nomas_app_prefs, NOMAS, APP_PREFS, GtkDialog)


NomasAppPrefs        *nomas_app_prefs_new          (NomasAppWindow *win);
