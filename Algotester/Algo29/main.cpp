#include <iostream>
using namespace std;

int main() {
    long int n, s, ss=0;
    cin >> n;
    for (int i = 0; i < n-1; ++i) {
        cin >> s;
        ss += s;
    }
    s=(n*(n+1))/2;
    cout << s-ss;
    return 0;
}
