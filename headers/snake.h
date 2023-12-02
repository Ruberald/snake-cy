#ifndef SNAKE_H
#define SNAKE_H

#include "linked_list.h"

enum SEGMENT {
    HEAD = 0x00000100,
    PART = 0x00000200,
    TAIL = 0x00000300
};

enum FOOD {
    FRUIT,
    POISON
};

enum Direction {
    TOP,
    RIGHT,
    DOWN,
    LEFT
};

typedef Node Segment;
typedef LinkedList Snake;

extern void (* add_segment)(Snake snake, int value);
extern void (* update_segment)(Snake snake, int old_seg, int new_seg);

void remove_head(Snake snake);

Snake createSnake();

void eat(Snake snake, enum FOOD food);

#endif
