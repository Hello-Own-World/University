#include <iostream>
using namespace std;

//template <typename T> // placeholder for type
//T mysum(T x, T y){
//    return x+y;
//}

//#2

template <typename T>
class Myclass{
private:
    T x;
public:
    Myclass(T xx) : x{xx}{
    }
    T getx() const{
        return x;
    }
    void setx(T ax){
        x = ax;
    }
};


int main() {
//    int intresult = mysum<int>(5, 6);
//    cout << "Int result is: " <<intresult << endl;
//    double doubleresult = mysum<double>(12.0, 15.5);
//    cout << "Double result is: " <<doubleresult << endl;
//#2

    Myclass<int> o{123};
    cout << "The vale of data member is " << o.getx() << endl;
    o.setx(456);
    cout << "The vale of data member is " << o.getx() << endl;

    Myclass<double> o2{4.25};
    cout << "The vale of data member is " << o2.getx() << endl;
    o2.setx(6.28);
    cout << "The vale of data member is " << o2.getx() << endl;
    return 0;
}
