#ifndef SPRITE_H
#define SPRITE_H

#include "snake.h"

struct Sprite {
    char * head_sprite[4];
    char * part_sprite[4];
    char * tail_sprite[4];
};

extern struct Sprite sprite;

char * return_sprite(enum SEGMENT segment, enum Direction direction);

#endif
