#ifndef C_PRODUCTO_A2_H
#define C_PRODUCTO_A2_H

#include "AbstractProductoA.h"

class CProductoA2 : public AbstractProductoA {
public:
    std::string Funcion1A() const override {
        return "Producto A2.";
    }
};

#endif // C_PRODUCTO_A2_H
