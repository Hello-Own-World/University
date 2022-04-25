#include <iostream>
using namespace std;

int main() {
    string s, x, y;
    int n, j, i, k=0;
    cin >> s;
    cin >> n;
    for (int l = 0; l < n; ++l) {
        cin >> x;
        y+=x;
    }

    j = 0;
    while (true){
        i = y.find(s[j]);
        if (i == -1){
            break;
        }
        y[i] = '-';
        j++;
        if (j>=s.size()){
            k+=1;
            j=0;
        }
    }
    cout << k;




    return 0;
}
