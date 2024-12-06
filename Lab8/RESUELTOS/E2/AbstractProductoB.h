#ifndef ABSTRACT_PRODUCTO_B_H
#define ABSTRACT_PRODUCTO_B_H

#include "AbstractProductoA.h"
#include <string>

class AbstractProductoB {
public:
    virtual ~AbstractProductoB() {}
    virtual std::string Funcion1B() const = 0;
    virtual std::string Funcion2B(const AbstractProductoA& colaborador) const = 0;
};

#endif // ABSTRACT_PRODUCTO_B_H
