#include <iostream>
#include <deque>

using namespace std;

long long int n, m, k, mid;
deque<long long int> a(n);
deque<long long int> b(m);

bool check(int) {
    long long int res = 0;

    long long int j = m - 1;

    for (auto x: a) {
        while (x + b[j] > mid) {
            j--;
            if (j == -1) break;
        }
        if (j == -1)break;
        res += j + 1;

    }
    if (res >= k) return true;
    else return false;
}

int main() {

    cin >> n;


    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cin >> m;

    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    cin >> k;

    long long int l = 2 * -1e9, r = 2 * 1e9, res = -1;

    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout<< mid;


    return 0;
}