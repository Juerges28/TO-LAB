#ifndef OTHER_H
#define OTHER_H

#include "item.h"

// Clase para color
class Color : public item {
    string colorName;
public:
    Color(string name) : colorName(name) {}
    string GetName() override { return "Color"; }
    float GetPrice() override { return 0.0; } // Sin costo adicional
    void GetConfiguration() override {
        cout << "Laptop Color: " << colorName << endl;
    }
};

// Clase para marca
class Brand : public item {
    string brandName;
public:
    Brand(string name) : brandName(name) {}
    string GetName() override { return "Brand"; }
    float GetPrice() override { return 0.0; } // Sin costo adicional
    void GetConfiguration() override {
        cout << "Brand: " << brandName << endl;
    }
};

#endif // OTHER_H
