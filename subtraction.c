/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "apc.h"


Dlist *subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    Dlist *result_head = NULL, *result_tail = NULL;
    int borrow = 0, diff = 0;

    while (tail1 != NULL || tail2 != NULL)
    {
        int digit1 = (tail1 != NULL) ? tail1->data : 0;
        int digit2 = (tail2 != NULL) ? tail2->data : 0;

        digit1 -= borrow;  // subtract borrow if any

        if (digit1 < digit2)
        {
            digit1 += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        diff = digit1 - digit2;

        insert_first(&result_head, &result_tail, diff);

        if (tail1) tail1 = tail1->prev;
        if (tail2) tail2 = tail2->prev;
    }

    // Remove leading zeros from the result (if any)
    while (result_head && result_head->data == 0 && result_head->next != NULL)
    {
        Dlist *temp = result_head;
        result_head = result_head->next;
        result_head->prev = NULL;
        free(temp);
    }

    return result_head;
}

