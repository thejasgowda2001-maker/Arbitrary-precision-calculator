/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "apc.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <operand1> <operator> <operand2>\n", argv[0]);
		printf("Example: %s 13579+24689\n", argv[0]);
		return 1;
	}

	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL;
	char operator;
	char *expression = argv[1];

	// Extract opertor and its position
	int op_pos = -1;
    for (int i = 0; expression[i]; i++)
    {
        if (expression[i] == '+' || expression[i] == '-' ||
            expression[i] == '*' || expression[i] == '/')
        {
            operator = expression[i];
            op_pos = i;
            break;
        }
    }

	if (op_pos == -1)
    {
        printf("Error: Operator not found in expression.\n");
        return 1;
    }

    // Split operands
    char num1[512], num2[512];
    strncpy(num1, expression, op_pos);
    num1[op_pos] = '\0';
    strcpy(num2, expression + op_pos + 1);

	// Validate input
    if (strlen(num1) == 0 || strlen(num2) == 0)
    {
        printf("Invalid expression. Operands missing.\n");
        return 1;
    }

	// Convert strings to DLLs
    string_to_dlist(num1, &head1, &tail1);
    string_to_dlist(num2, &head2, &tail2);

	// Perform operation
    switch (operator)
    {
        case '+':
            headR = addition(head1, tail1, head2, tail2);
			break;
        case '-':
            headR = subtraction(head1, tail1, head2, tail2);
            break;
        case '*':
            headR = multiplication(head1, tail1, head2, tail2);
            break;
        case '/':
            headR = division(head1, tail1, head2, tail2); 
            break;
        default:
            printf("Unsupported operator.\n");
            free_list(&head1);
            free_list(&head2);
            return 1;
    }

    printf("- - - - - - - - - - - - -\n");
    printf("  APC - Operation Result\n");
    printf("- - - - - - - - - - - - - -\n");
    printf("Expression : %s\n", expression);
    printf("Operator   : %c\n", operator);
    printf("Result   = ");
    print_list(headR);
    printf("_ _ _ _ _ _ _ _ _ _\n");
    

    // Free the all memory
    free_list(&head1);
    free_list(&head2);
    free_list(&headR);

    return 0;
}