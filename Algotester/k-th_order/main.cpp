#include <iostream>
#include <algorithm>

#define ll long long int

using namespace std;

int main() {
    ll n, m, k, res;
    cin >> n;
    int arr1[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }
    cin >> m;

    ll arr2[m];
    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }
    cin >> k;




    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    ll l = 2 * -1e9, r = 2 * 1e9, mid;
    ll s = 0;

    while (l <= r) {
        mid = (l + r) / 2;

        s = 0;
        ll j = m - 1;

        for (int i = 0; i < n; ++i) {
            while (arr2[j] > mid - arr1[i]) {
                j--;
                if (j == -1) {
                    break;
                }
            }
            if (j == -1) {
                break;
            }
            s += j + 1;
        }

        res = mid;

        if (s < k) {
            l = mid + 1;
            res = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << res+1;

    return 0;
}


/*
3
2 3 4
3
3 2 1
4
 */


