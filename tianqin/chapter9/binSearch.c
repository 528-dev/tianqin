#include<stdio.h>
#include<stdlib.h>
// binary search.
// The premise is that the array is ordered.
int binSearch(int arr[], int n, int k){
    int left = 0, right = n - 1, mid;
    if (n == 0) {
        printf("The array is empty.\n");
        return -1;
    }
    while (left <= right){
        mid = left + (right - left) / 2;
        if (k < arr[mid]){
            right = mid - 1;
            continue;
        }
        if (k > arr[mid]){
            left = mid + 1;
            continue;
        }
        return mid;
    }
    return -1;
}

int binSearchRecsn(int arr[], int left, int right, int k){
    if (left > right){
        printf("NOT FOUND!\n");
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (k < arr[mid]) return binSearchRecsn(arr, left, mid - 1, k);
    if (k > arr[mid]) return binSearchRecsn(arr, mid + 1, right, k);
    return mid;
}

int test(){
    int arr[] = {1, 3, 4, 7, 8, 13, 24, 35};
    int n = sizeof(arr) / sizeof(int);
    int k = 35;
    printf("The index of %d in arr is: %d\n", k, binSearchRecsn(arr, 0, n - 1, k));
}

int main(){
    test();
}