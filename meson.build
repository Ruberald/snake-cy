project('snake', 'c')

sources = (
  'src/main.c'
  )
incdir = include_directories('headers')
deps = [dependency('ncurses')]

executable('snake', sources, include_directories: incdir, dependencies: deps)
