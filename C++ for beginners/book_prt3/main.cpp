#include <iostream>
using namespace std;

//void myfunction(){
//    static int count = 0; // will be created after first usage of function and then skipped
//    count++;
//    cout << "The function is called " << count << " time(s)" << endl;
//}

class MyClass{
public:
    static string name;

    static void mystaticfunction();
    void myfunction();

};

string MyClass::name = "John Doe";

void MyClass::mystaticfunction() {
    cout << "Hello world from a static member function" << endl;
};

void MyClass::myfunction() {
    cout << "Hello world from a static member function" << endl;
};


int main() {
//for (int i = 0; i < 5; i++){
//    myfunction();
//}

    cout << "Static data member value: " << MyClass::name<<endl;
    MyClass::name = "Jane Doe";
    cout << "Static data member value: " << MyClass::name<<endl;

    MyClass::mystaticfunction();//static func can be used without object
    MyClass obj;
    obj.myfunction(); // def func only via object


    return 0;
}
