#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;

/* Include the prototypes here */

void insert_at_first(Dlist **head, Dlist **tail, int data);
void insert_at_last(Dlist **head, Dlist **tail, int data);
void delete_list(Dlist **head, Dlist **tail);

/*store the operands into the list */
int operand_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *argv[],int sign_flag);

/*Addition */
//here multiply flag denotes whether addition function is being called from the multiplication function or not
void addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR, int multiply_flag);

/*subtraction*/
void subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,int sign_flag);

/*Multiplication*/
void multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*Division */
// int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

#endif