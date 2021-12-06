#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int find_count = 0;
    for (int i = 0; i < 1000; i++) {
        ostringstream sout;
        sout << std::setfill(('0')) << std::setw(3) << i;
        string key = sout.str();
        int j;
        for (j = 0; j < N; j++) {
            if (key.at(0) == S.at(j)) {
                for (j++; j < N; j++) {
                    if (key.at(1) == S.at(j)) {
                        for (j++; j < N; j++) {
                            if (key.at(2) == S.at(j)) {
                                // Find Key
                                find_count++;
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
    cout << find_count << endl;
}
