/*
 *  File:   test-sll.c
 *  Author: Brett Heithold
 *  
 *  Description:
 *
 *
 */

#include "sll.h"
#include "integer.h"

int main(void) {
    SLL *list = newSLL(displayINTEGER, freeINTEGER);

    insertSLL(list, sizeSLL(list), newINTEGER(5));
    insertSLL(list, sizeSLL(list), newINTEGER(6));
    insertSLL(list, sizeSLL(list), newINTEGER(2));
    insertSLL(list, sizeSLL(list), newINTEGER(9));
    insertSLL(list, sizeSLL(list), newINTEGER(1));

    // before changes
    printf("Before changes: ");
    displaySLL(list, stdout);
    fprintf(stdout, "\n");

    // set head tail and index to different values
    void *old1 = setSLL(list, 0, newINTEGER(17));
    void *old4 = setSLL(list, sizeSLL(list)-1, newINTEGER(17));
    void *old2 = setSLL(list, sizeSLL(list), newINTEGER(17));
    void *old3 = setSLL(list, 2, newINTEGER(17));

    // after changes
    printf("After changes: ");
    displaySLL(list, stdout);
    fprintf(stdout, "\n");
    
    return 0;
}
