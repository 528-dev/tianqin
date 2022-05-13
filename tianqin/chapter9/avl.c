#include<stdio.h>
#include<stdlib.h>
#include"avl.h"

struct AVLTNode{
    int key, height;
    PAVLTNode left, right;
};

static int calHeight(PAVLTNode p){
    if (!p) return -1;
    return p->height;
}

// left-left
static AvlTree singleRotateWithLeft(AvlTree k2){
    AvlTree k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    k1->height = __max(calHeight(k1->left), calHeight(k1->right)) + 1;
    k2->height = __max(calHeight(k2->left), calHeight(k2->right)) + 1;
    return k1;
}

// right-right
static AvlTree singleRotateWithRight(AvlTree k1){
    AvlTree k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;

    k1->height = __max(calHeight(k1->left), calHeight(k1->right)) + 1;
    k2->height = __max(calHeight(k2->left), calHeight(k2->right)) + 1;
    return k2;
}

// left-right
static AvlTree doubleRotateWithLeft(AvlTree k3){
    k3->left = singleRotateWithRight(k3->left);
    return singleRotateWithLeft(k3);
}

static AvlTree doubleRotateWithRight(AvlTree k1){
    k1->right = singleRotateWithLeft(k1->right);
    return singleRotateWithRight(k1);
}

AvlTree new_AvlTree(int key, AvlTree left, AvlTree right, int height){
    AvlTree ret = (AvlTree)malloc(sizeof(AVLTNode));
    ret->left = left;
    ret->right = right;
    ret->key = key;
    ret->height = height;
    return ret;
}

AvlTree insert(AvlTree at, int key){
    if (!at){
        return new_AvlTree(key, NULL, NULL, 0);
    }
    if (key < at->key){
        at->left = insert(at->left, key);
        if (calHeight(at->left) - calHeight(at->right) == 2){
            if (key < at->left->key){
                at = singleRotateWithLeft(at);
            }else{
                at = doubleRotateWithLeft(at);
            }
        }
    }
    else if (key > at->key){
        at->right = insert(at->right, key);
        if (calHeight(at->right) - calHeight(at->left) == 2){
            if (key > at->right->key){
                at = singleRotateWithRight(at);
            }else{
                at = doubleRotateWithRight(at);
            }
        }
    }
    else;  // key == at->key we'll do nothing.

    at->height = __max(calHeight(at->left), calHeight(at->right)) + 1;
    return at;
}

