#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 2 
void delStrN(char* str, int k, int n){
    char* q = str, * p;
    int i;
    for (i = 0; i < k; ++i) ++q;
    p = q;
    for (i = 0; i < n && *q; ++i, ++q);
    while (*q){
        *p = *q;
        ++p, ++q;
    }*p = '\0';
}

void test2(){
    char s[] = "abcdefghijk";
    delStrN(s, 4, 20);
    printf("%s", s);
}

// 3
void displaceByStr(char** s, int i, int j, char* subStr){
    char* combStr;
    int size, k, tmp;
    size = strlen(*s) + strlen(subStr) - (j - i + 1);
    combStr = (char*)malloc(sizeof(char) * (size + 1));
    for (k = 0; k < i; ++k) combStr[k] = (*s)[k];
    tmp = k;
    for (; k < strlen(subStr) + tmp; ++k) combStr[k] = subStr[k - i];
    for (; k < size; ++k) combStr[k] = (*s)[++j];
    *s = combStr;
}

void test3(){
    char str[] = "abcdefghijk";
    char* s = str;
    displaceByStr(&s, 3, 6, "lmnopqrs");
    printf("%s", s);
}

// 4
// 5

int main(){
    test3();
}