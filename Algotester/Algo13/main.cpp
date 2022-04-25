#include <iostream>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1;
    cin >> s2;
    int i = 0;
    bool flag = true;

    while (s1[i]!='\0'){
        flag = true;
        s3 = s1.substr(i, s2.length());
        for (int j = 0; j < s2.length()-1; ++j) {
            if(s3[j]!='?'){
                if (s3[j]!=s2[j]){
                    flag = false;
                    break;
                }

            } else{
                if (j!=s2.length()-1){
                    continue;
                } else{
                    cout << "YES";
                    return 0;
                }
            }
        }
        if (flag){
            cout << "YES";
            return 0;
        }
        i++;

    }
    cout << "NO";
    return 0;
}
