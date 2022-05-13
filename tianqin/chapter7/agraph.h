#ifndef AGRAPH_H
#define AGRAPH_H

#define MAXSIZE 50

typedef struct ArcNode* PArcNode;
typedef struct ArcNode{
    int adjvex;
    PArcNode nextArc;
    // int info;
}ArcNode;

typedef struct VNode* Vertex;
typedef struct VNode{
    char data;
    PArcNode firstArc;
}VNode;
typedef struct ANode{
    Vertex adjlist[MAXSIZE];
    int n, e;
} *AGraph;

#endif