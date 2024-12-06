#ifndef C_PRODUCTO_B1_H
#define C_PRODUCTO_B1_H

#include "AbstractProductoB.h"

class CProductoB1 : public AbstractProductoB {
public:
    std::string Funcion1B() const override {
        return "Producto B1.";
    }

    std::string Funcion2B(const AbstractProductoA& colaborador) const override {
        return "B1 con ayuda de " + colaborador.Funcion1A();
    }
};

#endif // C_PRODUCTO_B1_H
