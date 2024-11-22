#ifndef LAPTOPBUILDER_H
#define LAPTOPBUILDER_H

#include "laptop.h"
#include "processor.h"
#include "drive.h"
#include "display.h"

class laptopBuilder {
public:
    laptop *BuildBasicLaptop() {
        laptop *lap = new laptop();
        lap->AddParts(new IntelI5());
        lap->AddParts(new HDD());
        lap->AddParts(new Normal());
        return lap;
    }

    laptop *BuildHighEndLaptop() {
        laptop *lap = new laptop();
        lap->AddParts(new IntelI7());
        lap->AddParts(new SDD());
        lap->AddParts(new Normal());
        return lap;
    }
};

#endif // LAPTOPBUILDER_H
