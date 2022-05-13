#include<stdio.h>
#include<stdlib.h>

void qsHelp(int arr[], int lo, int hi){
    int tmp = arr[lo];
    int i = lo, j = hi;
    if (lo >= hi) return;
    while (i < j){
        while (i < j && tmp <= arr[j]) --j;
        if (i < j){
            arr[i] = arr[j];
            ++i;
        }
        while (i < j && tmp >= arr[i]) ++i;
        if (i < j){
            arr[j] = arr[i];
            --j;
        }
    }
    arr[i] = tmp;
    qsHelp(arr, lo, i - 1);
    qsHelp(arr, i + 1, hi);
}

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insertSort(int arr[], int n){
    int tmp, i, j;
    for (i = 1; i < n; ++i){
        tmp = arr[i];
        for (j = i; j > 0; --j){
            if (arr[j - 1] < tmp) break;
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

void shellSort(int arr[], int n){
    int k, i, j, tmp;
    for (k = n / 2; k > 0; k /= 2){
        for (i = k; i < n; i += k){
            tmp = arr[i];
            for (j = i; j >= k; j -= k){
                if (arr[j - k] < tmp)break;
                arr[j] = arr[j - k];
            }
            arr[j] = tmp;
        }
    }
}

void bubbleSort(int arr[], int n){
    int i, j, tag;
    for (i = 0; i < n - 1; ++i){
        tag = 0;
        for (j = n - 1; j > i; --j){
            if (arr[j] < arr[j - 1]){
                tag = 1;
                swap(arr + j, arr + j - 1);   
            }
        }
        if (!tag) break;
    }
}

void quickSort(int arr[], int n){
    qsHelp(arr, 0, n - 1);
}

void selectSort(int arr[], int n){
    int i, j, min, minIndex;
    for (i = 0; i < n - 1; ++i){
        min = arr[i];
        minIndex = i;
        for (j = i + 1; j < n; ++j){
            if (arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr + i, arr + minIndex);
    }
}

int testSort(void sort(int[], int)){
    int a[] = {4, 5, 6, 2, 3, 1, 7, 9, 8};
    int n = sizeof(a) / sizeof(int);
    sort(a, n);
    for (int i = 0; i < n; ++i)printf("%d ", a[i]);
}

int main(){
    testSort(selectSort);
}