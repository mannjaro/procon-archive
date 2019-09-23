#include <iostream>
#include <algorithm>

using namespace std;

int N, X;
int M[1000];

int main (){
    int sum = 0;
    cin >> N;
    cin >> X;
    for (int i = 0; i < N ; i++){
        cin >> M[i];
        X -= M[i];
        sum++;
    }
    sort(M, M+N);
    for (int i = 0; X >= M[0] ;X -= M[0], sum++){}
    cout << sum << endl;
    return 0;
}