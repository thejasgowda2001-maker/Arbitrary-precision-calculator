/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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

Dlist *addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    Dlist *result_head = NULL, *result_tail = NULL;
    int carry = 0, sum = 0;

    // Add from tail to head (least significant digit to most)
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int digit1 = (tail1 != NULL) ? tail1->data : 0;
        int digit2 = (tail2 != NULL) ? tail2->data : 0;

        sum = digit1 + digit2 + carry;
        carry = sum / 10;

        insert_first(&result_head, &result_tail, sum % 10);

        if (tail1 != NULL) tail1 = tail1->prev;
        if (tail2 != NULL) tail2 = tail2->prev;
    }

    return result_head;
}
