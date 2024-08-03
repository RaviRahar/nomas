project('nomas', 'c', version: '0.0.1')

###########################################
############ CONFIGURE PROJECT ############
###########################################
conf = configuration_data()

prod = true

conf.set('NOMAS_PRODUCTION', prod)

subdir('assets')
subdir('src')

executable(meson.project_name(), sources: sources, dependencies: deps, install: true)
