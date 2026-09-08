/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/

#include "apc.h"
#include<stdio.h>
#include<stddef.h>

// Division function
Dlist *division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2) {
    if (head2 == NULL) {
        printf("Error: Division by zero\n");
        return NULL;
    }

    // If the dividend < divisor, quotient will be 0
    if (compare(head1, head2) < 0) {
        // Create a linked list with single digit 0
        Dlist *quot = create_node(0);
        return quot;
    }

    Dlist *quotient_head = NULL, *quotient_tail = NULL;
    Dlist *remainder_head = NULL, *remainder_tail = NULL;

    Dlist *current = head1;

    // Iterate over dividend digits (from the head to tail)
    while (current != NULL) {
        // Append current digit to remainder
        append_digit(&remainder_head, &remainder_tail, current->data);

        // Remove leading zeros in remainder if any present
        remove_leading_zeros(&remainder_head, &remainder_tail);

        // Initialize count for this digit of quotient
        int count = 0;

        // While remainder >= divisor
        while (compare(remainder_head, head2) >= 0) {
            // remainder = remainder - divisor
            Dlist *temp = subtraction(remainder_head, remainder_tail, head2, tail2);

            // Free old remainder
            free_list(&remainder_head);
            remainder_head = temp;
            // Update remainder_tail accordingly
            remainder_tail = get_tail(remainder_head);

            count++;
        }

        // Append count to quotient
        append_digit(&quotient_head, &quotient_tail, count);

        current = current->next;
    }

    // Remove leading zeros in quotient if any present
    remove_leading_zeros(&quotient_head, &quotient_tail);

    // Free remainder list if needed
    free_list(&remainder_head);

    return quotient_head;
}
