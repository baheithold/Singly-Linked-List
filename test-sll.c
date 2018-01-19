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

    printf("Value at index 0: ");
    displayINTEGER(getSLL(list, 0), stdout);
    printf("\n");
    printf("Value at index 1: ");
    displayINTEGER(getSLL(list, 1), stdout);
    printf("\n");
    printf("Value at index 2: ");
    displayINTEGER(getSLL(list, 2), stdout);
    printf("\n");
    printf("Value at index 3: ");
    displayINTEGER(getSLL(list, 3), stdout);
    printf("\n");
    printf("Value at index 4: ");
    displayINTEGER(getSLL(list, 4), stdout);
    printf("\n");

    displaySLL(list, stdout);
    fprintf(stdout, "\n");
    
    return 0;
}
