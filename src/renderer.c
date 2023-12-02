#include "renderer.h"
#include <curses.h>
#include <locale.h>
#include <string.h>

void initializeRenderer(Screen * screen) {
    setlocale(LC_ALL, "");
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

void draw_call(WINDOW * win, char * str, int x, int y) {
    wmove(win, y, x);
    waddstr(win, str);
}

void renderFrame(WINDOW *win, void (* draw)(WINDOW * win, void (* draw_call)(WINDOW * win, char * str, int x, int y))) {
    wclear(win);
    box(win, 0 , 0);
    renderTitle(win, "Snake Game!");
    // Placeholder for frame rendering logic
    // You can add your frame rendering logic here
    // For example, drawing the snake or any other game elements
    // wmove(win, 10, (getmaxx(win) - 1) / 2);
    // waddstr(win, "◊");
    // wmove(win, 11, (getmaxx(win) - 1) / 2);
    // waddstr(win, "▮");
    // wmove(win, 12, (getmaxx(win) - 1) / 2);
    // waddstr(win, "▮");
    // wmove(win, 13, (getmaxx(win) - 1) / 2);
    // waddstr(win, "▮");
    // wmove(win, 14, (getmaxx(win) - 1) / 2);
    // waddstr(win, "▾");
    draw(win, draw_call);
    wrefresh(win);
}

void closeRenderer(Screen * screen) {
    delwin(screen->window);
    endwin();
}

