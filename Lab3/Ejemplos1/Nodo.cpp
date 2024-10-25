#include <iostream>
#include <memory>

class Nodo;

class Nodo {
public:
    std::shared_ptr<Nodo> siguiente;
    std::weak_ptr<Nodo> anterior; // weak_ptr para evitar ciclos de referencia

    ~Nodo() {
        std::cout << "Nodo destruido" << std::endl;
    }
};

int main() {
    std::shared_ptr<Nodo> nodo1 = std::make_shared<Nodo>();
    std::shared_ptr<Nodo> nodo2 = std::make_shared<Nodo>();

    nodo1->siguiente = nodo2;
    nodo2->anterior = nodo1;

    return 0;
}