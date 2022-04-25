//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool check_palindrome(string s){
//    string s1;
//
//    for (char i : s) {
//        if (i!='-'){
//            s1+=i;
//        }
//    }
//
//    if (s1.length()==1){
//        return true;
//    }
//    double med = round((s.length()+1)/2);
//    for (int i = 0; i < med; ++i) {
//        if (s[i] != s[s.length()-i-1]){
//            return false;
//        }
//    }
//    return true;
//}
//
//int main() {
//    int n, count = 0;
//    string s;
//    cin >> n;
//    cin >> s;
//
//    for (int i = n; i > 0; i--) {
//        for (int j = 0; j < n-i+1; ++j) {
//            if(check_palindrome(s)){
//
//                if (j == n-i-1){
//                    cout << "-1";
//                    return 0;
//                }
//                break;
//            }
//
//
//            //s.erase(j,i);
//            for (int k = j; k < i; ++k) {
//                s[j] = '-';
//            }
//
//
//            count++;
//            if (s == string(5, '-')){
//                cout << count;
//                return 0;
//            }
//        }
//    }
//
//    return 0;
//}


#include <iostream>
#include <cmath>
using namespace std;

bool check_palindrome(string s){
    if (s.length()==1){
        return true;
    }
    double med = round((s.length()+1)/2);
    for (int i = 0; i < med; ++i) {
        if (s[i] != s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}

int main() {
    int n, count = 0;
    string s;
    cin >> n;
    cin >> s;
    //cout << check_palindrome(s);
    for (int i = n; i > 0; i--) {
        for (int j = 0; j < n-i+1; ++j) {
            if(check_palindrome(s.substr(j, i))){

                if (j == n-i-1){
                    cout << "-1";
                    return 0;
                }
                break;
            }

            s.erase(j,i);
            count++;
            if (s == ""){
                cout << count;
                return 0;
            }
        }
    }






    return 0;
}


