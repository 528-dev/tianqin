#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
typedef vector<int> Sqlist;
int solution3(Sqlist arr){
    unordered_map<int, int> m;
    for (auto i : arr){
        m[i] += 1;
        cout << m.count(i) << endl;
        cout << i << ":" << m[i] << endl;
    }
    for (auto i : m){
        if (i.second > arr.size() / 2){
            return i.first;
        }
    }return -1;
}

int main(){
    cout << solution3(vector<int> {1, 2, 2, 2, 3, 2, 4});
}