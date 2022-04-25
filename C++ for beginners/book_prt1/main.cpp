#include <iostream>

//using namespace std;


//int myfunction(int x, int y); //names for parameters are optional, but not type
//
//void print_hi();
//
//void print_custom_msg(const string& msg, int x){
//    static int y = 1;
//    cout << y<< endl;
//    y++;
//
//}

class test1{
public:

    static void print_msg(int x){
        std::cout << "Static function!"<< x;
    };
     static int i;

    test1(){
        //nothing
    };
};





int test1::i=1;



int main() {

    //static int x = 5;

    test1::i = 2;
//    test1 obj;
//    obj.print_msg();
    //test1::print_msg();


    //std::cout << test1::i;
    int x = 5;
    test1::print_msg(5);



    /* #1
    //definition
    int x1 = 1;
    char y1 = 'a';
    double z1 = 1.5;
    //declaration
    int x2;
    char y2;
    double z2;
    //initialisation
    int x3 {123};
    char y3 {'b'};
    double z3 {2.5};

    cout << "x1 " << x1 << endl;
    cout << "y1 " << y1 << endl;
    cout << "z1 " << z1 << endl;

    cout << "x2 " << x2 << endl;
    cout << "y2 " << y2 << endl;
    cout << "z2 " << z2 << endl;

    cout << "x3 " << x3 << endl;
    cout << "y3 " << y3 << endl;
    cout << "z3 " << z3 << endl;
     */

    /* #2
    int x = 0;
    int y = 0;

    std::cin >> x >> y; //!
    std::cout << "You entered: " << x << " and " << y;
     */

    /* #3
    int x = 9 / 2;
    std::cout << "The result is: " << x << '\n'; double d = 9 / 2;
    std::cout << "The result is: " << d << '\n'; d = 9.0 / 2;
    std::cout << "The result is: " << d;
    */

    /* #4
     std::array and std::vector
     */

    /* #5
    int x = 5;

    int* p = &x;

    cout << "Address: " << p << endl;
    cout << "Value: " << *p << endl; //dereferencing
    //використовуючи розіменування можна змінити значення змінної за адресом
    *p = 8;
    cout << "New value: " << *p << endl; //dereferencing
    */

    /* #6
    //Reference type
    int x = 5;
    int& y = x; //reference type - two different names that refer to the same object
    // if we change any of them the both will be changed as they refer to the same object in memory
    */
    /* #7
     * Summing up pointers and references
     *
    int x = 5;

    int* y = &x;// pointer to x that contains its address
    cout<< "Pointer: "<<y<<endl;
    cout<< "Dereferencing of pointer: "<<*y<<endl;
    *y +=1; // we can use dereferenced pointer to change value by its address
    cout<< "Pointer: "<<y<<endl;
    cout<< "Dereferencing of pointer: "<<*y<<endl;
    int& z = x;
    cout<< "Reference: "<<z<<endl;
    z+=1;
    cout<< "Reference: "<<z<<endl;
*/
    /* #8
     * Strings

    string s = "Hello world!";
    string b = "!";

    cout << s+b;//add strings
    // two ways of accessing chars in string
    cout << s[0];
    cout << s.at(0);
    //compare strings
    if (s == b){
        cout<<1;
    }
    bool x = s == "Hello world!";
    cout << x;
    */
    /* #9 */
    //???
    //int b = 5;
    //const int* c = &b;
    /*
    string a = "Hello";
    const char* z = a.c_str();

    cout << a.c_str();
    cout << z;
    printf("%p", z);
    //cout << c;
     */
    /* #10
     * substr()
     * find()
     *

    string s = "Hello world!";
    string substring = s.substr(6, 6); // substr(start, length)
    cout << substring;

    string g = "This is my own world!";
    cout << g.find("world"); // find substring in main string
    */

    /* #11
    std::string s = "This is a Hello World string.";

    std::string stringtofind = "Hello";

    std::string::size_type found = s.find(stringtofind);

    if (found != std::string::npos){
        std::cout << "Substring found at position: " << found;
    }

    else    {
        std::cout << "The substring is not found.";
    }
     */
    /* #12
    * auto type
    auto x = 10;
    auto y = 125.356;
    auto z = 'f';

    auto& j = x;
    auto* g = &y;
    */
    /*

    int y = 10;
    const int x = 5;
    const int z = y;

    constexpr int x1 = 5;
    constexpr int z1 = x;


    cout << x <<"\n"<< z;
    cout << x <<"\n"<< z;

    */
    /* #13

    //print_hi();
    string msg1 = "Hello world!";
    string& msg2 = msg1;

    //cout<< msg1 << endl;
    //cout<< msg2 << endl;

    print_custom_msg(msg1, x);
    print_custom_msg(msg1, x);
    print_custom_msg(msg1, x);
    print_custom_msg(msg1, x);
    print_custom_msg(msg1, x);

*/
    /* #14 */

    {
        //I can artificially create blocks anywhere in code, so there will be local variables
    }

    return 0;
}


