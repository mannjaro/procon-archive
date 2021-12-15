#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1e9 + 1;

int main() {
    ll n, w;
    cin >> n >> w;
    vector<ll>weight(n+1, 0);
    vector<ll>value(n+1, 0);
    for (int i = 1; i <= n; ++i) cin >> weight[i] >> value[i];
    vector<vector<ll>>dp(n+1, vector<ll>(100001, 0)); // dp [i][value] iまでの品物でvalueになる最小の重さ
    for (int i = 1; i < 100001; ++i) dp[0][i] = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 100001; ++j) {
            if (j < value[i]) dp[i][j] = dp[i - 1][j];
            else if (j >= value[i]) dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - value[i]] + weight[i]);
        }
    }
    int ans = 100000; // max value
    while (dp[n][ans] > w) --ans;
    cout << ans << endl;
    return 0;
}
