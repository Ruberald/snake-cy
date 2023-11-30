#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>

#include "snake.h"
#include "renderer.h"

int main() {
    Screen screen;

    initializeRenderer(&screen);

    char title[] = "Snake Game!";
    renderTitle(screen.window, title);

    // game loop
    int ch;
    while ((ch = getch()) != 'q') {
        renderFrame(screen.window);
    }

    closeRenderer(&screen);

    return 0;
}
