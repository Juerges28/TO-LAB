#include <iostream>
#include "FooManager.h"

using namespace std;

int main() {
    cout << "Patron singleton" << endl;

    FooManager::Create();

    FooManager* pMyFoo1 = FooManager::GetInst();
    if (pMyFoo1 != 0) {
        cout << "Primera instancia Inst sample data: " << pMyFoo1->GetSampleData() << endl;
        cout << pMyFoo1 << endl;
    }

    FooManager* pMyFoo2 = FooManager::GetInst();
    if (pMyFoo2 != 0) {
        cout << "Segunda instancia Inst sample data: " << pMyFoo2->GetSampleData() << endl;
        cout << pMyFoo2 << endl;
    }

    return 0;
}
