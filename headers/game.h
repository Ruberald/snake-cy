#ifndef GAME_H
#define GAME_H

#include "renderer.h"
#include "snake.h"

enum Event {
    STEP,
    TURN,
};

enum IssuedDirection {
    ISSUED_TOP = 0x00010000,
    ISSUED_RIGHT = 0x00020000,
    ISSUED_DOWN = 0x00030000,
    ISSUED_LEFT = 0x00040000,
};

extern struct Game {
    Screen screen;
    Snake snake;

    int snake_pos_x, snake_pos_y;

    Segment turn_queue[];
} game;

extern enum Direction snake_direction;

void snake_turn(enum Direction direction);

void renderSnake(WINDOW * win, void (* draw_call)(WINDOW * win, char * str, int x, int y));

void init_game();

void update_game(enum Event event, enum Direction direction);

void close_game();

#endif
