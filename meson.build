project('snake', 'c')

sources = files(
  'src/main.c',
  'src/linked_list.c',
  'src/renderer.c'
  )
incdir = include_directories('headers')
deps = [dependency('ncurses')]

executable('snake', sources, include_directories: incdir, dependencies: deps)
