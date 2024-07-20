project('nomas', 'c', version: '0.0.1')

###########################################
############ CONFIGURE PROJECT ############
###########################################
configdata = configuration_data()
# configdata.set('version', version)

subdir('assets')
subdir('src')

executable(meson.project_name(), sources: sources, dependencies: deps, install: true)
