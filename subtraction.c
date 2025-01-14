#include "apc.h"

void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
    Dlist *tempa = *head1;
    printf("Head -> ");
    while (tempa) {
        /* Printing the list */
        printf("%d <-", tempa->data);

        /* Traverse in forward direction */
        tempa = tempa->next;
        if (tempa)
            printf("> ");
    }
    printf(" Tail\n");

    Dlist *tempb = *head2;
    printf("Head -> ");
    while (tempb) {
        /* Printing the list */
        printf("%d <-", tempb->data);

        /* Traverse in forward direction */
        tempb = tempb->next;
        if (tempb)
            printf("> ");
    }
    printf(" Tail\n");

}
