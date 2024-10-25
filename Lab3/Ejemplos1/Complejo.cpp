#include <iostream>
using namespace std;

class Complejo {
private:
    double real, imaginario;
public:
    Complejo(double r = 0, double i = 0) : real(r), imaginario(i) {}

    // Sobrecarga del operador +
    Complejo operator + (const Complejo& c) {
        return Complejo(real + c.real, imaginario + c.imaginario);
    }

    void mostrar() {
        cout << real << " + " << imaginario << "i" << endl;
    }
};

int main() {
    Complejo c1(3.0, 4.0), c2(1.0, 2.0);
    Complejo c3 = c1 + c2; // Llama a Complejo::operator+
    c3.mostrar();
    return 0;
}