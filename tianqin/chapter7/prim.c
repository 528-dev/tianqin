#include<stdio.h>
#include<stdlib.h>
#include"mgraph.h"

void prim(MGraph G, int v0, int *sum){
    int lowCost[MAXSIZE], vset[MAXSIZE], v;
    int i, j, k, MIN;
    sum = 0, v = v0;
    for (i = 0; i < G->n; ++i){
        lowCost[i] = G->edges[v][i];
        vset[i] = 0;
    }
    vset[v] = 1;
    for (i = 0; i < G->n - 1; ++i){
        MIN = INT_MAX;
        for (j = 0; j < G->n; ++j){
            if (vset[j] == 0 && lowCost[j] < MIN){
                MIN = lowCost[j];
                k = j;
            }
        }
        vset[k] = 1;
        v = k;
        sum += MIN;
        for (j = 0; j < G->n; ++j){
            if (vset[j] == 0 && G->edges[v][j] < lowCost[j]){
                lowCost[j] = G->edges[v][j];
            }
        }
    }
}