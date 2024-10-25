#include "lista.h"

// CONSTRUCTORES POR DEFECTO
Lista::Lista() {
    cout << "constructor por defecto\n";
}

void Lista::copiaArreglo(int arreglo[], int size, Nodo **inicio) {
    Nodo *iNodo;
    int i = 0;
    *inicio = new Nodo;
    (**inicio).valor = arreglo[i];
    (**inicio).siguiente = nullptr;
    (**inicio).anterior = nullptr;
    i++;
    iNodo = *inicio;
    while (i < size) {
        iNodo->siguiente = new Nodo;
        iNodo->siguiente->anterior = iNodo;
        iNodo = iNodo->siguiente;
        iNodo->valor = arreglo[i];
        iNodo->siguiente = nullptr;
        i++;
    }
}

void Lista::imprimeListaAdelante(Nodo *inicio) {
    Nodo *iNodo = inicio;
    while (iNodo != nullptr) {
        cout << iNodo->valor << " ";
        iNodo = iNodo->siguiente;
    }
    cout << endl;
}

void Lista::imprimeListaAtras(Nodo *inicio) {
    Nodo *iNodo = inicio;
    if (iNodo == nullptr) return;
    while (iNodo->siguiente != nullptr) {
        iNodo = iNodo->siguiente;
    }
    while (iNodo != nullptr) {
        cout << iNodo->valor << " ";
        iNodo = iNodo->anterior;
    }
    cout << endl;
}

void Lista::destruyeLista(Nodo *inicio) {
    Nodo *iNodo = inicio;
    Nodo *AuxNodo;
    while (iNodo != nullptr) {
        AuxNodo = iNodo->siguiente;
        delete iNodo;
        iNodo = AuxNodo;
    }
}

Nodo* Lista::buscarAdelante(Nodo *inicio, int valor) {
    Nodo *iNodo = inicio;
    while (iNodo != nullptr) {
        if (iNodo->valor == valor) {
            return iNodo;
        }
        iNodo = iNodo->siguiente;
    }
    return nullptr;
}

Nodo* Lista::buscarAtras(Nodo *inicio, int valor) {
    Nodo *iNodo = inicio;
    if (iNodo == nullptr) return nullptr;
    while (iNodo->siguiente != nullptr) {
        iNodo = iNodo->siguiente;
    }
    while (iNodo != nullptr) {
        if (iNodo->valor == valor) {
            return iNodo;
        }
        iNodo = iNodo->anterior;
    }
    return nullptr;
}