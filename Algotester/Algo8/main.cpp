#include <iostream>
using namespace std;

bool check_prime(double x){
    double y = ((x*x)-1)/24;
    double z = y - static_cast<int>(y);
    if ( x==2 || x==3|| z==0 ){
        return true;
    };
    return false;
}
int other_num(int x){
    int a1, ans = 0;
    for (int i = 3; i < 49999; ++i) { // its middle of prime numbers all in 100 000
        if(x%i==0){
            a1 = x / i;
            ans = (a1<i) ? i : a1;
            break;
        }
    }
    return ans;
}


int main() {

int h;
cin >> h;
if(h%2==0){
    cout << h/2;
} else if(check_prime(h)){
    if (h == 2 || h == 3 || h == 5){
        cout << "1";
        return 0;
    }
    cout << (((h-9)/2)+2);
} else{
    cout << other_num(h);
}

    return 0;
}
