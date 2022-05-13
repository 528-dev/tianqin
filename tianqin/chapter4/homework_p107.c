#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

// 不定义字符串，直接使用 char* 做字符串
// 1 将 str 中的 'a' 字符全部换成 'b' 字符
void displace(char* str, char a, char b){
    char* p = str;
    if (!p){
        printf("str == NULL");
        return;
    }
    while (*p){
        if (*p == a) *p = b;
        ++p;
    }
}
int test1(){
    int n;
    char* str, a, b;
    printf("Please enter the char number : ");
    scanf("%d", &n);
    str = (char*)malloc(sizeof(char) * (n + 1));
    printf("Please enter the string of %d characters:", n);
    scanf("%s", str);
    printf("To use \'a\' to displace \'b\'; which is \'a\' and \'b\':");
    fflush(stdin);
    scanf("%c %c", &a, &b);
    printf("Already displaced \'a\' with \'b\':");
    displace(str, a, b);
    printf("%s", str);
}

// 2
void reverse(char* str){
    if (!str){
        printf("String == NULL");
        return;
    }
    int n = strlen(str);
    char* p = str;
    for (int i = 0, j = n - 1; i < j; ++i, --j){
        swap(str + i, str + j);
    }
}

void test2(){
    char a[] = "abcdefg";
    reverse(a);
    printf("%s", a);
}

// 3
void delcrtnchar(char* a, char c){
    if (!a){
        printf("a == NULL");
        return;
    }
    char* p, * q;
    p = q = a;
    while (*q){
        while (*q == c) ++q;
        *p = *q;
        ++p, ++q;
    }
    while (*p){
        *p = '\0';
        ++p;
    }
}

void test3(){
    char str[] = "abcaaaaacbea";
    delcrtnchar(str, 'a');
    printf("%s", str);
}

// 4 KMP implement
// eq to matchAlgorithm.c 


int main(){
    test3();
}