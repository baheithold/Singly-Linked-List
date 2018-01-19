/*
 *  File:   sll.c
 *  Author: Brett Heithold
 *
 *  Description:
 */


#include "sll.h"


typedef struct node {
    void *value;
    struct node *next;
} NODE;

NODE *newEmptyNODE(void) {
    NODE *n = malloc(sizeof(NODE));
    assert(n != 0);
    n->value = NULL;
    n->next = NULL;
    return n;
}

NODE *newNODE(void *value, NODE *next) {
    NODE *n = malloc(sizeof(NODE));
    assert(n != 0);
    n->value = value;
    n->next = next;
    return n;
}


static void addToFront(SLL *items, void *value);
static void addToBack(SLL *items, void *value);

struct SLL {
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *, FILE *);
    void (*free)(void *);

    void (*addToFront)(SLL *, void *);
    void (*addToBack)(SLL *, void *);
}; 


SLL *newSLL(void (*d)(void *, FILE *), void (*f)(void *)) {
    SLL *items = malloc(sizeof(SLL));
    assert(items != 0);
    items->head = NULL;
    items->tail = NULL;
    items->size = 0;
    items->display = d;
    items->free = f;
    items->addToFront = addToFront;
    items->addToBack = addToBack;
    return items;
}


void insertSLL(SLL *items, int index, void *value) {
    assert(index >= 0 && index <= items->size);
    if (index == 0 || items->size == 0) {
        // Node is to be added to the front of the list
        items->addToFront(items, value);
    }
}



/******************** Private **************************/
void addToFront(SLL *items, void *value) {
    assert(items != 0);
    items->head = newNODE(value, items->head);
    items->size++;
}

void addToBack(SLL *items, void *value) {
    assert(items != 0);
    if (items->size == 0) {
        // List is empty
        items->addToFront(items, value);
    }
    else {
        items->tail->next = newNODE(value, NULL);
        items->tail = items->tail->next;
        items->size++;
    }
}
