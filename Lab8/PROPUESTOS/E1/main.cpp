#include <iostream>
#include <string>
#include "RecetaFactory.cpp"
using namespace std;

int main() {
    int opcion;

    while (true) {
        cout << "\n--- Selecciona un tipo de cocina para tu receta ---" << endl;
        cout << "1. Italiana\n2. Mexicana\n3. Japonesa\n0. Salir" << endl;
        cout << "Opción: ";
        cin >> opcion;

        if (opcion == 0) {
            cout << "Saliendo..." << endl;
            break;
        }

        Receta *receta = RecetaFactory::crearReceta(opcion);
        if (receta) {
            receta->mostrarDetalles();
            delete receta;
        } else {
            cout << "Opción inválida. Intenta nuevamente." << endl;
        }
    }

    return 0;
}
