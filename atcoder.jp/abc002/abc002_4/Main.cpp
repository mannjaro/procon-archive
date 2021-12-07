#include <bits/stdc++.h>

using namespace std;


int main() {
    int N, M;
    cin >> N >> M;
    bool p[200][200];
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        p[x][y] = true;
    }
    int max_mem = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        vector<int> a;
        for (int i = 0; i < N; ++i) {
            if (bit & (1 << i)) {
                a.push_back(i);
            }
        }
        bool flag = true;
        for (int i : a) {
            for (int j : a) {
                if (i == j) continue;
                if (i < j) {
                    if (!p[i][j]) {
                        flag = false;
                        break;
                    }
                }
            }
        }
        if (flag) {
            max_mem = max(max_mem, (int)(a.size()));
        }
    }
    cout << max_mem << endl;
    return 0;
}
