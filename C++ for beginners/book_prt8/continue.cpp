//
// Created by yushc on 13.02.2022.
//

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class MyClass{
public:
    void operator()(){ //overload operator
        cout << "Function object called."<< '\n';
    }

    template<class T>
    void func(T){

    }
};

int main(){
    MyClass obj;
    obj.func([](){cout << "aaa";});

    auto mylambda = [](){cout << "Hello from lambda!";}; // lambda expression
    // [] - for obligatory param, ()-for optional
    mylambda();

    map<char, int> mymap  = { {'a', 1}, {'a', 1 }, {},};

    std::vector<int> v = { 5, 10, 4, 1, 3, 15 };
    std::sort(std::begin(v), std::end(v), [](int x, int y) {return x > y; });
    for (const auto& el : v)
    {
        std::cout << el << '\n';
    }

    return 0;
};