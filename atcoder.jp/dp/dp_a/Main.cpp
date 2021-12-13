#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin >> n;
    vector<int>h(n, 0);
    for (int i = 0; i < n; ++i) cin >> h[i];
    vector<int> c(n+1, 0);
    c[1] = c[0] + abs(h[1] - h[0]);
    for (int i = 1; i < n; ++i) {
        c[i + 1] = min(c[i] + abs(h[i + 1] - h[i]), c[i - 1] + abs(h[i + 1] - h[i - 1]));
    }
    cout << c[n-1] << endl;
    return 0;
}