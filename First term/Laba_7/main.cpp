#include <iostream>

using namespace std;

int min1(int k, ...){        // min1 func for int
    int *p = &k;
    int last_min = *(p+2);
    for (int i = 1; i<=k; i++){
        if (*(p+2*i) < last_min){
            last_min = *(p+2*i);
        }
    }
    return last_min;
}

double min1(double k, ...){     // min1 func for double
    double *p = &k;
    double last_min = *(p+1);
    for (int i = 1; i<=k; i++){
        if (*(p+i) < last_min){
            last_min = *(p+i);
        }
    }
    return last_min;
}


int main() {

    cout << "Min values for integers:";
    cout << '\n' << min1(1, 0);
    cout << '\n' << min1(5, 0, -21, 0, -4, -31);
    cout << '\n' << min1(10, 9, 8, 7, 6, 5, 4, 3, -22, 1, 0);
    cout << '\n' << min1(12, 1, 41, 23, 1, 8, 36, 2, 89, 0, 74, 0, 12);
    cout << "\nMin values for doubles:";
    cout << '\n' << min1(5.0, 0.23, 1.5, 2.0, 0.1, -5.023);
    cout << '\n' << min1(10.0, 1.0, 2.0, 3.0, 4.0, 5.0, -6.0, 7.0, 8.0, 9.0, 10.0);
    cout << '\n' << min1(12.0, 754, 1, -62.03, 0.01, 0.32, 25, 0.8, -0.1, 99.1, 89);

    return 0;
}
