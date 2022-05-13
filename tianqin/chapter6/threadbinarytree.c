#include<stdio.h>
#include<stdlib.h>

typedef struct TBTNode* tBinTree;
typedef struct TBTNode{
    char data;
    int ltag, rtag;
    tBinTree left, right;
}TBTNode;

void inTread(tBinTree p, tBinTree* pre){
    if (!p) return;
    inTread(p->left, pre);

    if (!p->left){
        p->left = pre;
        p->ltag = 1;
    }

    if ((*pre) && !(*pre)->right){
        (*pre)->right = p;
        (*pre)->rtag = 1;
    }

    pre = p;

    inTread(p->right, pre);
}

void createInThread(tBinTree root){
    if (!root) return;
    tBinTree pre = NULL;
    inTread(root, pre);
    pre->right = NULL;
    pre->rtag = 1;
}

tBinTree firstNode(tBinTree tbt){
    while (!tbt->ltag){
        tbt = tbt->left;
    }return tbt;
}

tBinTree nextNode(tBinTree tbt){
    if (!tbt->rtag) return firstNode(tbt->right);
    else return tbt->right;
}

void inOrder(tBinTree root){
    while (root){
        printf("%c ", root->data);
        root = nextNode(root);
    }
}