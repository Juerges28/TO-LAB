#include "CFactory1.h"
#include "CFactory2.h"
#include "Cliente.h"

int main() {
    std::cout << "Cliente: Tipo 1\n";
    CFactory1* factory1 = new CFactory1();
    Cliente(*factory1);
    delete factory1;

    std::cout << "\nCliente: Tipo 2\n";
    CFactory2* factory2 = new CFactory2();
    Cliente(*factory2);
    delete factory2;

    return 0;
}
