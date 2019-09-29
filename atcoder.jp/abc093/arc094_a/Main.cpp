#include <iostream>
#include <algorithm>


#define REP(i, n) for(int i = 0; i < n ; i++)

using namespace std;

int main() {
    int a[3];
    int n = 3;
    REP(i, n) cin >> a[i];
    sort(a, a + n);
    int sum = 0;
    int obj = 3 * a[2];
    REP(i, n) sum += a[i];
    if (sum % 2 != (3 * a[2]) % 2) {
        obj++;
    } else {}
    if (obj % 3 == 1){
        obj += 2;
    } else if (obj % 3 == 2){
        obj++;
    } else {}
    int ans = (obj - sum) / 2;
    cout << ans << endl;
}