#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int inf = 1e9 + 20;

void shortestPath(vector<vector<pair<int, int>>> &adj, int V, int src, vector<int> &dist, int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, src));
    dist[src] = start;//starting point
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto x: adj[u]) {
            int v = x.first;
            int weight = x.second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n * n);
    int start_v;
    for (int i = 0; i < n; ++i) { // заповнення списку суміжності графа н*н елементів, послідовно з 0 по н-1
        int temp;
        for (int j = 0; j < n; ++j) {
            cin >> temp;
            if (i == 0 && j == 0) {
                start_v = temp;
            }
            if (j < n - 1) {
                graph[i * n + j + 1].push_back({i * n + j, temp});
            }
            if (j > 0) {
                graph[i * n + j - 1].push_back({i * n + j, temp});
            }
            if (i < n - 1) {
                graph[i * n + j + n].push_back({i * n + j, temp});
            }
            if (i > 0) {
                graph[i * n + j - n].push_back({i * n + j, temp});
            }
        }
    }

    vector<int> dist(n * n, inf);
    shortestPath(graph, n * n, 0, dist, start_v);

    int counter = 0;
    for (auto el: dist) {
        if (el <= m) {
            counter++;
        }
    }
    cout << counter;

    return 0;
}
/*
5 37
9 6 6 7 1
9 9 3 5 3
10 1 9 7 9
3 1 6 9 9
5 6 9 1 9

2 2
1 1
1 1
 */
