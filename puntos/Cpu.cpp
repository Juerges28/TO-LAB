#include "Cpu.h"
#include <iostream>

void CPU::on()
{
    std::cout << "CPU encendida" << std::endl;
    memoria.encender();
    micro.encender();
    fuente.encender();
}

void CPU::off()
{
    std::cout << "CPU apagada" << std::endl;
    memoria.apagar();
    micro.apagar();
    fuente.apagar();
}
