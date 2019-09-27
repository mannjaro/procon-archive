#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n = 0, c = 0, k = 0;
    int a[100000];
    cin >> n >> c >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    int ans = 1, base = 0;
    int passenger = 0;
    int p = 0;
    while (p != n){
        if (passenger < c && (a[p] - a[base] <= k)){
            p++;
            passenger++;
        } else {
            ans++;
            base = p;
            p++;
            passenger = 1;
        }
    }
    cout << ans << endl;
}