#include <iostream>
using namespace std;

int main() {

    int stud, types, x, maxsum = 0;

    cin >> stud;
    cin >> types;

    int arr[types];
    for (int i =0 ;i < types; i++){
        arr[i] = 0;
    }
    for (int i = 0; i<stud; i++) {
        for (int j = 0; j < types; j++) {
            cin >> x;
            if (arr[j] < x) {
                arr[j] = x;
            }
        }
    }
    for (int i = 0; i < types; ++i) {
        maxsum+=arr[i];
    }
    cout << maxsum;

    return 0;
}
