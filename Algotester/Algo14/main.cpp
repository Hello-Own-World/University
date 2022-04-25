#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ans {
    double x = 0.123;
    double y = 0.123;
};

ans divide(double x) {

    int xi = static_cast<int>(x);
    double res = x - xi;
    ans answ;
    if (res != 0.5) {
        if (x * 1 / 2 >= 0) {
            answ.x = x * 1 / 2;
        }
        if (x - 0.5 >= 0) {
            answ.y = x - 0.5;
        }
        return answ;
    }
    if (x - 0.5 >= 0) {
        answ.y = x - 0.5;
    }
    return answ;
}

int main() {
    int n, m;
    cin >> n;
    cin >> m;

    vector<double> arr1;
    vector<double> arr2;

    arr1.push_back(n);
    double x, y;
    ans answ;
    bool flag = false;
    int ar_sz;
    for (int i = 0; i < m; ++i) {
        flag = !flag;
        if (flag) {
            ar_sz = arr1.size();

            arr2.clear();

        } else {
            ar_sz = arr2.size();


            arr1.clear();
        }

        for (int j = 0; j < ar_sz; ++j) { //flag
            x = 0.11;
            y = 0.11;

            if (flag) {
                answ = divide(arr1[j]);
            } else {
                answ = divide(arr2[j]);
            }


            if (answ.x != 0.123) {
                x = answ.x;
            }
            if (answ.y != 0.123) {
                y = answ.y;
            }


            if (flag) {
                if (x != 0.11) {
                    if (std::find(arr2.begin(), arr2.end(), x) == arr2.end()) {
                        arr2.push_back(x);
                    }
                }
                if (y != 0.11) {
                    if (std::find(arr2.begin(), arr2.end(), y) == arr2.end()) {
                        arr2.push_back(y);
                    }
                }

            } else {
                if (x != 0.11) {
                    if (std::find(arr1.begin(), arr1.end(), x) == arr1.end()) {
                        arr1.push_back(x);
                    }
                }
                if (y != 0.11) {
                    if (std::find(arr1.begin(), arr1.end(), y) == arr1.end()) {
                        arr1.push_back(y);
                    }
                }


            }
        }
    }

    if (flag) {
        cout << arr2.size() << '\n';
        std::sort(arr2.begin(), arr2.end());


        for (int i = 0; i < arr2.size(); ++i) {

            printf("%.1lf ", arr2[i]);
        }

    } else {
        cout << arr1.size() << '\n';
        std::sort(arr1.begin(), arr1.end());

        for (int i = 0; i < arr1.size(); ++i) {

            printf("%.1lf ", arr1[i]);
        }

    }


    return 0;
}
