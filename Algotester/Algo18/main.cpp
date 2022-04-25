#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, faith=0, xm=0, ym=0, zm=0;
    cin >> n;
    int xx[n], yy[n], zz[n];
    for (int i = 0; i < n; ++i) {
        cin >> xx[i];
        cin >> yy[i];
        cin >> zz[i];
    }
    sort(xx, xx+n);
    sort(yy, yy+n);
    sort(zz, zz+n);

    if (n%2==0){
        xm = (xx[(n/2)-1]+xx[(n/2)])/2;
        ym = (yy[(n/2)-1]+yy[(n/2)])/2;
        zm = (zz[(n/2)-1]+zz[(n/2)])/2;
    } else{
        n = round(n/2);
        xm = xx[n];
        ym = yy[n];
        zm = zz[n];
    }
    for (int i = 0; i < n; ++i) {
        faith += abs(xm-xx[i]) + abs(ym-yy[i])+ abs(zm-zz[i]);
    }
    cout << faith;
    return 0;
}
