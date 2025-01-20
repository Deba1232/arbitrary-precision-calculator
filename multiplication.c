#include "apc.h"

void multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR){
    int num1, num2, count = 0, carry = 0;
    Dlist *headR2 = NULL, *tailR2 = NULL; //for result list2
    Dlist *head_backup = NULL, *tail_backup = NULL; //for backup list
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while(temp2){

        for(int i=0;i<count;i++){
            insert_at_first(&headR2, &tailR2, 0);
        }
        count++;
        //run the loop until temp1 gets null and carry becomes 0 
        while(temp1 || carry){

            if(temp1){
                num1 = temp1->data;
                temp1 = temp1->prev;
            }
            else{
                num1 = 0;
            }

            if(temp2){
                num2 = temp2->data;
            }
            else{
                num2 = 0;
            }

            int result = num1 * num2 + carry;
            carry = result / 10;

            if(count == 1){
                insert_at_first(headR, tailR, result%10);
            }
            else{
                insert_at_first(&headR2, &tailR2, result%10);
            }
        }

        addition(headR, tailR, &headR2, &tailR2, &head_backup, &tail_backup, 1);
        
        //empty result list 1 and result list 2
        delete_list(headR, tailR);
        delete_list(&headR2, &tailR2);

        //add the result from addition operation to result list 1
        Dlist *temp_backup = tail_backup;

        while(temp_backup){
            insert_at_first(headR, tailR, temp_backup->data);

            temp_backup = temp_backup->prev;
        }

        //now empty the backup list, so that new addition result can be added to it
        delete_list(&head_backup, &tail_backup);
        head_backup = tail_backup = NULL;
        
        temp1 = *tail1;
        temp2 = temp2->prev;
    }

    Dlist *tempR = *headR;

    while (tempR) {
        printf("%d", tempR->data);
        tempR = tempR->next;
    }
    printf("\n");
}