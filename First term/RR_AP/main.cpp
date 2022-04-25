#include <iostream>
#include "cmath"
using namespace std;
/*
int main() {
    double a=16.5, b=3.4 , x=0.61;
    double c = (b*x*x)/(pow(M_E, a*x));
    double S = ((pow(x,3)* pow(tan(pow(x+b,2)),2)+a)*c)/(sqrt(x+b));
    std::cout << S;
    return 0;
}
*/


// pow(e, x/2)*pow(b, x)*(cos(z)+sin(z))
// z = (sqrt(4b+pow(x,2)))/2
// x [1,2] hx = 0.2 b = 2,4,6,8

int main() {
    double x = 1, z, y;
    while (x<2){
        for (int b = 2; b<=8; b+=2){
            z = (sqrt(4*b+pow(x,2)))/2;
            y = pow(M_E, x/2)*pow(b, x)*(cos(z*(M_PI/180))+sin(z*(M_PI/180)));
            std::cout << "x= " << x << " b= " << b << " y= " << y <<std::endl;
        }
        x += 0.2;
    }
    return 0;
}



/*
int main() {
    double a, b, c, res;
    while(true){
        cout << "Calculating area of triangle.\nEnter values of 2 sides of triangle:\n";
        cin >> a;
        if (a<=0){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        cin >> b;
        if (b<=0){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        cout << "Enter value of angle between those sides(0-360 deg):\n";
        cin >> c;
        if (c<=0 || c>=360){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        break;
    }
    res = (a*b*sin(c*(M_PI/180)))/2;
    cout << "Area of triangle equals:" << res;
    return 0;
}
*/
/*
int main() {
    double a, b, c, v=0.000002, vb, n;
    while (true) {
        cout << "Enter size of your box in meters(x y z):" << endl;
        cin >> a;
        if (a<=0){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        cin >> b;
        if (b<=0){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        cin >> c;
        if (c<=0){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        break;
    }
    vb = a*b*c;
    n = vb/v;
    cout << "You can store "<<n<< " bolts in that box.\n";
    return 0;
}
 */
/*
int main(){
    int n, an, sn, a1 = 1, d=2;
    while (true){
        cout << "Sum of how many first members you want to calculate?:\n";
        cin >> n;
        if (n<=0){
            cout << "Wrong value! Try again...\n";
            continue;
        }
        break;
    }
    an = a1 + (n-1)*d;
    sn = ((a1+an)/2)*n;
    cout << "Sum of first " << n << " members = " << sn << endl;
    return 0;
}
*/



