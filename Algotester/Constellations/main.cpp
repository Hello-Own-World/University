#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void dfs(int v, vector<bool> &v_used, vector<vector<int>> &adj_lst, int &sum) {
    v_used[v-1] = true; //in general, i can just pop them, then no need to find unvisited
    for (auto el:adj_lst[v-1]) {
        sum++;
        if (!v_used[el-1]){
            dfs(el, v_used, adj_lst, sum);
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_lst(n);
    vector<bool> v_used(n, false);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj_lst[a - 1].push_back(b);
        adj_lst[b - 1].push_back(a);
    }
    int sum=0;
    vector<int> ans;

    for (int i = 1; i <= n; ++i) {
        if (!v_used[i-1]){
            dfs(i, v_used, adj_lst, sum);
            ans.push_back(sum/2);
            sum=0;
        }
    }

//    dfs(6, v_used, adj_lst);
    std::sort(ans.begin(), ans.end());
    cout << ans.size()<<'\n';
    for (auto el:ans) {
        cout << el <<'\n';
    }

    return 0;
}
/*
6 5
1 2
2 3
4 5
2 1
3 1
 */