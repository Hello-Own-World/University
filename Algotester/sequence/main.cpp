#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;


ull nfib(int n, vector<ull> &arr) {
    arr.push_back(0);
    arr.push_back(1);
    arr.push_back(1);
    ull prev = 1, lst = 1, temp;

    if (n == 1) {
        return prev;
    }
    if (n == 2) {
        return lst;
    }

    for (int i = 0; i < n - 2; ++i) {
        temp = lst;
        lst = lst + prev;
        prev = temp;

        arr.push_back(lst);
    }
    return lst;
}

int main() {
    ull k;
    int n;
    vector<ull> arr;
    cin >> n >> k;
    if (k > nfib(n + 2, arr)) {
        cout << "Flowers";
        return 0;
    }

    for (int i = n + 2; i > 2; i--) {
        if (k <= arr[i - 2]) {
            cout << '4';
            k += arr[i - 3];
        } else {
            cout << '7';
            k -= arr[i - 2];
        }
    }

    return 0;
}
