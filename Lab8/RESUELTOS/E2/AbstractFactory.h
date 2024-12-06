#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include "AbstractProductoA.h"
#include "AbstractProductoB.h"

class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
    virtual AbstractProductoA* CrearProductoA() const = 0;
    virtual AbstractProductoB* CrearProductoB() const = 0;
};

#endif // ABSTRACT_FACTORY_H
