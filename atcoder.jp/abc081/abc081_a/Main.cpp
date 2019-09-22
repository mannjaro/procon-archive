#include <iostream>
#include <stack>

using namespace std;

int main() {
    string a;
    cin >> a;
    int c = 0;
    for(int i = 0; i<3; i++){
        c += (a[i] == '1');
    }
    cout << c << endl;
}