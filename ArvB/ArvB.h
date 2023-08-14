#ifndef ARVB_H_INCLUDED
#define ARVB_H_INCLUDED


#define MAX 3
#define MIN 2

typedef struct BTreeNode {
  int val[MAX + 1], count;
  struct BTreeNode *link[MAX + 1];
} BTreeNode;




#endif // ARVB_H_INCLUDED
