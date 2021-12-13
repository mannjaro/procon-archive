#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> t(n+1, vector<int>(3, 0));
    for (int i = 1; i <= n; ++i) cin >> t[i][0] >> t[i][1] >> t[i][2];
    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    dp[1][0] = t[1][0];
    dp[1][1] = t[1][1];
    dp[1][2] = t[1][2];
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) { // j = now (n)
            for (int h = 0; h < 3; ++h) { // h = prev (n)
                if (j == h) continue;
                dp[i][j] = max(dp[i][j], dp[i - 1][h] + t[i][j]);
            }
        }
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << endl;
    return 0;
}
