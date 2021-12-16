#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, 0));
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < t.size(); ++j) {
            if (s.at(i) == t.at(j)) dp[i+1][j+1] = dp[i][j] +1;
            else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
        }
    }
    int len = dp[s.size()][t.size()];
    string ans;
    int i = s.size()-1;
    int j = t.size()-1;
    while (len > 0) {
        if (s[i] == t[j]) {
            ans += (s[i]);
            --i; --j; --len;
        } else if (dp[i+1][j+1] == dp[i][j+1]) --i;
        else --j;
    }
    string ans_reversed (ans.rbegin(), ans.rend());
    cout << ans_reversed << endl;
    return 0;
}
