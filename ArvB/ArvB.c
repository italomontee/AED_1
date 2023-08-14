#include <stdio.h>
#include <stdlib.h>
#include "ArvB.h"

BTreeNode *createNode(int val, BTreeNode *child) {
  BTreeNode *newNode;
  newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
  newNode->val[1] = val;
  newNode->count = 1;
  newNode->link[0] = NULL;
  newNode->link[1] = child;
  return newNode;
}

void insertNode(int val, int pos, BTreeNode *node,
        BTreeNode *child) {
  int j = node->count;
  while (j > pos) {
    node->val[j + 1] = node->val[j];
    node->link[j + 1] = node->link[j];
    j--;
  }
  node->val[j + 1] = val;
  node->link[j + 1] = child;
  node->count++;
}

void splitNode(int val, int *pval, int pos, BTreeNode *node,
         BTreeNode *child, BTreeNode **newNode) {
  int median, j;

  if (pos > MIN)
    median = MIN + 1;
  else
    median = MIN;

  *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
  j = median + 1;
  while (j <= MAX) {
    (*newNode)->val[j - median] = node->val[j];
    (*newNode)->link[j - median] = node->link[j];
    j++;
  }
  node->count = median;
  (*newNode)->count = MAX - median;

  if (pos <= MIN) {
    insertNode(val, pos, node, child);
  } else {
    insertNode(val, pos - median, *newNode, child);
  }
  *pval = node->val[node->count];
  (*newNode)->link[0] = node->link[node->count];
  node->count--;
}

int setValue(int val, int *pval,
           BTreeNode *node, BTreeNode **child) {
  int pos;
  if (!node) {
    *pval = val;
    *child = NULL;
    return 1;
  }

  if (val < node->val[1]) {
    pos = 0;
  } else {
    for (pos = node->count;
       (val < node->val[pos] && pos > 1); pos--)
      ;
    if (val == node->val[pos]) {
      printf("Duplicates are not permitted\n");
      return 0;
    }
  }
  if (setValue(val, pval, node->link[pos], child)) {
    if (node->count < MAX) {
      insertNode(*pval, pos, node, *child);
    } else {
      splitNode(*pval, pval, pos, node, *child, child);
      return 1;
    }
  }
  return 0;
}

void insert(int val, BTreeNode **root) {
  int flag, i;
  BTreeNode *child;

  flag = setValue(val, &i, *root, &child);
  if (flag)
    *root = createNode(i, child);
}

void search(int val, int *pos, BTreeNode *myNode) {
  if (!myNode) {
    return;
  }

  if (val < myNode->val[1]) {
    *pos = 0;
  } else {
    for (*pos = myNode->count;
       (val < myNode->val[*pos] && *pos > 1); (*pos)--)
      ;
    if (val == myNode->val[*pos]) {
      printf("%d is found\n", val);
      return;
    }
  }
  search(val, pos, myNode->link[*pos]);

  return;
}

void traversal(BTreeNode *myNode) {
  int i;
  if (myNode) {
    for (i = 0; i < myNode->count; i++) {
      traversal(myNode->link[i]);
      printf("%d ", myNode->val[i + 1]);
    }
    traversal(myNode->link[i]);
  }
}
