#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"head.h"

//3 逆置
void solution3(SList L){
    for (int i = 0; i < (L->length - 1) / 2; ++i){
        swap(L->data + i, L->data + (L->length - i - 1));
    }
}

void print3(SList L){
    for (int i = 0; i < L->length; ++i){
        printf("%d ", L->data[i]);
    }
}

void test3(){
    SList L = initSqlist();
    printf("before: ");
    print3(L);
    solution3(L);
    printf("later: ");
    print3(L);
}


//4 删除下标 i ~ j 的元素 (i <= j)
SList init4(){
    return initSqlist();
}

void solution4(SList L, int i, int j){
    if (i > L->length - 1) return;
    while (j < L->length - 1){
        L->data[i] = L->data[j + 1];
        ++i, ++j;
    }
    L->length = i;
}

void print4(SList L){
    print3(L);
}

void test4(){
    SList L = init4();
    print4(L);
    printf("\n");
    solution4(L, 3, 5);
    print4(L);
}

// 顺序表 L 将小于表头元素的整数放前面，大于表头的元素放后面

SList init5(){
    return initSqlist();
}

void solution5(SList L){
    int mark = L->data[0];
    int ptr = 0;
    int left = 0, right = L->length - 1;
    while (left != right){
        if (ptr == left){
            if (L->data[left] > L->data[right]){
                swap(L->data + left, L->data + right);
                ++left, ptr = right;
            }else{
                --right;
            }
        }else{
            if (L->data[left] > L->data[right]){
                swap(L->data + left, L->data + right);
                --right, ptr = left;
            }else{
                ++left;
            }
        }
    }
}

void test5(){
    SList L = init5();
    printf("before: ");
    printSqlist(L);
    printf("\n");
    solution5(L);
    printf("later: ");
    printSqlist(L);
    printf("\n");
}

// 6递增非空单链表，删除重复的节点

void solution6(List L){
    ptrToLNode h, p, q;
    h = L;
    p = L->next;
    if (!p) return;
    q = p->next;
    if (!q) return;
    while (q){
        if (q->data == p->data){
            ptrToLNode tmp = p;
            h->next = q;
            free(tmp);
            p = h->next;
            q = q->next;
        }else{
            h = p;
            p = q;
            q = q->next;
        }
    }
}


void test6(){
    List L = initList();
    solution6(L);
    printList(L);
}

// 7 删除单链表的最小值节点
List solution(List L){
    ptrToLNode ret = L->next;
    if (!ret) return ret;
    List ptr = L->next;
    int min = ptr->data;
    while (ptr){
        if (ptr->data < min){
            min = ptr->data;
            ret = ptr;
        }
        ptr = ptr->next;
    }return ret;
}

void test7(){
    List L = initList();
    ptrToLNode result = solution(L);
    printf("%d", result->data);
}

// 8 逆置单链表
void solution8(List L){
    if (!L->next) return;
    ptrToLNode pre, cur, nex;
    pre = NULL, cur = L->next, nex = cur->next;
    while (cur){
        cur->next = pre;
        pre = cur;
        cur = nex;
        if (nex)
            nex = nex->next;
    }
    L->next = pre;
}

void test8(){
    List L = initList();
    solution8(L);
    printList(L);
}

// 9分解单链表
void solution9(List A, List* C){
    List B = (List)malloc(sizeof(LNode));
    ptrToLNode tailB = B, preA = A;
    A = A->next;
    while (A){
        if (A->data % 2 == 0){
            tailB->next = A;
            tailB = tailB->next;
            preA->next = A->next;
            A = A->next;
            tailB->next = NULL;
        }else{
            preA = A;
            A = A->next;
        }
    }
    *C = B;
}

void test9(){
    List A = initList();
    List B;
    solution9(A, &B);
    printList(A);
    printList(B);
}

int main(){
    test9();
}