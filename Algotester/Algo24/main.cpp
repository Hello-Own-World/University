#include <iostream>
using namespace std;

int main() {
    long int n, m, k, sum=0, counter=0;
    cin >> n >> m >> k;
    long int arr[m];

    cin >> arr[0];
    sum += arr[0];

    if (m==1){
        cout << n-1;
        return 0;
    }


    for (int i = 1; i < m; ++i) {
        cin >> arr[i];
        if (sum+arr[i]<=k){
            sum += arr[i];

            if (i==m-1){
                counter++;
            }
        } else{
            counter++;
            sum=0;
            sum += arr[i];

            if (i==m-1){
                counter++;
            }
        }
    }
    if (counter > n){
        cout << "-1";
        return 0;
    }
    cout << n-counter;

    return 0;
}
