#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    string T[4] = { "dream", "erase","eraser", "dreamer"};
    int counter = 0;
    bool flag = false;
    while (counter != (int)S.size()) {
        flag = false;
        for (auto & i : T) {
            if (equal(S.end() - counter - (int)i.size(),S.end() - counter, i.begin())) {
                counter += (int)i.size();
                flag = true;
                break;
            }
        }
        if (!flag) {cout << "NO" << endl; break;}
    }
    if (flag) cout << "YES" << endl;
    return 0;
}
