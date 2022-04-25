#include <iostream>

using namespace std;

struct fraction{//дріб
    double num;    //чисельник
    double denom;  //знаменник
    double ans;
};
struct complex_fraction{
    double real_1, imag_1, real_2, imag_2, denom, real_ans, imag_ans;
};

double divide (fraction a){
    a.ans = a.num/a.denom;
    return a.ans;
};
complex_fraction divide (complex_fraction b){
    b.denom = b.real_2*b.real_2 + b.imag_2*b.imag_2;
    b.real_ans = ((b.real_1*b.real_2+b.imag_1*b.imag_2)/(b.denom));
    b.imag_ans = (b.real_2*b.imag_1-b.real_1*b.imag_2)/(b.denom);
    return b;
};

int main() {
    cout << "Do you want to divide integers or complex numbers?(0/1):"<<endl;
    int ans;
    cin >> ans;
    if (!ans){//int
        fraction a{};
        cout << "Enter value for numerator:"<<endl;
        cin >> a.num;
        cout << "Enter value for denominator:"<<endl;
        cin >> a.denom;
        cout << "Answer: \n" << divide(a)<<endl;


    }
    if (ans){//complex
        complex_fraction b{};
        cout << "Enter value of real part of 1st complex number:"<<endl;
        cin >> b.real_1;
        cout << "Enter value of imaginary part of 1st complex number:"<<endl;
        cin >> b.imag_1;
        cout << "Enter value of real part of 2st complex number:"<<endl;
        cin >> b.real_2;
        cout << "Enter value of imaginary part of 2st complex number:"<<endl;
        cin >> b.imag_2;
        b = divide(b);
        if (b.imag_ans>0) {
            cout << b.real_ans << " + " << b.imag_ans << "i" << endl;
        }
        if (b.imag_ans<0) {
            cout << b.real_ans << " - " << -1 * b.imag_ans << "i" << endl;
        }
        if (b.imag_ans == 0){
            cout << b.real_ans << endl;
        }
    }

    return 0;
}
