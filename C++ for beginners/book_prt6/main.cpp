#include <iostream>
#include "myheader.h"
using namespace std;

namespace MyNamespace{
    void myfunction();
}

void MyNamespace::myfunction() {
    cout<<"Hello world from a function inside namespace";
}

namespace A{
    namespace B{
        void hi();
    }
}

void A::B::hi() {
    cout << "Hello world from a function inside a nested namespace"<<endl;
}

int main() {
    say_hi();
    MyNamespace::myfunction();
    A::B::hi();
    using namespace A::B;
    hi();
    return 0;
}
