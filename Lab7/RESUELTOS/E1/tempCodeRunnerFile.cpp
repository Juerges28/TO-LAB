#include "laptopBuilder.h"

int main() {
    laptopBuilder builder;

    // Crear la primera configuración
    laptop *basicLaptop = builder.BuildBasicLaptop();
    cout << "Laptop Configuracion Basica:" << endl;
    basicLaptop->GetConfiguration();
    cout << "Total Costo: $" << basicLaptop->GetCost() << endl;

    cout << "\n----------------------------------\n";

    // Crear la segunda configuración
    laptop *highEndLaptop = builder.BuildHighEndLaptop();
    cout << "Laptop Configuracion High-End:" << endl;
    highEndLaptop->GetConfiguration();
    cout << "Total Costo: $" << highEndLaptop->GetCost() << endl;

    delete basicLaptop;
    delete highEndLaptop;

    return 0;
}
