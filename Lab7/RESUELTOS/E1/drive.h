#ifndef DRIVE_H
#define DRIVE_H

#include "item.h"

// Clase base para almacenamiento
class Drive : public item {};

// Disco duro HDD
class HDD : public Drive {
public:
    string GetName() override { return "Hard disk drive"; }
    float GetPrice() override { return 150.0; }
    void GetConfiguration() override {
        cout << "Capacity: 1TB, Data transfer: 1050 mbits/s" << endl;
    }
};

// Disco duro SSD
class SDD : public Drive {
public:
    string GetName() override { return "Solid state drive"; }
    float GetPrice() override { return 270.0; }
    void GetConfiguration() override {
        cout << "Capacity: 256GB, Data transfer: 1800 mbits/s" << endl;
    }
};

#endif // DRIVE_H
