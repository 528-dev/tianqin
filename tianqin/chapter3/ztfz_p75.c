#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"StackAndQueue.h"  // 函数实现在 SQfun.c 中

#define MAXSIZE 50

// 1 共享栈
typedef struct sharedStack* stack;
typedef struct sharedStack{
    int elem[MAXSIZE];
    int top1, top2;
}sharedStack;

stack initStack(){
    stack s = (stack)malloc(sizeof(sharedStack));
    s->top1 = -1, s->top2 = MAXSIZE;
    return s;
}

int push(stack stk, int tag, int e){
    if (stk->top1 + 1 == stk->top2){
        printf("stackOverflow");
        return 0;
    }
    if (tag == 0){
        stk->elem[++stk->top1] = e;
        return 1;
    }
    if (tag == 1){
        stk->elem[--stk->top2] = e;
        return 1;
    }
    return 0;
}

int pop(stack stk, int tag, int* e){
    if (tag == 0){
        if (stk->top1 == -1){
            printf("stack%d is empty", tag);
            return 0;
        }
        else{
            *e = stk->elem[stk->top1--];
            return 1;
        }
    }
    if (tag == 1){
        if (stk->top2 == MAXSIZE){
            printf("stack%d is empty", tag);
            return 0;
        }
        else{
            *e = stk->elem[stk->top2++];
            return 1;
        }
    }
    return 0;
}

int test1(){
    stack stk = initStack();
    int e;
    int a[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 8; ++i){
        if (i % 2)
            push(stk, 0, i);
        else
            push(stk, 1, i);
    }
    for (int i = 0; i < 4; ++i){
        if (pop(stk, 0, &e)) printf("%d ", e);
    }
    for (int i = 0; i < 4; ++i){
        if (pop(stk, 1, &e)) printf("%d ", e);
    }
}


// 2 队的双栈实现
typedef struct queThroughstk* queue;
typedef struct queThroughstk{
    sStack stk0, stk1;
}queThroughstk;

queue initQueue(){
    queue q = (queue)malloc(sizeof(queThroughstk));
    q->stk0 = initsStack();
    q->stk1 = initsStack();
    return q;
}

int enQueue(queue q, int e){
    int tmp;
    if (sStackFull(q->stk0)){
        if (sStackEmpty(q->stk1)){
            while (!sStackEmpty(q->stk0)){
                desStack(q->stk0, &tmp);
                ensStack(q->stk1, tmp);
            }
            ensStack(q->stk0, e);
            return 1;
        }else{
            printf("queue full\n");
            return 0;
        }
    }else{
        ensStack(q->stk0, e);
        return 1;
    }
}

int deQueue(queue q, int* e){
    int tmp;
    if (!sStackEmpty(q->stk1)){
        desStack(q->stk1, e);
        return 1;
    }
    if (!sStackEmpty(q->stk0)){
        while (!sStackEmpty(q->stk0)){
            desStack(q->stk0, &tmp);
            ensStack(q->stk1, tmp);
        }
        desStack(q->stk1, e);
        return 1;
    }
    printf("queue empty\n");
    return 0;
}

int queueEmpty(queue q){
    return (lStackEmpty(q->stk0) && lStackEmpty(q->stk1));
}

void test2(){
    int tmp;
    queue q = initQueue();
    for (int i = 0; i < 10; ++i){
        enQueue(q, i);
    }
    for (int i = 0; i < 5; ++i){
        deQueue(q, &tmp);
        printf("%d ", tmp);
    }
    putchar('\n');
    for (int i = 0; i < 10; ++i){
        enQueue(q, i);
    }
    for (int i = 0; i < 20; ++i){
        if (deQueue(q, &tmp))
            printf("%d ", tmp);
    }
    putchar('\n');
    for (int i = 0; i < 120; ++i){
        enQueue(q, i);
    }
    for (int i = 0; i < 120; ++i){
        if (deQueue(q, &tmp))
            printf("%d ", tmp);
    }
}

int main(){
    test2();
}