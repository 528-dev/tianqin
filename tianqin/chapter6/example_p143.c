#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

#define MAXSIZE 50

int op(int a, int b, char o){return 1;}

// example6_1 
// given a expression binary tree,
// please calculate it.

// note: the "op function" has not been implemented.
int comp(BinTree bt){
    if (!bt) return 0;
    if (bt->left && bt->right) return op(comp(bt->left), comp(bt->right), bt->data);
    return bt->data - '0';
}

// example6_2
// Calculate the height of a binary tree. 
int height(BinTree bt){
    if (!bt) return 0;
    return 1 + (__max(height(bt->left), height(bt->right)));
}

// exapmle6_3
// Serarch element in a binary tree.
int searchBinTree(BinTree bt, char elem, BinTree *p){
    if (!bt) return 0;
    *p = bt;
    if ((*p)->data = elem) return 1;
    if (searchBinTree(bt->left, elem, p)) return 1;
    if (searchBinTree(bt->right, elem, p)) return 1;
    return 0;
}

// example6_4
// visit the kth elements
int n = 0;
int travelK(BinTree bt, int k){
    if (!bt) return 0;
    ++n;
    if (n == k){
        printf("The kth element is %c.", bt->data);
        return 1;
    }
    if (travelK(bt->left, k)) return 1;
    if (travelK(bt->right, k)) return 1;
}