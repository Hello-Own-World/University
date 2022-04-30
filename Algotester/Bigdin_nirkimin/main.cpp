#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;

int orient(pair<int,int> p, pair<int,int> q, pair<int,int> r){
    int val = (q.second - p.second) * (r.first - q.first) -
              (q.first - p.first) * (r.second - q.second);

    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2;
}
void convex_hull(vector<pair<int,int>> &arr, int n, vector<pair<int,int>> &cont){
    if (n<3){
        return;
    }
    vector<pair<int,int>> hull;
    int l = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i].first<arr[l].first){
            l = i;
        }
    }
    int p = l, q;
    do {
        hull.push_back(arr[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; ++i) {
            if (orient(arr[p], arr[i], arr[q])==2){
                q = i;
            }
        }
        p = q;
    } while (p != l);
    for (auto & i : hull) {
        cont.emplace_back(i.first, i.second);
    }
}

int main() {
    int n, a, b, sum = 0;
    cin >> n;
    vector<pair<int, int>> dots;
    vector<pair<int, int>> contur;

    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        dots.emplace_back(a, b);
    }
    int res=0;
    int d, minx, miny;
    pair<int,int> p1, p2;
    convex_hull(dots, n, contur);
    for (int i = 0; i < n - 1; ++i) {
        p1 = contur[i];
        p2 = contur[i+1];
        minx = -p1.first;
        miny = -p1.second;
        p1.first -= minx;
        p1.second -= miny;
        p2.first -= minx;
        p2.second -= miny;
        d = __gcd(p2.first, p2.second);
        res += d+1;
    }
    cout << res;

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
 */
