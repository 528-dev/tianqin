#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"
#define MAXSIZE 30

// 1.Outputs every path from root node to each leaf node.
BinTree stk1[MAXSIZE];
int top1 = -1;
void pathRoot2Leaves(BinTree bt){
    if (!bt) return;
    if (!bt->left && !bt->right){
        printf("the path of %c is: ", bt->data);
        for (int i = 0; i <= top1; ++i){
            printf("%c ", stk1[i]->data);
        }putchar('\n');
    }
    stk1[++top1] = bt;
    pathRoot2Leaves(bt->left);
    pathRoot2Leaves(bt->right);
    --top1;
}

void test1(){
    char c;
    BinTree bt = NULL;
    printf("Please enter the elements:\n");
    for (int i = 0; i < 10; ++i){
        scanf(" %c", &c);
        bt = insertBT(bt, c);
    }
    pathRoot2Leaves(bt);
}

int main(){
    test1();
}