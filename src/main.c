#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>

#define CELLS_V 30
#define CELLS_H 60

char grid[CELLS_V][CELLS_H];
int window_rows, window_columns;

WINDOW *create_newwin(int height, int width, int starty, int startx) {	
    // new window
    WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
	wrefresh(local_win);

	return local_win;
}

int main() {

    // initialize the screen
    initscr();

    window_rows = getmaxy(stdscr), window_columns = getmaxx(stdscr);
    int startx = (window_columns - CELLS_H - 2) / 2, starty = (window_rows - CELLS_V - 2) / 2;

    // For interactive input
    cbreak();
    noecho();

    // Keypad enable
    keypad(stdscr, true);

    refresh();
    // new window
    WINDOW *local_win = create_newwin(CELLS_V + 2, CELLS_H + 2, starty, startx);

    // title
    char title[] = "Snake Game!";
    mvwprintw(local_win, 0, (CELLS_H - sizeof(title)) / 2, "%s", title);

    wrefresh(local_win);

    int ch;

    // game loop
    while ((ch = getch()) != 'q') {
        mvwprintw(local_win, 10, (CELLS_H - 1) / 2, "%c", ch);
        wrefresh(local_win);
    }

    endwin();

    return 0;
}
