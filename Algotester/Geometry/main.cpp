#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
using ll =  long long;

namespace fraction {
    pair<ll, ll> subtr_fractions(pair<ll, ll> l1, pair<ll, ll> l2) {
        pair<ll, ll> l;
        l.first = l1.first * l2.second - l2.first * l1.second;
        l.second = l1.second * l2.second;
        if (l.second != 0) {
            ll gcd = __gcd(l.first, l.second);
            if (gcd) {
                l.first = l.first / gcd;
                l.second = l.second / gcd;
            }
        }
        return l;
    }

    pair<ll, ll> sum_fractions(pair<ll, ll> l1, pair<ll, ll> l2) {
        pair<ll, ll> l;
        l.first = l1.first * l2.second + l2.first * l1.second;
        l.second = l1.second * l2.second;
        if (l.second != 0) {

            ll gcd = __gcd(l.first, l.second);
            if (gcd) {
                l.first = l.first / gcd;
                l.second = l.second / gcd;
            }
        }
        return l;
    }

    pair<ll, ll> divide_fractions(pair<ll, ll> l1, pair<ll, ll> l2) {
        pair<ll, ll> l;
        l.first = l1.first * l2.second;
        l.second = l1.second * l2.first;

        if (l.first != 0 && l.second != 0) {
            ll gcd = __gcd(l.first, l.second);
            if (gcd) {
                l.first = l.first / gcd;
                l.second = l.second / gcd;
            }
        }
        return l;
    }

    pair<ll, ll> multiply_fractions(pair<ll, ll> l1, pair<ll, ll> l2) {
        pair<ll, ll> l;
        l.first = l1.first * l2.first;
        l.second = l1.second * l2.second;
        if (l.second != 0) {
            ll gcd = __gcd(l.first, l.second);
            if (gcd) {
                l.first = l.first / gcd;
                l.second = l.second / gcd;
            }
        }
        return l;
    }

    pair<pair<ll, ll>, pair<ll, ll>> cross(ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) {
        if (b1 != 0 && b2 != 0) {
            pair<ll, ll> k1, k2, l1, l2, xx, y;
            k1 = {-a1, b1};
            k2 = {-a2, b2};
            l1 = {-c1, b1};
            l2 = {-c2, b2};
            pair<pair<ll, ll>, pair<ll, ll>> x;
            x.first = subtr_fractions(l2, l1);
            x.second = subtr_fractions(k1, k2);
            xx = divide_fractions(x.first, x.second);

            if (k1.second || l1.second) {
                y = sum_fractions(multiply_fractions(k1, xx), l1);
            } else {
                y = sum_fractions(multiply_fractions(k2, xx), l2);
            }
            if (xx.second < 0) {
                xx.first *= -1;
                xx.second *= -1;
            }
            if (y.second < 0) {
                y.first *= -1;
                y.second *= -1;
            }
            if (xx.first == 0) {
                xx.second = 1;
            }
            if (y.first == 0) {
                y.second = 1;
            }
            pair<pair<ll, ll>, pair<ll, ll>> dot = {xx, y};
            return dot;

        } else {
            if (b1 == 0) {
                pair<ll, ll> y, k2, l2, x;
                k2 = {-a2, b2};
                l2 = {-c2, b2};
                x = {-c1, a1};
                if (x.second != 0) {
                    ll gcd = __gcd(x.first, x.second);
                    x.first = x.first / gcd;
                    x.second = x.second / gcd;
                }
                y = sum_fractions(multiply_fractions(k2, x), l2);
                if (x.first == 0 && x.second != 0) {
                    x.second = 1;
                }
                if (y.first == 0 && y.second != 0) {
                    y.second = 1;
                }
                pair<pair<ll, ll>, pair<ll, ll>> dot = {x, y};
                return dot;
            } else {
                pair<ll, ll> y, k1, l1, x;
                k1 = {-a1, b1};
                l1 = {-c1, b1};
                x = {-c2, a2};
                if (x.second != 0) {
                    ll gcd = __gcd(x.first, x.second);
                    x.first = x.first / gcd;
                    x.second = x.second / gcd;
                }
                y = sum_fractions(multiply_fractions(k1, x), l1);
                if (x.first == 0 && x.second != 0) {
                    x.second = 1;
                }
                if (y.first == 0 && y.second != 0) {
                    y.second = 1;
                }
                pair<pair<ll, ll>, pair<ll, ll>> dot = {x, y};
                return dot;
            }
        }
    }
}

struct equ {
    ll a, b, c;

    equ(ll aa, ll bb, ll cc) {
        a = aa;
        b = bb;
        c = cc;
    }

    bool operator<(const equ &other) const {
        if (a < other.a)
            return true;
        if (a == other.a && b < other.b)
            return true;
        return (a == other.a && b == other.b && c < other.c);
    }
};

