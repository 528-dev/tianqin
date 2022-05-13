#include<stdio.h>
#include<stdlib.h>

int fillMat(int** a, int m, int n){
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            scanf("%d", a[i] + j);
        }
    }return 1;
}

int **getMatFrame(int m, int n){
    int** ret = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; ++i) ret[i] = (int*)malloc(sizeof(int) * n);
    return ret;
}

void printMat(int **mat, int m, int n){
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d ", mat[i][j]);
        }putchar('\n');
    }
}