#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

long double find_angle(int x1, int y1, int x2, int y2, int x3, int y3) {
    pair<int, int> a1, a2;
    long double ab, a1m, a2m, angle;
    a1.first = x2 - x1;
    a1.second = y2 - y1;
    a2.first = x3 - x1;
    a2.second = y3 - y1;
    ab = a1.first * a2.first + a1.second * a2.second;
    a1m = sqrt(pow(a1.first, 2) + pow(a1.second, 2));
    a2m = sqrt(pow(a2.first, 2) + pow(a2.second, 2));
    angle = acos(ab / (a1m * a2m));
    return angle * 180 / M_PI;
}

int main() {
    int n, a, b;
    long double min_angle = 361;
    vector<pair<int, int>> dots;
    cin >> n;
    dots.reserve(n);
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dots.emplace_back(a, b);
    }

    for (auto el1: dots) {
        for (auto el2: dots) {
            for (auto el3: dots) {
                if (el1 != el2 && el1 != el3 && el2 != el3) {
                    min_angle = min(min_angle,
                                    find_angle(el1.first, el1.second, el2.first, el2.second, el3.first, el3.second));
                }
            }
        }
    }

    cout << setprecision(4) << fixed << min_angle;
    return 0;
}
