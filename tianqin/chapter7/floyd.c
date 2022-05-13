#include<stdio.h>
#include<stdlib.h>
#include"mgraph.h"

void printPath(int u, int v, int path[][MAXSIZE], int A[][MAXSIZE]){
    if (A[u][v] == INF)return; // NO PATH !!
    if (path[u][v] == -1) printf("%d -> %d", u, v); // It means that A[u][v] != INF && path[u][v] == -1 is equal to direct arrival.
    else{
        int mid = path[u][v];
        printPath(u, mid, path, A);
        printPath(mid, v, path, A);
    }
}

void floyd(MGraph G, int path[][MAXSIZE], int A[][MAXSIZE]){
    int i, j, k;
    for (i = 0; i < G->n; ++i){
        for (j = 0; j < G->n; ++j){
            A[i][j] = G->edges[i][j];
            path[i][j] = -1;
        }
    }
    for (k = 0; k < G->n; ++k){
        for (i = 0; i < G->n; ++i){
            for (j = 0; j < G->n; ++j){
                if (A[i][k] != INF && A[k][j] != INF && A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}