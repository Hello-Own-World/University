#include <iostream>
#include <cmath>
using namespace std;

struct dot{
    int x;
    int y;
};

int main() {
    int xz, yz, xm, ym, n;
    double dist_z, dist_m=0;
    cin >> xz >> yz;
    cin >> xm >> ym >> n;

    dot arr[n];
    dot x{};

    for (int i = 0; i < n; ++i) {
        cin >> x.x;
        cin >> x.y;
        arr[i] = x;
    }

    dist_z = sqrt(pow(xz-xm,2)+pow(yz-ym,2));
    double temp;
    for (int i = 0; i < n; ++i) {
        temp = sqrt(pow(arr[i].x-xm,2)+pow(arr[i].y-ym,2));
        if (temp>dist_m){
            dist_m = temp;
        }
    }
    if (dist_z>dist_m){
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}
