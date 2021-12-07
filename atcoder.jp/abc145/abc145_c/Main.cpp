#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    int A[8][2] = {0};
    int B[8] = {0};
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> A[i][0] >> A[i][1];
    for (int i = 0; i < N; i++) B[i] = i;
    double route = 0; int cnt = 0;
    do {
        for (int i = 0; i < N-1; i++) {
            route += sqrt(pow(A[B[i]][0] - A[B[i+1]][0], 2) + pow(A[B[i]][1] - A[B[i+1]][1], 2));
        }
        ++cnt;
    } while (next_permutation(B, B+N));
    cout << fixed;
    cout << setprecision(8) << route / cnt << endl;
    return 0;
}
