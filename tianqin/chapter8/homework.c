#include<stdio.h>
#include<stdlib.h>

// 1.countSort evey key-value is different from each other.
void countSort(int a[], int b[], int n){
    int i, j, tmp, cnt;
    for (i = 0; i < n; ++i){
        cnt = 0;
        tmp = a[i];
        for (j = 0; j < n; ++j){
            if (a[j] < tmp) ++cnt;
        }
        b[cnt] = tmp;
    }
}

void test1(){
    int a[] = {4, 2, 3, 6, 1, 5, 9, 8, 7};
    int n = sizeof(a) / sizeof(int);
    int* b = (int*)malloc(sizeof(a));
    countSort(a, b, n);
    for (int i = 0; i < n; ++i) printf("%d ", b[i]);
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 3.doubleOrientBubbleSort
void doubleOrientBubbleSort(int a[], int n){
    int i = 0, j = n - 1, tmp;
    while (i < j){
        tmp = i;
        for (i = i + 1; i < j; ++i){
            if (a[i + 1] < a[i]) swap(a + i, a + i + 1);
        }
        i = tmp;

        --j;

        tmp = j;
        for (j = j - 1; j > i; --j){
            if (a[j - 1] > a[j]) swap(a + j - 1, a + j);
        }
        j = tmp;

        ++i;
    }
}

void test3(){
    int a[] = {4, 2, 3, 6, 1, 5, 9, 8, 7};
    int n = sizeof(a) / sizeof(int);
    doubleOrientBubbleSort(a, n);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}

// 8.linked list sort
typedef struct LinkNode *List, *PLinkNode;
typedef struct LinkNode{
    int val;
    PLinkNode next;
} LinkNode;

PLinkNode new_PLinkNode(int val, PLinkNode next){
    PLinkNode ret = (PLinkNode)malloc(sizeof(LinkNode));
    ret->val = val;
    ret->next = next;
    return ret;
}

// assumed linked-list include dummynode.
void linkInsetSort(List L){
    if (!(L->next && L->next->next)) return;
    PLinkNode head = L, first = L->next;
    PLinkNode prep = head, p = first, preq = first, q = first->next;
    while (q){
        prep = head, p = first;
        while (p != q){
            if (p->val > q->val) break;
            p = p->next;
            prep = prep->next;
        }
        if (p == q){
            preq = preq->next;
            q = q->next;
        }else{
            preq->next = q->next;
            prep->next = q;
            q->next = p;
            q = preq->next;
        }
    }
}

void test8(){
    int e;
    List L, last, tmp;
    L = new_PLinkNode(-1, NULL);
    last = L;
    printf("Enter the number sequence (type 'q' to quit):\n");
    while (scanf("%d", &e)){
        tmp = new_PLinkNode(e, NULL);
        last->next = tmp;
        last = tmp;
    }
    linkInsetSort(L);
    tmp = L->next;
    while (tmp){
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
}

// 9.shellSort by the increment the sequence of [5, 3, 1].
void shellSort(int arr[], int n){
    int i, j, k, l, tmp, incrmtSeq[] = {5, 3, 1};
    for (l = sizeof(incrmtSeq) / sizeof(int); l > -1; --l){
        k = incrmtSeq[l];
        for (i = k; i < n; ++i){
            tmp = arr[i];
            for (j = i; j - k >= 0; j -= k){
                if (arr[j - k] < tmp) break;
                arr[j] = arr[j - k];
            }
            arr[j] = tmp;
        }
    }
}

void test9(){
    int arr[] = {4, 6, 5, 1, 7, 2, 8, 3, 9};
    int n = sizeof(arr) / sizeof(int);
    shellSort(arr, n);
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
}

int main(){
    // test1();
    // test3();
    // test8();
    // test9();
}