#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

// MCQ
// 24 exchange left and right node.
BinTree exchangeLR(BinTree bt){
    if (bt->left) exchangeLR(bt->left);
    if (bt->right) exchangeLR(bt->right);

    BinTree tmp = bt->left;
    bt->left = bt->right;
    bt->left = tmp;

    return bt;
}

// Basic questions.
// 2.count
int cntBinTree(BinTree bt){
    if (!bt) return 0;
    return cntBinTree(bt->left) + cntBinTree(bt->right) + 1;
}

// 3.count the leaves
int cntBtLeaves(BinTree bt){
    if ((!bt->left) && (!bt->right)) return 1;
    if (bt->left && bt->right) return cntBinTree(bt->left) + cntBinTree(bt->right);
    if (bt->left) return cntBtLeaves(bt->left);
    return cntBtLeaves(bt->right);
}

// 4.link the node of Binary-tree leaves.
BinTree findFstLeaf(BinTree bt){
    if ((!bt->left) && (!bt->right)) return bt;
    if (bt->left) return findFstLeaf(bt->left);
    return findFstLeaf(bt->right);
}

void link(BinTree bt, BinTree *pre){
    if (!bt) return;
    link(bt->left, pre);

    if (*pre && !bt->left && !bt->right){
        ((*pre)->right) = bt;
    }
    *pre = bt;

    link(bt->right, pre);
}

void linkLeaves(BinTree bt, BinTree* head, BinTree* tail){
    BinTree pre = NULL;
    link(bt, &pre);
    *head = findFstLeaf(bt);
    *tail = pre;
}

// 5.reconstruct the "struct BTNode" by addition of "parent element".
typedef struct PBTNode *PBinTree;
typedef struct PBTNode{
    char data;
    PBinTree parent, left, right;
}PBTNode;

void triBTree(PBinTree bt){
    if (!bt) return;
    PBinTree tmp, queue[50];
    int top = -1;
    bt->parent = NULL;
    queue[++top] = bt;
    while (top != -1){
        tmp = queue[top--];
        if (tmp->left){
            tmp->left->parent = tmp;
            queue[++top] = bt->left;
        }
        if (tmp->right){
            tmp->right->parent = tmp;
            queue[++top] = bt->right;
        }
    }
}

// 6 convert the pretraversal array to posttraversal array. 
// ps:(FULL binary tree)
void helpConvert(BinTree *arr, int left, int right){
    BinTree tmp = arr[left];
    int i;
    for (i = 0; i < right - 1; ++i){
        arr[i] = arr[i + 1];
    }arr[i] = tmp;
}

void convert(BinTree *arr, int leftIndex, int rightIndex){
    if (leftIndex == rightIndex) return;
    int leftOrRightSize = (rightIndex - leftIndex) / 2;
    convert(arr, leftIndex + 1, leftIndex + leftOrRightSize);
    convert(arr, leftIndex + leftOrRightSize + 1, rightIndex);
    helpConvert(arr, leftIndex, rightIndex);
}

// 7. To find out the level of node X in binary tree.
typedef struct NodeInfo{
    BinTree bt;
    int level;
} NodeInfo, *btInfo;

btInfo new_btInfo(BinTree bt, int level){
    btInfo ret = (btInfo)malloc(sizeof(NodeInfo));
    ret->bt = bt;
    ret->level = level;
    return ret;
}

int findXLevel(BinTree bt, char x){
    btInfo queue[50];
    btInfo tmp;
    int top = -1, curLevel = 0;
    queue[++top] = new_btInfo(bt, 1);
    while (top == -1){
        tmp = queue[top--];
        if (tmp->bt->left) queue[++top] = new_btInfo(tmp->bt->left, tmp->level + 1);
        if (tmp->bt->right) queue[++top] = new_btInfo(tmp->bt->right, tmp->level + 1);
        if (curLevel != tmp->level){
            curLevel = tmp->level; 
        }
        if (tmp->bt->data = x) return tmp->level;
    }
    return 0;
}

