#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include"head.h"

// 1 个位数个元素 个位数的元素 仅用一个变量找到MIN
int solution1(SList L){
    int i;
    // i = 10 * MIN + index
    for (i = 10 * L->data[i % 10] + 0; i % 10 < L->length; ++i){
        i = (i / 10 < L->data[i % 10] ? i / 10 : L->data[i % 10]) * 10 + i % 10;
    }
    return i / 10;
}

void test1(){
    SList L = initSqlist();
    printf("%d", solution1(L));
}

// 2 逆序打印单链表
void help(List);
void solution2(List L){
    help(L->next);
}

void help(List L){
    if (!L) return;
    help(L->next);
    printf("%d ", L->data);
}

void test2(){
    List L = initList();
    solution2(L);
}

// 3
int solution3(List A, List B){
    A = A->next, B = B->next;
    while (A && B){
        if (A->data != B->data) return 0;
        A = A->next, B = B->next;
    }
    if (!A && !B) return 1;
    return 0;
}

void test3(){
    List A = initList();
    List B = initList();
    printf("%s", solution3(A, B) ? "same" : "not same");
}

// 4 
int solution4(List A, List B){
    ptrToLNode pA = A->next, pB = B->next;
    while (pA && pB && pA->data == pB->data){
        pA = pA->next;
        pB = pB->next;
    }
    if (!pA && !pB) return 0;
    if (pA && pB) return pA->data < pB->data ? -1 : 1;
    return !pA ? -1 : 1;
}

void test4(){
    List A = initList(), B = initList();
    int mark = solution4(A, B);
    if (!mark) printf("A == B");
    else if (mark == -1) printf("A < B");
    else printf("A >= B"); 
}

// 5
List solution5(){
    int hash[26];
    memset(hash, 0, sizeof(int) * 26);
    List L, tmp, tail;
    L = (List)malloc(sizeof(LNode));
    L->data = -1;
    L->next = NULL;
    tail = L;
    int n, val;
    scanf("%d", &n);
    n += 1;
    while (--n){
        scanf("%d", &val);
        if (hash[val - 1] == 1) continue;
        tmp = (List)malloc(sizeof(LNode));
        tmp->data = val;
        tmp->next = NULL;
        tail->next = tmp;
        tail = tail->next;
        hash[val - 1] = 1;
    }
    return L;
}

void test5(){
    List L = solution5();
    printList(L);
}

int main(){
    test5();
}