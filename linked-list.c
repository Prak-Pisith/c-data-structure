#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  /* data */
  int data; // data to be stored in node
  struct node *next; // Pointer to the next node
}
node;

int main (void) {


  // List of size
  node *list = NULL;

  node *n = malloc(sizeof(node));
  if (n == NULL) {
    return 1;
  }
  n->data = 1;
  n->next = NULL;

  // Update list to point to the new node
  list = n;

  // Add a new number to list
  n = malloc(sizeof(node));
  if (n == NULL) {
    free(list);
    return 1;
  }
  n->data = 2;
  n->next = NULL;
  list->next = n;

  // Add a new number to list
  n = malloc(sizeof(node));
  if (n == NULL) {
    free(list->next);
    free(list);
    return 1;
  }
  n->data = 3;
  n->next = NULL;
  list->next->next = n;

  // Print number
  node *tmp = list;
  while (tmp != NULL)
  {
    printf("%i\n", tmp->data);
    tmp = tmp->next;
  }
  

}