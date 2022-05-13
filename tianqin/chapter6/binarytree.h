#ifndef BINARYTREE_H
#define BINARYTREE_H

typedef struct BTNode *BinTree;
typedef struct BTNode{
    char data;
    BinTree left, right;
} BTNode;

void visit(BinTree);
void preOrder(BinTree);
void inOrder(BinTree);
void postOrder(BinTree);
void levelTrav(BinTree);
void preOrderNonRecursion(BinTree);
void preOrderNonRecursion2(BinTree);
void inOrderNonRecursion(BinTree);
void postOrderNonRecursion(BinTree);
void postOrderNonRecurions2(BinTree);
BinTree insertBT(BinTree, char);

#endif