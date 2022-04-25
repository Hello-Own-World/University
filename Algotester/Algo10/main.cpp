#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int r, R;
    double s1, s2;
    cin >> R;
    cin >> r;

    s1 = R+r+ sqrt(3)* r;
    s2 = R* sqrt(3);

    if (s1<=s2){
        cout << "safe";
    } else{
        cout << "rumpled";
    }

    return 0;
}
