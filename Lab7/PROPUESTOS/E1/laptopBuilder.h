#ifndef LAPTOPBUILDER_H
#define LAPTOPBUILDER_H

#include "laptop.h"
#include "processor.h"
#include "drive.h"
#include "display.h"
#include "other.h"
#include "printer.h"

class laptopBuilder
{
public:
    laptop *BuildOfficeLaptop()
    {
        laptop *lap = new laptop();
        lap->AddParts(new IntelI5());
        lap->AddParts(new Plasma());
        lap->AddParts(new HDD());
        lap->AddParts(new BasicPrinter());
        lap->AddParts(new Color("Black"));
        lap->AddParts(new Brand("Dell"));
        return lap;
    }

    laptop *BuildGamingLaptop()
    {
        laptop *lap = new laptop();
        lap->AddParts(new AMD());
        lap->AddParts(new Normal());
        lap->AddParts(new SDD());
        lap->AddParts(new AdvancedPrinter());
        lap->AddParts(new Color("Red"));
        lap->AddParts(new Brand("Asus"));
        return lap;
    }
};

#endif // LAPTOPBUILDER_H
