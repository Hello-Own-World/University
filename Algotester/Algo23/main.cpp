#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    int min_max=9999, local_min_max;
    for (int i = 0; i < m; ++i) {
        local_min_max = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j][i] >local_min_max){
                local_min_max = arr[j][i];
            }
        }
        if (local_min_max < min_max){
            min_max = local_min_max;
        }
    }
    cout << min_max;

 return 0;
}
