#ifndef C_PRODUCTO_A1_H
#define C_PRODUCTO_A1_H

#include "AbstractProductoA.h"

class CProductoA1 : public AbstractProductoA {
public:
    std::string Funcion1A() const override {
        return "Producto A1.";
    }
};

#endif // C_PRODUCTO_A1_H
