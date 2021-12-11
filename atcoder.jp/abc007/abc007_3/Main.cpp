#include <bits/stdc++.h>

using namespace std;


vector<int> bfs(const vector<vector<int>> &G, int v) {
    vector<int> dist(10000, -1);
    queue<int> q;
    dist[v] = 0;
    q.push(v);
    while (!q.empty()) {
        int f = q.front();
        q.pop();
        for (auto next : G[f]) {
            if (dist[next] != -1) continue;
            dist[next] = dist[f] + 1;
            q.push(next);
        }
    }
    return dist;
}

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> G(10000);
    int start, goal;
    int x, y;
    cin >> y >> x;
    --x; --y;
    start = x + y*C;
    cin >> y >> x;
    --x; --y;
    goal = x + y*C;
    char line[100][100] = {0};
    for (y = 0; y < R; ++y) {
        for (x = 0; x < C; ++x) {
            cin >> line[y][x];
        }
    }
    for (y = 1; y < R; ++y) { //i = y j = x
        for (x = 1;x  < C; ++x) {
            if (line[y-1][x] == '.') G[x + y*C].push_back(x + (y-1)*C);
            if (line[y][x - 1] == '.') G[x + y*C].push_back(x-1 + y*C);
            if (line[y][x+1] == '.') G[x + y*C].push_back(x+1 + y*C);
            if (line[y+1][x] == '.') G[x + y*C].push_back(x + (y+1)*C);
        }
    }
    auto dist = bfs(G, start);
    cout << dist[goal] << endl;
    return 0;
}
