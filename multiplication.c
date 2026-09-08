/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"
#include <stdlib.h>

Dlist *multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    if (!head1 || !head2)
        return NULL;

    Dlist *t2 = tail2;
    int zero_padding = 0;

    Dlist *result_head = NULL;

    while (t2)
    {
        int carry = 0;
        Dlist *partial_head = NULL, *partial_tail = NULL;
        Dlist *t1 = tail1;

        // Append zeros for place value
        for (int i = 0; i < zero_padding; i++)
        {
            insert_first(&partial_head, &partial_tail, 0);
        }

        while (t1)
        {
            int product = t1->data * t2->data + carry;
            insert_first(&partial_head, &partial_tail, product % 10);
            carry = product / 10;
            t1 = t1->prev;
        }

        if (carry)
        {
            insert_first(&partial_head, &partial_tail, carry);
        }

        result_head = add_lists(result_head, partial_head);

        t2 = t2->prev;
        zero_padding++;
    }

    // Remove leading zeros if any
    while (result_head && result_head->data == 0 && result_head->next != NULL)
    {
        Dlist *temp = result_head;
        result_head = result_head->next;
        result_head->prev = NULL;
        free(temp);
    }

    return result_head;
}


