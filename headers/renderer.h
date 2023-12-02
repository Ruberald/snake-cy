#ifndef RENDERER_H
#define RENDERER_H

#include <ncurses.h>

#define CELLS_V 30
#define CELLS_H 60

typedef struct Screen {
    char grid[CELLS_V][CELLS_H];
    int window_rows, window_columns;

    WINDOW * window;
} Screen;

void initializeRenderer(Screen * screen);
WINDOW *createWindow(int height, int width, int starty, int startx);
void renderTitle(WINDOW *win, const char *title);
void renderFrame(WINDOW *win, void (* draw)(WINDOW * win, void (* draw_call)(WINDOW * win, char * str, int x, int y)));
void closeRenderer(Screen * screen);

#endif // RENDERER_H
