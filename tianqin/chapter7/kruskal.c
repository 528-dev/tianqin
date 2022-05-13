#include<stdio.h>
#include<stdlib.h>
#include"mgraph.h"
typedef struct RNode{
    int a, b;
    int weight;
}RNode, *Road;
Road roads[MAXSIZE];
int v[MAXSIZE];
int getRoot(int a){
    while (v[a] != a) a = v[a];
    return a;
}

int cmp(const void *a, const void *b){
    return ((Road)a)->weight - ((Road)b)->weight;
}

void Kruskal(MGraph G, int *sum, Road road[]){
    int vn = G->n, en = G->e, a, b;
    *sum = 0;
    for (int i = 0; i < vn; ++i) v[i] = i;
    qsort(roads, en, sizeof(Road), cmp);
    for (int i = 0; i < en; ++i){
        a = getRoot(road[i]->a);
        b = getRoot(road[i]->b);
        if (a != b){
            v[a] = b;
            printf("The %d and %d have been incorporate.", a, b);
            sum += road[i]->weight;
        }
    }
}