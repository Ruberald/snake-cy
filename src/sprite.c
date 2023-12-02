#include "sprite.h"
#include "snake.h"

struct Sprite sprite = {
    .head_sprite = {"▲", "▶", "▼", "◀"},
    .part_sprite = {"▮", "▬", "▮", "▬"},
    .tail_sprite = {"▿", "◃", "▵", "▹"}
};

char * return_sprite(enum SEGMENT segment, enum Direction direction) {
    switch(segment) {
        case HEAD:
            return sprite.head_sprite[direction];
        case PART:
            return sprite.part_sprite[direction];
        case TAIL:
            return sprite.tail_sprite[direction];
    }
}
