#ifndef CPU_H
#define CPU_H
#include <iostream>
#include "fuente.h"
#include "memoria.h"
#include "micro.h"

class CPU
{
    private:
        Memoria memoria;
        Micro micro;
        Fuente fuente;
    public:
        void on();
        void off();
};

#endif // CPU_H