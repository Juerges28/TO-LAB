#include <iostream>
#include "GUIFactory.h"
#include "Application.h"

int main() {
    // Cliente Windows
    std::cout << "Cliente: Windows" << std::endl;
    WinFactory winFactory;
    Application(winFactory, 1);

    std::cout << std::endl;

    // Cliente Mac
    std::cout << "Cliente: Mac" << std::endl;
    MacFactory macFactory;
    Application(macFactory, 2);

    std::cout << std::endl;

    // Cliente Linux
    std::cout << "Cliente: Linux" << std::endl;
    LinuxFactory linuxFactory;
    Application(linuxFactory, 3);

    return 0;
}
