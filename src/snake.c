#include "snake.h"

void (* add_segment)(Snake snake, int value) = prepend;
void (* update_segment)(Snake snake, int old_seg, int new_seg) = update;

void remove_head(Snake snake) { removeAt(snake, 0);}

static inline int get_segment_type(int value) {
    return (value & 0x0000FF00);
}

static inline int get_segment_turn(int value) {
    return (value & 0x000000FF);
}

static inline void set_segment_type(Segment seg, int value) {
    seg->value = (seg->value & 0xFFFF00FF) | value;
}

static inline void set_segment_turn(Segment seg, int value) {
    seg->value = (seg->value & 0xFFFFFF00) | value;
}

static inline void set_segment_issued_turn(Segment seg, int value) {
    seg->value = (seg->value & 0xFF00FFFF) | ((value + 1) << 16);
}

Snake createSnake() {
    Snake snake = create_list();

    add_segment(snake, TOP | TAIL);
    add_segment(snake, TOP | HEAD);

    return snake;
}

void eat(Snake snake, enum FOOD food) {
    switch(food) {
        case FRUIT: {
            set_segment_type(snake->head, PART);
            add_segment(snake, HEAD);
            set_segment_issued_turn(snake->head, get_segment_turn(snake->head->next->value));
            break;
        }
        case POISON: {
            // enum Direction turn = get_segment_turn(snake->head->value);
            remove_head(snake);
            set_segment_type(snake->head, HEAD);
            // set_segment_turn(snake->head, turn);
            break;
        }
    }
}

