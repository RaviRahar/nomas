proname = meson.project_name()
datadir = get_option('datadir')
pkgdatadir = datadir / proname

gnome = import('gnome')

###########################################
############## Dependencies ###############
###########################################
deps = dependency('gtk4')
sources = files('main.c')

###########################################
########### SCHEMA DEPENDENCIES ###########
###########################################
install_data(
  'gschema.xml',
  install_tag: 'gschema',
  install_dir: datadir / 'glib-2.0' / 'schemas',
  rename: proname + '.gschema.xml',
)
# Just for build, final schemas are installed in post_install target
gnome.compile_schemas(build_by_default: true, depend_files: 'gschema.xml')

###########################################
########### GRESOURCE DEPENDENCIES ########
###########################################
gnome.compile_resources(
  proname,
  'gresources.xml',
  gresource_bundle: true,
  install: true,
  install_dir: datadir + proname,
)

configure_file(input: 'config.h.in', output: 'config.h', configuration: configdata)

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
