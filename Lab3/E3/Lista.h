#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

class Lista
{
public:
    Lista();
    void copiaArreglo(int arreglo[], int size, Nodo **inicio);
    void imprimeListaAdelante(Nodo *inicio);
    void imprimeListaAtras(Nodo *inicio);
    void destruyeLista(Nodo *inicio);
    Nodo* buscarAdelante(Nodo *inicio, int valor);
    Nodo* buscarAtras(Nodo *inicio, int valor);
    ~Lista() {}
};

#endif