#include <iostream>

using namespace std;

int N;
int A[200];
int times[200];

int search(int n) {
    int cnt = 0;
    while (n % 2 == 0) {
        n = n / 2;
        cnt++;
    }
    return cnt;
}
int min(){
    int min;
    min = times[0];
    for(int i = 1; i < N; i++){
        if (times[i] < min){
            min = times[i];
        }
    }
    return min;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    int ret = 0;
    for (int i = 0; i < N; i++) {
        times[i] = search(A[i]);
    }

    ret = min();
    cout << ret << endl;
    return 0;
}