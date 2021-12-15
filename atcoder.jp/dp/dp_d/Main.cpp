#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll>weight(n+1, 0);
    vector<ll>value(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> weight[i] >> value[i];
    vector<vector<ll>>dp(n+1, vector<ll>(w+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else if (j >= weight[i]) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }
    cout << dp[n][w] << endl;
    return 0;
}
