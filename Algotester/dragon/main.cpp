#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull mod = 1e9 + 7;

ull cat_num(ull n) {
    ull cat_num[n + 1];

    cat_num[0] = 1%mod;
    cat_num[1] = 1%mod;

    for (int i = 2; i <= n; i++) {
        cat_num[i] = 0;
        for (int j = 0; j < i; j++){
            cat_num[i] += (cat_num[j] * cat_num[i - j - 1]);
            cat_num[i] = cat_num[i]%mod;
        }
    }

    return cat_num[n];
}

ull powm(ull cn, ull kk, ull n) {
    for (int i = 0; i < n; ++i) {
        cn = cn * kk % mod;
    }
    return cn;
}

int main() {
    ull n, k;
    cin >> n >> k;
    cout << powm(cat_num(n), k, n);//fact
    return 0;
}
