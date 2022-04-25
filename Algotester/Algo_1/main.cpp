#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double find_side(int x1, int y1, int x2, int y2){
    double side = sqrt(pow(x1-x2, 2)+pow(y1-y2,2));
    return side;
}


int main() {
    int arr[6];
    int k;
    char ch;
    for (int i = 0; i<6; i++){
        cin >> arr[i];
    }
    cin >> k;

    for (int i = 0; i<k; i++){
        cin >> ch;
    }

    double side1 = find_side(arr[0], arr[1],arr[2],arr[3]);
    double side2 = find_side(arr[0], arr[1],arr[4],arr[5]);
    double side3 = find_side(arr[2], arr[3],arr[4],arr[5]);

    double hp = (side1 + side2 + side3)/2;
    double area = sqrt(hp*(hp-side1)*(hp-side2)*(hp-side3));

    double fin = area/(pow(2, k));

    cout << std::setprecision(9) << fin << '\n';

    return 0;
}
