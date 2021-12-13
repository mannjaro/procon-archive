#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e9;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n, 0);
    for (int i = 0; i < n; ++i) cin >> h[i];
    vector<ll> c(n+1, INF);
    c[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < min(i+1, k); ++j) {
             c[i+1] = min(c[i+1], c[i-j] + abs(h[i+1] - h[i-j]));
        }
    }
    cout << c[n-1] << endl;
    return 0;
}
