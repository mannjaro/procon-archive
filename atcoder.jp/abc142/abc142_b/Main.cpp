#include <iostream>
#include <map>
#include <string>
#include <algorithm>

#define REP(i, n) for(int i = 0; i < n ; i++)

using namespace std;

int main() {
    int n = 0;
    int k = 0;
    cin >> n >> k;
    int h[n];
    REP(i, n) cin >> h[i];
    sort(h, h + n);
    int ret = 0;
    for (int i = 0; i < n; i++){
        if (h[i] >= k){
            ret++;
        }
    }
    cout << ret << endl;
}