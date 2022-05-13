#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackAndQueue.h"

sStack initsStack(){
    sStack s = (sStack)malloc(sizeof(SqStack));
    s->top = -1;
    memset(s->data, 0, MAXSIZE * sizeof(int));
    return s;
}

int sStackEmpty(sStack s){
    return s->top == -1;
}

int sStackFull(sStack s){
    return s->top == MAXSIZE - 1;
}

int ensStack(sStack s, int e){
    if (sStackFull(s)) return 0;
    s->data[++s->top] = e;
    return 1;
}

int desStack(sStack s, int* e){
    if (sStackEmpty(s)) return 0;
    *e = s->data[s->top--];
    return 1;
}

lStack initlStack(){
    lStack s = (lStack)malloc(sizeof(LNode));
    s->data = -1;
    s->next = NULL;
}

int lStackEmpty(lStack s){
    return s->next == NULL;
}

int enlStack(lStack s, int e){
    lStack tmp = (lStack)malloc(sizeof(LNode));
    tmp->data = e;
    tmp->next = s->next;
    s->next = tmp;
    return 1;
}

int delStack(lStack s, int* e){
    if (lStackEmpty(s)) return 0;
    lStack tmp = s->next;
    *e = tmp->data;
    s->next = tmp->next;
    free(tmp);
    return 1;
}

sQueue initsQueue(){
    sQueue q = (sQueue)malloc(sizeof(SqQueue));
    memset(q->data, 0, MAXSIZE * sizeof(int));
    q->front = q->rear = 0;
    return q;
}

int sQueueEmpty(sQueue q){
    return q->front == q->rear;
}

int sQueueFull(sQueue q){
    return (q->rear + 1) % MAXSIZE == q->front;
}

int ensQueue(sQueue q, int e){
    if (sQueueFull(q)) return 0;
    q->rear = (q->rear + 1) % MAXSIZE;
    q->data[q->rear] = e;
    return 1;
}

int desQueue(sQueue q, int* e){
    if (sQueueEmpty(q)) return 0;
    q->front = (q->front + 1) % MAXSIZE;
    *e = q->data[q->front];
    return 1;
}

lQueue initlQueue(){
    lQueue q = (lQueue)malloc(sizeof(LiQueue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int lQueueEmtpy(lQueue q){
    return (q->front == NULL || q->rear == NULL);
}

int enlQueue(lQueue q, int e){
    QNode* tmp = (QNode*)malloc(sizeof(QNode));
    tmp->data = e;
    tmp->next = NULL;
    if (lQueueEmtpy(q)){
        q->front = q->rear = tmp;
        return 1;
    }
    q->rear->next = tmp;
    q->rear = tmp;
    return 1;
}

int delQueue(lQueue q, int* e){
    QNode* tmp;
    if (lQueueEmtpy(q)) return 0;
    // not empty
    tmp = q->front;
    *e = tmp->data;
    if (q->front == q->rear)
        q->front = q->rear = NULL;
    else
        q->front = q->front->next;
    free(tmp);
    return 1;
}