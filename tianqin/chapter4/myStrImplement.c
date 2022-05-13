#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myStr.h"

string initMyStr(char* p){
    string s = (string)malloc(sizeof(myStr));
    char* q = p, * r;
    s->length = 0;
    if (!p){
        s->s = NULL;
        return s;
    }
    while (*q){
        ++q, ++s->length;
    }
    s->s = (char*)malloc(sizeof(char) * (s->length + 1));
    q = p, r = s->s;
    while (*q){
        *r = *q;
        ++r, ++q;
    }*r = '\0';
    return s;
}

int strAssign(string str, char* p){
    char* q;
    char* r;
    if (!p) return 0;
    if (str->s) free(str->s);
    str->length = 0;
    q = p;
    while (*q){
        ++str->length;
        ++q;
    }
    str->s = (char*)malloc(sizeof(char) * (str->length + 1));
    q = p, r = str->s;
    while (*q){
        *r = *q;
        ++r, ++q;
    }
    *r = '\0';
    return 1;
}

int strLen(string s){
    if (!s) return -1;
    return s->length;
}

int strCmp(string s1, string s2){
    if (!s1 || !s2){
        printf("strCmp crash");
        exit(-1);
    }
    char* p = s1->s, *q = s2->s;
    while ((*p) && (*q) && (*p == *q)){
        ++p, ++q;
    }
    return (*p - *q);
}

string concat(string s1, string s2){
    if (!s1 || !s2){
        printf("concat crash");
        exit(-1);
    }
    string s = (string)malloc(sizeof(myStr));
    s->length = s1->length + s2->length;
    s->s = (char*)malloc(sizeof(char) * (s->length + 1));
    char* p = s->s, *q = s1->s;
    while (*q){
        *(p++) = *(q++);
    }
    q = s2->s;
    while (*q){
        *(p++) = *(q++);
    }
    return s;
}

int subStr(string sub, string str, int pos, int len){
    int i, j;
    if (!sub || pos < 0 || pos > str->length - 1 || len < 0 || len > str->length - pos){
        printf("subStr failed");
        return 0;
    }
    if (sub->s){
        free(sub->s);
    }
    sub->s = (char*)malloc(sizeof(char) * (len + 1));
    for (i = pos, j = 0; i < pos + len; ++i, ++j){
        sub->s[j] = str->s[i];
    }sub->s[j] = '\0';
    sub->length = len;
    return 1;
}

int clearString(string s){
    if (s->s){
        free(s->s);
        s->s = NULL;
    }
    s->length = 0;
    return 1;
}

int print(string s){
    printf("%s\n", s->s);
    return 1;
}