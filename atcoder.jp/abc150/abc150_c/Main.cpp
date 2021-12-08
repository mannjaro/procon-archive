#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int B[10] = {0};
    int P[10] = {0};
    int Q[10] = {0};
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> Q[i];
    for (int i = 1; i <= N; i++) B[i - 1] = i;
    int counter = 0; int p_find = 0; int q_find = 0;
    do {
        bool P_flag = true;
        bool Q_flag = true;
        for (int i = 0; i < N; i++) {
            if (P[i] != B[i]) P_flag = false;
            if (Q[i] != B[i]) Q_flag = false;
        }
        if (P_flag) p_find = counter;
        if (Q_flag) q_find = counter;
        ++counter;
    } while (next_permutation(B, B+N));
    cout << abs(p_find - q_find) << endl;
    return 0;
}
