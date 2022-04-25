//
// Created by yushc on 15.04.2022.
//

#include "LanguagePack.h"
#include "MeasureUnitPack.h"
#include "OS_support_package.h"

class Software {
private:
    std::unique_ptr<LanguagePack> lang_pack; // client knows only interfaces it doesn't know  even which implementation it is using XD
    std::unique_ptr<MeasureUnitPack> meas_un_pack;
    std::unique_ptr<OS_support_package> os_supp_pack;
public:
    Software(LanguagePack *lp, MeasureUnitPack *mp, OS_support_package *op)
            : lang_pack{lp}, meas_un_pack{mp}, os_supp_pack{op} {};

    void show_sys_lang() {
        lang_pack->show_sys_lang();
    }

    void show_meas_sys() {
        meas_un_pack->show_measure_sys();
    }

    void show_supp_os() {
        os_supp_pack->show_OS_support();
    }
};

#ifndef OOP_LAB3_SOFTWARE_H
#define OOP_LAB3_SOFTWARE_H

#endif //OOP_LAB3_SOFTWARE_H
