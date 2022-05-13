#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"head.h"


void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

SList initSqlist(){
    int val;
    SList L = (SList)malloc(sizeof(Sqlist));
    L->length = 0;
    while (scanf("%d", &val)){
        L->data[L->length++] = val;
    }
    return L;
}

void printSqlist(SList L){
    for (int i = 0; i < L->length; ++i){
        printf("%d ", L->data[i]);
    }putchar('\n');
}

List initList(){
    List L = (List)malloc(sizeof(LNode));
    ptrToLNode tail = L;
    L->next = NULL;
    int val;
    while (scanf("%d", &val)){
        ptrToLNode tmp = (ptrToLNode)malloc(sizeof(LNode));
        tmp->data = val;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tmp;
    }
    fflush(stdin);
    return L;
}

void printList(List L){
    ptrToLNode p = L->next;
    while (p){
        printf("%d ", p->data);
        p = p->next;
    }putchar('\n');
}

