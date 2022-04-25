#include <iostream>
#include <vector>

using namespace std;

int sum = 0;

void dfs(int v, vector<bool> &v_used, vector<vector<int>> &adj_lst, vector<int> &val) {
    v_used[v - 1] = true;
    sum += val[v - 1];
    for (auto el: adj_lst[v - 1]) {
        if (!v_used[el - 1]) {
            dfs(el, v_used, adj_lst, val);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<int> val;
    vector<vector<int>> vert(n);
    vector<bool> v_used(n, false);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        val.push_back(a - b);
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        vert[a - 1].push_back(b);
        vert[b - 1].push_back(a);
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (!v_used[i]) {
            sum = 0;
            dfs(i + 1, v_used, vert, val);
            if (sum>=0){
                ans.push_back(sum);
            }
        }
    }
    sum =0;
    for (auto el:ans) {
        sum += el;
    }
    cout << sum;


    return 0;
}
/*
3 1
10 3
2 10
7 6
1 2
 */