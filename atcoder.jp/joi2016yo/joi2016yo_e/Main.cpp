#include <bits/stdc++.h>

using namespace std;

typedef struct edge {
    int to;
    int64_t cost;
} edge;


const int64_t INF = 1e11;

typedef pair<int64_t , int>P; // weight, vertex


vector<int> bfs(const vector<vector<int>> &G, int n, const vector<int> &c_vec) { // Gは隣接リスト, vは始点
    vector<int> dist(n, -1);  // -1で埋めることで，未到達を-1で判定できる
    queue<int> q;
    for (auto c : c_vec) {
        q.push(c);
        dist.at(c) = 0;
    }
    while (!q.empty()) { // 2. Qが空になるまで続ける
        int f = q.front(); // Dequeue
        q.pop();
        for (auto next : G[f]) {
            if (dist[next] != -1) continue;
            dist[next] = dist[f] + 1;  // 3. 親+1の距離を子に追加する
            q.push(next);  // 4. 取り出した点に隣接するものをEnqueueする
        }
    }
    return dist;
}

vector<int64_t> djk(const vector<vector<edge>> &graph,int n, int s) {
    vector<int64_t> d(n, INF);
    d[s] = 0;   // sから[i]までの最短経路を記録 (d[s]はsからsまでのコスト==0)
    priority_queue<P, vector<P>, greater<>> pq;
    pq.push(P(0, s));   // P(x, y) yへの重み（距離）の合計x
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        if (d[p.second] < p.first) {
            continue;  // 記録してある最短距離より，取り出した要素の距離情報のほうが大きい
        }
        for (auto i : graph[p.second]) {
            if (d[p.second] + i.cost < d[i.to]) {
                d[i.to] = d[p.second] + i.cost; //値の更新
                pq.push(P(d[i.to], i.to));
            }
        }
    }
    return d;
}

vector<int64_t>calc_cost(int n, int s, int p, int q, const vector<int> &safety) {
    vector<int64_t>fee(n, INF);
    for (int i = 0; i < n; ++i) {
        if (safety[i] == 0) {
            fee.at(i) = INF;
        } else if (safety[i] <= s) {
            fee.at(i) = q;
        } else {
            fee.at(i) = p;
        }
    }
    return fee;
}


int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    int p, q;
    cin >> p >> q;
    vector<int> c(k, 0);
    vector<vector<int>> n_list(n);
    vector<vector<edge>>g(n);
    for (int i = 0; i < k; ++i) {int tmp; cin >> tmp; c[i] = tmp - 1;}
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        n_list[a].push_back(b);
        n_list[b].push_back(a);
    }
    vector<int> safety_town;
    safety_town = bfs(n_list, n, c);
    vector<int64_t> cost;
    cost = calc_cost(n, s, p, q, safety_town);
    for (int i = 0; i < n; ++i) {
        for (auto next : n_list[i]) {
            g[i].push_back(edge{next, cost[next]});
        }
    }
    vector<int64_t> d = djk(g, n, 0);
    cout << d[n-1] - cost[n-1] << endl;
    return 0;
}

