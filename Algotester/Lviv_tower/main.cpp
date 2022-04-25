//#include <iostream>
//#include <iomanip>
//#include <cmath>
//
//using namespace std;
//
//int main() {
//    long double r, h, res;
//    cin >> r >> h;
//    res = 2 * M_PI * r * (sqrt((sqrt(2 * r * h + h * h) - sqrt(2 * r * h + h * h) * r / (r + h)) *
//                              (sqrt(2 * r * h + h * h) + sqrt(2 * r * h + h * h) * r / (r + h))) - h);
//    cout << setprecision(20) << res;
//    return 0;
//}

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
using ld = long double;

int main() {
    ld r, h, x, hh, z, hhh, res;
    cin >> r >> h;
    x = sqrt(2 * r * h + h * h);
    hh = x * r / (r + h);
    z = sqrt((x - hh) * (x + hh));
    hhh = z - h;
    res = 2 * M_PI * r * hhh;
    cout <<setprecision(20)<< res;
    return 0;
}