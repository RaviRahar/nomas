proname = meson.project_name()
datadir = get_option('datadir')

install_data(
  'man',
  install_tag: 'man',
  install_dir: datadir / 'applications',
  rename: proname + '.man.1',
)
install_data(
  'desktop',
  install_tag: 'desktop',
  install_dir: datadir / 'applications',
  rename: proname + '.desktop',
)
install_data(
  'appdata.xml',
  install_tag: 'appdata',
  install_dir: datadir / 'metainfo',
  rename: proname + '.appdata.xml',
)
install_subdir(
  'icons',
  install_tag: 'icons',
  install_dir: datadir / 'icons' / 'hicolor' / '48x48' / 'apps',
  strip_directory: true,
)

subdir_done()
