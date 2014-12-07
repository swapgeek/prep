/*
 * Reverse a linked list (iterative version
 */
#include "linked_list.h"

void reverse_llist(struct node **headref)
{
    struct node *prev_node = NULL, *next_node = NULL, *current = NULL;

    current = *headref;
    while (current) {
        next_node = current->next;
        current->next = prev_node;
        prev_node = current;
        current = next_node;
    }
    *headref = prev_node;
}

int main (void)
{
   
    /* Build a temporary linked_list */
    struct node * head  = NULL;
    head = build_llist();
    print_llist(head);
    reverse_llist(&head);
    print_llist(head);
    delete_llist(&head);
    return 0;
}
