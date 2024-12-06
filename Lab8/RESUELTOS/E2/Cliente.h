#ifndef CLIENTE_H
#define CLIENTE_H

#include "AbstractFactory.h"
#include <iostream>

void Cliente(const AbstractFactory& factory) {
    const AbstractProductoA* productoA = factory.CrearProductoA();
    const AbstractProductoB* productoB = factory.CrearProductoB();

    std::cout << productoB->Funcion1B() << "\n";
    std::cout << productoB->Funcion2B(*productoA) << std::endl;

    delete productoA;
    delete productoB;
}

#endif // CLIENTE_H
