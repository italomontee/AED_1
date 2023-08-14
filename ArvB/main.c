#include <stdio.h>
#include <stdlib.h>
#include "ArvB.h"

int main() {
  int val, ch;
  BTreeNode *root = NULL;

  insert(8, &root);
  insert(9, &root);
  insert(10, &root);
  insert(11, &root);
  insert(15, &root);
  insert(16, &root);


  traversal(root);

  printf("\n");
  search(17, &ch, root);
}
