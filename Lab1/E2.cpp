#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Persona {
    int edad;
    int gradoInstruccion; 
};

int generarAleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}

double calcularPromedioEdad(Persona personas[], int cantidad) {
    int sumaEdades = 0;
    for (int i = 0; i < cantidad; ++i) {
        sumaEdades += personas[i].edad;
    }
    return static_cast<double>(sumaEdades) / cantidad;
}

int obtenerMayorEdad(Persona personas[], int cantidad) {
    int mayorEdad = personas[0].edad;
    for (int i = 1; i < cantidad; ++i) {
        if (personas[i].edad > mayorEdad) {
            mayorEdad = personas[i].edad;
        }
    }
    return mayorEdad;
}

void contarPorGradoInstruccion(Persona personas[], int cantidad, int &primaria, int &secundaria, int &superior) {
    primaria = secundaria = superior = 0;
    for (int i = 0; i < cantidad; ++i) {
        if (personas[i].gradoInstruccion == 1) {
            ++primaria;
        } else if (personas[i].gradoInstruccion == 2) {
            ++secundaria;
        } else if (personas[i].gradoInstruccion == 3) {
            ++superior;
        }
    }
}

int main() {
    srand(time(0));

    int N;
    cout << "Ingrese la cantidad de personas a encuestar: ";
    cin >> N;

    Persona personas[N];

    for (int i = 0; i < N; ++i) {
        personas[i].edad = generarAleatorio(15, 80);  
        personas[i].gradoInstruccion = generarAleatorio(1, 3);  
    }

    // a) El promedio de edades
    double promedioEdad = calcularPromedioEdad(personas, N);
    cout << "El promedio de edades es: " << promedioEdad << endl;

    // b) La mayor edad
    int mayorEdad = obtenerMayorEdad(personas, N);
    cout << "La mayor edad es: " << mayorEdad << endl;

    // c, d, e) Cantidad de personas por grado de instrucción
    int primaria, secundaria, superior;
    contarPorGradoInstruccion(personas, N, primaria, secundaria, superior);

    cout << "Cantidad de personas con instrucción Primaria: " << primaria << endl;
    cout << "Cantidad de personas con instrucción Secundaria: " << secundaria << endl;
    cout << "Cantidad de personas con instrucción Superior: " << superior << endl;

    return 0;
}
