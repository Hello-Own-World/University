#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int k, n, count = 0;
    cin >> k >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr+n);
    if (k<arr[0]){
        cout << '0';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        k-=arr[i];
        count++;
        if (k-arr[i+1]<0){
            cout << count;
            return 0;
        }
    }
    cout << count;



    return 0;
}
//0 4
//5 3 9 1