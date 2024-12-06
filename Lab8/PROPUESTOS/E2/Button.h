#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>

// Clase abstracta Button
class Button {
public:
    virtual void Draw() const = 0;
    virtual ~Button() = default;
};

// Productos concretos
class WinButton : public Button {
public:
    void Draw() const override;
};

class MacButton : public Button {
public:
    void Draw() const override;
};

class LinuxButton : public Button {
public:
    void Draw() const override;
};

#endif // BUTTON_H
