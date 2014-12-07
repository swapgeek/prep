/*
 * Linked list definition and helper functions
 */
#include<stdlib.h>
#include<stdio.h>
struct node {
    int data;
    struct node * next;
};

struct node *new_node(int data)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->next = NULL;
}

void print_llist(struct node *node)
{

    printf("\n[");
    while (node) {
        printf("%d, ", node->data);
        node = node->next;
    }
    printf("]\n");
}

struct node *build_llist(void)
{
    struct node *node = NULL, *head = NULL;
    int val = 0;
    printf("\nEnter node values (Ctrl-D to stop)\t");
    while (scanf("%d", &val) > 0 ) {
        if (node == NULL) {
            node = new_node(val);
            head = node;
        } else {
            node->next = new_node(val);
            node = node->next;
        }
    }
    return head;
}

void delete_llist(struct node **headref)
{
    struct node *current = *headref;
    struct node *next = NULL;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    *headref = NULL;
}
