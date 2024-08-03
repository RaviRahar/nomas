#pragma once

#include <gtk/gtk.h>
#include "nomasapp.h"


#define NOMAS_APP_WINDOW_TYPE (nomas_app_window_get_type ())
G_DECLARE_FINAL_TYPE (NomasAppWindow, nomas_app_window, NOMAS, APP_WINDOW, GtkApplicationWindow)


NomasAppWindow       *nomas_app_window_new          (NomasApp *app);
void                    nomas_app_window_open         (NomasAppWindow *win,
                                                         GFile            *file);
