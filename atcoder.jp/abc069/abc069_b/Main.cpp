#include <iostream>
#include <stack>

using namespace std;

int main() {
    string a;
    cin >> a;
    int strsize = 0;
    strsize = a.size() - 2;
    string num = std::to_string(strsize);
    cout << a[0] + num + a[strsize + 1] << endl;
}