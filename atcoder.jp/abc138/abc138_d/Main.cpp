#include <bits/stdc++.h>

using namespace std;

vector<bool> seen;
vector<int> res;

void dfs(vector<vector<int>> &g, int v) {
    seen[v] = true;
    for (auto next_v : g[v]) {
        if (seen[next_v]) continue;
        res[next_v] += res[v];
        dfs(g, next_v);
    }
}

int main() {
    int n = 0, q;
    cin >> n >> q;
    vector<vector<int>> g(n);
    for (int i = 0; i < n-1; ++i) {
        int a, b;
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    seen = vector<bool>(n, false);
    res = vector<int> (n, 0);
    for (int i = 0; i < q; ++i) {
        int p, x;
        cin >> p >> x;
        res[p-1] += x;
    }
    dfs(g, 0);
    for (auto i : res) {
        cout << i << " ";
    }
    return 0;
}
