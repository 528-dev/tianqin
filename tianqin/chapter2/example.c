#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "head.h"
// 例题2.1
ptrToSqlist init2_1(){
    ptrToSqlist ret = (ptrToSqlist)malloc(sizeof(Sqlist));
    for (int i = 0; i < 10; ++i){
        ret->data[i] = i;
    }
    ret->length = 10;
    return ret;
}
void insertSqlist2_1(ptrToSqlist p){
    int value, i;
    while (scanf("%d", &value) == 1){
        for (i = p->length++; i > 0; --i){
            if (p->data[i - 1] > value){
                p->data[i] = p->data[i - 1];
            }else{
                break;
            }
        }p->data[i] = value;
    }
}
void print2_1(ptrToSqlist p){
    for (int i = 0; i < p->length; ++i){
        printf("%d ", p->data[i]);
    }
}
void test2_1(){
    ptrToSqlist p = init2_1();
    insertSqlist2_1(p);
    print2_1(p);
}
// 例题2.2
ptrToSqlist init2_2(){
    return init2_1();
}

int deleteElem(ptrToSqlist L, int p, int* e){
    if (p > L->length - 1 || p < 0) return 0;
    *e = L->data[p];
    for (int i = p; i < L->length - 1; ++i){
        L->data[i] = L->data[i + 1];
    }L->length--;
    return 1;
}

void print2_2(ptrToSqlist p){
    print2_1(p);
}

void test2_2(){
    int p;
    int e;
    ptrToSqlist plst = init2_2();
    scanf("%d", &p);
    deleteElem(plst, p, &e);
    print2_2(plst);
}

// 例题2.3
int init2_3(List* A, List* B){
    *A = (List)malloc(sizeof(LNode));
    *B = (List)malloc(sizeof(LNode));
    return 1;
}

ptrToLNode CreateNode(int e){
    ptrToLNode ret = (ptrToLNode)malloc(sizeof(LNode));
    ret->data = e;
    ret->next = NULL;
    return ret;
}

int erect(List A, List B){
    List pA = A, pB = B;
    int turn = 1;
    for (int i = 1; i < 13; ++i){
        if (turn % 2){
            pA->next = CreateNode(i);
            pA = pA->next;
        }else{
            pB->next = CreateNode(i);
            pB = pB->next;
        }
        ++turn;
    }return 1;
}

List mergeAB(List A, List B){
    List C = CreateNode(0);
    ptrToLNode pA = A->next, pB = B->next, pC = C;
    while (pA && pB){
        if (pA->data < pB->data){
            pC->next = pA;
            pA = pA->next;
            pC = pC->next;
        }else{
            pC->next = pB;
            pB = pB->next;
            pC = pC->next;
        }
    }
    if (!pA){
        pC->next = pB;
    }else{
        pB->next = pA;
    }
    return C;
}

void print2_3(List C){
    if (!C) return;
    C = C->next;
    while (C){
        printf("%d ", C->data);
        C = C->next;
    }
}

void test2_3(){
    List A, B, C;
    init2_3(&A, &B);
    erect(A, B);
    printf("A:");
    print2_3(A);
    printf("B:");
    print2_3(B);
    C = mergeAB(A, B);
    printf("C:");
    print2_3(C);
}


// 例题2.4
List init2_4(){
    int val;
    char c;
    List ret = (List)malloc(sizeof(LNode));
    ptrToLNode pr = ret;
    ptrToLNode tmp;
    while (scanf("%d", &val)){
        tmp = (ptrToLNode)malloc(sizeof(LNode));
        tmp->data = val;
        tmp->next = NULL;
        pr->next = tmp;
        pr = pr->next;
        c = getchar();
        if (c == '\n') break;
    }
    return ret;
}

void print2_4(List L){
    if (!L) return;
    L = L->next;
    while (L){
        printf("%d ", L->data);
        L = L->next;
    }
}

int findAndDelete(List L, int e){
    ptrToLNode p, q;
    p = L, q = L->next;
    while (q){
        if (q->data == e){
            p->next = q->next;
            return 1;
        }
        p = p->next;
        q = q->next;
    }
    return 0;
}
int test2_4(){
    List L = init2_4();
    printf("before:");
    print2_4(L);
    printf("\n");
    findAndDelete(L, 3);
    printf("later:");
    print2_4(L);
    printf("\n");
}

// 双链表的操作
// 尾插构造双链表
ptrToDLNode createDlistR(){
    char c;
    int elem;
    ptrToDLNode head, tail, tmp;
    printf("Enter elements which you want to insert in tail(split by space):\n");
    head = (ptrToDLNode)malloc(sizeof(DLNode));
    head->data = 0;
    head->next = head;
    head->prior = head;
    tail = head;
    while (true){
        scanf("%d", &elem);
        tmp = (ptrToDLNode)malloc(sizeof(DLNode));
        tmp->data = elem;
        tmp->prior = tail;
        tmp->next = tail->next;
        tail->next = tmp;
        head->prior = tmp;
        tail = tmp;
        c = getchar();
        if (c == '\n') break;
    }
    return head;
}

