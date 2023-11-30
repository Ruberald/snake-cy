#ifndef SNAKE_H
#define SNAKE_H

#include "linked_list.h"

typedef Node Segment;
typedef LinkedList Snake;

void (* add_segment)(Snake snake, int value) = append;

#endif
