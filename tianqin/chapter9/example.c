#include<stdio.h>
#include<stdlib.h>
// example9_1 search sequentially.
int searchSeq(int arr[], int n, int k){
    for (int i = 0; i < n; ++i){
        if (arr[i] == k) return i;
    }return -1;
}

int main(){
    
}