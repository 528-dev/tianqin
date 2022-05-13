#ifndef MGRAPH_H
#define MGRAPH_H

#define MAXSIZE 50
#define INF 100

typedef struct MNode{
    int edges[MAXSIZE][MAXSIZE];
    int vex[MAXSIZE];
    int n, e;
}MNode, *MGraph;

#endif