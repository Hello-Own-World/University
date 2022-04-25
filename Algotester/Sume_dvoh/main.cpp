#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    long long int x;
    cin >> n >> m >> x;
    long long int arr1[n], arr2[m];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    if (n <= m) {
        sort(arr2, arr2 + m);
        int l = 0, r = m - 1;
        long long min = 2e18;
        long long int z;
        for (long long int el: arr1) {
            z = x - el;
            if (z == 0) {
                continue;
            }

            if (z < 0) {
                z = 1;
            }
            l = 0, r = m - 1;

            while (l != r && l - r != -1) {
                if (arr2[(l + r) / 2] < z) {
                    l = (l + r) / 2;
                } else {
                    r = (l + r) / 2;
                }
            }


            z = x - el - arr2[l];

            if (z < 0) {
                z *= -1;
            }

            if (min > z) {
                min = z;
            }

            z = x - el - arr2[r];
            if (z < 0) {
                z *= -1;
            }

            if (min > z) {
                min = z;
            }

        }
        cout << min;

    } else {
        sort(arr1, arr1 + n);
        int l = 0, r = n - 1;
        long long min = 2e18; // may be not enough
        long long int z;
        for (long long int el: arr2) {
            z = x - el;
            if (z == 0) {
                continue;
            }

            if (z < 0) {
                z = 1;
            }
            l = 0, r = n - 1;

            while (l != r && l - r != -1) {
                if (arr1[(l + r) / 2] < z) {
                    l = (l + r) / 2;
                } else {
                    r = (l + r) / 2;
                }
            }

            z = x - el - arr1[l];

            if (z < 0) {
                z *= -1;
            }

            if (min > z) {
                min = z;
            }

            z = x - el - arr1[r];
            if (z < 0) {
                z *= -1;
            }

            if (min > z) {
                min = z;
            }
        }
        cout << min;
    }
    return 0;
}
