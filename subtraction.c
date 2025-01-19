#include "apc.h"

void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int flag){
    int num1, num2, value, borrow = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    if((flag == 0) || (flag == 1)){

        while(temp1 || temp2){

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

            insert_at_first(headR, tailR, value);

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
            insert_at_first(headR, tailR, '-');
        }
    }
    else{
        insert_at_first(headR, tailR, 0);
    }

    Dlist *tempr = *headR;
    while (tempr) {
        /* Printing the list */
        if(tempr->data == 45){
            printf("%c", tempr->data);
        }
        else{
            printf("%d", tempr->data);
        }
        /* Traverse in forward direction */
        tempr = tempr->next;
    }
    printf("\n"); 
}