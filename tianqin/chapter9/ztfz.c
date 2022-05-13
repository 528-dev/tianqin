#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

// 1.To determine if a binary search tree is legitimate.
int inTrav(BinTree bt, BinTree *pre){
    if (!bt) return 1;

    int retLeft, retRight;
    retLeft = inTrav(bt->left, pre);
    
    if (!pre && (*pre)->key > bt->key) return 0;
    (*pre) = bt;
    
    retRight = inTrav(bt->right, pre);
    
    return retLeft && retRight;
}

int solution(BinTree bt){
    return inTrav(bt, NULL);
}