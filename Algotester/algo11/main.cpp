#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    if (n<k || n>3*k){
        cout << "Impossible";
        return 0;
    }
    int x = n/k;
    int y = n%k;
    for (int i = 0; i < k; ++i) {
        if (y!=0){
            cout << x+1 << ' ';
            y--;
            continue;
        }
        cout <<x << ' ';
    }
    return 0;
}
