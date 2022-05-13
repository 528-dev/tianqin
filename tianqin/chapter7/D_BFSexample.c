#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"agraph.h"

// example7_1 Find the furthest node.
int visited[MAXSIZE];

void initVisited(){
    memset(visited, 0, sizeof(int) * MAXSIZE);
}

int BFS1(AGraph G, int v){
    int queue[MAXSIZE], tmp;
    int front = 0, rear = 0;
    PArcNode p;
    visited[v] = 1;
    queue[rear] = v;
    rear = (rear + 1) % MAXSIZE;
    while (front != rear){
        tmp = queue[front];
        front = (front + 1) % MAXSIZE;
        p = G->adjlist[tmp]->firstArc;
        while (p){
            if (visited[p->adjvex] == 0){
                visited[p->adjvex] = 1;
                queue[rear] = p->adjvex;
                rear = (rear + 1) % MAXSIZE;
            }
            p = p->nextArc;
        }
    }return tmp;
}

// example7_2 Determines whether an undirected graph is a tree.
void DFS2(AGraph G, int v, int *vn, int *en){
    PArcNode p;
    visited[v] = 1;
    (*vn)++;
    p = G->adjlist[v]->firstArc;
    while (p){
        (*en)++;
        if (!visited[p->adjvex]) // had done mistake there !!!
            DFS2(G, p->adjvex, vn, en);
        p = p->nextArc;
    }
}

int gisTree(AGraph G){
    int vn, en;
    initVisited();
    DFS2(G, 0, &vn, &en);
    if (vn == G->n && vn - 1 == en / 2) return 1; 
    // every vertex has been visited
    return 0;
}

// example7_3 Determines whether there' s a path between vertex i and j
// in undirected graph.

int ablei2j(AGraph G, int i, int j){
    initVisited();
    BFS1(G, i);
    return visited[j];
}