#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int d, c, k;
    double R;
    cin >> R >> d >> c >> k;

    double v1, v2, r = R - d, ls = -R, rs = R, res, h;

    while (abs(rs - ls) > 1e-12) {
        h = (ls + rs) / 2.0;
        v1 = (1.0 / 3.0) * M_PI * pow(R - h, 2) * (3 * R - (R - h)); // h - bin search
        v2 = (1.0 / 3.0) * M_PI * pow(r - h, 2) * (3 * r - (r - h));
        if (-r < h && h < r) {
            v1 = v1 - v2;
            res = v1 * c + v2;
        } else if(h>=r) {
            v2 = 0;
            res = v1 * c;
        } else{
            v2 = (4.0/3.0)*M_PI* pow(r, 3);
            v1 = v1-v2;
            res = v1*c + v2;
        }
        if (res > k) {
            ls = h;
        } else {
            rs = h;
        }
    }
    cout << h;
    return 0;
}
