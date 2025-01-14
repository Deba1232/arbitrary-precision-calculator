#include "apc.h"

void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
    int num1, num2, sum, carry = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while(temp1 || temp2){
        Dlist *res_node = (Dlist *)calloc(1, sizeof(Dlist));

        if(!res_node){
            fprintf(stderr, "Memory couldn't be allocated\n");
		    exit(EXIT_FAILURE);
        }

        if(!temp1){
            num1 = 0;
            num2 = temp2->data;
        }
        else if(!temp2){
            num1 = temp1->data;
            num2 = 0;
        }
        else{
            num1 = temp1->data;
            num2 = temp2->data;
        }

        sum = num1 + num2 + carry;
        carry = sum/10;

        res_node->data = sum%10;
        res_node->prev = NULL;
        res_node->next = NULL;

        if(!*headR && !*tailR){
            *headR = res_node;
            *tailR = res_node;
        }
        else{
            res_node->next = *headR;
            (*headR)->prev = res_node;
            *headR = res_node;
        }

        if(temp1 && temp2){
            temp1 = temp1->prev;
            temp2 = temp2->prev;
        }
        //if temp2 is null, only traverse temp1
        else if(temp1){
            temp1 = temp1->prev;
        }
        //if temp1 is null, only traverse temp2
        else{
            temp2 = temp2->prev;
        }
    }
    //if there's still a carry left after the above operation
    if(carry){
        Dlist *res_node = (Dlist *)calloc(1, sizeof(Dlist));

        if(!res_node){
            fprintf(stderr, "Memory couldn't be allocated\n");
		    exit(EXIT_FAILURE);
        }

        res_node->data = carry;
        res_node->prev = NULL;
        res_node->next = NULL;

        res_node->next = *headR;
        (*headR)->prev = res_node;
        *headR = res_node;
    }

    Dlist *tempR = *headR;
    
    while (tempR) {
        printf("%d", tempR->data);
        tempR = tempR->next;
    }
    printf("\n");
}
