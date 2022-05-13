#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"matrix.h"
void swap(int* a, int* b){
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

// 1 Please move the non-zeor elements to the front of array in order.
void moveElem(int *array, int n){
    int i, j;
    i = j = 0;
    while (j < n){
        if (array[j] != 0){
            array[i] = array[j];
            ++i, ++j;
        }else{
            ++j;
        }
    }
    while (i < n){
        array[i] = 0;
        ++i;
    }
}

void test1(){
    int* a = (int*)malloc(sizeof(int) * 10);
    memset(a, 0, sizeof(int) * 10);
    a[3] = 1, a[7] = 9, a[9] = 4;
    moveElem(a, 10);
    for (int i = 0; i < 10; ++i) printf("%d ", a[i]);
}

// 2 recursion implement:
// 1) the max of array which size is n;
float findMax(float* array, int i, int j){
    if (i == j) return array[i];
    if (array[i] > array[j]) return findMax(array, i, j - 1);
    return findMax(array, i + 1, j);
}

void test2_1(){
    float array[] = {1, 2, 6, 32, 4, 5, 7};
    printf("%f", findMax(array, 0, (sizeof(array) / sizeof(float) - 1)));
}

// 2) the sum of array which size is n;
float calSum(float* array, int n){
    if (n == 1) return array[0];
    return calSum(array, n - 1) + array[n - 1];
}

void test2_2(){
    float array[] = {1, 2, 6, 32, 4, 5, 7};
    printf("%.2f", calSum(array, (sizeof(array) / sizeof(float))));
}

// 3) the mean of array which size is n;
float calMean(float* array, int n){
    if (n == 1) return array[0];
    return (calSum(array, n - 1) + array[n - 1]) / (float)n;
}

void test2_3(){
    float array[] = {1, 2, 6, 32, 4, 5, 7};
    printf("%.2f", calMean(array, (sizeof(array) / sizeof(float))));
}

// 3 coding to move the odds in front of the evens that all in array which size is n;

void mvElem2(int *array, int n){
    int front, rear;
    front = 0, rear = n - 1;
    while (front < rear){
        if (!(array[front] % 2) && (array[rear] % 2)){
            swap(array + front, array + rear);
            ++front, --rear;
        }
        else if ((array[front] % 2) && (array[rear] % 2)) ++front;
        else if ((!array[front] % 2) && !(array[rear] % 2)) --rear;
        else ++front, --rear;
    }
}

void test3(){
    int i = 10, a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    mvElem2(a, 10);
    while (i--) printf("%d ", a[10 - i]);
}

// 4 Splitting an array causes the left elements value are lower than array[n - 1] and 
//   the right elements value are greater than array[n - 1].  

void splitArr(int* array, int n){
    int i, j, tmp;
    i = 0, j = n - 1;
    swap(array + i, array + j);
    tmp = array[i];

    while (i < j){
        while ((i < j) && (tmp < array[j])) --j;
        if (i < j){
            array[i] = array[j];
            ++i;
        }
        while ((i < j) && (tmp > array[i])) ++i;
        if (i < j){
            array[j] = array[i];
            --j;
        }
        array[i] = tmp;
    }
}

void test4(){
    int n = 10, arr[] = {3, 4, 7, 4, 2, 8, 7, 9, 4, 5};
    splitArr(arr, n);
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
}


// 5 Find the Element which is the max(min) in its row and column and print it
void fdMxAndMn(int** mat, int m, int n){
    int max, min, maxj, minj, maxTag, minTag;
    for (int i = 0; i < m; ++i){
        maxTag = minTag = 1;
        max = min = mat[i][0];
        maxj = minj = 0;
        for (int j = 1; j < n; ++j){
            if (mat[i][j] > max){
                max = mat[i][j];
                maxj = j;
            }
            if (mat[i][j] < min){
                min = mat[i][j];
                minj = j;
            }
        }

        for (int k = 0; k < m; ++k){
            if (mat[k][maxj] > max) maxTag = 0;
            if (mat[k][minj] < min) minTag = 0;
        }

        if (maxTag){
            printf("MAX:mat[%d][%d] = %d\n", i, maxj, max);
        }

        if (minTag){
            printf("MIN:mat[%d][%d] = %d\n", i, minj, min);
        }
    }
}

void test5(){
    int **mat, m, n;    
    printf("Enter the m and n:\n");
    scanf("%d %d", &m, &n);
    mat = getMatFrame(m, n);
    printf("Enter the matrix of m * n:\n");
    fillMat(mat, m, n);
    fdMxAndMn(mat, m, n);
}

// 6 
// 1) Given a sparse matrix, to create triMat.
typedef int (*trimat)[3];

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

void printTriMat(trimat t){
    int n = t[0][0] + 1;
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < 3; ++j){
            printf("%d ", t[i][j]);
        }printf("\n");
    }
}

void test6_1(){
    int** a = getMatFrame(4, 4), n;
    trimat t;
    fillMat(a, 4, 4);
    printf("mat:\n");
    printMat(a, 4, 4);
    t = createTriMat(a, 4, 4, &n);
    printf("trimat:\n");
    printTriMat(t);
}

// 2) To find the element uniquely identified by its val in trimat and print the information.
int findXInTrimat(int elem, trimat tm, trimat *elemTriArray){
    int i, size = tm[0][0];
    *elemTriArray = tm + 1;
    for (i = 1; i <= size; ++i){
        if (tm[i][0] == elem){
            *elemTriArray = tm + i;
            return 1;
        }
    }return 0;
}

void test6_2(){
    int m, n, **mat, triSize, e;
    trimat tm, result;
    printf("Enter the m and n:\n");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix:\n");
    mat = getMatFrame(m, n);
    fillMat(mat, m, n);
    tm = createTriMat(mat, m, n, &triSize);
    printf("Which element do you search for:\n");
    scanf("%d", &e);
    if (findXInTrimat(e, tm, &result)){
        printTriMat(tm);
        printf("The information of %d in matrix\n", e);
        printf("%d %d %d", (*result)[0], (*result)[1], (*result)[2]);
    }else{
        printf("%d is not in the matrix", e);
    }
}

// 7 To transpose the matrix in the form of trimat.
int tranTriMat(trimat tm){
    int size = tm[0][0];
    if (!size){
        printf("NULL matrix");
        return 0;
    }
    for (int i = 1; i <= size; ++i){
        swap(tm[i] + 1, tm[i] + 2);
    }
    return 1;
}

void test7(){
    int **mat, m, n, triSize;
    trimat tm;
    printf("Enter the m and n:\n");
    scanf("%d %d", &m, &n);
    printf("Enter the matrix:\n");
    mat = getMatFrame(m, n);
    fillMat(mat, m, n);
    tm = createTriMat(mat, m, n, &triSize);
    printTriMat(tm);
    tranTriMat(tm);
    printf("Transposed:\n");
    printTriMat(tm);
}

// 8 addition operation of trimat.
trimat addTrimat(trimat tm1, trimat tm2){
    
}

int main(){
    test7();
}