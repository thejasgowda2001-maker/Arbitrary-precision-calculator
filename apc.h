#ifndef APC_H
#define APC_H

#define SUCCESS 0
#define FAILURE -1

typedef int data_t;

typedef struct node
{
    struct node *prev;
    data_t data;
    struct node *next;
} Dlist;

/* ========== DLL Operations ========== */
Dlist *create_node(data_t data);

int insert_first(Dlist **head, Dlist **tail, data_t data);
int insert_last(Dlist **head, Dlist **tail, data_t data);
void free_list(Dlist **head);
void print_list(Dlist *head);

/* ========== Input Conversion ========== */
void string_to_dlist(const char *str, Dlist **head, Dlist **tail);

/* ========== Arithmetic Operations ========== */
Dlist *addition(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist *subtraction(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist *multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist *add_lists(Dlist *head1, Dlist *head2);

// Add these two helper declarations here:
void append_digit(Dlist **head, Dlist **tail, data_t digit);
void remove_leading_zeros(Dlist **head, Dlist **tail);
int compare(Dlist *head1, Dlist *head2);
Dlist *get_tail(Dlist *head);
int compare(Dlist *head1, Dlist *head2);

Dlist *division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2); // Optional 

#endif
