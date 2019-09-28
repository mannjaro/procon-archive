#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define REP(i, n) for(int i = 1; i <= n ; i++)

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    map<int, int>A;
    map<int, int>B;
    REP(i, n) {
        int num = 0;
        cin >> num;
        A[i] = num;
    }
    for (auto itr = A.begin(); itr != A.end(); itr++){
        B[itr->second] = itr->first;
    }
    for (auto itr = B.begin(); itr != B.end(); itr++){
        cout << itr->second << endl;
    }
}