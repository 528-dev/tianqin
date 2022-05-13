#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"StackAndQueue.h"

// 后缀式计算
char* s_gets(char* s, int n, int* size){
    char* ret = NULL;
    int i = 0;
    ret = fgets(s, n, stdin);
    if (ret){
        while (s[i] != '\n' && s[i] != '\0'){
            ++i;
        }
        if (s[i] == '\n'){
            s[i] = '\0';
        }
        *size = i;
    }
    return ret;
}

int operator(int a, int b, char op){
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    if (op == '/'){
        if (b == 0) {
            printf("division by zero");
            exit(-1);
        }
        return a / b;
    }
}

int calculate(char s[], int size){
    int num;
    int a, b, result;
    lStack numStk;
    numStk = initlStack();
    for (int i = 0; i < size; ++i){
        if (s[i] >= '0' && s[i] <= '9'){
            num = s[i] - '0';
            enlStack(numStk, num);
        }else{
            if (delStack(numStk, &b) == 0){
                printf("error");
                exit(-1);
            }
            if (delStack(numStk, &a) == 0){
                printf("error");
                exit(-1);
            }
            result = operator(a, b, s[i]);
            enlStack(numStk, result);
        }
    }
    delStack(numStk, &result);
    return result;
}

void test(){
    int n;
    char s[20];
    s_gets(s, 20, &n);
    printf("%d", calculate(s, n));
}

int main(){
    test();
}