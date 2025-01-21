#include "apc.h"

void insert_at_first(Dlist **head, Dlist **tail, int data){
    Dlist *res_node = (Dlist *)calloc(1, sizeof(Dlist));

    if(!res_node){
        fprintf(stderr, "Memory couldn't be allocated\n");
		exit(EXIT_FAILURE);
    }

    res_node->data = data;
    res_node->prev = NULL;
    res_node->next = NULL;

    if(!*head && !*tail){
        *head = res_node;
        *tail = res_node;
    }
    else{
        res_node->next = *head;
        (*head)->prev = res_node;
        *head = res_node;
    }
}

void insert_at_last(Dlist **head, Dlist **tail, int data){
    Dlist *digit_node = (Dlist *)calloc(1, sizeof(Dlist));

    if(!digit_node){
        fprintf(stderr, "Memory couldn't be allocated\n");
		exit(EXIT_FAILURE);
    }

    digit_node->data = data;
    digit_node->prev = NULL;
    digit_node->next = NULL;
        
    if(!*head && !*tail){
        *head = digit_node;
        *tail = digit_node;
    }
    else{
        digit_node->prev = *tail;
        (*tail)->next = digit_node;
        *tail = digit_node;
    }
}

void delete_list(Dlist **head, Dlist **tail){
    Dlist *temp = *head;
    
    while(*head){
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    free(*head);

    *head = *tail = NULL;
}

void zeronode(Dlist **head, Dlist **tail)
{
    while((*head)->data == 0)
    {
        if((*head)->next == NULL)
            break;
        delete_first(head,tail);
    }
}

void delete_first(Dlist **head, Dlist **tail)
{
    if(*head == NULL)   //if list is empty
    {
        return ;
    }
    if((*head)->next == NULL) //condition to check whether only single node is present in the list or not
    {
        free(*head);
        *head =*tail=NULL;
        return;
    }
    Dlist *temp = *head;    //if multiple nodes are present
    *head = temp->next;
    free(temp);
    (*head)->prev=NULL;
}