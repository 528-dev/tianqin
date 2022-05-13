#include<stdio.h>
#include<stdlib.h>
#include"mgraph.h"

void printPath(int v, int path[]){
    int stack[MAXSIZE], top = -1;
    while (v != -1){
        stack[++top] = v;
        v = path[v];
    }
    printf("the path to %d is:\n", v);
    while (top != -1){
        printf("%d ", stack[top--]);
    }
}

void dijkstra(MGraph G, int v, int dist[], int path[]){
    int set[MAXSIZE];
    int u, min, vn = G->n, en = G->e;
    for (int i = 0; i < vn; ++i){
        set[i] = 0;
        dist[i] = G->edges[v][i];
        path[i] = v ? dist[i] < INF : -1;
    }
    set[v] = 1, path[v] = -1;
    for (int i = 0; i < vn - 1; ++i){
        min = INF;
        for (int j = 0; j < vn; ++j){
            if (set[j] == 0 && dist[j] < min){
                min = dist[j];
                u = j;
            }
        }
        set[u] = 1;
        for (int i = 0; i < vn; ++i){
            if (set[i] == 0 && G->edges[u][i] != INF && dist[u] + G->edges[u][i] < dist[i]){
                dist[i] = dist[u] + G->edges[u][i];
                path[i] = u;
            }
        }
    }
}
