#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
using ll = long long;

pair<ll, ll> p0; // global because needs to be used in compare function

pair<ll, ll> nextToTop(stack<pair<ll, ll>> s) { // find next to top in stack
    pair<ll, ll> p = s.top();
    s.pop();
    pair<ll, ll> res = s.top();
    s.push(p);
    return res;
}

ll dist_squre(pair<ll, ll> &p1, pair<ll, ll> &p2) {
    return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
}


ll orientation(pair<ll, ll> p, pair<ll, ll> q, pair<ll, ll> r) {
    ll val = (q.second - p.second) * (r.first - q.first) - //
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  // collinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

ll compare(pair<ll, ll> &p1, pair<ll, ll> &p2) {
    ll o = orientation(p0, p1, p2);
    if (!o) { // if collinear
        return (dist_squre(p0, p2) >= dist_squre(p0, p1)) ? -1 : 1;
    }
    return (o == 2) ? -1 : 1;
}

void convex_hull(vector<pair<ll, ll>> &dots, ll n, vector<pair<ll, ll>> &contour) {
    //first step find lowest y coordinate, if there is several sort by smallest x
    ll ymin = dots[0].second, xmin = dots[0].first, ind = 0;
    for (int i = 0; i < n; ++i) {
        if (dots[i].second < ymin || ymin == dots[i].second && dots[i].first < xmin) {
            ymin = dots[i].second;
            xmin = dots[i].first;
            ind = i;
        }
    }
    //set the lowest dot first
    swap(dots[0], dots[ind]);

    p0 = dots[0];
    qsort(&dots[1], n - 1, sizeof(pair<ll, ll>), reinterpret_cast<int (*)(const void *, const void *)>(compare));

    ll m = 1;
    for (int i = 1; i < n; ++i) {
        while (i < n - 1 &&
               orientation(p0, dots[i], dots[i + 1]) == 0) { // remove all elements while angle is same compared to p0
            i++;
        }
        dots[m] = dots[i];
        m++;
    }

    if (m < 3) return; // no contour

    stack<pair<ll, ll>> s; // push first 3 elements
    s.push(dots[0]);
    s.push(dots[1]);
    s.push(dots[2]);

    for (int i = 3; i < m; ++i) {
        while (s.size() > 1 && orientation(nextToTop(s), s.top(), dots[i]) != 2) {
            s.pop();
        }
        s.push(dots[i]);
    }
    while (!s.empty()) {
        pair<ll, ll> p = s.top();
        contour.push_back(p);
        s.pop();
    }
}

int main() {
    ll n, a, b;
    cin >> n;
    vector<pair<ll, ll>> dots;
    vector<pair<ll, ll>> contour;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dots.emplace_back(a, b);
    }
    ll res = 0;
    ll d;
    pair<ll, ll> p1, p2;
    convex_hull(dots, n, contour);
    ll i1, i2, aa, bb;
    for (int i = 0; i < contour.size(); i++) { // calculate num of int/int coordinates
        i1 = i;
        i2 = i + 1;
        if (i == contour.size() - 1) {
            i1 = 0;
            i2 = i;
        }
        p1 = contour[i1];
        p2 = contour[i2];
//        minx = -p1.first;
//        miny = -p1.second;
//        p1.first -= minx;
//        p1.second -= miny;
//        p2.first -= minx;
//        p2.second -= miny;
        aa = abs(p1.first - p2.first);
        bb = abs(p1.second - p2.second);
        d = __gcd(aa, bb)+1;
        res += d;
    }
    cout << res-contour.size();

    return 0;
}

/*
3
 0 0
 2 0
 0 2

 4
 0 0
 2 0
 0 2
 2 2


 13
-11 0
0 0
5 0
13 0
5 4
-2 4
-1 7
1 11
5 12
-2 12
0 -12
6 -12
11 -9
 */
