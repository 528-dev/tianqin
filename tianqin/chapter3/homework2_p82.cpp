#include<iostream>
#include<stack>
#include<queue>
#include<cmath>

using namespace::std;

void swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

// 思考题
// 1
double sqrt1(double A, double p, double e){
    if (fabs(p * p - A) < e) return p;
    else sqrt1(A, (p + A / p) / 2, e);
}

double sqrt2(double A, double e){
    double p = A;
    while (fabs(p * p - A) > e){
        p = (p + A / p) / 2;
    }
    return p;
}

// 2 输出 n 个字符全排列
void permutation(char s[], int k, int n){
    if (!k){
        for (int i = 0; i < n; ++i){
            cout << s[i] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i <= k; ++i){
        swap(s + i, s + k);
        permutation(s, k - 1, n);
        swap(s + i, s + k);
    }
}

void test1(){
    double A;
    while (cin >> A){
        cout << "sqrt1(A) = " << sqrt1(A, A, 0.00001) << endl;
        cout << "sqrt2(A) = " << sqrt2(A, 0.00001) << endl;
    }
}

void test2(){
    char a[] = "abcde";
    permutation(a, 4, 5);
}

int main(){
    test2();
}