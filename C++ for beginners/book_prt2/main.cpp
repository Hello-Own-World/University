#include <iostream>
#include <utility>
using namespace std;

//class clas1{
//private:
//    int y = 10;
//    int* p;
//public:
//    int x = 5;
//
//
//    clas1(int xx, int yy, int pp): x{xx}, y{yy}, p{new int {pp}} { // user defined constructor
////        x = xx;
////        y = yy;
//        cout << "Constructor was invoked!"<<endl;
//    }
//
//    clas1(const clas1& rhs): x{rhs.x}, y{rhs.y}, p{new int{*rhs.p}}
//    {
//        cout << "User-defined copy constructor was invoked!" <<endl;
//    }
//
//
//
//    void prt_msg(){
//        cout << "1 function!";
//        x = x+y;
//    }
//
//};


//
//class Father{
//public:
//    int x = 1;
//private:
//    int x2 = 2;
//protected:
//    int x3 = 3;
//
//};
//
//class Son : public Father{ // derived class can access only public members of main class, same works for objects
//    public:
//    int y = x+2;
//
//    int z = x + x3;
//};


class Person{
public:
    string name;

    explicit Person(string name1){
        name = std::move(name1);
    };

    string getname(){
        return name;
    }
};

class Student : public Person{
public:
    int semester;

    Student(const string& name1, int sem):Person::Person{name1}{
        semester = sem;
    };

    int getsemester() const{
      return semester;
    };
};












int main() {


//    int x = 123;
//    int y = 456;
//    std::cout << "The values with automatic storage duration are: " << x << ' ' << y << std::endl;
//
//    int* p = new int{123};
//    std::cout << "The value with dynamic storage duration: " << *p <<std::endl;
//    delete p;

//    clas1 obj(5, 10, 12);
//    clas1 obj1(15, 20, 128);
//
//    clas1 obj2 = obj1;
//
//    //obj.prt_msg();
//    //obj.x += 1;
//
//    cout << obj.x << endl;
//    cout << obj1.x << endl;


//Father one;
//Son one_;
//one.x+=2;
//one_.x += 2;

Person person("John Doe");
cout << person.getname() << endl;

Student student1{"Jane Doe", 2};
cout << student1.getname() << endl;
cout << "Semester is: " << student1.semester << endl;


    return 0;
}
