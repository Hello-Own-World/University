#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i<n+1; i++){
        if(i%2 == 0){
            cout << "0";
        }
        else{
            cout << "1";
        }
    }
    return 0;
}
