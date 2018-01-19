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
    assert(items != 0);
    if (index == 0) {
        // Node is to be added to the front of the list
        items->addToFront(items, value);
        items->tail = items->head;
    }
    else if (index == items->size) {
        // Node is to be added to the back of the list
        items->addToBack(items, value);
    }
    else {
        // Node is to be inserted at an index between 0 and items->size
        NODE *curr = items->head;
        assert(curr != 0);
        while (index > 1) {
            curr = curr->next;
            index--;
        }
        curr->next = newNODE(value, curr->next);
        items->size++;
    }
}


int sizeSLL(SLL *items) {
    return items->size;
}


void displaySLL(SLL *items, FILE *fp) {
    fprintf(fp, "{");
    NODE *curr = items->head;
    while (curr != NULL) {
        items->display(curr->value, fp);
        if (curr->next != NULL) {
            fprintf(fp, ",");
        }
        curr = curr->next;
    }
    fprintf(fp, "}");
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
