#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int v, vector<bool> &v_used, vector<vector<int>> &adj_lst, const string &s, vector<char> &ans1, vector<int> &ans2) {
    v_used[v-1] = true;
    ans1.emplace_back(s[v-1]);
    ans2.emplace_back(v-1);
    for (auto el:adj_lst[v-1]) {
        if (!v_used[el-1]){
            dfs(el, v_used, adj_lst, s, ans1, ans2);
        }
    }
}


int main() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    vector<char> ans1;
    vector<int> ans2;
    vector<vector<int>> vert(s.length());
    vector<bool> v_visited(s.length(), false);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        vert[a-1].push_back(b);
        vert[b-1].push_back(a);
    }

    for (int i = 0; i < s.length(); ++i) {
        if (!v_visited[i]){
            dfs(i+1, v_visited, vert, s, ans1, ans2);
            std::sort(ans1.begin(), ans1.end());//remake
            std::sort(ans2.begin(), ans2.end());//remake

            for (int j = 0; j < ans1.size(); ++j) {
                s[ans2[j]]=ans1[j];
            }
            ans1.clear();
            ans2.clear();
        }
    }

    cout << s;



    return 0;
}


/*
dcaba
2
1 5
2 3
*/