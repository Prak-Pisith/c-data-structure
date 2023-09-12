#include <stdio.h>
#include <stdlib.h>

int main (void) {

  /* 
    Both are equivalent, Create Array of Size 3
    1. Put fixed memory on the STACK
    2. Put fixed memory on the HEAP
   */

  // int list[3];
  int *list = malloc(3 * sizeof(int)); // both are equal
  
  // check error
  if (list == NULL) {
    return 1;
  }

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  // Time passes
  // Need more spaces

  int *tmp = realloc(list, 4 * sizeof(int));
  // Safty check
  if (tmp == NULL) {
    free(list);
    return 1;
  }

  for (int i = 0; i < 3; i++) {
    tmp[i] = list[i];
  }
  tmp[3] = 4;
  // Temp task is completed

  // Free old array
  free(list);

  // Remember new array
  list = tmp;

  for (int i = 0; i < 4; i++) {
    printf("%i\n", list[i]);
  }
  /* 
    Why don't we free the TMP?
    Because tmp have assigned to list then both pointed to the same address
    and below free list => mean that free that same address (both list and tmp are freed)
   */
  free(list);
  return 0;



}