int main() {
    ll n;
    cin >> n;
    set<equ> equations;
    for (int i = 0, a, b, c, gcd; i < n; ++i) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0) {
            continue;
        }
        gcd = __gcd(__gcd(a, b), c);
        if (gcd != 0) {
            a = a / gcd;
            b = b / gcd;
            c = c / gcd;
        }
        if (a < 0) {
            a *= -1;
            b *= -1;
            c *= -1;
        } else if (a == 0 && b < 0) {
            b *= -1;
            c *= -1;
        }
        equations.emplace(a, b, c);
    }
    unordered_map<string, ll> dot_holder;
    unordered_map<string, ll> parallel_holder;
    string sdot;
    auto it = equations.begin();
    for (auto i = it; i != equations.end(); ++i) {
        for (auto j = ++it; j != equations.end(); ++j) {
            pair<pair<ll, ll>, pair<ll, ll>> dot = fraction::cross(i->a, i->b, i->c, j->a, j->b, j->c);
            if (dot.first.second != 0 && dot.second.second != 0) { // in case of intersection
                sdot = to_string(dot.first.first) + to_string(dot.first.second) + to_string(dot.second.first) +
                       to_string(dot.second.second);
                if (dot_holder.find(sdot) != dot_holder.end()) { // elem is in map
                    dot_holder.find(sdot)->second++;
                } else {//in case of parallelism
                    dot_holder.insert({sdot, 1});
                }
            } else {
                ll a1, a2, b1, b2;
                a1 = i->a;
                b1 = i->b;
                a2 = j->a;
                b2 = j->b;
                ll gcd = __gcd(i->a, i->b);
                if (gcd) {
                    a1 = a1 / gcd;
                    b1 = b1 / gcd;
                }
                gcd = __gcd(j->a, j->b);
                if (gcd) {
                    a2 = a2 / gcd;
                    b2 = b2 / gcd;
                }
                if (a1 == a2 && b1 == b2) {
                    string s = to_string(a1) + to_string(b1);
                    if (parallel_holder.find(s) != parallel_holder.end()) {
                        parallel_holder.find(s)->second++;
                    } else {
                        parallel_holder.insert({s, 2});
                    }
                }
            }
        }
    }
    ll m = 0;
    vector<ll> lambd;
    vector<ll> nu;
    for (auto &el: dot_holder) { // m = number of dots with intersection >= 3 lines
        if (el.second > 2) {
            el.second = 0.5 + sqrt(1 + 8 * el.second) /
                              2; //formula to calculate num of lines in intersection (from arithmetic progression)
            lambd.push_back(el.second);
            m++;
        }
    }
    ll p = parallel_holder.size();
    for (auto el: parallel_holder) {
        if (el.second > 2) {
            el.second = 0.5 + sqrt(1 + 8 * el.second) / 2;
        }
        nu.push_back(el.second);
    }
    ll nn;
    nn = equations.size();
    ll r;
    ll res1, res2 = 0, res3 = 0;
    res1 = (nn - 1) * nn / 2;
    for (int i = 0; i < m; ++i) {
        res2 += (lambd[i] - 2) * (lambd[i] - 1) / 2;
    }
    for (int i = 0; i < p; ++i) {
        res3 += (nu[i] - 1) * nu[i] / 2;
    }
    r = 1 + nn + res1 - res2 - res3;
    cout << r;
    return 0;
}

/*
Tests:
3
1 0 0
0 1 0
-1 -1 1

11
1 2 3
2 4 6
3 9 27
-3 9 27
-3 -9 -27
0 0 1
0 0 9
0 0 -9
1 1 1
1 -1 1
1 0 1



6
1 1 1
-1 -1 -1
1 -1 1
-1 1 -1
-1 1 1
1 1 -1

 7
 1 2 3
 2 4 5
 1 -2 5
 -2 -4 5
 2 -4 15
 7 13 5
 14 26 100

6
-1 2 3
-2 4 7
1 -2 3
2 -4 10
-1 -2 1
-2 -4 11

-1 2
 1 -2
-1 -2


 8
 5 6 -15
 5 2 -15
 5 3 -15
 5 -5 -15
 2 3 10
 2 1 10
 2 4 10
 2 6 10




 5
7 13 5
14 26 100
-1 2 3
-2 4 7
2 -4 10

 20
 20 45 -30
 20 1 -30
 20 -3 -30
 20 0 -30
 20 15 -30
 0 4 5
 0 4 15
 0 4 -45
 7 5 150
 7 5 250
 7 5 -100
 150 250 50000
 150 1 50000
 150 156 50000
 150 2880 50000
 150 22 50000
 10 250 50000
 1 3 5
 1 2 5
 1 5 5

*/
