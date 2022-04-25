#include <iostream>
using namespace  std;

enum class Days{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

enum class Colors{
    Red,
    Green,
    Blue
};



int main() {
//    Days myday = Days::Monday;
//    cout << "The enum value is now Monday." << '\n';
//    if (myday == Days::Monday){
//        myday = Days::Friday;
//    }
//    cout << "Nobody likes Mondays. The value is now Friday.";
//#2

Colors mycolors = Colors::Green;

switch (mycolors){
    case Colors::Red:
        cout << "The color is Red." << endl;
        break;
    case Colors::Green:
        cout << "The color is Green." << endl;
        break;
    case Colors::Blue:
        cout << "The color is Blue." << endl;
        break;
    default:
        break;
}

    return 0;
}
