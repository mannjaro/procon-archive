#include <bits/stdc++.h>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    vector<vector<int>> a(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> a[i][j];
        }
    }
    int ret = 0;
    for (int bit = 0; bit < (1 << R); ++bit) {
        auto b = a;
        for (int i = 0; i < R; ++i) {
            if (bit & (1 << i)) {
                // i行目を裏返す
                for (int j = 0; j < C; ++j) {
                    b[i][j] = b[i][j] == 0 ? 1 : 0;
                }
            }
        }

        //各列の裏表の数を数える
        int tmp_max = 0;
        for (int j = 0; j < C; ++j) {
            int num = 0;
            for (int i = 0; i < R; ++i) {
                if (b[i][j] == 0) {
                    ++num;
                }
            }
            tmp_max += max(num, R - num);
        }
        ret = max(ret, tmp_max);
    }
    cout << ret << endl;
    return 0;
}
