#include<stdio.h>
#include<stdlib.h>
#include"agraph.h"

// 1.To determine is there a path fron u to v.
int visited[MAXSIZE];

void initVisited(){
    for (int i = 0; i < MAXSIZE; ++i){
        visited[i] = 0;
    }
}

int pathV2U(AGraph G, int u, int v){
    initVisited();
    printf("%s", "yes" ? dfs(G, u, v) : "no");
}

int dfs(AGraph G, int u, int v){
    PArcNode p;
    visited[u] = 1;
    p = G->adjlist[u]->firstArc;
    while (p){
        if (!visited[p->adjvex]){
            visited[p->adjvex] = 1;
            if (p->adjvex == v)
                return 1;
            else
                if(dfs(G, p->adjvex, v))
                    return 1;   
            p = p->nextArc;
        }
    }
    return 0;
}

// 2.Defining the nodes that each node can reach as the root node, 
// to print all the root nodes.

void findRoot(AGraph G){
    int vn = G->n;
    for (int i = 0; i < vn; ++i){
        if (BFS(G, i)) printf("%d ", i);
    }
}

int BFS(AGraph G, int u){
    int queue[MAXSIZE], front = 0, rear = 0;
    int v;
    PArcNode p;
    initVisited();
    queue[rear] = u;
    rear = (rear + 1) % MAXSIZE;
    visited[u] = 1;
    while (rear != front){
        v = queue[front];
        front = (front + 1) % MAXSIZE;
        p = G->adjlist[v]->firstArc;
        while (p){
            if (!visited[p->adjvex]){
                visited[p->adjvex] = 1;
                queue[rear] = p->adjvex;
                rear = (rear + 1) % MAXSIZE;
            }
            p = p->adjvex;
        }
    }
    for (int i = 0; i < G->n; ++i){
        if (visited[i] == 0) return 0;
    }
    return 1;
}