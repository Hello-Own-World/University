#include <iostream>

using namespace std;

int main() {
    long long int n, k, x, s, ls = 0, rs = 1e12, xx, ss;
    cin >> n >> k;
    long long int arr[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    while (true) {
        s = 0;
        x = (ls + rs) / 2;
        for (long long int i = 0; i < n; ++i) {
            s += max((long long) arr[i] - (long long) (x * (i + 1)), (long long) 0);
        }
        if (s < k) {
            rs = x; // checked зменшувати x щоб збільшити суму
            if (rs == ls) {
                break;
            }
        } else {
            ls = x;
            if (rs - ls == 1) {
                x = ls;
                long long s1 = 0, s2 = 0;
                for (long long int i = 0; i < n; ++i) {
                    s1 += max((long long) arr[i] - (long long) (x * (i + 1)), (long long) 0);
                }
                x = rs;
                for (long long int i = 0; i < n; ++i) {
                    s2 += max((long long) arr[i] - (long long) (x * (i + 1)), (long long) 0);
                }
                if (s2 > k) {
                    s = s2;
                } else {
                    s = s1;
                    x = ls;
                }
                break;
            }
        }
    }

    ss = s;
    xx = x;

    ls = 1, rs = 1e12;

    while (true) {
        s = 0;
        x = (ls + rs) / 2;
        for (int i = 0; i < n; ++i) {
            s += max((long long) arr[i] + (long long) (x * (i + 1)), (long long) 0);
        }
        if (s < k) {
            ls = x;
            if (rs - ls == 1) {
                x = ls;
                long long s1 = 0, s2 = 0;
                for (long long int i = 0; i < n; ++i) {
                    s1 += max((long long) arr[i] + (long long) (x * (i + 1)), (long long) 0);
                }
                x = rs;
                for (long long int i = 0; i < n; ++i) {
                    s2 += max((long long) arr[i] + (long long) (x * (i + 1)), (long long) 0);
                }
                if (s2 > k) {
                    s = s2;
                } else {
                    s = s1;
                    x = ls;
                }
                break;
            }
        } else {
            rs = x;
            if (rs == ls) {
                break;
            }
        }
    }

    if (abs((long long) k - (long long) ss) > abs((long long) k - (long long) s)) {
        cout << (long long) x * -1 << ' ' << s;
    } else {
        cout << xx << ' ' << ss;
    }

    return 0;
}

