#include <gtk/gtk.h>

#include "nomasapp.h"
#include "nomasappprefs.h"
#include "nomasappwin.h"

struct _NomasApp
{
  GtkApplication parent;
};

G_DEFINE_TYPE (NomasApp, nomas_app, GTK_TYPE_APPLICATION);

static void
nomas_app_init (NomasApp *app)
{
}

static void
preferences_activated (GSimpleAction *action, GVariant *parameter, gpointer app)
{
  NomasAppPrefs *prefs;
  GtkWindow *win;

  win = gtk_application_get_active_window (GTK_APPLICATION (app));
  prefs = nomas_app_prefs_new (NOMAS_APP_WINDOW (win));
  gtk_window_present (GTK_WINDOW (prefs));
}

static void
quit_activated (GSimpleAction *action, GVariant *parameter, gpointer app)
{
  g_application_quit (G_APPLICATION (app));
}

static GActionEntry app_entries[] = {
  { "preferences", preferences_activated, NULL, NULL, NULL },
  { "quit", quit_activated, NULL, NULL, NULL }
};

static void
nomas_app_startup (GApplication *app)
{
  const char *quit_accels[2] = { "<Ctrl>Q", NULL };

  G_APPLICATION_CLASS (nomas_app_parent_class)->startup (app);

  g_action_map_add_action_entries (G_ACTION_MAP (app), app_entries,
                                   G_N_ELEMENTS (app_entries), app);
  gtk_application_set_accels_for_action (GTK_APPLICATION (app), "app.quit",
                                         quit_accels);
}

static void
nomas_app_activate (GApplication *app)
{
  NomasAppWindow *win;

  win = nomas_app_window_new (NOMAS_APP (app));
  gtk_window_present (GTK_WINDOW (win));
}

static void
nomas_app_open (GApplication *app, GFile **files, int n_files, const char *hint)
{
  GList *windows;
  NomasAppWindow *win;
  int i;

  windows = gtk_application_get_windows (GTK_APPLICATION (app));
  if (windows)
    win = NOMAS_APP_WINDOW (windows->data);
  else
    win = nomas_app_window_new (NOMAS_APP (app));

  for (i = 0; i < n_files; i++)
    nomas_app_window_open (win, files[i]);

  gtk_window_present (GTK_WINDOW (win));
}

static void
nomas_app_class_init (NomasAppClass *class)
{
  G_APPLICATION_CLASS (class)->startup = nomas_app_startup;
  G_APPLICATION_CLASS (class)->activate = nomas_app_activate;
  G_APPLICATION_CLASS (class)->open = nomas_app_open;
}

NomasApp *
nomas_app_new (void)
{
  return g_object_new (NOMAS_APP_TYPE, "application-id", "ravirahar.nomas",
                       "flags", G_APPLICATION_HANDLES_OPEN, NULL);
}
