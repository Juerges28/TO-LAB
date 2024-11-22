#ifndef LAPTOP_H
#define LAPTOP_H

#include <vector>
#include "item.h"

class laptop {
public:
    void AddParts(item *item) { mLaptopParts.push_back(item); }

    float GetCost() {
        float cost = 0.0;
        for (auto part : mLaptopParts) {
            cost += part->GetPrice();
        }
        return cost;
    }

    void GetConfiguration() {
        for (auto part : mLaptopParts) {
            cout << part->GetName() << ": ";
            part->GetConfiguration();
        }
    }

    ~laptop() {
        for (auto part : mLaptopParts) {
            delete part;
        }
    }

private:
    vector<item*> mLaptopParts;
};

#endif // LAPTOP_H
