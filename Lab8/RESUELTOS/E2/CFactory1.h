#ifndef C_FACTORY1_H
#define C_FACTORY1_H

#include "AbstractFactory.h"
#include "CProductoA1.h"
#include "CProductoB1.h"

class CFactory1 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override {
        return new CProductoA1();
    }

    AbstractProductoB* CrearProductoB() const override {
        return new CProductoB1();
    }
};

#endif // C_FACTORY1_H
