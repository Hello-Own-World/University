#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;

    int len = n.length();
    char lst_min = '9';
    char sorted_lst[len]; // change later
    int counter = 0, lst_pointer;
    char min_int[len], max_int[len];


    for (int j = 0; j < len; ++j) { //sort str by num
        for (int i = 0; i < len; i++) {
            if (n[i] != '-') {
                if (n[i] <= lst_min) {

                    lst_min = n[i];
                    lst_pointer = i;
                }
            }
        }
        sorted_lst[counter] = lst_min;
        counter++;
        lst_min = '9';
        n[lst_pointer] = '-';
    }

    for (int i = 0; i<len; i++){    // get max lst
        max_int[i] = sorted_lst[len - 1 - i];
    }

    for (int j = 0; j<len; j++) {   //make minimum int
        for (int i = 0; i < len; i++) {
            if (sorted_lst[i] != '-') {
                if (sorted_lst[i] != '0') {
                    min_int[j] = sorted_lst[i];
                    sorted_lst[i] = '-';
                    break;
                } else {
                    if (j != 0) {
                        min_int[j] = '0';
                        sorted_lst[i] = '-';
                        break;
                    }

                }

            }
        }
    }


    for (int i = 0; i<len; i++){    // print min lst
        cout << min_int[i];
    }
    cout << " ";
    for (int i = 0; i<len; i++){    // print max lst
        cout << max_int[i];
    }
    return 0;
}
