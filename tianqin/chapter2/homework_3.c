#include<stdlib.h>
#include<stdio.h>
#include"head.h"

// 1输出倒数第 k 个节点值
int solution1(List L, int k){
    int n = k;
    ptrToLNode pre = L, tail = L;
    while (k-- && tail){
        tail = tail->next;
    }
    if (!tail) {
        printf("the length is less than k!!!");
        return 0;
    }
    while (tail){
        pre = pre->next;
        tail = tail->next;
    }
    printf("%d th data from the end: %d", n, pre->data);
    return 1;
}

void test1(){
    List L = initList();
    solution1(L, 4);
}

// 2

void reverse(SList, int, int, int);
void solution2(SList arr, int k){
    reverse(arr, k, 0, k - 1);
    reverse(arr, arr->length - k, k, arr->length - 1);
    reverse(arr, arr->length, 0, arr->length - 1);
}
void reverse(SList arr, int k, int begin, int end){
    for (int i = begin, j = end; i < j && i < begin + k; ++i, --j) swap(arr->data + i, arr->data + j);
}

void test2(){
    SList arr = initSqlist();
    solution2(arr, 3);
    printSqlist(arr);
}

// 3 找到主元素 出现次数超过了 n/2 个就是主元素
int solution3(SList arr){
    int cnt, maj;
    cnt = 1, maj = arr->data[0];
    for (int i = 1; i < arr->length; ++i){
        if (arr->data[i] == maj){
            ++cnt;
            continue;
        }else{
            if (cnt > 0){
                --cnt;
            }else{
                maj = arr->data[i];
                cnt = 1;
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < arr->length; ++i){
        if (arr->data[i] == maj) cnt++;
    }
    if (cnt > arr->length / 2) return maj;
    return -1;
}

void test3(){
    SList arr = initSqlist();
    int result = solution3(arr);
    printf("%d", result);
}


int main(){
    test3();
}