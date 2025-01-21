#include "apc.h"

void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int multiply_flag){
    int num1, num2, sum, carry = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while(temp1 || temp2){

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

        insert_at_first(headR, tailR, sum%10);

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
        insert_at_first(headR, tailR, carry);
    }

    if(!multiply_flag){
        zeronode(headR, tailR);
        
        Dlist *tempR = *headR;
        while (tempR) {
            printf("%d", tempR->data);
            tempR = tempR->next;
        }
        printf("\n");
    }
}
