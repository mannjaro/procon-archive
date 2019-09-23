#include <iostream>
#include <algorithm>

using namespace std;

string S;

int main() {
    int flag = 0;
    int memo[2] = {0};
    cin >> S;
    for (int i = 0; i < S.size(); i++){
        if (S[i] == 'A' && flag == 0){
            flag++;
            memo[0] = i;
        } else if (S[i] == 'Z') {
            memo[1] = i;
        }
    }
    cout << memo[1] - memo[0] + 1 << endl;
    return 0;
}
