#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr1[n][k], arr2[n][k];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >>arr1[i][j];
            if (!i) {
                arr2[i][j] = arr1[i][j];
            } else{
                arr2[i][j] = 3700;
            }
        }
    }

    //go through one el (necessary cause it fills arr2)
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < k; ++j) {
//            arr2[i][j] = arr1[i][j] + arr2[i-1][0];
//        }
//    }


    for (int i = 1; i < k; ++i) { //k-1 times but with correction in k for better use
        for (int j = i; j <n ; ++j) {
            for (int l = 0; l < k; ++l) {
                arr2[j][l] = min(arr2[j][l], arr1[j][l] + arr2[j-i][i-1]);
            }
        }
    }




//
//    //go through sec el
//    for (int i = 2; i < n; i++) {//-1
//        for (int j = 0; j < k; ++j) {
//            arr2[i][j] = min(arr2[i][j], arr1[i][j] + arr2[i-2][1]);
//        }
//    }
//
//    for (int i = 3; i < n; i++) {//-1
//        for (int j = 0; j < k; ++j) {
//            arr2[i][j] = min(arr2[i][j], arr1[i][j] + arr2[i-3][2]);
//        }
//    }


//

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < k; ++j) {
//            cout << arr2[i][j] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << '\n';
    cout << *min_element(arr2[n-1],arr2[n-1]+k);
    return 0;
}
/*
5 3
5 10 15
2 10 15
5 5 5
20 20 1
20 1 1
 */
