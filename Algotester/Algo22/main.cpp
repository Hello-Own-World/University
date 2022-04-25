#include <iostream>
#include <cmath>
using namespace std;


int main() {
    int n, m , s, z;
    cin >> n >> m >> s;
    int arr[n];
    if (n%2==0){
        z = (n/2);
        arr[z] = m;
    } else{
        z = static_cast<int>(round(n/2));
        arr[z] = m;
    }
    if (m*(n-(z+1)) <= s-m){
        s-=m;
        for (int i = z+1; i < n; ++i) {
            arr[i] = m;
            s-=m;
        }
        if (s>0){
            arr[n-1]+=s;
        }
        for (int i = 0; i < z; ++i) {
            arr[i] = 0;
        }

    } else{
        cout << "-1";
        return 0;
    }

    for (int el:arr) {
        cout << el << ' ';
    }

    return 0;
}
