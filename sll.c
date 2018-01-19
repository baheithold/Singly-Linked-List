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


struct SLL {
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *, FILE *);
    void (*free)(void *);
}; 


SLL *newSLL(void (*d)(void *, FILE *), void (*f)(void *)) {
    SLL *items = malloc(sizeof(SLL));
    assert(items != 0);
    items->head = NULL;
    items->tail = NULL;
    items->size = 0;
    items->display = d;
    items->free = f;
    return items;
}
