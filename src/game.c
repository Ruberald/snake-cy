#include "game.h"
#include "renderer.h"
#include "snake.h"
#include "sprite.h"
#include <curses.h>

struct Game game = {
//    .screen = NULL,
};

// Snake 

int get_segment_type(int value) {
    return (value & 0x0000FF00);
}

int get_segment_turn(int value) {
    return (value & 0x000000FF);
}

int get_segment_issued_turn(int value) {
    return (value & 0x00FF0000);
}

void set_segment_type(Segment seg, int value) {
    seg->value = (seg->value & 0xFFFF00FF) | value;
}

void set_segment_turn(Segment seg, int value) {
    seg->value = (seg->value & 0xFFFFFF00) | ((value >> 16) - 1);
}

void set_segment_issued_turn(Segment seg, int value) {
    seg->value = (seg->value & 0xFF00FFFF) | ((value + 1) << 16);
}

void snake_turn(enum Direction direction) {
    game.snake->head->value = (game.snake->head->value & 0xFF00) | direction;
}

void segment_turn(Segment seg, enum Direction direction) {

}

void renderSnake(WINDOW * win, void (* draw_call)(WINDOW * win, char * str, int x, int y)) {
    int i = 1;
    int x_factor, y_factor;

    Segment seg = game.snake->head;
    draw_call(win, return_sprite(get_segment_type(seg->value), get_segment_turn(seg->value)), game.snake_pos_x, game.snake_pos_y);

    for(Segment seg = game.snake->head->next; seg; seg = seg->next, i++) {
        if(get_segment_issued_turn(seg->value))
            set_segment_turn(seg, get_segment_issued_turn(seg->value));
        if((get_segment_turn(seg->value)) != (get_segment_turn(seg->prev->value)))
            set_segment_issued_turn(seg, get_segment_turn(seg->prev->value));

        switch(get_segment_turn(seg->value)) {
            case TOP: {
                x_factor = 0;
                y_factor = i;
                break;
            }

            case RIGHT: {
                x_factor = -i;
                y_factor = 0;
                break;
            }

            case DOWN: {
                x_factor = 0;
                y_factor = -i;
                break;
            }

            case LEFT: {
                x_factor = i;
                y_factor = 0;
                break;
            }
        }
            
        draw_call(win, 
                  return_sprite(get_segment_type(seg->value), get_segment_turn(seg->value)), 
                  game.snake_pos_x + x_factor, 
                  game.snake_pos_y + y_factor);
    }

    switch(get_segment_turn(game.snake->head->value)) {
        case TOP: {
            x_factor = 0;
            y_factor = -1;
            break;
        }

        case RIGHT: {
            x_factor = 1;
            y_factor = 0;
            break;
        }

        case DOWN: {
            x_factor = 0;
            y_factor = 1;
            break;
        }

        case LEFT: {
            x_factor = -1;
            y_factor = 0;
            break;
        }
    }

    game.snake_pos_x += x_factor;
    game.snake_pos_y += y_factor;

}

// Events

void listen(enum Event event, enum Direction direction) {
    switch(event) {
        case TURN: 
            snake_turn(direction);
            break;
        case STEP: 
            break;
    }
}

// Game 

void init_game() {
    initializeRenderer(&game.screen);

    game.snake = createSnake();

    game.snake_pos_x = 10, game.snake_pos_y = 10;

    char title[] = "Snake Game!";
    renderTitle(game.screen.window, title);

    eat(game.snake, FRUIT);
    eat(game.snake, FRUIT);
    eat(game.snake, FRUIT);
    eat(game.snake, FRUIT);
    eat(game.snake, FRUIT);
    eat(game.snake, FRUIT);
}

void update_game(enum Event event, enum Direction direction) {
    renderFrame(game.screen.window, renderSnake);
    listen(event, direction);

    // eat(game.snake, FRUIT);
}

void close_game() {
    closeRenderer(&game.screen);
}

