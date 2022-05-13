#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
// 1.To ranks all negative keywords before non-negative keywords.
void solution1(int arr[], int n){
    int i = 0, j = n - 1;
    while (i < j){
        while (i < j && arr[i] < 0) ++i;
        while (i < j && arr[j] >= 0) --j;
        if (i < j) {
            swap(arr + i, arr + j);
            ++i, --j;
        }
    }
}

void test1(){
    int a[] = {-1, -3, 6, 3, -2, 0, -3, 5, 8, -2};
    int n = sizeof(a) / sizeof(int);
    solution1(a, n);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}

// 2.To sort A[] whose elements differ to each other from "0" to "n - 1" to B[].
void solution(int A[], int B[], int n){
    for (int i = 0; i < n; ++i) B[A[i]] = A[i];
}

int main(){
    test1();
}