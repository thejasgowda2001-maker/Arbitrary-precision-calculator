#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "apc.h"
//Function to cretae a new nodw with given data
Dlist *create_node(int data)
{
    Dlist *new = malloc(sizeof(Dlist));
    new->data = data;
    new->prev = new->next = NULL;
    return new;
}
//Insert end of Dll
int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = create_node(data);
    if (!new) return -1;  //memory

    if (*head == NULL)//empty list new node is head and tail
        *head = *tail = new; //link at last
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return 0;
}

int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = create_node(data);
    if (!new) return -1;

    if (*head == NULL)  //empty list
    {
        *head = *tail = new; //link before head
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
    return 0;
}

//Add two list
Dlist *add_lists(Dlist *head1, Dlist *head2)
{
    Dlist *t1 = head1, *t2 = head2;
    Dlist *result = NULL, *tail = NULL;
    int carry = 0;

    // Move to tail of both lists
    while (t1 && t1->next) t1 = t1->next;
    while (t2 && t2->next) t2 = t2->next;

    while (t1 || t2 || carry)
    {
        int sum = carry;
        if (t1) { sum += t1->data; t1 = t1->prev; }
        if (t2) { sum += t2->data; t2 = t2->prev; }

        insert_first(&result, &tail, sum % 10); //store last digit
        carry = sum / 10;
    }

    return result;
}
//convert string to dlist
void string_to_dlist(const char *str, Dlist **head, Dlist **tail)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            insert_last(head, tail, str[i] - '0');
        else
            printf("Invalid character in input: %c\n", str[i]);
    }
}
//print num stored in dll
void print_list(Dlist *head)
{
    while (head && head->data == 0) head = head->next; // skip leading zeros
    if (!head) { printf("0\n"); return; }

    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}
//free the list
void free_list(Dlist **head)
{
    Dlist *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
//comparing the dll
int compare(Dlist *head1, Dlist *head2)
{
    int len1=0, len2=0;
    Dlist *temp1=head1, *temp2=head2;
    while(temp1)
    {
        len1++;
        temp1=temp1->next;
    }
    while(temp2)
    {
        len2++;
        temp2=temp2->next;
    }
    if(len1>len2)
    return 1;
    else if(len1<len2)
    return -1;
    //same length  
    temp1=head1;
    temp2=head2;
    while(temp1 && temp2)
    {
        if(temp1->data > temp2->data)
        return 1;
        else if(temp1->data < temp2->data)
        return -1;

        temp1=temp1->next;
        temp2=temp2->next;
    }
    return 0;
}
//append digit at end of dll
void append_digit(Dlist **head, Dlist **tail, data_t digit) {
    Dlist *new_node = create_node(digit);
    if (new_node == NULL)
        return; // handle malloc failure if needed

    if (*head == NULL) {
        *head = new_node;
        *tail = new_node;
    } else {
        (*tail)->next = new_node;
        new_node->prev = *tail;
        *tail = new_node;
    }
}
//remove extra zeroes
void remove_leading_zeros(Dlist **head, Dlist **tail) {
    if (*head == NULL) return;

    while (*head != NULL && (*head)->data == 0 && (*head)->next != NULL) {
        Dlist *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }
//if all nodes deleted
    if (*head == NULL) {
        *tail = NULL;
    }
}
//move to last node
Dlist *get_tail(Dlist *head) {
    if (!head) return NULL;
    while (head->next) head = head->next;
    return head;
}

