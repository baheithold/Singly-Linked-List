/*
 *  File:   test-sll.c
 *  Author: Brett Heithold
 *  
 *  Description:
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "integer.h"

static void showItems(SLL *items) {
   printf("The items are ");
   displaySLL(items,stdout);
   printf(".\n");
   printf("The items (debugged) are ");
   displaySLLdebug(items,stdout);
   printf(".\n");
}

int main(void) {
    SLL *items = newSLL(displayINTEGER,freeINTEGER);
    showItems(items);
    insertSLL(items,0,newINTEGER(3));                   //insert at front
    insertSLL(items,sizeSLL(items),newINTEGER(2));      //insert at back
    insertSLL(items,1,newINTEGER(1));                   //insert at middle
    showItems(items);
    printf("The value ");
    INTEGER *i = removeSLL(items,0);                   //remove from front
    displayINTEGER(i,stdout);
    printf(" was removed.\n");
    freeINTEGER(i);
    showItems(items);
    int x = getINTEGER((INTEGER *) getSLL(items,0));    //get the first item
    printf("The first item is %d.\n",x);
    printf("Freeing the list.\n");
    freeSLL(items);

    // Testing unionSLL
    printf("\nTesing unionSLL...\n");
    SLL *recipient = newSLL(displayINTEGER, freeINTEGER);
    SLL *donor = newSLL(displayINTEGER, freeINTEGER);
    printf("Empty recipient: ");
    showItems(recipient);
    printf("\n");
    printf("Empty donor: ");
    showItems(donor);
    printf("\n");

    // Add items to recipient list
    printf("Adding values 1, 2, and 3 to recipient...\n");
    insertSLL(recipient,0,newINTEGER(1));                   //insert at front
    insertSLL(recipient,sizeSLL(recipient),newINTEGER(3));      //insert at back
    insertSLL(recipient,1,newINTEGER(2));                   //insert at middle

    // Add items to donor list
    printf("Adding values 4, 5, and 6 to donor...\n\n");
    insertSLL(donor,0,newINTEGER(4));                   //insert at front
    insertSLL(donor,sizeSLL(donor),newINTEGER(6));      //insert at back
    insertSLL(donor,1,newINTEGER(5));                   //insert at middle

    // Display recipient and donor lists before union
    printf("Recipient before union: ");
    showItems(recipient);
    printf("Recipient size before union: %d\n", sizeSLL(recipient));
    printf("Donor before union: ");
    showItems(donor);
    printf("Donor size before union: %d\n", sizeSLL(donor));

    // Perform union
    printf("\nPerforming union of recipient and donor lists...\n");
    unionSLL(recipient, donor);

    printf("\nRecipient list after union: ");
    showItems(recipient);
    printf("Recipient size after union: %d\n", sizeSLL(recipient));
    printf("\nDonor list after union: ");
    showItems(donor);

    printf("Freeing the recipient and donor lists...\n\n");
    freeSLL(recipient);
    freeSLL(donor);

  	return 0;
}
