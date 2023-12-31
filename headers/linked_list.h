#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node * prev;
    struct Node * next;

    int value;
} * Node;

typedef struct LinkedList {
    struct Node * head;
    struct Node * tail;

    int length;
} * LinkedList; 

LinkedList create_list();

Node create_node(int value);

int getAt(LinkedList list, int index);

void append(LinkedList list, int value);

void prepend(LinkedList list, int value);

void update(LinkedList list, int oldValue, int newValue);

void insertAt(LinkedList list, int index, int value);

void removeAt(LinkedList list, int index);

#endif
