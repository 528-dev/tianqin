#include<stdio.h>
#include<stdlib.h>
#include"aov.h"

int topSort(AGraph G){
    int stack[MAXSIZE], top = -1;
    int i, j, k, n = 0;
    PArcNode p;
    for (i = 0; i < G->n; ++i){
        if (!G->adjlist[i]->count){
            stack[++top] = i;
        }
    }
    while (top != -1){
        j = stack[top--];
        ++n;
        printf("%c ", G->adjlist[j]->data);
        p = G->adjlist[j]->firstArc;
        while (p){
            k = p->adjvex;
            --(G->adjlist[k]->count);
            if (G->adjlist[k]->count == 0){
                stack[++top] = k;
            }
            p = p->nextArc;
        }
    }
    if (n == G->n) return 1;
    return 0;
}