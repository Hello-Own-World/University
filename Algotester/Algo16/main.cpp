#include <iostream>
using namespace std;

int main() {
int n, max=0, dif;
cin>>n;
int arr[n];
for (int i = 0; i < n; ++i) {
    cin >> arr[i];
}
    for (int i = 1; i < n; ++i) {
        if (arr[i-1]>=arr[i]){
            dif = arr[i-1]-arr[i]+1;
            if (dif > max){
                max = dif;
            }
            arr[i]+=dif;
        }
    }
cout << max;
    return 0;
}