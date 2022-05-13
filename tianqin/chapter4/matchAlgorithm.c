#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"myStr.h"

// 暴力搜索 O(n^2)
int match1(string str, string subStr){
    int i, j, tmp;
    for (i = 0; i < str->length - subStr->length + 1; ++i){
        tmp = i;
        for (j = 0; j < subStr->length; ++j){
            if (str->s[i] != subStr->s[j]) break;
            ++i;
        }
        if (j == subStr->length) return tmp;
        i = tmp;
    }
    return -1;
}

int test1(){
    string s1 = initMyStr("abcdkji");
    string s2 = initMyStr("dkjik");
    printf("%d", match1(s1, s2));
}


// KMP Algorithm
void getNext(char* p, int** next, int* size){
    int j, k;
    *next = (int*)malloc(sizeof(int) * strlen(p));
    (*next)[0] = -1;
    j = 0, k = -1;
    while (j < strlen(p) - 1){
        if (k == -1 || p[j] == p[k]){
            ++j, ++k;
            (*next)[j] = k;
        }else{
            k = (*next)[k];
        }
    }
    *size = strlen(p);
}

int matchKmp(string str, string subStr){
    int* next, size, i, j;
    getNext(subStr->s, &next, &size);
    i = j = 0;
    while (i < str->length && j < subStr->length){
        if (j == -1 || str->s[i] == subStr->s[j]) ++i, ++j;
        else j = next[j];
    }if (j == subStr->length) return i - subStr->length;
    return -1;
}

void test2(){ 
    int* arr, n;
    string s = initMyStr("abcabcd");
    string subs = initMyStr("abce");
    printf("%d", matchKmp(s, subs));
}


int main(){
    test2();
}