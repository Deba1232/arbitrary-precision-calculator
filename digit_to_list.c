#include "apc.h"

void digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *argv[]){

    while(*argv[1]){
        Dlist *digit_node = (Dlist *)calloc(1, sizeof(Dlist));

        if(!digit_node){
            fprintf(stderr, "Memory couldn't be allocated\n");
		    exit(EXIT_FAILURE);
        }

        digit_node->data = *argv[1] - '0';
        digit_node->prev = NULL;
        digit_node->next = NULL;
        
        if(!*head1 && !*tail1){
            *head1 = digit_node;
            *tail1 = digit_node;
        }
        else{
            digit_node->prev = *tail1;
            (*tail1)->next = digit_node;
            *tail1 = digit_node;
        }

        argv[1]++;
    }

    while(*argv[3]){
        Dlist *digit_node = (Dlist *)calloc(1, sizeof(Dlist));

        if(!digit_node){
            fprintf(stderr, "Memory couldn't be allocated\n");
		    exit(EXIT_FAILURE);
        }
        
        digit_node->data = *argv[3] - '0';
        digit_node->prev = NULL;
        digit_node->next = NULL;
        
        if(!*head2 && !*tail2){
            *head2 = digit_node;
            *tail2 = digit_node;
        }
        else{
            digit_node->prev = *tail2;
            (*tail2)->next = digit_node;
            *tail2 = digit_node;
        }

        argv[3]++;
    }
}

