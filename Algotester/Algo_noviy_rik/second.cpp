#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[m];
    double max;

    for (int i = 0; i < m; ++i) {
        cin >> arr[i];
    }

    sort(arr, arr + m);
    max = 0;

    for (int i = 1; i <= n && i <= m; ++i) {
        if (pow(arr[m - i], 3) * i > max) {
            max = pow(arr[m - i], 3) * i;
        }
    }


    cout << setprecision(30) << (4.0 / 3.0) * M_PI * max;

    return 0;
}
