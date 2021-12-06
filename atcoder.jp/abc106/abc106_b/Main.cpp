#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; i = i + 2) {
        int mod_count = 0;
        for (int j = 1; j <= i; j++) {
            if ((i % j) == 0) {
                mod_count++;
            }
        }
        if (mod_count == 8) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

