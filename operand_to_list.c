#include "apc.h"

int operand_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[], int flag){

    if(**(argv + 2) == '+'){
        while(*argv[1]){
            insert_at_last(head1, tail1, *argv[1] - '0');
            argv[1]++;
        }

        while(*argv[3]){
            insert_at_last(head2, tail2, *argv[3] - '0');
            argv[3]++;
        }

    }
    else if(**(argv + 2) == '-'){
        //if the first operand has more digits than second operand
        if(strlen(argv[1]) > strlen(argv[3])){
            
            while(*argv[1]){
                insert_at_last(head1, tail1, *argv[1] - '0');
                argv[1]++;
            }

            while(*argv[3]){
                insert_at_last(head2, tail2, *argv[3] - '0');
                argv[3]++;
            }
        }
        //if the second operand has more digits than first operand
        else if(strlen(argv[1]) < strlen(argv[3])){
            flag = 1;

            while(*argv[1]){
                insert_at_last(head2, tail2, *argv[1] - '0');
                argv[1]++;
            }

            while(*argv[3]){
                insert_at_last(head1, tail1, *argv[3] - '0');
                argv[3]++;
            }
        }
        else{
            //if first operand is greater than the second operand
            if(strcmp(argv[1], argv[3]) > 0){
                while(*argv[1]){
                    insert_at_last(head1, tail1, *argv[1] - '0');
                    argv[1]++;
                }

                while(*argv[3]){
                    insert_at_last(head2, tail2, *argv[3] - '0');
                    argv[3]++;
                }
            }
            //if first operand is lesser than the second operand
            else if(strcmp(argv[1], argv[3]) < 0){
                flag = 1;

                while(*argv[1]){
                    insert_at_last(head2, tail2, *argv[1] - '0');
                    argv[1]++;
                }

                while(*argv[3]){
                    insert_at_last(head1, tail1, *argv[3] - '0');
                    argv[3]++;
                }
            }
            //if both the operands are same
            else{
                flag = 2;

                while(*argv[1]){
                    insert_at_last(head1, tail1, *argv[1] - '0');
                    argv[1]++;
                }

                while(*argv[3]){
                    insert_at_last(head2, tail2, *argv[3] - '0');
                    argv[3]++;
                }
            }
        }
        return flag;
    }
}