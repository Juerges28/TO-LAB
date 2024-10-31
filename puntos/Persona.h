#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    int edad;
public:
    Persona(string nombre, int edad);
    string getNombre();
    int getEdad();
    template <typename T> 
    T max(T a, T b){
        return a > b ? a : b;
    }
    ~Persona();
};

#endif // PERSONA_H
