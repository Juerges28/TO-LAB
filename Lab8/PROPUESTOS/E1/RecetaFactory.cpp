#include <iostream>
#include "Receta.cpp"
using namespace std;

class RecetaFactory {
public:
    static Receta *crearReceta(int tipo) {
        switch (tipo) {
            case 1:
                return new RecetaItaliana();
            case 2:
                return new RecetaMexicana();
            case 3:
                return new RecetaJaponesa();
            default:
                return nullptr;
        }
    }
};
