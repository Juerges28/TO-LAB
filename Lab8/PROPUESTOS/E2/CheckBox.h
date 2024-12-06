#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <iostream>

// Clase abstracta CheckBox
class CheckBox {
public:
    virtual void Draw() const = 0;
    virtual ~CheckBox() = default;
};

// Productos concretos
class WinCheckBox : public CheckBox {
public:
    void Draw() const override;
};

class MacCheckBox : public CheckBox {
public:
    void Draw() const override;
};

class LinuxCheckBox : public CheckBox {
public:
    void Draw() const override;
};

#endif // CHECKBOX_H
