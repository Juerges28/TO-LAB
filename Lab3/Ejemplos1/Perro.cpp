#include <iostream>
#include <memory>

class Perro {
public:
    void ladrar() {
        std::cout << "Guau!" << std::endl;
    }
};

int main() {
    std::unique_ptr<Perro> ptrPerro = std::make_unique<Perro>();
    ptrPerro->ladrar();

    // No se puede copiar un unique_ptr
    // std::unique_ptr<Perro> ptrPerro2 = ptrPerro; // Error

    // Pero se puede transferir la propiedad
    std::unique_ptr<Perro> ptrPerro2 = std::move(ptrPerro);
    ptrPerro2->ladrar();

    return 0;
}