#ifndef PRINTER_H
#define PRINTER_H

#include "item.h"

// Clase base para impresoras
class Printer : public item {};

// Impresora básica
class BasicPrinter : public Printer {
public:
    string GetName() override { return "Basic Printer"; }
    float GetPrice() override { return 120.0; }
    void GetConfiguration() override {
        cout << "Black & White, 20 ppm" << endl;
    }
};

// Impresora avanzada
class AdvancedPrinter : public Printer {
public:
    string GetName() override { return "Advanced Printer"; }
    float GetPrice() override { return 250.0; }
    void GetConfiguration() override {
        cout << "Color, 40 ppm, Duplex printing" << endl;
    }
};

#endif // PRINTER_H
