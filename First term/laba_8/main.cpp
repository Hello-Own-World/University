#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;

struct student{
    string name;
    string home_address;
    string group;
    double ranking;
};

student get_new_stud(){
    student a;
    cout << "Enter in one line your name, surname and patronym:" <<endl;
    getline(cin, a.name);
    getline(cin, a.name);
    cout << "Enter your home address:" <<endl;
    cin >> a.home_address;
    cout << "Enter your group:" <<endl;
    cin >> a.group;
    cout << "Enter your ranking:" <<endl;
    cin >> a.ranking;
    cin.clear();
    return a;
}

int main() {
    fstream file("student.bin", ios::out | ios::binary | ios::trunc); //, ios::out | ios::binary
    file.open("student.bin", ios::out | ios::binary | ios::trunc);
    int n;
    string a;
    cout << "How many student's do you want to add?: "<< endl;
    cin >> n;
    student lst[10];

    for (int i = 0; i<n; i++){
        lst[i] = get_new_stud();
        cout << lst[i].name << lst[i].home_address << lst[i].group << lst[i].ranking;
        file.write(lst[i].name, sizeof(student))

    }
    file.close();

    //ofstream file("student.bin", ios::in | ios::binary | ios::trunc); //, ios::out | ios::binary
    //file.open("student.bin", ios::in | ios::binary | ios::trunc);

    //if (!file.is_open()) // если файл небыл открыт
    //{
     //   cout << "Error opening file!\n";
     //   return 1;
    //}

    //file.write(b.name, 20);
    //file.close();


    return 0;
}
