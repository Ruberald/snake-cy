#include <curses.h>
#include <ncurses.h>
#include <stdbool.h>

#include "snake.h"
#include "renderer.h"
#include "game.h"

int main() {

    init_game();

    // game loop
    int ch;
    while ((ch = getch()) != 'q') {
        enum Event event;
        enum Direction direction;

        switch(ch) {
            case 'a': {
                event = TURN;
                direction = LEFT;
                break;
            }

            case 'd': {
                event = TURN;
                direction = RIGHT;
                break;
            }

            case 'w': {
                event = TURN;
                direction = TOP;
                break;
            }

            case 's': {
                event = TURN;
                direction = DOWN;
                break;
            }

            default: {
                event = STEP;
                break;
            }
        }
        update_game(event, direction);
    }

    close_game();

    return 0;
}
