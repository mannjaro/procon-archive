#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];
    for (int i = 0; i < N; ++i) cin >> C[i];
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());
    long long ans = 0;
    for (int b : B) {
        auto itr_a = lower_bound(A.begin(), A.end(), b);
        auto itr_c = upper_bound(C.begin(), C.end(), b);
        ans += distance(A.begin(), itr_a) * distance(itr_c, C.end());
    }
    cout << ans << endl;
    return 0;
}
