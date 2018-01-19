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

    displaySLL(list, stdout);
    fprintf(stdout, "\n");
    
    return 0;
}
