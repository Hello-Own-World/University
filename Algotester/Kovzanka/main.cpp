#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

using namespace std;
using ll = long long;

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

    pair<pair<ll, ll>, pair<ll, ll>>
    cross(ll a1, ll b1, pair<ll, ll> c1, ll a2, ll b2, pair<ll, ll> c2) {
        if (b1 != 0 && b2 != 0) {
            pair<ll, ll> k1, k2, l1, l2, xx, y;
            k1 = {-a1, b1};
            k2 = {-a2, b2};
            c1.second = c1.second * (-1);
            l1 = divide_fractions(c1, {b1, 1});
            c2.second = c2.second * (-1);
            l2 = divide_fractions(c2, {b2, 1});
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
                c2.second = c2.second * (-1);
                l2 = divide_fractions(c2, {b2, 1});
                c1.second = c1.second * (-1);
                x = divide_fractions(c1, {a1, 1});
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
                c1.second = c1.second * (-1);
                l1 = divide_fractions(c1, {b1, 1});
                c2.second = c2.second * (-1);
                x = divide_fractions(c2, {a2, 1});
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
    ll a, b;
    pair<ll, ll> c;

    equ(ll aa, ll bb, pair<ll, ll> cc) {
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
    int n;
    cin >> n;
    set<equ> equations;
    set<pair<int, int>> dots;
    pair<int, int> temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp.first >> temp.second;
        dots.insert(temp);
    }
    if (dots.size() <= 2) {
        cout << "Bad lady-killer.";
        return 0;
    }
    pair<int, int> m0, ab, c;
    auto it = dots.begin();
    int a, b, gcd;
    for (auto i = it; i != dots.end(); ++i) {
        for (auto j = ++it; j != dots.end(); ++j) {
            m0 = {(i->first + j->first), (i->second + j->second)};
            ab = {j->first - i->first, j->second - i->second};
            a = -ab.first;
            b = -ab.second;
            c = {ab.first * m0.first + ab.second * m0.second, 2};
            if (a == 0 && b == 0) {
                continue;
            }
            gcd = __gcd(__gcd(a, b), c.first);
            if (gcd != 0) {
                a = a / gcd;
                b = b / gcd;
                c.first = c.first / gcd;
            }
            if (a < 0) { // hope it will make duplicate look the same
                a *= -1;
                b *= -1;
                c.second *= -1;
            } else if (a == 0 && b < 0) {
                b *= -1;
                c.second *= -1;
            }
            equations.emplace(a, b, c);
        }
    }
    unordered_map<string, ll> dot_holder;
    string sdot;
    auto it1 = equations.begin();
    for (auto i = it1; i != equations.end(); ++i) {
        for (auto j = ++it1; j != equations.end(); ++j) {
            pair<pair<ll, ll>, pair<ll, ll>> dot = fraction::cross(i->a, i->b, i->c, j->a, j->b, j->c);
            if (dot.first.second != 0 && dot.second.second != 0) { // in case of intersection
                sdot = to_string(dot.first.first) + to_string(dot.first.second) + to_string(dot.second.first) +
                       to_string(dot.second.second);
                if (dot_holder.find(sdot) != dot_holder.end()) { // elem is in map
                    continue;
                } else {
                    dot_holder.insert({sdot, 1});
                }
            }
        }
        if (dot_holder.size() == 1) {
            cout << "True story!";
        } else {
            cout << "Bad lady-killer.";
        }
        return 0;
    }
}

/*
 5
 0 0
 1 1
 0 2
 -1 1
 0 1

 2
 1 1
 0 0

 */