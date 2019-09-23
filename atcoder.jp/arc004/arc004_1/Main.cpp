#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int X[100];
int Y[100];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i];
        cin >> Y[i];
    }
    int max = 0;
    int xdf = 0;
    int ydf = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            xdf = X[i] - X[j];
            ydf = Y[i] - Y[j];
            int ret = pow(xdf, 2) + pow(ydf, 2);
            if (ret > max){
                max = ret;
            }
        }
    }
    long double  ret = sqrt(max);
    cout << ret << endl;
    return 0;
}