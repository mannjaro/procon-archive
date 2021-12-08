#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> dn(n+1), kn(m);
    dn[0] = 0;
    for (int i = 1; i < n; ++i) {
        cin >> dn[i];
    }
    dn[n] = d;
    for (int i = 0; i < m; ++i) {
        cin >> kn[i];
    }
    sort(dn.begin(), dn.end());
    int ans = 0;
    for (auto dst : kn) {
        int pos = lower_bound(dn.begin(), dn.end(), dst) - dn.begin();
        if (pos == 0);
        else {
            ans += min(dn[pos] - dst, dst -  dn[pos-1]);
        }
    }
    cout << ans << endl;
    return 0;
}
