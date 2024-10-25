#include <iostream>
using namespace std;

class Calculadora {
public:
    // Sobrecarga de la función suma para enteros
    int suma(int a, int b) {
        return a + b;
    }

    // Sobrecarga de la función suma para números de punto flotante
    double suma(double a, double b) {
        return a + b;
    }
};

int main() {
    Calculadora calc;
    cout << "Suma de enteros: " << calc.suma(3, 4) << endl; // Llama a suma(int, int)
    cout << "Suma de doubles: " << calc.suma(3.5, 4.5) << endl; // Llama a suma(double, double)
    return 0;
}