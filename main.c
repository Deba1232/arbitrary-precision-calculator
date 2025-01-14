#include "apc.h"

int main(int argc, char* argv[])
{
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL,*tailR=NULL;

	if(argc == 4){

		if(isdigit(**(argv + 1)) && isdigit(**(argv + 3))){
			char operator = **(argv + 2);

			if(operator=='+' || operator=='-' || operator=='x' || operator=='/'){
				switch (operator){
					case '+':
                		digit_to_list(&head1,&tail1,&head2,&tail2,argv);
						/* call the function to perform the addition operation */
                		addition(&head1,&tail1,&head2,&tail2,&headR,&tailR);
						break;
					case '-':
						digit_to_list(&head1,&tail1,&head2,&tail2,argv);	
						/* call the function to perform the subtraction operation */
						subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR);
						break;
					case 'x':	
						/* call the function to perform the multiplication operation */
						break;
					case '/':	
						/* call the function to perform the division operation */
						break;
					default:
						printf("Invalid Input:-( Try again...\n");
				}
			}
			else{
				fprintf(stderr, "Improper operator given\n");
				exit(EXIT_FAILURE);
			}
		}
		else{
			fprintf(stderr, "Improper operands given\n");
			exit(EXIT_FAILURE);
		}
		
	}
	else{
		fprintf(stderr, "Arguments not proper\n");
		exit(EXIT_FAILURE);
	}

	return 0;
}
