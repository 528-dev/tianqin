#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agraph.h"

int visit[MAXSIZE];
void initVisit(){
    memset(visit, 0, MAXSIZE * sizeof(int));
}

void DFS(AGraph G, int v){
    PArcNode p;
    visit[v] = 1;
    printf("%c ", G->adjlist[v]);
    p = G->adjlist[v]->firstArc;
    while (p){
        if (!visit[p->adjvex]){
            DFS(G, p->adjvex);
        }
        p = p->nextArc;
    }
}

void dfs(AGraph G){
    initVisit(visit);
    for (int i = 0; i < G->n; ++i){
        if (!visit[i]) DFS(G, i);
    }
}

void BFS(AGraph G, int v){
    PArcNode p;
    int queue[MAXSIZE], front = 0, rear = 0;
    int tmp;
    printf("%c ", G->adjlist[v]->data);
    visit[v] = 1;

    queue[rear] = v;
    rear = (rear + 1) % MAXSIZE;

    while (front != rear){
        tmp = queue[front];
        front = (front + 1) % MAXSIZE;
        p = G->adjlist[tmp]->firstArc;
        while (p){
            if (!visit[p->adjvex]){
                printf("%c ", G->adjlist[p->adjvex]->data);
                visit[p->adjvex] = 1;
                queue[rear] = p->adjvex;
                rear = (rear + 1) % MAXSIZE;
            }
            p = p->nextArc;
        }
    }
}

void bfs(AGraph G){
    initVisit(visit);
    for (int i = 0; i < G->n; ++i){
        if (!visit[i]) BFS(G, i);
    }
}