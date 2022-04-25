#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    double R = 1, R2, ang, sum;
    double l = n / 2.0, r = 5 * n;

    do {
        sum = 0;
        R2 = R;
        for (int i = 1; i <= n; ++i) {
            R = (l + r) / 2.0;
            ang = (2 * pow(R, 2) - pow(i, 2)) / (2 * pow(R, 2));
            sum += acos(ang);
        }
        if (sum < 2 * M_PI) {
            r = R;
        } else {
            l = R;
        }

    } while (abs(R2 - R) > 1e-4);

    cout << R;

    return 0;
}