void printDList(DList h){
    DList stop = h;
    h = h->next;
    while (h != stop){
        printf("%d ", h->data);
        h = h->next;
    }
}

void testDL(){
    DList dList = createDlistR();
    printDList(dList);
}

// 例题2.5
//(1)
ptrToSqlist init2_5(){
    return init2_1();
}
void print2_5(ptrToSqlist p){
    print2_1(p);
}
void reverse2_5_1(ptrToSqlist Sq, int k){
    int i, j;
    for (i = 0, j = Sq->length - 1; i < j && i < k; ++i, --j){
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
        Sq->data[j] = Sq->data[i] ^ Sq->data[j];
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
    }
}
void test2_5_1(){
    ptrToSqlist p = init2_5();
    reverse2_5_1(p, 7);
    print2_5(p);
}

//(2)
void reverse2_5_2(ptrToSqlist Sq, int k){
    int i, j;
    // 先对前 k 个进行置逆
    for (i = 0, j = Sq->length - 1; i < j && i < k; ++i, --j){
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
        Sq->data[j] = Sq->data[i] ^ Sq->data[j];
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];    
    }
    // 再对后 k 个整体置逆
    for (i = Sq->length - k, j = Sq->length - 1; i < j; ++i, --j){
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
        Sq->data[j] = Sq->data[i] ^ Sq->data[j];
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
    }
}
void test2_5_2(){
    ptrToSqlist p = init2_5();
    reverse2_5_2(p, 7);
    print2_5(p);
}

//(3)
void reverse2_5_3(ptrToSqlist Sq, int k){
    int i, j;
    // 先对前 k 个进行置逆
    for (i = 0, j = Sq->length - 1; i < j && i < k; ++i, --j){
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
        Sq->data[j] = Sq->data[i] ^ Sq->data[j];
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];    
    }
    // 再对后 k 个整体置逆
    for (i = Sq->length - k, j = Sq->length - 1; i < j; ++i, --j){
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
        Sq->data[j] = Sq->data[i] ^ Sq->data[j];
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
    }
    // 最后对前 k 个整体置逆
    for (i = 0, j = Sq->length - k - 1; i < j; ++i, --j){
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
        Sq->data[j] = Sq->data[i] ^ Sq->data[j];
        Sq->data[i] = Sq->data[i] ^ Sq->data[j];
    }
}

void test2_5_3(){
    ptrToSqlist p = init2_5();
    reverse2_5_3(p, 7);
    print2_5(p);
}

// 真题造访1
// 下标 0 ~ m + n - 1 范围
SList initZt1(int m, int n){
    SList L = (SList)malloc(sizeof(Sqlist));
    L->length = 0;
    int val, i, j;
    for (i = 0; i < m; ++i){
        scanf("%d", &val);
        for (j = L->length++; j > 0 && val < L->data[j - 1]; --j){
            L->data[j] = L->data[j - 1];
        }
        L->data[j] = val;
    }
    for (i = m; i < m + n; ++i){
        scanf("%d", &val);
        for (j = L->length++; j > m && val < L->data[j - 1]; --j){
            L->data[j] = L->data[j - 1];;
        }
        L->data[j] = val;
    }
    return L;
}

void printZt1(SList L){
    print2_1(L);
}

void solveZt1(SList L, int m, int n){
    int i, j, tmp;
    for (i = m; i < m + n; ++i){
        int tmp = L->data[i];
        for (j = i; j > 0 && L->data[j - 1] > tmp; --j){
            L->data[j] = L->data[j - 1];
        }
        L->data[j] = tmp;
    }
}

void testZt1(){
    SList L = initZt1(8, 4);
    printf("before:");
    printZt1(L);
    printf("\n");
    solveZt1(L, 8, 4);
    printZt1(L);
    printf("\n");
}


// 真题仿造2
List initZt2(){
    return init2_4();
}

void solveZt2(List A, List B){
    ptrToLNode pa, pb, pre;
    pre = A;
    pa = A->next, pb = B->next;
    while (pa && pb){
        if (pb->data < pa->data){
            pb = pb->next;
        }
        else if (pb->data == pa->data){
            pre->next = pa->next;
            free(pa);
            pa = pre->next;
        }else{
            pre = pre->next;
            pa = pa->next;
        }
    }
}

void printZt2(List L){
    print2_4(L);
}

void testZt2(){
    List A = initZt2();
    List B = initZt2();
    solveZt2(A, B);
    printZt2(A);
}



int main(){
    testZt2();
}
