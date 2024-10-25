#include "lista.h"

int main(int argc, char const *argv[]) {
    int arreglo[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int longitud = sizeof(arreglo) / sizeof(*arreglo);
    Nodo *inicio = nullptr;

    Lista lista1;  // llama al constructor defecto
    lista1.copiaArreglo(arreglo, longitud, &inicio);
    lista1.imprimeListaAdelante(inicio);
    lista1.imprimeListaAtras(inicio);

    Nodo *encontrado = lista1.buscarAdelante(inicio, 5);
    if (encontrado != nullptr) {
        cout << "Valor encontrado adelante: " << encontrado->valor << endl;
    } else {
        cout << "Valor no encontrado adelante" << endl;
    }

    encontrado = lista1.buscarAtras(inicio, 5);
    if (encontrado != nullptr) {
        cout << "Valor encontrado atras: " << encontrado->valor << endl;
    } else {
        cout << "Valor no encontrado atras" << endl;
    }

    lista1.destruyeLista(inicio);

    int espera;
    cin >> espera;

    return 0;
}