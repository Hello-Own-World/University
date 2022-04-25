#include <iostream>
using namespace std;

bool find_sq(int n, char arr1[][10], int k, int x){ // x size of square
    int x1 = n+1-x;
    int counter = 0;

    for (int i = 0; i < x1; ++i) {     //move starting point
        for (int j = 0; j < x1; ++j) { //same
            for (int l = i; l < x+i; ++l) {
                for (int m = j; m < x+j; ++m) {
                    if (arr1[l][m]=='1'){
                        counter++;
                    }
                    //cout<< arr1[l][m];
                }
                //cout << '\n';
                
            }
            if (counter <= k){
                //cout << "success";
                return true;
            }
            counter = 0;
            //cout << '\n';

        }
    }

    return false;
}

int get_square(int n, char arr1[][10], int k){
    int x = n;

    while (!find_sq(n, arr1, k, x)){
        x--;
    }
    cout << x;

}




int main() {
    int n, k;
    cin >> n;
    cin >> k;

    char arr[10][10];

    string s2;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            arr[i][j] = s[j];
        }
    }

    get_square(n, arr, k);



    return 0;
}

