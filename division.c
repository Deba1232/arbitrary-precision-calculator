#include "apc.h"

void division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[]){
    int count = 0;
    int length1 = strlen(argv[1]), length2 = strlen(argv[3]);

    if(atoi(argv[3]) == 0){
        printf("Cannot divide by ZERO\n");
		return;
    }

    if(length1 > length2 || (length1 == length2 && strcmp(argv[1], argv[3]) > 0)){
        operand_to_list(head1, tail1, head2, tail2, argv, 0);
    }
    else if(strcmp(argv[1], argv[3]) < 0){
        printf("0\n");
        return;
    }
    else{
        printf("1\n");
        return;
    }

    while((length1 > length2) || ((*head1)->data >= (*head2)->data)){

        if(length1 < length2){
            break;
        }

        if(length1 == 1 && (*head1)->data == (*head2)->data){
            subtraction(head1, tail1, head2, tail2, headR, tailR, 2, 1);
        }
        else{
            subtraction(head1, tail1, head2, tail2, headR, tailR, 0, 1);
        }

        delete_list(head1, tail1);

        Dlist *tempR = *tailR;
        while(tempR){
            insert_at_first(head1, tail1, tempR->data);
            tempR = tempR->prev;
        }

        delete_list(headR, tailR);

        Dlist *temp = *head1;
        length1 = 0; //here we are resetting the value of length1 as now we want to take length for the new number present in list1
        while(temp){
            length1++;
            temp = temp->next;
        }

        count++;
    }
    printf("%d\n", count);
}
