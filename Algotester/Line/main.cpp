#include <iostream>
#include <algorithm>

using namespace std;
typedef long long int ll;

pair<ll, ll> find_k(ll x1, ll y1, ll x2, ll y2) {
    pair<ll, ll> k;
    k.first = y2 - y1;
    k.second = x2 - x1;

    if (k.second != 0) {
        ll gcd = __gcd(k.first, k.second);
        if (gcd) {
            k.first = k.first / gcd;
            k.second = k.second / gcd;
        }
    }
    return k;
}

pair<ll, ll> find_l(ll x1, ll y1, ll x2, ll y2) {
    pair<ll, ll> l;
    l.first = x2 * y1 - x1 * y2;
    l.second = x2 - x1;

    if (l.second != 0) {
        ll gcd = __gcd(l.first, l.second);
        if (gcd) {
            l.first = l.first / gcd;
            l.second = l.second / gcd;
        }
    }
    return l;
}

pair<ll, ll> min_ratio(pair<ll, ll> l1, pair<ll, ll> l2) {
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

pair<ll, ll> sum_ratio(pair<ll, ll> l1, pair<ll, ll> l2) {
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

pair<ll, ll> divide_ratio(pair<ll, ll> l1, pair<ll, ll> l2) {
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

pair<ll, ll> multiply_ratio(pair<ll, ll> l1, pair<ll, ll> l2) {
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

string run(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3, ll x4, ll y4) {
    if (x1 != x2 && x3 != x4) {
        pair<ll, ll> k1, k2, l1, l2, xx, y;
        k1 = find_k(x1, y1, x2, y2);
        k2 = find_k(x3, y3, x4, y4);
        l1 = find_l(x1, y1, x2, y2);
        l2 = find_l(x3, y3, x4, y4);
        pair<pair<ll, ll>, pair<ll, ll>> x;
        x.first = min_ratio(l2, l1);
        x.second = min_ratio(k1, k2);
        xx = divide_ratio(x.first, x.second);

        if (k1.second || l1.second) {
            y = sum_ratio(multiply_ratio(k1, xx), l1);
        } else {
            y = sum_ratio(multiply_ratio(k2, xx), l2);
        }
        if (xx.second < 0) {
            xx.first *= -1;
            xx.second *= -1;
        }
        if (y.second < 0) {
            y.first *= -1;
            y.second *= -1;
        }

        return to_string(xx.first) + '/' + to_string(xx.second) + ' ' + to_string(y.first) + '/' + to_string(y.second);
    } else {
        if (x1 == x2) {
            pair<ll, ll> y, k2, l2;
            k2 = find_k(x3, y3, x4, y4);
            l2 = find_l(x3, y3, x4, y4);
            y = sum_ratio(multiply_ratio(k2, {x1, 1}), l2);
            return to_string(x1) + '/' + to_string(1) + ' ' + to_string(y.first) + '/' + to_string(y.second);
        } else {
            pair<ll, ll> y, k1, l1;
            k1 = find_k(x1, y1, x2, y2);
            l1 = find_l(x1, y1, x2, y2);
            y = sum_ratio(multiply_ratio(k1, {x3, 1}), l1);
            return to_string(x3) + '/' + to_string(1) + ' ' + to_string(y.first) + '/' + to_string(y.second);
        }
    }
}

int main() {
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    cout << run(x1, y1, x2, y2, x3, y3, x4, y4);
    return 0;
}
