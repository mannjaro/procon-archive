#include <iostream>

using namespace std;

string s;

int main() {
    cin >> s;
    int size = s.size();
    int n = size / 2 + size % 2;
    int iterator = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        cout << s[iterator];
        iterator += 2;
    }
    return 0;
}