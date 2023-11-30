#include "renderer.h"
#include <curses.h>
#include <string.h>

void initializeRenderer(Screen * screen) {
    // Initialize the screen
    initscr();

    // For interactive input
    cbreak();
    noecho();

    // Keypad enable
    keypad(stdscr, true);

    refresh();

    screen->window_rows = getmaxy(stdscr), screen->window_columns = getmaxx(stdscr);

    int startx = (screen->window_columns - CELLS_H - 2) / 2, starty = (screen->window_rows - CELLS_V - 2) / 2;
    screen->window = createWindow(CELLS_V + 2, CELLS_H + 2, starty, startx);
}

WINDOW * createWindow(int height, int width, int starty, int startx) {	
    // new window
    WINDOW *local_win;

    local_win = newwin(height, width, starty, startx);
    box(local_win, 0 , 0);
    wrefresh(local_win);

    return local_win;
}

void renderTitle(WINDOW *win, const char *title) {
    mvwprintw(win, 0, (getmaxx(win) - strlen(title)) / 2, "%s", title);
    wrefresh(win);
}

void renderFrame(WINDOW *win) {
    // Placeholder for frame rendering logic
    // You can add your frame rendering logic here
    // For example, drawing the snake or any other game elements
    wrefresh(win);
}

void closeRenderer(Screen * screen) {
    delwin(screen->window);
    endwin();
}

