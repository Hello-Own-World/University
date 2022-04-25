#include <iostream>

using namespace std;

enum class Engine {
    V2,
    V4,
    V6,
    V8,
    V10,
    V12
};

string eng_to_str(Engine engine) {
    switch (engine) {
        case Engine::V2:
            return "V2";
        case Engine::V4:
            return "V4";
        case Engine::V6:
            return "V6";
        case Engine::V8:
            return "V8";
        case Engine::V10:
            return "V10";
        case Engine::V12:
            return "V12";
    }

}

class Vehicle {
protected:
    string brand;
    Engine engine;

public:
    Vehicle(string brand, Engine engine) {
        this->brand = std::move(brand);
        this->engine = engine;
//        cout << "A\n";
    }

    virtual void refuel(double value) = 0;

    virtual void get_info() = 0;

};

class Car : public Vehicle {
protected:
    int number_plate;
    string color;
    string model;
public:
    Car(string color, string model, int number_plate, const string &brand, Engine engine) : Vehicle(brand, engine) {

        this->color = std::move(color);
        this->model = std::move(model);
        this->number_plate = number_plate;
//        cout << "B\n";
    };


};


class Electric_car : public Car {
protected:
    double battery;
public:
    Electric_car(double battery, string color, string model, int numberPlate, const string &brand, Engine engine) : Car(
            std::move(color), std::move(model), numberPlate, brand, engine) {
        this->battery = battery;
//        cout << "C\n";
    }

    void refuel(double value) override {
        battery += value;
    }

    void get_info() override {
        cout << "\nBrand: " << brand << '\n'
             << "Engine: " << eng_to_str(engine) << '\n'
             << "Number plate: " << number_plate << '\n'
             << "Colour: " << color << '\n'
             << "Model: " << model << '\n'
             << "Charge: " << battery << '\n';
    }

};

class Petrol_car : public Car {
public:
    Petrol_car(double fuel, string color, string model, int numberPlate, const string &brand, Engine engine) : Car(
            std::move(color), std::move(model),
            numberPlate,
            brand, engine) {
        this->fuel = fuel;
//        cout << "D\n";
    }

    void refuel(double value) override {
        fuel += value;
    }

    void get_info() override {
        cout << "\nBrand: " << brand << '\n'
             << "Engine: " << eng_to_str(engine) << '\n'
             << "Number plate: " << number_plate << '\n'
             << "Colour: " << color << '\n'
             << "Model: " << model << '\n'
             << "Fuel: " << fuel << '\n';
    }

protected:
    double fuel;
};

class Hybrid_car : Petrol_car, Electric_car {
public:
    Hybrid_car(double fuel, double battery, string color, string model, int numberPlate, const string &brand,
               Engine engine)
            : Petrol_car(fuel, std::move(color), std::move(model), numberPlate, brand, engine),
              Electric_car(battery, std::move(color), std::move(model), numberPlate, brand, engine) {
//        cout << "E\n";
    };

    void refuel(double voltage, double petrol) {
        battery += voltage;
        fuel += petrol;
    }

    void get_info() override {
        cout << "\nBrand: " << Electric_car::brand << '\n'
             << "Engine: " << eng_to_str(Electric_car::engine) << '\n'
             << "Number plate: " << Electric_car::number_plate << '\n'
             << "Colour: " << Electric_car::color << '\n'
             << "Model: " << Electric_car::model << '\n'
             << "Charge: " << battery << '\n'
             << "Fuel: " << fuel << '\n';
    }
};


int main() {
    Electric_car e_car(0, "red", "van", 2365, "Mercedes", Engine::V8);
    Petrol_car p_car(0, "blue", "sedan", 9999, "Toyota", Engine::V10);
    Hybrid_car h_car(0, 0, "green", "van", 7895, "BMW", Engine::V12);

    e_car.get_info();
    p_car.get_info();
    h_car.get_info();

    e_car.refuel(20);
    p_car.refuel(35);
    h_car.refuel(20, 125);

    e_car.get_info();
    p_car.get_info();
    h_car.get_info();

    return 0;
}
