#include "Persona.h"
#include <iostream>
#include <string>
using namespace std;

Persona::Persona(string nombre, int edad)
{
    this->nombre = nombre;
    this->edad = edad;
}
Persona::~Persona()
{
    cout << "Se destruyo el objeto" << endl;
}

string Persona::getNombre()
{
    return nombre;
}

int Persona::getEdad()
{
    return edad;
}
