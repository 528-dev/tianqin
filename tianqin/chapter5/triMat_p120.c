#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"
// sparse matrix --- triple tuples
/********************************************************************************************/
typedef int (*trimat)[3]; // defined a pointer to array of three;

void printTriMat(trimat t){
    int n = t[0][0] + 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 3; ++j){
            printf("%d ", t[i][j]);
        }printf("\n");
    }
}

// example5_4
// specialized a sparse matrix and transfer to matrix of three tuples form;
trimat createTriMat(int **matrix, int m, int n, int* trimatSize){
    *trimatSize = 1;
    trimat ret = (trimat)malloc(sizeof(int) * 3 * (*trimatSize));
    ret[0][1] = m, ret[0][2] = n;
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            if (matrix[i][j] != 0){
                ++(*trimatSize);
                realloc(ret, sizeof(int) * 3 * (*trimatSize));
                ret[*trimatSize - 1][0] = matrix[i][j];
                ret[*trimatSize - 1][1] = i;
                ret[*trimatSize - 1][2] = j;
            }
        }
    }
    ret[0][0] = *trimatSize - 1;
    return ret;
}

int testCreateTriMat(){
    int** a = getMatFrame(4, 4), n;
    trimat t;
    fillMat(a, 4, 4);
    printf("mat:\n");
    printMat(a, 4, 4);
    t = createTriMat(a, 4, 4, &n);
    printf("trimat:\n");
    printTriMat(t);
}

int main(){
    
}