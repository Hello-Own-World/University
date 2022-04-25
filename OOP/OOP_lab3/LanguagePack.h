//
// Created by yushc on 15.04.2022.
//

#ifndef OOP_LAB3_SOFTWARE_H
#define OOP_LAB3_SOFTWARE_H


class LanguagePack {
public:
    virtual void show_sys_lang() = 0;
};

class Eng_lang : public LanguagePack {
public:
    void show_sys_lang() override {
        std::cout << "\nCurrent system language is English.";
    }
};

class French_lang : public LanguagePack {
public:
    void show_sys_lang() override {
        std::cout << "\nLa langue actuelle du système est le français.";
    }
};

class German_lang : public LanguagePack {
public:
    void show_sys_lang() override {
        std::cout << "\nAktuelle Systemsprache ist Deutsch.";
    }
};


#endif //OOP_LAB3_SOFTWARE_H
