#include "apc.h"

int main(int argc, char* argv[])
{
	Dlist *head1=NULL, *tail1=NULL;
    Dlist *head2=NULL, *tail2=NULL; 
    Dlist *headR=NULL, *tailR=NULL;

	int operand_flag = 1;
	/* Flag to indicate if the result is negative or zero*/
	int sign_flag = 0;

	if(argc == 4){
		//validation for both the operands
		char *operand1 = argv[1], *operand2 = argv[3];

		while(*operand1){
			if(!isdigit(*operand1)){
				operand_flag = 0;
				break;
			}
			operand1++;
		}

		while(*operand2){
			if(!isdigit(*operand2)){
				operand_flag = 0;
				break;
			}
			operand2++;
		}

		if(operand_flag){
			char operator = **(argv + 2);

			if(operator=='+' || operator=='-' || operator=='x' || operator=='/'){
				switch (operator){
					case '+':
                		operand_to_list(&head1,&tail1,&head2,&tail2,argv,sign_flag);
						/* call the function to perform the addition operation */
                		addition(&head1,&tail1,&head2,&tail2,&headR,&tailR,0);
						break;
					case '-':
						sign_flag = operand_to_list(&head1,&tail1,&head2,&tail2,argv,sign_flag);	
						/* call the function to perform the subtraction operation */
						subtraction(&head1,&tail1,&head2,&tail2,&headR,&tailR,sign_flag,0);
						break;
					case 'x':
						operand_to_list(&head1,&tail1,&head2,&tail2,argv,sign_flag);	
						/* call the function to perform the multiplication operation */
						multiplication(&head1,&tail1,&head2,&tail2,&headR,&tailR);
						break;
					case '/':
						/* call the function to perform the division operation */
						division(&head1,&tail1,&head2,&tail2,&headR,&tailR, argv);
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
