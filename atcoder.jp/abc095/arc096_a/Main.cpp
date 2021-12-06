#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    int min  = A * X + B * Y;
    int x, y, z;
    int val;
    for (z = 0; z <= max(X, Y) * 2; z = z + 2) {
        x = X - (z/2);
        if (x <= 0) {
            x = 0;
        }
        y = Y - (z/2);
        if (y <= 0) {
            y = 0;
        }
        val = A*x + B*y + C*z;
        if (min > val) {
            min = val;
        }
    }
    cout << min << endl;
}
