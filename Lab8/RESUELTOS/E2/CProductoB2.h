#ifndef C_PRODUCTO_B2_H
#define C_PRODUCTO_B2_H

#include "AbstractProductoB.h"

class CProductoB2 : public AbstractProductoB {
public:
    std::string Funcion1B() const override {
        return "Producto B2.";
    }

    std::string Funcion2B(const AbstractProductoA& colaborador) const override {
        return "B2 con ayuda de " + colaborador.Funcion1A();
    }
};

#endif // C_PRODUCTO_B2_H
