#include <bits/stdc++.h>

using namespace std;



int bfs(const vector<vector<int>> &G, int s, int g) { // start , goal
    vector<int> dist(1e6, -1);
    queue<int> q;
    dist[s] = 0;
    q.push(s);// 1. Enqueue
    int len = 0;
    while (!q.empty()) { // 2. Qが空になるまで続ける
        int f = q.front(); // Dequeue
        if (f == g) {len = dist[g];break;}
        q.pop();
        for (auto next : G[f]) {
            if (dist[next] != -1) continue;
            dist[next] = dist[f] + 1;  // 3. 親+1の距離を子に追加する
            q.push(next);  // 4. 取り出した点に隣接するものをEnqueueする
        }
    }
    return len;
}

int main() {
    int ans = 0;
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> G(H*W);
    int point[10] = {0};
    string line[H];
    int start = 0;
    for (int y = 0; y < H; ++y) {
        cin >> line[y];
    }
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            for (int i = 0; i < N; ++i) {
                if (line[y].at(x) == (i+1) + '0') {
                    point[i] = x + y*W;
                }
            }
            if (line[y].at(x) == 'S') {
                start = x + y*W;
            }
            if ((y - 1 >= 0) && (line[y-1].at(x) != 'X')) {
                G[x + y*W].push_back(x + (y-1)*W);
            }
            if ((x - 1 >= 0) && (line[y].at(x-1) != 'X')) {
                G[x + y*W].push_back(x-1 + y*W);
            }
            if ((x + 1 < W) && (line[y].at(x+1) != 'X')) {
                G[x + y*W].push_back(x+1 + y*W);
            }
            if ((y + 1 < H) && (line[y+1].at(x) != 'X')) {
                G[x + y*W].push_back(x + (y+1)*W);
            }
        }
    }
    ans += bfs(G,start, point[0]);
    for (int i = 1 ; i < N; ++i) {
        ans += bfs(G, point[i-1], point[i]);
    }
    cout << ans << endl;
    return 0;
}
