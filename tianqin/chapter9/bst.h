#ifndef BST_H
#define BST_H

struct BTNode;
struct BTNode{
    int key;
    PBTNode left, right;   
};
typedef struct BTNode *BinTree, *PBTNode;
typedef struct BTNode BTNode;

BinTree new_BinTree(int, BinTree, BinTree);
BinTree bstSearch(BinTree, int);
BinTree bstSearchNonRecursion(BinTree, int);
BinTree bstInsert(BinTree, int);
BinTree createBst(int[], int);
BinTree bstFindMin(BinTree);
BinTree bstFindMax(BinTree);
BinTree bstDelete(BinTree, int);

#endif