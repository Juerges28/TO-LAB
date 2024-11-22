#include "laptopBuilder.h"
#include "printer.h"
#include "other.h"

int main() {
    laptopBuilder builder;

    // Crear laptop para oficina
    laptop *officeLaptop = builder.BuildOfficeLaptop();
    cout << "Office Laptop Configuration:" << endl;
    officeLaptop->GetConfiguration();
    cout << "Total Cost: $" << officeLaptop->GetCost() << endl;

    cout << "\n----------------------------------\n";

    // Crear laptop para gaming
    laptop *gamingLaptop = builder.BuildGamingLaptop();
    cout << "Gaming Laptop Configuration:" << endl;
    gamingLaptop->GetConfiguration();
    cout << "Total Cost: $" << gamingLaptop->GetCost() << endl;

    // Limpiar memoria
    delete officeLaptop;
    delete gamingLaptop;

    return 0;
}
