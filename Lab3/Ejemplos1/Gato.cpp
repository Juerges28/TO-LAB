#include <iostream>
#include <memory>

class Gato {
public:
    void maullar() {
        std::cout << "Miau!" << std::endl;
    }
};

int main() {
    std::shared_ptr<Gato> ptrGato1 = std::make_shared<Gato>();
    {
        std::shared_ptr<Gato> ptrGato2 = ptrGato1;
        ptrGato2->maullar();
        std::cout << "Contador de referencias: " << ptrGato1.use_count() << std::endl;
    }
    // ptrGato2 se destruye aquí, pero el objeto Gato sigue existiendo porque ptrGato1 aún lo apunta
    std::cout << "Contador de referencias: " << ptrGato1.use_count() << std::endl;

    return 0;
}