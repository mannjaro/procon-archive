#include <iostream>

using namespace std;

int N;
int A[100];

int main(){
    int min, max;
    min = 0;
    max = 0;
    cin >> N;
    for (int i = 0; i < N ; i++){
        cin >> A[i];
    }
    min = A[0];
    max = A[1];
    for (int i = 0; i < N ; i++){
        if (A[i] < min){
            min = A[i];
        }
        if (A[i] > max){
            max = A[i];
        }
    }
    int ret = max - min;
    cout << ret << endl;
    return 0;
}