#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector<vector<ll>> dp(n+1, vector<ll>(21, 0));
    // DP[i][j] == Ai までの変数の和が j である式の個数
    dp[0][0] = 1;
    dp[1][a[0]] = 1;
    for (int i = 1; i < n-1; ++i) {
        for (int j = 0; j <= 20; ++j) {
            if (j + a[i] > 20)      dp[i+1][j] = dp[i][j - a[i]];
            else if (j - a[i] < 0)  dp[i+1][j] = dp[i][j + a[i]];
            else                    dp[i+1][j] = dp[i][j - a[i]] + dp[i][j + a[i]];
        }
    }
    cout << dp[n-1][a[n-1]] << endl;
    return 0;
}
