#include <iostream>
using namespace std;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    auto y = (long long int) ((c - 1) / (1 - ((long double) a / b)));
    while ((y - (y * a / b) != c)) {
        y++;
    }
    cout << y * a;
    return 0;
}