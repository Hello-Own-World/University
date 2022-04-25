#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, ans, counter = 0, counter1 = 0;
    cin >> n;
    cin >> ans;
    if (ans%2 == 0){
        counter = 1;
    }
    for (int i = 0; i<n-1 ; i++) {
        cin >> ans;
        if (ans % 2 == 0) {
            if (counter != 1) {
                counter = 1;
                counter1 += 1;
            }
        }
        if (ans % 2 != 0) {
            if (counter != 0) {
                counter = 0;
                counter1 += 1;
            }

        }
    }
    cout << counter1;
    return 0;
}
