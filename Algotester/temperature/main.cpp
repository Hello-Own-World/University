#include <iostream>
#include <cmath>

using namespace std;
typedef long long int ll;

int main() {

    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    ll l = min(a, b), r = max(a, b) + (n - 1) * k;
    ll mid, res, res1;
    ll nt;

    //for min
    while (l <= r) {
        mid = (l + r) / 2;
        nt = 0;
        ll midt = mid;
        nt += ceil(((long double) max<ll>(midt, a) - min<ll>(midt, a)) / k);
        nt += ceil(((long double) max<ll>(midt, b) - min<ll>(midt, b)) / k);
        res = mid;

        if (nt > n - 1) {
            r = mid - 1;
            res = r;
        } else {
            l = mid + 1;
        }
    }

    //bin search for max
    l = min(a, b) - (n - 1) * k, r = max(a, b);
    while (l <= r) {
        mid = (l + r) / 2;
        nt = 0;
        ll midt = mid;
        nt += ceil(((long double) max<ll>(midt, a) - min<ll>(midt, a)) / k);
        nt += ceil(((long double) max<ll>(midt, b) - min<ll>(midt, b)) / k);
        res1 = mid;

        if (nt > n - 1) {
            l = mid + 1;
            res1 = l;
        } else {
            r = mid - 1;
        }
    }
    cout << res << ' ' << res1;
    return 0;
}
