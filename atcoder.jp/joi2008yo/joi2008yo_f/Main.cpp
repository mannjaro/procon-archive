#include <bits/stdc++.h>

using namespace std;

typedef struct edge {
    int to;
    int cost;
} edge;

typedef long long ll;

const ll INF = 1e9;

typedef pair<int, int>P; // weight, vertex

vector<ll> djk(const vector<vector<edge>> &graph,int n, int s) {    // graph, #node, start
    vector<ll> d(n, INF);
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

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<edge>> g(n);
    for (int i = 0; i < k; ++i) {
        int flag = 0;
        cin >> flag;
        if (flag == 1) {
            // add route
            int c, d, e;
            cin >> c >> d >> e;
            --c; --d;
            g[c].push_back(edge{d, e});
            g[d].push_back(edge{c, e});
        } else if (flag == 0) {
            // customer
            int a, b;   // a to b
            cin >> a >> b;
            --a; --b;
            vector<ll> d = djk(g, n, a);
            if (d[b] == INF) {
                cout << -1 << endl;
            } else {
                cout << d[b] << endl;
            }
        }
    }
    return 0;
}
