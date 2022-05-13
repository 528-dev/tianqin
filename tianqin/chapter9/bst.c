#include<stdio.h>
#include<stdlib.h>
#include"bst.h"



BinTree new_BinTree(int key, BinTree left, BinTree right){
    BinTree ret;
    ret = (BinTree)malloc(sizeof(BTNode));
    ret->key = key;
    ret->left = left;
    ret->right = right;
    return ret;
}

BinTree bstSearch(BinTree bt, int key){
    if (!bt) return bt;
    if (bt->key < key) return search(bt->left, key);
    if (bt->key > key) return search(bt->right, key);
    return bt;
}

BinTree bstSearchNonRecursion(BinTree bt, int key){
    while (bt){
        if (key < bt->key){
            bt = bt->left;
            continue;
        }
        if (key > bt->key){
            bt = bt->right;
            continue;
        }
        return bt;
    }
    printf("NOT FOUND\n");
    return bt;
}

BinTree bstInsert(BinTree bt, int key){
    if (!bt) return new_BinTree(key, NULL, NULL);
    if (key < bt->left) bt->left = bstInsert(bt->left, key);
    bt->right = bstInsert(bt->right, key);
}

BinTree createBst(int keyArr[], int n){
    BinTree ret = NULL;
    for (int i = 0; i < n; ++i){
        bstInsert(ret, keyArr[i]);
    }
    return ret;
}

BinTree bstFindMin(BinTree bt){
    while (bt->left) bt = bt->left;
    return bt;
}

BinTree bstFindMax(BinTree bt){
    if (!bt) return NULL;
    if (!bt->right) return bt;
    return bstFindMax(bt->right); 
}

BinTree bstDelete(BinTree bt, int key){
    BinTree tmp;
    if (!bt) return bt;
    if (key < bt->key) bt->left = bstDelete(bt->left, key);
    if (key > bt->key) bt->right = bstDelete(bt->right, key);
    // Found element to be deleted.
    if (bt->left && bt->right){
        tmp = bstFindMin(bt->right);
        bt->key = tmp->key;
        bt->right = bstDelete(bt->right, tmp->key);
    }
    else{
        tmp = bt;
        if (!bt->left) bt = bt->right;
        else bt = bt->left;
        free(tmp);
    }
    return bt;
}