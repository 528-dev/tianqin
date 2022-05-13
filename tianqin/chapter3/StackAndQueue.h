#ifndef HEAD_H
#define HEAD_H

#define MAXSIZE 50

typedef struct SqStack* sStack;
typedef struct SqStack{
    int data[MAXSIZE];
    int top;
}SqStack;

typedef struct LNode* lStack;
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;

typedef struct SqQueue* sQueue;
typedef struct SqQueue{
    int data[MAXSIZE];
    int front, rear;
}SqQueue;

typedef struct LiQueue* lQueue;
typedef struct QNode{
    int data;
    struct QNode* next;
}QNode;
typedef struct LiQueue{
    QNode* front;
    QNode* rear;
}LiQueue;

sStack initsStack();
int sStackEmpty(sStack);
int sStackFull(sStack);
int ensStack(sStack, int);
int desStack(sStack, int*);
lStack initlStack();
int lStackEmpty(lStack);
int enlStack(lStack, int);
int delStack(lStack, int*);
sQueue initsQueue();
int sQueueEmpty(sQueue);
int sQueueFull(sQueue);
int ensQueue(sQueue, int);
int desQueue(sQueue, int*);
lQueue initlQueue();
int lQueueEmtpy(lQueue);
int enlQueue(lQueue, int);
int delQueue(lQueue, int*);

#endif