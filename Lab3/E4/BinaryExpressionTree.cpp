#include "BinaryExpressionTree.h"

Nodo* BinaryExpressionTree::construirArbol(const string& expresion) {
    stack<Nodo*> pila;
    stringstream ss(expresion);
    string token;

    while (ss >> token) {
        if (token == "+" || token == "*") {
            Nodo* nodo = new Nodo(token);
            nodo->derecho = pila.top(); pila.pop();
            nodo->izquierdo = pila.top(); pila.pop();
            pila.push(nodo);
        } else {
            pila.push(new Nodo(token));
        }
    }

    raiz = pila.top();
    return raiz;
}

int BinaryExpressionTree::evaluar(Nodo* nodo) {
    if (!nodo->izquierdo && !nodo->derecho) {
        return stoi(nodo->valor);
    }

    int izquierda = evaluar(nodo->izquierdo);
    int derecha = evaluar(nodo->derecho);

    if (nodo->valor == "+") {
        return izquierda + derecha;
    } else if (nodo->valor == "*") {
        return izquierda * derecha;
    }

    return 0;
}

int BinaryExpressionTree::evaluar() {
    return evaluar(raiz);
}

void BinaryExpressionTree::destruirArbol(Nodo* nodo) {
    if (nodo) {
        destruirArbol(nodo->izquierdo);
        destruirArbol(nodo->derecho);
        delete nodo;
    }
}