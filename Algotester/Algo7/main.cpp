#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m = 0, x=1, z;
    string s, sf;

    cin >> n;
    cin >> s;

    n = sqrt(n);
    int arr[n][n];
    for (int i = 0; i <= 2*n-1; ++i) { //row
        z = m;
        for (int j = 0; j < x; ++j) { //column
            if (z<s.length()) {
                sf += s[z];
                s[z] = '-';
                z += n-1;
            } else{
                break;
            }
        }
        x++;

        if (s[m + 1] != '-') {
            m++;
        } else{
            m = s.find_first_not_of('-');
        }

    }
cout << sf;


    return 0;
}
//16
//abdgcehkfilnjmop

//9
//124357689