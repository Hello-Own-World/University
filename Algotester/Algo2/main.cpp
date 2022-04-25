#include <iostream>
using namespace std;

int main() {
    string str;
    int x=0, y=0, x1, y1;

    getline(cin, str);
    cin >> x1;
    cin >> y1;

    {
        int i = 0;
        while (str[i]!='\0'){
            if (str[i] == 'R'){
                x++;
                i++;
            }
            else{
                y++;
                i++;
            }
        }
    }

    if (x1<=x && y1<=y){
        cout << "YES";
    } else{
        cout<< "NO";
    }



    return 0;
}
