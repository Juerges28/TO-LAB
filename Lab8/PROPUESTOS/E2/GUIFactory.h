#ifndef GUIFACTORY_H
#define GUIFACTORY_H

#include "Button.h"
#include "CheckBox.h"

// Clase abstracta GUIFactory
class GUIFactory {
public:
    virtual Button* CreateButton() const = 0;
    virtual CheckBox* CreateCheckBox() const = 0;
    virtual ~GUIFactory() = default;
};

// Fábricas concretas
class WinFactory : public GUIFactory {
public:
    Button* CreateButton() const override;
    CheckBox* CreateCheckBox() const override;
};

class MacFactory : public GUIFactory {
public:
    Button* CreateButton() const override;
    CheckBox* CreateCheckBox() const override;
};

class LinuxFactory : public GUIFactory {
public:
    Button* CreateButton() const override;
    CheckBox* CreateCheckBox() const override;
};

#endif // GUIFACTORY_H
