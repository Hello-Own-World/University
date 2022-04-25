#include <iostream>
#include <memory>
//using namespace std;

//class MyClass{
//private:
//    int x;
//    double d;
//public:
//    MyClass(int xx, double dd):x{xx},d{dd}{};
//    void print_data(){
//        std::cout<<"Data members values are: " << x << " and: " << d;
//    }
//};

//class BaseClass{
//public:
//    virtual void dowork()=0;
//    virtual ~BaseClass(){};
//};
//
//class DerivedClass:public BaseClass{
//public:
//    void dowork()override{
//        std::cout << "Do work from DerivedClass"<<'\n';
//    }
//};
//
//class SecondDerivedClass:public BaseClass{
//public:
//    void dowork()override{
//        std::cout<<"Do work from SecondDerivedClass" << "\n";
//    }
//};





int main() {
//    char mychar = 64;
//    int myint = 123;
//    double mydouble = 456.789;
//    bool myboolean = true;
//    myint = mychar;
//    mydouble = myint;
//    mychar = myboolean;

//int x = 123;
//double d = 456.789;
//bool b = true;
//
//double doubleresult = static_cast<double>(x);
//std::cout << "Int to double: " << doubleresult << '\n';
//
//int intresult = static_cast<int>(d);
//std::cout << "Double to int: " << intresult << '\n';
//
//bool boolresult = static_cast<bool>(x);
//std::cout << "Int to bool: " << boolresult << '\n';

//    std::unique_ptr<int> p = std::make_unique<int>(123);
//    std::cout << "The value of a pointed-to object is: " << *p << '\n';

//std::unique_ptr<MyClass> p = std::make_unique<MyClass>(123, 456.789);
//p->print_data();

//    std::shared_ptr<int> p1 = std::make_shared<int>(123);
//    std::shared_ptr<int> p2 = p1;
//    std::shared_ptr<int> p3 = p1;
//
//    std::cout << "Value accessed through a first pointer: " << *p1 << '\n';
//    std::cout << "Value accessed through a first pointer: " << *p2 << '\n';
//    std::cout << "Value accessed through a first pointer: " << *p3 << '\n';

//std::unique_ptr<BaseClass> p = std::make_unique<DerivedClass>();
//p->dowork();
//
//std::unique_ptr<BaseClass> p2 = std::make_unique<SecondDerivedClass>();
//p2->dowork();


    try {
        std::cout<<"Throwing an integer exception with value of 123..."<<'\n';
        int x = 123;
        throw x;
        std::cout << "Throwing a double exception..." << '\n';
        throw 456.789;
    }
    catch (int ex){
        std::cout <<"An integer exception of value: " << ex << " caught and handled." << '\n';
    }
    catch (double ex) {
        std::cout << "Double exception: " << ex << " caught and handled." << '\n';
    }
    return 0;
}
