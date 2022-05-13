#include<iostream>
#include<stack>
#include<queue>
#include<string>

#define MAXSIZE 10
using namespace::std;

// 3
// 1) 任意前 n 项 I >= O
// 2) 可以 例如：ABC IOIOIO; CBA IIIOOO
// 3)
int isLegal(char seq[]){
    int i, n = 0;
    for (i = 0; seq[i] != '\0'; ++i){
        if (seq[i] == 'I') ++n;
        if (seq[i] == 'O') --n;
        if (n < 0) return 0;
    }return 1;
}

void test3(){
    char s[50];
    cin.getline(s, 50);
    printf("%d", isLegal(s));
}

// 6 循环单链表 仅有尾指针 设计队列的实现
typedef struct Node6* ptrNode6;
typedef ptrNode6 queue6;
typedef struct Node6{
    int data;
    ptrNode6 next;
}Node6;

queue6 init6(){
    queue6 q = (queue6)malloc(sizeof(Node6));
    q->next = q;
    return q;
}

int enqueue6(queue6* q, int e){
    ptrNode6 tmp = (ptrNode6)malloc(sizeof(Node6));
    tmp->data = e;
    tmp->next = (*q)->next;
    (*q)->next = tmp;
    *q = (*q)->next;
    return 1;
}

int dequeue6(queue6* q, int* e){
    ptrNode6 head, tmp;
    if ((*q)->next == *q){
        printf("EMPTY\n");
        return 0;
    }
    head = (*q)->next;
    tmp = head->next;
    *e = tmp->data;
    head->next = tmp->next;
    free(tmp);
    if (head->next == head){
        *q = head;
    }
    return 1;
}
void test6(){
    queue6 q = init6();
    int e;
    for (int i = 0; i < 10; ++i){
        enqueue6(&q, i);
    }
    for (int i = 0; i < 12; ++i){
        dequeue6(&q, &e);
        printf("%d ", e);
        putchar('\n');
    }
}

// 7 见 SQfunc.c 中对循环队列的实现

// 8 通过 tag 实现队列数组的充分利用
typedef struct Queue8* queue8;
typedef struct Queue8{
    int data[MAXSIZE];
    int front, rear;
    char tag;
}Queue8;

queue8 init8(){
    queue8 q = (queue8)malloc(sizeof(Queue8));
    q->tag = 0;
    q->front = q->rear = 0;
    return q;
}

int enQueue8(queue8 q, int e){
    // 判断是否空
    if (q->front == q->rear && q->tag == 1){
        printf("FULL\n");
        return 0;
    }
    // 不为空
    q->tag = 1;
    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % MAXSIZE;
    return 1;
}

int deQueue8(queue8 q, int* e){
    if (q->tag == 0){
        printf("EMPTY\n");
        return 0;
    }
    *e = q->data[q->front];
    q->front = (q->front + 1) % MAXSIZE;
    if (q->front == q->rear) q->tag = 0;
    return 1;
}

void test8(){
    int e;
    queue8 q = init8();
    for (int i = 0; i < 12; ++i){
        enQueue8(q, i);
    }
    putchar('\n');
    for (int i = 0; i < 12; ++i){
        if (deQueue8(q, &e)) printf("%d ", e);
    }
    putchar('\n');
}

// 9 将非负十进制整数 N 转换为二进制数
string transd2b(int N){
    string s("");
    int k;
    while (N){
        k = N % 2;
        N = N / 2;
        s = to_string(k) + s;
    }
    return s;
}

void test9(){
    int k;
    while (cin >> k)
        cout << transd2b(k) << endl;
}

// 10 检查 () [] {} 是否匹配 对于 '' "" 中的括号忽略
int inspectpair(string s){
    stack<char> stk;
    char c;
    for (int i = 0; i < s.size(); ++i){
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
        if (s[i] == char(34)){
            ++i;
            while (s[i] != char(34)){
                cout << i;
                if (i == s.size()) return 0;
                ++i;
            }
        }
        if (s[i] == char(39)){
            ++i;
            while (s[i] != char(39)){
                cout << i;
                if (i == s.size()) return 0;
                ++i;
            }
        }
        if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (stk.empty()) return 0;
            if (s[i] == ')'){
                c = stk.top();
                if (c == '(') stk.pop();
                else return 0;
            }
            if (s[i] == ']'){
                c = stk.top();
                if (c == '[') stk.pop();
                else return 0;
            }
            if (s[i] == '}'){
                c = stk.top();
                if (c == '{') stk.pop();
                else return 0;
            }
        }
    }
    return stk.empty();
}

void test10(){
    string s;
    while (cin >> s){
        // printf("%s", inspectpair(s) ? "matched\n" : "not matched yet\n");
        cout << (inspectpair(s) ? "matched" : "not matched yet") << endl;
    }

}

int main(){
    test10();
}