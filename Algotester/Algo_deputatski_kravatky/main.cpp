#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m, y = 0;
    double l = 0, r = 1'000'000'000, x = 0, xo;
    cin >> m >> n;
    double arr[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + m);

    while (true) {
        y = 0;
        xo = x;
        x = (l + r) / 2;

        if (abs(x - xo) < 0.0001) {
            break;
        }

        for (int i = 0; i < m; ++i) {
            y += (int) (arr[i] / x);
        }
        if (y >= n) {
            l = x;
        } else {
            r = x;
        }
    }

    cout << setprecision(16) << x;

    return 0;
}