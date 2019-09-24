#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> A;
    map<string, int> B;
    int N, M;
    string s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        A[s]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> s;
        B[s]++;
    }
    int max = 0;
    auto begin = A.begin(), end = A.end();
    for (auto iter = begin; iter != end; iter++) {
        string key = iter->first;
        int a = 0;
        if (B.count(key)){
            a = iter->second - B[key];
        } else {
            a = iter->second;
        }
        if (a > max){
            max = a;
        }
    }
    cout << max << endl;
    return 0;
}