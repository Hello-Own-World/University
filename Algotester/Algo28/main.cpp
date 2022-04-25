#include <iostream>

using namespace std;

int main() {
    int n, c4 = 0, c = 0;
    string s;
    cin >> n >> s;
    char lst = s[0];
    if (lst == '7') {
        c = 1;
    } else {
        c4++;
    }
    for (int i = 0; i < n; ++i) {
        if (s[i] != lst) {
            lst = s[i];
            if (lst == '4') {
                c4++;
            }
        }
    }
    cout << c4 - 1 + c;
    return 0;
}
