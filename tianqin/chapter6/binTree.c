#include<stdio.h>
#include<stdlib.h>
#include"binarytree.h"

#define MAXSIZE 50

void visit(BinTree bt){
    printf("%c ", bt->data);
}

void preOrder(BinTree bt){
    if (!bt) return;
    visit(bt);
    preOrder(bt->left);
    preOrder(bt->right);
}

void inOrder(BinTree bt){
    if (!bt) return;
    inOrder(bt->left);
    visit(bt);
    inOrder(bt->right);
}

void postOrder(BinTree bt){
    if (!bt) return;
    postOrder(bt->left);
    postOrder(bt->right);
    visit(bt);   
}

// Layer order traversal
void levelTrav(BinTree bt){
    if (!bt) return;
    BinTree queue[MAXSIZE];
    BinTree tmp;
    int front, rear;
    front = rear = 0;
    queue[rear] = bt;
    rear = (rear + 1) % MAXSIZE;
    while (front != rear){
        tmp = queue[front];
        front = (front + 1) % MAXSIZE;
        printf("%d ", tmp->data);
        if (tmp->left){
            queue[rear] = tmp->left;
            rear = (rear + 1) % MAXSIZE;
        }
        if (tmp->right){
            queue[rear] = tmp->right;
            rear = (rear + 1) % MAXSIZE;
        }
    }
}

void preOrderNonRecursion(BinTree bt){
    if (!bt) return;
    BinTree stk[MAXSIZE];
    int top = -1;
    stk[++top] = bt;
    while (top != -1){
        bt = stk[top--];
        visit(bt);
        if (bt->right) stk[++top] = bt->right;
        if (bt->left) stk[++top] = bt->left;
    }
}

void preOrderNonRecursion2(BinTree bt){
    if (!bt) return;
    BinTree stk[MAXSIZE];
    int top = -1;
    while (bt || top != -1){
        while (bt){
            visit(bt);
            stk[++top] = bt;
            bt = bt->left;
        }
        if (top != -1){
            bt = stk[top--];
            bt = bt->right;
        }
    }
}

void inOrderNonRecursion(BinTree bt){
    BinTree stk[MAXSIZE];
    int top = -1;
    while (bt || top != -1){
        while (bt){
            stk[++top] = bt;
            bt = bt->left;
        }
        if (!bt){
            bt = stk[top--];
            visit(bt);
            bt = bt->right;
        }
    }
}


// Inferior
void postOrderNonRecursion(BinTree bt){
    BinTree stk1[MAXSIZE], stk2[MAXSIZE];
    int top1 = -1, top2 = -1;
    stk1[++top1] = bt;
    while (top1 != -1){
        bt = stk1[top1--];
        stk2[++top2] = bt;
        if (bt->left) stk1[++top1] = bt->left;
        if (bt->right) stk1[++top1] = bt->right;
    }
    while (top2 != -1){
        visit(stk2[top2]);
        --top2;
    }
}

// advanced
// by tag
void postOrderNonRecursion2(BinTree bt){
    BinTree stk[MAXSIZE];
    int top = -1;
    stk[++top] = bt;
    while (top != -1){
        bt = stk[top--];
        if (bt){
            stk[++top] = bt;
            stk[++top] = NULL;
            if (bt->right) stk[++top] = bt->right;
            if (bt->left) stk[++top] = bt->left;
        }else{
            --top;
            bt = stk[top--];
            visit(bt);
        }
    }
}

BinTree insertBT(BinTree bt, char e){
    if (!bt) {
        BinTree newBinTree = (BinTree)malloc(sizeof(BTNode));
        newBinTree->data = e;
        newBinTree->left = newBinTree->right = NULL;
        return newBinTree;
    }
    if (e >= bt->data) bt->right = insertBT(bt->right, e);
    if (e < bt->data) bt->left = insertBT(bt->left, e);
    return bt;
}
