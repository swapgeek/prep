#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
struct node {
  int data;
  struct node * next;
};

void printlist(struct node *node);

void reverse(struct node **headref)
{
  struct node *old_head = NULL, *current = NULL, *prev = NULL, *next = NULL;

 
  old_head = *headref;
  current = *headref;
  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *headref = prev;

}

struct node *new_node(int data)
{
  struct node *node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->next = NULL;
}

void printlist(struct node *node)
{

  cout << endl;
  while (node) {
    cout << node->data << ", ";
    node = node->next;
  }
  cout << endl;

}
int main(void) {

  int i;
  struct node * node = NULL, *head = NULL;
  while (1) {
    cin >> i;
    if (i < 0) 
      break;
    if (node == NULL) {
      node = new_node(i);
      head = node;
    } else {
      node->next = new_node(i);
      node = node->next;
    }
  }

  printlist(head);
  cout << endl;
  reverse(&head);
  printlist(head);
  cout << endl;

}
