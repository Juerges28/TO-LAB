#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "item.h"

// Clase base para procesadores
class Processor : public item {};

// Procesador Intel I5
class IntelI5 : public Processor {
public:
    string GetName() override { return "Intel I5"; }
    float GetPrice() override { return 3000.0; }
    void GetConfiguration() override {
        cout << "1.5 GHz, 2 cores, 8MB cache, RAM 4GB - 8GB" << endl;
    }
};

// Procesador Intel I7
class IntelI7 : public Processor {
public:
    string GetName() override { return "Intel I7"; }
    float GetPrice() override { return 4700.0; }
    void GetConfiguration() override {
        cout << "1.6 GHz, 4 cores, 16MB cache, RAM 16GB" << endl;
    }
};

#endif // PROCESSOR_H
