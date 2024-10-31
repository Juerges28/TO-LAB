#include "Persona.h"
#include <iostream>

using namespace std;

inline int max(int a, int b) { return (a > b) ? a : b; }

int main(){
    Persona per1 = Persona("Jorge",  21);
    Persona per2 = Persona("Pepito", 22);
    cout << per1.getNombre() << " tiene " << per1.getEdad() << " años" << endl;
    cout << per2.getNombre() << " tiene " << per2.getEdad() << " años" << endl;

    //comparar edades con template
    //cout << "La edad mayor es: " << per1.max(per1.getEdad(), per2.getEdad()) << endl; 
    //comparar edades con funcion inline
    cout << "La edad mayor es: " << max(per1.getEdad(), per2.getEdad()) << endl;  
};
