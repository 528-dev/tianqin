#include<stdio.h>
#include<stdlib.h>
#include"matrix.h"

typedef struct OLNode* PNode;
typedef struct OLNode{
    int row, col;
    PNode right, down;
    int val;
}OLNode;

typedef struct CLNode{
    PNode *rhead, *chead;  // array of pointers to OLNode;
    int m, n, k;
}CLNode, *CrossList;

// example5_5. Given a matrix whose size is m * n;
// Please create the CrossLinked-list;

CrossList createCrsLinkedMat(int **mat, int m, int n){
    if (!mat) return NULL;
    if (!(*mat)) return NULL;
    CrossList cl = (CrossList)malloc(sizeof(CLNode));
    PNode *tmpArr = (PNode*)malloc(sizeof(PNode) * n);
    PNode tmp;
    cl->chead = (PNode*)malloc(sizeof(PNode) * m);
    cl->rhead = (PNode*)malloc(sizeof(PNode) * n);
    
    for (int i = 0; i < m; ++i) cl->chead[i] = (PNode)malloc(sizeof(OLNode));
    for (int i = 0; i < n; ++i) cl->rhead[i] = (PNode)malloc(sizeof(OLNode));
    for (int i = 0; i < m; ++i){
        cl->chead[i]->col = cl->chead[i]->row = -1;
        cl->chead[i]->right = NULL;
        cl->chead[i]->down = NULL;
    }

    for (int i = 0; i < n; ++i){
        cl->rhead[i]->col = cl->rhead[i]->row = -1;
        cl->rhead[i]->right = cl->rhead[i]->down = NULL;
    }

    for (int i = 0; i < n; ++i) tmpArr[i] = cl->rhead[i];

    for (int i = 0; i < m; ++i){
        PNode p = cl->chead[i];
        for (int j = 0; j < n; ++j){
            if (mat[i][j] != 0){
                tmp = (PNode)malloc(sizeof(OLNode));
                tmp->row = i, tmp->col = j;
                tmp->right = tmp->down = NULL;
                tmp->val = mat[i][j];

                tmpArr[j]->down = tmp;
                p->right = tmp;
                
                tmpArr[j] = tmp;
                p = tmp;
            }
        }
    }
    return cl;
}

void printCrsLink(CrossList cl, int r, int c){
    PNode p = cl->rhead[c];
    p = p->down;
    while (p && p->row != r) p = p->down;
    printf("cl[%d][%d] = %d", r, c, p->val);
}

int test1(){
    int m, n;
    int **mat;
    CrossList cl;
    printf("Enter the m and n:\n");
    scanf("%d %d", &m, &n);
    mat = getMatFrame(m, n);
    printf("Enter the matrix:\n");
    fillMat(mat, m, n);
    cl = createCrsLinkedMat(mat, m, n);
    printCrsLink(cl, 2, 2);
}

int main(){
    test1();
}