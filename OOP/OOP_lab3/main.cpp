#include <iostream>
#include <iomanip>
#include "di.hpp"
#include "Software.h"

using namespace std;
namespace di = boost::di;

int main() {
    const auto injector1 = di::make_injector(
            di::bind<LanguagePack>.to<Eng_lang>(),
            di::bind<MeasureUnitPack>.to<MetricSystem>(),
            di::bind<OS_support_package>.to<Windows_OS>()
    );
    const auto injector2 = di::make_injector(
            di::bind<LanguagePack>.to<German_lang>(),
            di::bind<MeasureUnitPack>.to<ImperialSystem>(),
            di::bind<OS_support_package>.to<Ubuntu_OS>()
    );

    auto soft1 = injector1.create<unique_ptr<Software>>();
    soft1->show_sys_lang();
    soft1->show_meas_sys();
    soft1->show_supp_os();

    auto soft2 = injector2.create<unique_ptr<Software>>();
    soft2->show_sys_lang();
    soft2->show_meas_sys();
    soft2->show_supp_os();

    auto soft3 = di::make_injector(
            di::bind<LanguagePack>.to<French_lang>(),
            di::bind<MeasureUnitPack>.to<MetricSystem>(),
            di::bind<OS_support_package>.to<Mac_OS>()
    ).create<Software>();

    soft3.show_sys_lang();
    soft3.show_meas_sys();
    soft3.show_supp_os();

    return 0;
}