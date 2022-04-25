#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, s = 0, temp, size;
    cin >> n;
    int arr[n];
    vector<int> sum;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] < arr[i - 1] && i != 0) {
            cout << "No";
            return 0;
        }
    }

    s += arr[0];
    for (int i = 1; i < n; ++i) {
        temp = arr[i];
        if (s < temp) {
            s += temp;
            size = sum.size();
            for (int j = 0; j < size; ++j) {
                if (sum[j] + temp <= arr[n - 1]) {
                    sum.push_back(sum[j] + temp);
                }
            }
            for (int j = 0; j < i; ++j) {
                sum.push_back(temp + arr[j]);
            }

        } else {
            s += temp;
            if (find(sum.begin(), sum.end(), temp) != sum.end()) {
                cout << "No";
                return 0;
            }
            size = sum.size();
            for (int j = 0; j < size; ++j) {
                if (sum[j] + temp <= arr[n - 1]) {
                    sum.push_back(sum[j] + temp);
                }
            }
        }
    }
    cout << "Yes";


    return 0;
}

