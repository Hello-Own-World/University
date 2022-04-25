#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    double a;
    cin >> n;
    vector<double> arr;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        arr.push_back(a);
    }
   std::sort(arr.begin(), arr.end());
    a = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        a = (arr[i]+a)/2;
    }

   cout << std::setprecision(7) << a;
    return 0;
}
