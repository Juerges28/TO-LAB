#include <iostream>
using namespace std;

template <typename T>
class Pila {
private:
    T* elementos;      
    int capacidad;     
    int cima;          

public:
    Pila(int size);    
    ~Pila();           
    void push(T elemento); 
    T pop();          
    T peek();         
    bool isEmpty();   
    bool isFull();    
};

template <typename T>
Pila<T>::Pila(int size) {
    capacidad = size;
    elementos = new T[capacidad];
    cima = -1; 
}

template <typename T>
Pila<T>::~Pila() {
    delete[] elementos; 
}

template <typename T>
void Pila<T>::push(T elemento) {
    if (!isFull()) {
        elementos[++cima] = elemento; 
    } else {
        cout << "La pila está llena." << endl;
    }
}

template <typename T>
T Pila<T>::pop() {
    if (!isEmpty()) {
        return elementos[cima--]; 
    } else {
        cout << "La pila está vacía." << endl;
        return T();
    }
}

template <typename T>
T Pila<T>::peek() {
    if (!isEmpty()) {
        return elementos[cima];
    } else {
        cout << "La pila está vacía." << endl;
        return T();
    }
}

template <typename T>
bool Pila<T>::isEmpty() {
    return cima == -1; 
}


template <typename T>
bool Pila<T>::isFull() {
    return cima == capacidad - 1; 
}

int main() {
    Pila<int> pilaInt(5);
    pilaInt.push(1);
    pilaInt.push(2);
    cout << "Elemento en la cima (int): " << pilaInt.peek() << endl; 
    cout << "Elemento removido (int): " << pilaInt.pop() << endl;   
    cout << "Elemento en la cima (int) después de pop: " << pilaInt.peek() << endl; 

    Pila<char> pilaChar(5);
    pilaChar.push('A');
    pilaChar.push('B');
    cout << "Elemento en la cima (char): " << pilaChar.peek() << endl; 
    cout << "Elemento removido (char): " << pilaChar.pop() << endl;   
    cout << "Elemento en la cima (char) después de pop: " << pilaChar.peek() << endl; 

    return 0;
}
