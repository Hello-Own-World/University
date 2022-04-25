#include <iostream>

#define p 1234567891
using namespace std;
unsigned long long int s = 0, a, b;

unsigned long long int foo(unsigned long long int x, unsigned long long int y) {
    if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        return foo((x * x) % p, y / 2);
    }

    return (foo(x, y - 1) * x) % p;
}

void foo2(unsigned long long int n) {
    if (n > b) {
        return;
    }
    if (n >= a) {
        s = (s + foo(n % p, n % (p - 1))) % p;
    }
    foo2(10 * n + 4);
    foo2(10 * n + 7);

}

int main() {
    cin >> a >> b;

    foo2(0);

    cout << s;
    return 0;
}