#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n ; i++)

using namespace std;

int main() {
    int n = 0;
    long double ret = 0;
    cin >> n;
    long double cnt = 0;
    for (int i = 1; i <= n; i++){
        if (i % 2 == 1){
            cnt++;
        }
    }
    ret = cnt / n;
    cout << ret << endl;
}