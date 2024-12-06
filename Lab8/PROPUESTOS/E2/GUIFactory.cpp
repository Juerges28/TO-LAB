#include "GUIFactory.h"

// Implementaciones de WinFactory
Button* WinFactory::CreateButton() const {
    return new WinButton();
}

CheckBox* WinFactory::CreateCheckBox() const {
    return new WinCheckBox();
}

// Implementaciones de MacFactory
Button* MacFactory::CreateButton() const {
    return new MacButton();
}

CheckBox* MacFactory::CreateCheckBox() const {
    return new MacCheckBox();
}

// Implementaciones de LinuxFactory
Button* LinuxFactory::CreateButton() const {
    return new LinuxButton();
}

CheckBox* LinuxFactory::CreateCheckBox() const {
    return new LinuxCheckBox();
}
