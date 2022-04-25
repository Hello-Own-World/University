#include <iostream>
using namespace std;

int main() {
    int n, a, b, count = 0;
    string s;
    cin >> n >> a >> b;
    cin >> s;
    bool flag1= true, flag2 = true;

    if (b>a){
        while (flag1){
            if (s[b-7-1]!=0 && b-7>=0 && b-7>=a){
                b-=7;
                count++;
            } else{
                break;
            }
        }
    }
    else{
        while (flag2){
            if (s[b+7-1]!=0 && b+7<=n && b+7<=a){
                b+=7;
                count++;
            } else{
                break;
            }
        }
    }


    if (a>b){
        while (flag1){
            if (s[a-4-1]!=0 && a-4>=0 && a-4>=b){
                a-=4;
                count++;
            } else{
                break;
            }
        }
    }
    else{
        while (flag2){
            if (s[a+4-1]!=0 && a+4<=n && a+4<=b){
                a+=4;
                count++;
            } else{
                break;
            }
        }
    }
    if (a==b){
        cout << count;
    } else{
        cout << "-1";
    }

    return 0;
}
