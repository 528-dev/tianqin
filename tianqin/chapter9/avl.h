#ifndef AVL_H
#define AVL_H

struct AVLTNode;
typedef struct AVLTNode *AvlTree, *PAVLTNode;
typedef struct AVLTNode AVLTNode;

AvlTree new_AvlTree(int, AvlTree, AvlTree, int);
AvlTree insert(AvlTree, int);

#endif