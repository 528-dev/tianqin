#ifndef AOV_H
#define AOV_H

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
    int count;
    PArcNode firstArc;
}VNode;
typedef struct ANode{
    Vertex adjlist[MAXSIZE];
    int n, e;
} *AGraph;

#endif