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

static void showItems(SLL *items)
   {
   printf("The items are ");
   displaySLL(items,stdout);
   printf(".\n");
   printf("The items (debugged) are ");
   displaySLLdebug(items,stdout);
   printf(".\n");
   }

int main(void)
   {
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

    // Test unionSLL functionality
    printf("\nTesting unionSLL now...\n");
    printf("Creating empty recipient and donor lists...\n");
    SLL *recipient = newSLL(displayINTEGER, freeINTEGER);
    SLL *donor = newSLL(displayINTEGER, freeINTEGER);
    printf("First testing a union with two empty lists...\n");
    printf("Recipient: ");
    displaySLL(recipient, stdout);
    printf("\n");
    printf("Donor: ");
    displaySLL(donor, stdout);
    printf("\n");

    printf("Adding integers 3 4 5 to recipient...\n");
    insertSLL(recipient, sizeSLL(recipient), newINTEGER(3));
    insertSLL(recipient, sizeSLL(recipient), newINTEGER(4));
    insertSLL(recipient, sizeSLL(recipient), newINTEGER(5));
    printf("Adding integers 1 2 to donor...\n");
    insertSLL(donor, sizeSLL(donor), newINTEGER(1));
    insertSLL(donor, sizeSLL(donor), newINTEGER(2));
    printf("Recipient: ");
    displaySLL(recipient, stdout);
    printf("\n");
    printf("Donor: ");
    displaySLL(donor, stdout);
    printf("\n");
    unionSLL(recipient, donor);
    printf("Recipient after union: ");
    displaySLL(recipient, stdout);
    printf("\n");
    printf("Donor after union: ");
    displaySLL(donor, stdout);
    printf("\n");
    freeSLL(recipient);
    freeSLL(donor);

   return 0;
   }
