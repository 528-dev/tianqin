#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int tmp[], int lo, int mid, int hi){
    int i, j, p;
    p = i = lo, j = mid + 1;
    while (i <= mid && j <= hi){
        if (arr[i] < arr[j]){
            tmp[p] = arr[i];
            ++i;
        }else{
            tmp[p] = arr[j];
            ++j;
        }
        ++p;
    }
    while (i <= mid){
        tmp[p++] = arr[i++];
    }
    while (j <= hi){
        tmp[p++] = arr[j++];
    }
    for (int i = lo; i <= hi; ++i) arr[i] = tmp[i];
}

void MSort(int arr[], int tmp[], int lo, int hi){
    int mid = lo + (hi - lo) / 2;
    if (lo >= hi) return;
    MSort(arr, tmp, lo, mid);
    MSort(arr, tmp, mid + 1, hi);
    merge(arr, tmp, lo, mid, hi);
}

void mergeSort(int arr[], int n){
    int lo = 0, hi = n - 1;
    int *tmp = (int*)malloc(sizeof(int) * n);
    MSort(arr, tmp, lo, hi);
}

int main(){
    int a[] = {3, 6, 2, 4, 5, 1, 9, 7, 8};
    int n = sizeof(a) / sizeof(int);
    mergeSort(a, n);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}