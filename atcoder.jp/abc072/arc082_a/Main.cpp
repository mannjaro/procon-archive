#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n ; i++)

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    map<int, int>A;
    int B[100000] = {0};
    REP(i, n) {
        int a = 0;
        cin >> a;
        A[a]++;
    }
    for (auto itr = A.begin(); itr != A.end(); itr++){
        const int key = itr->first;
        if (A.count(key - 1)){
            B[key] += A[key - 1];
        }
        if (A.count(key + 1)){
            B[key] += A[key + 1];
        }
        B[key] += A[key];
    }
    int ret = 0;
    for (int i = 0; i < 100000; i++){
        if (ret < B[i]){
            ret = B[i];
        }
    }
    cout << ret << endl;
}