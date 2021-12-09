#include <bits/stdc++.h>

typedef long long ll;
const ll INF = 1e15;

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<ll> H(N), S(N);
    for (int i = 0; i < N; ++i) cin >> H[i] >> S[i];
    ll left = 0; ll right = INF;
    while (right - left > 1) {
        bool flag = true;
        ll mid = (left + right)/2;
        vector<ll> t(N, 0);
        for (int i = 0; i < N; i++) {
            if (mid < H[i]) flag = false;
            else t[i] = (mid - H[i]) / S[i];
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < N; i++) {
            if (t[i] < i) flag = false;
        }
        if (flag) right = mid;
        else left = mid;
    }
    cout << right << endl;
    return 0;
}
