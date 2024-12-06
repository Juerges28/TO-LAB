#ifndef ABSTRACT_PRODUCTO_A_H
#define ABSTRACT_PRODUCTO_A_H

#include <string>

class AbstractProductoA {
public:
    virtual ~AbstractProductoA() {}
    virtual std::string Funcion1A() const = 0;
};

#endif // ABSTRACT_PRODUCTO_A_H
