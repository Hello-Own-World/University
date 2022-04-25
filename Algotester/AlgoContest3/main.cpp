#include <iostream>
using namespace std;

int find_char(string s1, string s2){
    long int size = s1.length()-1;
    for (int i = 0; i < size; ++i) {
        if(s1[i]!=s2[i]){
            return i;
        }
    }
}

bool find_ne(string s1, string s2, int ind){
    bool f1 = false, f2 = false;
    for (int i = 0; i <= ind-1; i++) {
        if(s1[i]!=s1[ind]){
            f1 = true;
            break;
        }
    }

    for (int i = s1.length()-1; i >= ind+1; i--) {
        if(s1[i]!=s1[ind]){
            f2 = true;
            break;
        }
    }

    if (f1 && f2){
        return true;
    }
    return false;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length()<s2.length()){
        cout << "no";
        return 0;
    }
    int i = 0;
    while (s1[i]!='\0'){
        int ind = find_char(s1,s2);
        if(s1==s2){
            cout << "yes";
            return 0;
        }
        if (find_ne(s1,s2,ind)){
            s1.erase(ind,1);
        } else{
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
    return 0;
}