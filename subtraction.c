#include "apc.h"

void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int flag){
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

    int num1, num2, value, borrow = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    if((flag == 0) || (flag == 1)){

        while(temp1 || temp2){
            Dlist *res_node = (Dlist *)calloc(1, sizeof(Dlist));

            if(!res_node){
                fprintf(stderr, "Memory could't be allocated\n");
                exit(EXIT_FAILURE);
            }

            if(!temp2){
                num1 = temp1->data;
                num2 = 0;
            }
            else{
                num1 = temp1->data;
                num2 = temp2->data;
            }

            if(borrow){
                //if the previous adjacent node has value 0, change it to 9 and set borrow flag
                if(num1 == 0){
                    num1 = 9;
                    borrow = 1;
                }
                else{
                    num1-=1;
                    borrow = 0;
                }
            }
            
            if(num1 < num2){
                num1+=10;
                borrow = 1; 
            }
            
            value = num1 - num2;

            res_node->data = value;
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
        }

        if((*headR)->data == 0){
            Dlist *node_remove = *headR;
        
            *headR = (*headR)->next;
            (*headR)->prev = NULL;
            node_remove->next = NULL;

            free(node_remove);
        }

        if(flag){
            Dlist *sign_node = (Dlist *)calloc(1, sizeof(Dlist));

            if(!sign_node){
                fprintf(stderr, "Memory could't be allocated\n");
                exit(EXIT_FAILURE);
            }

            sign_node->data = '-';
            sign_node->prev = NULL;
            sign_node->next = NULL;
        }
    }
    else{
        Dlist *res_node = (Dlist *)calloc(1, sizeof(Dlist));

        if(!res_node){
            fprintf(stderr, "Memory could't be allocated\n");
            exit(EXIT_FAILURE);
        }

        res_node->data = 0;
        res_node->prev = NULL;
        res_node->next = NULL;

        *headR = res_node;
        *tailR = res_node;
    }


    Dlist *tempr = *headR;
    printf("Head -> ");
    while (tempr) {
        /* Printing the list */
        printf("%d <-", tempr->data);

        /* Traverse in forward direction */
        tempr = tempr->next;
        if (tempr)
            printf("> ");
    }
    printf(" Tail\n");

}
