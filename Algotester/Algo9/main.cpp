#include <iostream>
using namespace std;

int main() {
    string l, r, l2, r2;

    cin >> l;
    cin >> r;
    l2 = l;
    r2 = r;

    if (r.length()>l.length()){
        int n = r.length()-l.length();
        l = string(n, '-')+ l;
    }
    int rn, ln;

    for (int i = r.length()-1; i > -1; i--) {
        if (i!=0){
            r[i]='9';
            r2[i]='9';
        }
        for (int j = 0; j < 10; ++j) {
//            bool flag;
//            if (l[i-1]=='-' || i == 0){
//                flag = true;
//            } else if (l[i]!='-' && r[i]>l[i] ){
//                flag = false;
//            }
            if (r[i]=='1' && i==0){
                //flag = false;
                break;
            }
            if (r2[i]=='1' && i==0){
                //flag = false;
                break;
            }
            if (r2[i]!='0'){
                r2[i] = r2[i]-1;
            } else{
                break;
            }
            if (r[i]!='0' && r[i]>l[i]){
                r[i] = r[i]-1;
            } else{
                //break;
            }
            rn = stoi(r, nullptr);
            ln = stoi(l2, nullptr);
            if (rn < ln){
                r[i] = r[i]+1;
                //flag = false;
                break;
            }

        }
    }


    int x, y;
    x = stoi(r, nullptr);
    y = stoi(r2, nullptr);
    if (y > ln && y < rn){
        bool flag = true;
        while (flag){
            if (y/10 >= ln && y/10 <= rn){
                y = y/10;
            } else{
                cout << y;
                flag = false;
            }
        }
    } else{
        cout << x;

    }
    return 0;
}
