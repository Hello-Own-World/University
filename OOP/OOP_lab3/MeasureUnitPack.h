//
// Created by yushc on 15.04.2022.
//

#ifndef OOP_LAB3_MEASUREUNITPACK_H
#define OOP_LAB3_MEASUREUNITPACK_H


class MeasureUnitPack {
public:
    virtual void show_measure_sys() = 0;
};

class MetricSystem : public MeasureUnitPack {
public:
    void show_measure_sys() override {
        std::cout << "\nCurrent unit system is metric.";
    }
};

class ImperialSystem : public MeasureUnitPack {
public:
    void show_measure_sys() override {
        std::cout << "\nCurrent unit system is imperial.";
    }
};


#endif //OOP_LAB3_MEASUREUNITPACK_H
