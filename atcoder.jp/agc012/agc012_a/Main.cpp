#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;

int main() {
    cin >> N;
    int A[1000000];
    for (int i = 0; i < 3 * N; i++) {
        cin >> A[i];
    }
    sort(A, A + 3 * N, greater<>());
    long long int sum = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        cnt++;
        sum += A[cnt];
        cnt++;
    }
    cout << sum << endl;
    return 0;
}