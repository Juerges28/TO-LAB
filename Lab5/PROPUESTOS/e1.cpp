#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;                
    Nodo<T>* siguiente;    

    Nodo(T valor) : dato(valor), siguiente(nullptr) {}
};

template <typename T>
class ListaEnlazadaSimple {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazadaSimple() : cabeza(nullptr) {}

    void agregar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            Nodo<T>* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void imprimir() const {
        Nodo<T>* temp = cabeza;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }

    ~ListaEnlazadaSimple() {
        Nodo<T>* temp;
        while (cabeza) {
            temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaEnlazadaSimple<int> listaEdades;
    listaEdades.agregar(25);
    listaEdades.agregar(30);
    listaEdades.agregar(45);
    cout << "Secuencia de edades: ";
    listaEdades.imprimir();

    ListaEnlazadaSimple<string> listaPalabras;
    listaPalabras.agregar("Hola");
    listaPalabras.agregar("Mundo");
    listaPalabras.agregar("C++");
    cout << "Secuencia de palabras: ";
    listaPalabras.imprimir();

    return 0;
}
