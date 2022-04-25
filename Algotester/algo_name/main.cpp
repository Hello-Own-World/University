#include <iostream>

using namespace std;

int main() {
    int n, n1, counter=0;
    string str, str1;
    cin >> str;
    cin >> str1;

    n = str.length();
    n1 = str1.length();

    for (int j = 0; j< n1; j++){
        for (int i = 0; i<n; i++){
            if (str[i] != '-') {
                if (str[i] == str1[j]) {
                    str[i] = '-';
                    counter++;
                    break;
                }
            }
        }
    }
    if (counter == n1){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

    return 0;
}
