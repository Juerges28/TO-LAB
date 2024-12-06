#include "Application.h"

Application::Application(const GUIFactory& factory, int os) {
    Button* button = factory.CreateButton();
    button->Draw();
    delete button; // Limpieza de memoria
}
