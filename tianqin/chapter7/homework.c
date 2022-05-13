#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"mgraph.h"
#include"agraph.h"

// 7.AGraph to MGraph.
MGraph a2m(AGraph AG){
    MGraph MG = (MGraph)malloc(sizeof(MNode));
    PArcNode p;
    MG->e = AG->e;
    MG->n = AG->n;
    for (int i = 0; i < MG->n; ++i){
        for (int j = 0; j < MG->n; ++j){
            MG->edges[i][j] = 0;
        }
    }
    for (int i = 0; i < AG->n; ++i){
        p = AG->adjlist[i]->firstArc;
        while (p){
            MG->edges[i][p->adjvex] = 1;
            p = p->nextArc;
        }
    }
    return MG;
}

// 8.To count the inward degree of node k.
int cntTheInwardDegree(AGraph AG, int k){
    int cnt = 0;
    PArcNode p;
    for (int i = 0; i < AG->n; ++i){
        p = AG->adjlist[i]->firstArc;
        while (p){
            if (p->adjvex == k) ++cnt;
            p = p->nextArc;
        }
    }
    return cnt;
}

// 9.DFS Non-recursive.
void DSFNonRecursive(AGraph AG, int u){
    int v;
    int visited[MAXSIZE];
    int top = -1, stk[MAXSIZE];
    PArcNode p;
    memset(visited, 0, sizeof(int) * MAXSIZE);

    stk[++top] = u;
    visited[u] = 1;
    printf("%c ", AG->adjlist[u]->data);

    while (top != -1){
        v = stk[top];
        p = AG->adjlist[v]->firstArc;
        while (p && visited[p->adjvex] != 0) p = p->nextArc;
        if (!p) --top;
        else{
            printf("%c ", AG->adjlist[p->adjvex]->data);
            visited[p->adjvex] = 1;
            stk[++top] = p->adjvex;
        }
    }
}