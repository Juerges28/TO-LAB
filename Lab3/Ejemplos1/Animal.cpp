#include <iostream>
using namespace std;

class Animal {
public:
    virtual void hacerSonido() {
        cout << "El animal hace un sonido" << endl;
    }
};

class Perro : public Animal {
public:
    void hacerSonido() override {
        cout << "El perro ladra" << endl;
    }
};

class Gato : public Animal {
public:
    void hacerSonido() override {
        cout << "El gato maúlla" << endl;
    }
};

void hacerSonidoAnimal(Animal* animal) {
    animal->hacerSonido();
}

int main() {
    Animal* a;
    Perro p;
    Gato g;

    a = &p;
    hacerSonidoAnimal(a); // Llama a Perro::hacerSonido()

    a = &g;
    hacerSonidoAnimal(a); // Llama a Gato::hacerSonido()

    return 0;
}