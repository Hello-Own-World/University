//
// Created by yushc on 15.04.2022.
//

#ifndef OOP_LAB3_OS_SUPPORT_PACKAGE_H
#define OOP_LAB3_OS_SUPPORT_PACKAGE_H


class OS_support_package {
public:
    virtual void show_OS_support() = 0;
};

class Mac_OS : public OS_support_package {
public:
    void show_OS_support() override {
        std::cout << "\nCurrent system supports Mac OS\n";
    }
};

class Ubuntu_OS : public OS_support_package {
public:
    void show_OS_support() override {
        std::cout << "\nCurrent system supports Ubuntu OS\n";
    }
};

class Windows_OS : public OS_support_package {
public:
    void show_OS_support() override {
        std::cout << "\nCurrent system supports Windows OS\n";
    }
};

#endif //OOP_LAB3_OS_SUPPORT_PACKAGE_H
