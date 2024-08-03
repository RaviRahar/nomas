proname = meson.project_name()
datadir = get_option('datadir')
pkgdatadir = datadir / proname

gnome = import('gnome')

###########################################
############## Dependencies ###############
###########################################
deps = dependency('gtk4', 'dbus-1', 'json-glib-1.0')
sources = files(proname + '.c')
sources += files(proname + 'app.c')
sources += files(proname + 'appwin.c')
sources += files(proname + 'appprefs.c')

###########################################
########### SCHEMA DEPENDENCIES ###########
###########################################
install_data(
  proname + '.gschema.xml',
  install_tag: 'gschema',
  install_dir: datadir / 'glib-2.0' / 'schemas',
)
# Just for build, final schemas are installed in post_install target
sources += gnome.compile_schemas(build_by_default: true, depend_files: proname + '.gschema.xml')

###########################################
########### GRESOURCE DEPENDENCIES ########
###########################################
if prod
  gnome.compile_resources(
    proname,
    proname + '.gresource.xml',
    gresource_bundle: true,
    install: true,
    install_dir: datadir + proname,
  )
else
  sources += gnome.compile_resources(
    proname,
    proname + '.gresource.xml',
    gresource_bundle: false,
  )
endif

configure_file(input: 'config.h.in', output: 'config.h', configuration: conf)

gnome.post_install(
  # <prefix>/<datadir>/glib-2.0/schemas.
  glib_compile_schemas: true,
  # gio_querymodules: List of directories relative to prefix where giomodule.cache file will be updated.
  # <prefix>/<datadir>/icons/hicolor.
  gtk_update_icon_cache: true,
  # <prefix>/<datadir>/applications.
  update_desktop_database: true,
  update_mime_database: true,
)

subdir_done()

# app9_resources = gnome.compile_resources('nomasapp9_resources',
#   'nomasapp.gresource.xml',
#   source_dir: meson.current_source_dir())

# app9_schemas = gnome.compile_schemas()

# executable('nomasapp9',
#   'main.c',
#   'nomasapp.c',
#   'nomasappwin.c',
#   'nomasappprefs.c',
#   app9_resources,
#   app9_schemas,
#   dependencies: libgtk_dep,
#   c_args: common_cflags)
