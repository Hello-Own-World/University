#include <iostream>
#include <vector>
#include <array>
using namespace std;


//class A{
//public: A(){
//    cout << "Constructor 1" << '\n';
//}
//
//};
//class B:public A{
//public: B(){
//        cout << "Constructor 2" << '\n';
//    }
//
//};
//class C:public A{
//public: C(){
//        cout << "Constructor 3" << '\n';
//    }
//
//};
//class D:public B, public C{
//public: D(){
//        cout << "Constructor 4" << '\n';
//    }
//
//};


int main() {

    vector<int> v = {1, 2, 3, 4, 5};
//    v.push_back(10);
//    for (int& el : v){
//        cout << el <<' ';
//    }

    auto it = v.begin() +3;
    v.erase(it);

    for (auto el: v) {
        cout << el << '\n';
    }






//    B* b = new D();


    return 0;
}
