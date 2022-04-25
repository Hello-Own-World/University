#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int endr;
bool f2 = false;

class Node {
public:
    int value;
    bool visited = false;
    bool finished = false;//del.
    vector<Node *> sons{};

    explicit Node(int val) : value{val} {};

};

bool check(Node *node) {
    if (node->value == endr) {
        return true;
    }
    return false;
}

void find_cycle(Node *root, Node *prev, vector<int> &path) {
    if (f2) {
        return;
    }
    if (root->finished) {
        return;
    }
    if (root->visited) {
        endr = root->value;
//        path.push_back(root->value); ???
        f2 = true;
//        cout << "cycle found"<<root->value;
        return;
    }
    root->visited = true;
    for (auto el: root->sons) {
        if (el != prev) {//&& root->value != endr
            find_cycle(el, root, path);
        }
    }
    root->finished = true;
    if (f2) {
        path.push_back(root->value);
    }
}


int main() {
    int n, temp;
    cin >> n;
    vector<Node *> nodes;

    for (int i = 1; i <= n; ++i) {
        nodes.push_back(new Node(i));
    }

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        nodes[a-1]->sons.push_back(nodes[b-1]);
        nodes[b-1]->sons.push_back(nodes[a-1]);
    }
    vector<int> path;
    find_cycle(nodes[0], nullptr, path);


    while (path[path.size() - 1] != endr) {
        path.pop_back();
    }

    cout << path.size() << '\n';

    std::sort(path.begin(), path.end());
    for (auto el: path) {
        cout << el << ' ';
    }
    return 0;
}
/*
4
1 2
2 3
3 4
4 2



  5
4 9
9 11
11 12
12 7
7 9

5
4 9
9 11
11 12
12 7
7 4

 5
-10 0
0 1
1 -100
-100 1000
1000 0

10
3 4
3 8
8 10
4 6
6 13
-2 3
-2 7
7 0
0 15
15 7

10
3 4
3 8
8 10
4 6
6 13
-2 3
-2 7
7 0
0 15
15 -2

10
3 4
3 8
8 10
4 6
6 13
-2 3
-2 7
7 0
0 15
15 3


10
3 4
3 8
8 10
4 6
6 13
-2 3
-2 7
7 0
0 15
15 10

 10
3 4
3 8
8 10
4 6
6 13
-2 3
-2 7
7 0
0 15
15 6

 10
 2 3
 1 2
 1 6
 3 7
 7 8
 3 4
 4 5
 9 5
 10 9
 10 6

 */