/*
 * Count number of elements in a linked list
 */
#include "linked_list.h"
/*struct node {
    int data;
    struct node *next;
}
*/

int count(struct node *head)
{
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main (void)
{
   
    /* Build a temporary linked_list */
    struct node * head  = NULL;
    head = build_llist();
    print_llist(head);

    printf("No of elements in linked list is %d\n", count(head));
    delete_llist(&head);
    return 0;
}
