project('snake', 'c')

sources = files(
  'src/main.c',
  'src/linked_list.c',
  'src/renderer.c',
  'src/snake.c',
  'src/game.c',
  'src/sprite.c'
  )
incdir = include_directories('headers')
deps = [dependency('ncursesw')]

executable('snake', sources, include_directories: incdir, dependencies: deps)
