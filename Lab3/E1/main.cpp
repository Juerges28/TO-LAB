#include "rectangulo.h"
using namespace std;

int main(int argc, char* argv[])
{
    auto x = make_unique<Rectangulo>();
    cout << "Dibujar(): \n"; x->Dibujar();

    auto y = make_unique<Rectangulo>(30, 5);
    cout << "Dibujar(30,5): \n"; y->Dibujar();

    cout << "Dibujar(40,2): \n"; x->Dibujar(40, 2);

    auto obj1 = make_unique<Rectangulo>(*x);
    obj1->Dibujar();
    
    auto obj2 = make_unique<Rectangulo>(*y);
    obj2->Dibujar();

    return 0;
}