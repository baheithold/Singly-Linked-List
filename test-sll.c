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

    displaySLL(list, stdout);
    fprintf(stdout, "\n");
    
    return 0;
}
