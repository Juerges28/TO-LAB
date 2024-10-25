#include <iostream>
#include <memory>
using namespace std;
#include "time.h"

int main()
{
    auto t1 = make_unique<Time>(10, 50, 59); // instancia 1 - constructor valores defecto
    t1->print();           // 10:50:59
    auto t2 = make_unique<Time>();              // instancia 2
    t2->print();           // 00:00:00
    t2->setTime(6, 39, 9);
    t2->print();           // 06:39:09

    if (t1->equals(*t2))
        cout << "Dos objetos son IGUALES\n";
    else
        cout << "Dos objetos NO son IGUALES\n";

    return 0;
}