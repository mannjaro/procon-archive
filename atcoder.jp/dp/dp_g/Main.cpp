#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[100001] = {0};
vector<vector<int>> g(100001);

ll memo(int x) {
    if (dp[x] != -1) return dp[x];
    ll fans = 0;
    for (auto next: g[x]) {
        fans = max(fans, memo(next) + 1);
    }
    return dp[x] = fans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(memo(i), ans);
    }
    cout << ans << endl;
}
