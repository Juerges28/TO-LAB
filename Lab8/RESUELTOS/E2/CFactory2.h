#ifndef C_FACTORY2_H
#define C_FACTORY2_H

#include "AbstractFactory.h"
#include "CProductoA2.h"
#include "CProductoB2.h"

class CFactory2 : public AbstractFactory {
public:
    AbstractProductoA* CrearProductoA() const override {
        return new CProductoA2();
    }

    AbstractProductoB* CrearProductoB() const override {
        return new CProductoB2();
    }
};

#endif // C_FACTORY2_H
