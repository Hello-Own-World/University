#include <iostream>
using namespace std;

int main() {
    int n, x, max=0, min=1000000001;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x>max){
            max = x;
        }
        if (x<min){
            min = x;
        }
    }
    cout << max-min;

    return 0;
}
