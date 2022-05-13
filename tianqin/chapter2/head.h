#define MAXSIZE 100

// 顺序表结构定义
typedef struct Sqlist* ptrToSqlist;
typedef ptrToSqlist SList;
typedef struct Sqlist{
    int data[MAXSIZE];
    int length;
}Sqlist;

// 单链表结构定义
typedef struct LNode* ptrToLNode;
typedef ptrToLNode List;
typedef struct LNode{
    int data;
    struct LNode* next;
}LNode;

// 双链表结构定义
typedef struct DLNode* ptrToDLNode;
typedef ptrToDLNode DList;
typedef struct DLNode{
    int data;
    struct DLNode* prior;
    struct DLNode* next;
}DLNode;

SList initSqlist();
void printSqlist(SList);
List initList();
void printList(List);
void swap(int*, int*);