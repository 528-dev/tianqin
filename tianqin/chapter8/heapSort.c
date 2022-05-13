#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void perdown(int arr[], int lo, int hi){
    int child, i = lo;
    int tmp = arr[lo];
    while (i * 2 <= hi){
        child = i * 2;
        if (child + 1 <= hi && arr[child + 1] > arr[child]) ++child;
        if (tmp > arr[child]) break;
        arr[i] = arr[child];
        i = child;
    }arr[i] = tmp;
}

void heapSort(int arr[], int n){
    int i, tmp;
    for (i = n / 2; i > 0; --i) perdown(arr, i, n);
    for (i = n; i > 1; --i){
        swap(arr + 1, arr + i);
        perdown(arr, 1, i - 1);
    }
}

int main(){
    int arr[] = {-1, 4, 5, 3, 7, 2, 8, 9, 1, 6};
    int n = sizeof(arr) / sizeof(int);
    heapSort(arr, n - 1);
    for (int i = 1; i < n; ++i) printf("%d ", arr[i]);
}