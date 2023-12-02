#include "linked_list.h"
#include <stdlib.h>

LinkedList create_list() {
    LinkedList list = (LinkedList) malloc(sizeof(struct LinkedList));

    list->head = list->tail = NULL;
    list->length = 0;

    return list;
}

Node create_node(int value) {
    Node node = (Node) malloc(sizeof(struct Node));

    node->value = value;
    node->next = node->prev = NULL;

    return node;
}

int getAt(LinkedList list, int index) {

    if (index < 0 || index >= list->length) {
        perror("Error: Index out of bounds!\n");
        exit(EXIT_SUCCESS);
    }


    Node current = list->head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    return current->value;
}

void append(LinkedList list, int value) {
    Node node = create_node(value);

    list->length++;

    if(list->tail == NULL) {
        list->head = list->tail = node;
        return;
    }

    list->tail->next = node;
    node->prev = list->tail;
    list->tail = node;
}

void prepend(LinkedList list, int value) {
    Node node = create_node(value);

    list->length++;

    if(list->head == NULL) {
        list->head = list->tail = node;
        return;
    }

    list->head->prev = node;
    node->next = list->head;
    list->head = node;
}

void update(LinkedList list, int oldValue, int newValue) {
    for(Node current = list->head; current != NULL; current = current->next) {
        if(current->value == oldValue) {
            current->value = newValue;
            return;
        }
    }
}

void insertAt(LinkedList list, int index, int value) {
    Node current = list->head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }
    
    Node node = create_node(value);

    list->length++;

    node->next = current;
    node->prev = current->prev;
    current->prev = node;
    node->prev->next = node;
}

void removeAt(LinkedList list, int index) {
    Node current = list->head;

    for (int i = 0; i < index; ++i) {
        current = current->next;
    }

    list->length--;

    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current);
}
