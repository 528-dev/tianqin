#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

// Please constructe A binary tree, given a pre-order traversal and a middle-order traversal.
BinTree CreateBT(char* pre, char* in, int l1, int r1, int l2, int r2){
    BinTree bt;
    int i, leftn, rightn;
    if (l1 > r1) return NULL;
    bt = (BinTree)malloc(sizeof(BTNode));
    bt->data = pre[l1];
    for (i = l2; i <= r2 && pre[l1] != in[i]; ++i);
    leftn = (i - 1) - l2 + 1;
    rightn = r2 - (i + 1) + 1;
    bt->left = CreateBT(pre, in, l1 + 1, l1 + 1 + leftn - 1, l2, i - 1);
    bt->right = CreateBT(pre, in, l1 + 1 + leftn - 1 + 1, r1, i + 1, r2);
    return bt;
}

