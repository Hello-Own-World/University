#include <iostream>
#include <vector>

using namespace std;


int arr[101][101];
int arr1[101][101];

void check_box(pair<int, int> xy, int a) {
    if (arr[xy.first + 1][xy.second]==1 || arr[xy.first - 1][xy.second]==1 || arr[xy.first][xy.second + 1]==1 ||
        arr[xy.first][xy.second - 1]==1) {
        arr[xy.first][xy.second] = 1;
    }
}
void check_box(pair<int, int> xy) {
    if (arr1[xy.first + 1][xy.second]==1 || arr1[xy.first - 1][xy.second]==1 || arr1[xy.first][xy.second + 1]==1 ||
        arr1[xy.first][xy.second - 1]==1) {
        arr1[xy.first][xy.second] = 1;
    }
}


int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<int, int>> to_check;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 0) {
                to_check.emplace_back(i, j);
            }
        }
    }

    for (pair<int,int> el: to_check) {
        check_box(el, m, arr);

    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << ' ' << arr[i][j] << ' ';
        }
        cout << '\n';
    }


    return 0;
}
/*
3 4 1
0 1 0 0
1 0 0 0
0 0 0 1
 */