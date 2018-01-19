/*
 *  File:   sll.c
 *  Author: Brett Heithold
 *
 *  Description:
 */


#include "sll.h"


/*
 *  Type: NODE
 *  Description: This is the NODE struct used for the implementation
 *  of the SLL class.
 */
typedef struct node {
    void *value;
    struct node *next;
} NODE;


/*
 *  Constructor: newEmptyNODE
 *  Usage: NODE *n = newEmptyNODE();
 *  Description: This constructor creates an empty NODE object.
 */
NODE *newEmptyNODE(void) {
    NODE *n = malloc(sizeof(NODE));
    assert(n != 0);
    n->value = NULL;
    n->next = NULL;
    return n;
}


/*
 *  Constructor: newNODE
 *  Usage: NODE *n = newNODE(value, next);
 *  Description: This constructor creates a new NODE object with a value
 *  and initializes the node's next pointer.
 */
NODE *newNODE(void *value, NODE *next) {
    NODE *n = malloc(sizeof(NODE));
    assert(n != 0);
    n->value = value;
    n->next = next;
    return n;
}


// Private SLL method prototypes
static void addToFront(SLL *items, void *value);
static void addToBack(SLL *items, void *value);


/*
 *  Type: SLL
 *  Description: This is the SLL struct used for basis of the SLL class.
 */
struct SLL {
    NODE *head;
    NODE *tail;
    int size;
    void (*display)(void *, FILE *);
    void (*free)(void *);

    void (*addToFront)(SLL *, void *);
    void (*addToBack)(SLL *, void *);
}; 


/*
 *  Constructor: newSLL
 *  Usage: SLL *s = newSLL(displayINTEGER, freeINTEGER);
 *  Description: This constructor initializes a new SLL object. It sets the
 *  head and tail pointers to NULL as well as the size to 0. This constructor
 *  also sets the function pointers.
 */
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


/*
 *  Method: insertSLL
 *  Usage: insertSLL(s, i, v);
 *  Description: This method inserts a value into the list at a given index.
 *  It runs in constant time for insertions at the very end of the list
 *  and runs in constant time for insertions that are a constant distance
 *  from the front. The singly-linked list uses zero-based indexing.
 */
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


/*
 *  Method: getSLL
 *  Usage:  void *value = getSLL(list, index);
 *  Description: This method returns the value at the given index. It runs in
 *  constant time for retrievals at the very back of the list and at a constant
 *  distance from the front of the list.
 */
void *getSLL(SLL *items, int index) {
    assert(index >= 0 && index <= items->size);
    if (index == 0) {
        return items->head->value;
    }
    else if (index == items->size) {
        return items->tail->value;
    }
    else {
        NODE *curr = items->head;
        while (index > 0) {
            curr = curr->next;
            index--;
        }
        return curr->value;
    }
}


/*
 *  Method: sizeSLL
 *  Usage: int size = sizeSLL(list);
 *  Description: This method returns the number of items stored in the list.
 */
int sizeSLL(SLL *items) {
    return items->size;
}


/*
 *  Method: displaySLL
 *  Usage: displaySLL(list, stdout);
 *  Description: This method prints the items stored in the list to the 
 *  file pointer passed as an argument. There is no preceeding or following
 *  whitespace printed.
 *  Example: If the list holds the integers 5, 6, 2, 9, and 1 from front to back
 *           {5,6,2,9,1}
 *           Empty-List
 *           {}
 */
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
