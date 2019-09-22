#include <iostream>
#include <stack>

using namespace std;

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    string f;
    if ((a * b) % 2 == 0){
        f = "Even";
    } else f =  "Odd";
    cout << f << endl;
}