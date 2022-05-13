#include<stdio.h>
#include<stdlib.h>

// the operation of matrix
/****************************************************************************************/
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

// 矩阵的转置
void trsmat(int **a, int ***b, int am, int an, int *bm, int *bn){
    // a 是 m * n 的矩阵
    // 那么 b 是 n * m 的矩阵
    *b = (int**)malloc(sizeof(int*) * an); // n 个数组的指针
    for (int i = 0; i < an; ++i){
        (*b)[i] = (int*)malloc(sizeof(int) * am);
    }
    for (int i = 0; i < am; ++i){
        for (int j = 0; j < an; ++j){
            (*b)[j][i] = a[i][j];
        }
    }
    *bm = an, *bn = am;
}

void test1(){
    int **a, **b, m, n, bm, bn;
    printf("Please enter the m and n (split by space):");
    scanf("%d %d", &m, &n);
    a = (int**)malloc(sizeof(int*) * m);
    for (int i = 0; i < m; ++i) a[i] = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            scanf("%d", *(a + i) + j);
        }
    }
    trsmat(a, &b, m, n, &bm, &bn);
    printf("trsmat ed:\n");
    for (int i = 0; i < bm; ++i){
        for (int j = 0; j < bn; ++j){
            printf("%d ", b[i][j]);
        }putchar('\n');
    }
}

void addMat(int **a, int **b, int **c, int m, int n){
    c = getMatFrame(m, n);
    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n; ++j){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void test2(){
    int m, n;
    printf("Please enter the m and n (split by space):");
    scanf("%d %d", &m, &n);
    int **a = getMatFrame(m, n);
    int **b = getMatFrame(m, n);
    printf("Enter the");
}

void multMat(int **a, int **b, int am, int an, int bm, int bn, int ***result, int *rm, int *rn){
    if (an != bm) {
        printf("invalid operate");
        return;
    }
    *rm = am, *rn = bn;
    *result = getMatFrame(*rm, *rn);
    for (int i = 0; i < am; ++i){
        for (int j = 0; j < bn; ++j){
            (*result)[i][j] = 0;
            for (int k = 0; k < an; ++k){
                (*result)[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void test3(){
    int **a, **b, **c;
    int am, an, bm, bn, cm, cn;
    printf("Enter the am and an (split by space):");
    scanf("%d %d", &am, &an);
    a = getMatFrame(am, an);
    printf("Enter the matrix a:\n");
    fillMat(a, am, an);
    printf("Enter the bm and bn (split by space):");
    scanf("%d %d", &bm, &bn);
    b = getMatFrame(bm, bn);
    printf("Enter the matrix b:\n");
    fillMat(b, bm, bn);
    printf("a * b = \n");
    multMat(a, b, am, an, bm, bn, &c, &cm, &cn);
    printMat(c, cm, cn);
}

int main(){
    test3();
}