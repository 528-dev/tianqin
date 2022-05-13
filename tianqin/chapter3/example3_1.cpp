#include<iostream>
#include<string>
#include<stack>
using namespace::std;
// 括号匹配问题
int match(string s){
    stack<char> stk;
    for (auto c : s){
        if (c == '('){
            stk.push('(');
        }
        if (c == ')'){
            if (stk.empty()){
                return 0;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

void test(){
    string s;
    getline(cin, s);
    if (match(s)) cout << "matched" << endl;
    else cout << "not matched" << endl;
}

int main(){
    test();
}