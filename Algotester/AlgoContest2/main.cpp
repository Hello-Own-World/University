#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> decToBinary(int n)
{
    vector<int> vb;
    int i = 0;
    while (n > 0) {
        vb.push_back(n % 2);
        n = n / 2;
        i++;
    }
    std::reverse(vb.begin(), vb.end());
    return vb;
}


int main() {
    int l, r;
    cin >> l;
    cin >> r;
    string str, lb, rb;
    vector<int> arr = decToBinary(l);
    for (int i = 0; i < arr.size(); ++i) {
        str += arr[i]+'0';
    }
    lb = str;
    string s1 ;
    str = "";
    vector<int> arr2 = decToBinary(r+l);
    for (int i = 0; i < arr2.size(); ++i) {
        str += arr2[i]+'0';
    }

    //cout <<str;




    string s = "11";
    int counter = 0;
    cout << s << '\n';
    s1 = s;
    while (true){
    //for (int i = 0; i < 10; ++i) {

        if (s1!=s){
            if(stoi(s)<= stoi(str)){
                cout << s << '\n';
                counter ++;
            } else{
                break;
            }
        }

        if (s == string(s.length(), '1')){
            s = "1"+string(s.length()-1, '0')+'1';
        }
        for (int i = s.length()-1; i > 0; i--) {
            if (s1!=s){
                if(stoi(s) <= stoi(str)){
                    cout << s << '\n';
                    counter++;
                } else{
                    break;
                }
            }
            s1 = s;
            if (s[i] =='0'){
                s[i] = '1';
                for (int j = s.length()-1; j > i; j--) {
                    s[j]='0';
                }

            }
        }



    }


cout << counter;
    return 0;
}
