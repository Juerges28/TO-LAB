#ifndef DISPLAY_H
#define DISPLAY_H

#include "item.h"

// Clase base para pantallas
class DisplayType : public item {};

// Pantalla Normal
class Normal : public DisplayType {
public:
    string GetName() override { return "Non-touch screen"; }
    float GetPrice() override { return 195.0; }
    void GetConfiguration() override {
        cout << "15.6 inch FHD (1920x1080)" << endl;
    }
};

// Monitor Plasma
class Plasma : public DisplayType {
public:
    string GetName() override { return "Plasma screen"; }
    float GetPrice() override { return 300.0; }
    void GetConfiguration() override {
        cout << "17 inch Plasma HD (1600x900)" << endl;
    }
};

#endif // DISPLAY_H
