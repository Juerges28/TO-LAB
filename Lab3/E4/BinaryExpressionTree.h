#ifndef BINARYEXPRESSIONTREE_H
#define BINARYEXPRESSIONTREE_H

#include "Nodo.h"
#include <stack>
#include <sstream>

class BinaryExpressionTree {
public:
    Nodo* raiz;

    BinaryExpressionTree() : raiz(nullptr) {}

    Nodo* construirArbol(const string& expresion);
    int evaluar(Nodo* nodo);
    int evaluar();
    void destruirArbol(Nodo* nodo);
    ~BinaryExpressionTree() {
        destruirArbol(raiz);
    }
};

#endif