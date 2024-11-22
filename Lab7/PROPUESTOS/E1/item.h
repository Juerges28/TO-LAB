#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class item {
public:
    virtual string GetName() { return ""; }
    virtual float GetPrice() { return 0.0; }
    virtual void GetConfiguration() {}
    virtual ~item() = default;
};

#endif // ITEM_H
