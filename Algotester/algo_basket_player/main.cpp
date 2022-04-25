#include <iostream>
using namespace std;

int main() {
    long int n,m,k, counter = 0;

    cin >> n;
    cin >> m;
    cin >> k;

    if (m>n && k != 1 ) {
        while (n < m) {
            n = n * k;
            counter++;
        }
        cout << counter;
    }else if (m<=n){
        cout << "0";
    }
    else{
        cout << "-1";
    }
    return 0;
}
