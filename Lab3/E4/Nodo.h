#ifndef NODO_H
#define NODO_H

#include <iostream>
#include <string>

using namespace std;

class Nodo {
public:
    string valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(string val) : valor(val), izquierdo(nullptr), derecho(nullptr) {}
};

#endif