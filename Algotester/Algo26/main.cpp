#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n, m;
    string s;
    cin >> n >> m;

    vector<vector<char>> arr1(n, vector<char>(m)), arr2(n, vector<char>(m));
    vector<char> first_occ = {'0'};

    for (int i = 0; i < n; ++i) {
        cin >> s;
        for (int j = 0; j < m; ++j) {
            arr1[i][j] = s[j];
            arr2[i][j] = s[j];
        }
    }

    std::vector<char>::iterator it;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            it = find(first_occ.begin(), first_occ.end(), arr1[i][j]);
            if (it != first_occ.end()){

                for (int k = 0; k < m; ++k) {
                    if (arr2[i][k]==arr1[i][j]){
                        arr2[i][k] = '-';
                    }
                }

            } else{
                first_occ.push_back(arr1[i][j]);
            }
        }
        first_occ.clear();
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            it = find(first_occ.begin(), first_occ.end(), arr1[j][i]);
            if (it != first_occ.end()){

                for (int k = 0; k < n; ++k) {
                    if (arr2[k][i]==arr1[j][i]){
                        arr2[k][i] = '-';
                    }
                }

            } else{
                first_occ.push_back(arr1[j][i]);
            }
        }

        first_occ.clear();
    }


//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < m; ++j) {
//            cout << arr1[i][j];
//        }
//        cout << '\n';
//    }
//
//    cout << '\n';

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr2[i][j]!='-'){
                cout << arr2[i][j];
            }
        }
//       cout << '\n';
    }

    return 0;
}
