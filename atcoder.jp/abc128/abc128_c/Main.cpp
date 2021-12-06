#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> bulb[2500];
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int num;
            cin >> num; num--;
            bulb[i].push_back(num);
        }
    }
    int P[100] = {0};
    for (int i = 0; i < M; i++) {
        cin >> P[i];
    }

    // bit 探索
    int success = 0;
    for (int bit = 0; bit < (1 << N); ++bit) {
        int lights_on = 0;
        for (int i = 0; i < M; i++) {
            int cnt = 0;
            for (int a : bulb[i]) {
                if (bit & (1 << a)) {
                    cnt++;
                }
            }
            if (cnt % 2 == P[i]) {
                lights_on++;
            }
        }
        if (lights_on == M) {
            success++;
        }
    }
    cout << success << endl;
}
