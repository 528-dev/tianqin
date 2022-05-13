#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

// 10.Double-order traversal.
void visit(BinTree bt){
    printf("%d ", bt->data);
}
void dubOrderTra(BinTree bt){
    if (!bt) return;
    visit(bt);
    dubOrderTra(bt->left);
    visit(bt);
    dubOrderTra(bt->right);
}

// 11.