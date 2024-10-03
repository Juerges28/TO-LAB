//Crear un programa que indique si un número es un cubo perfecto (anstrong) o no, se dice que un 
//número es cubo perfecto si al sumar el cubo de sus dígitos dan el mismo número.
//Por ejemplo 153, cubos de sus dígitos: 1^3 + 5^3 + 3^3 = 153. -> es cubo perfecto

#include <iostream>
#include <math.h>
using namespace std;

int obtenerCubos(int n){
    int suma = 0;
    while(n>0) {
        int digito = n%10;
        suma = suma + (digito*digito*digito);
        n = n/10;
    }
    return suma;
}

void comprobar(int n){
    int y = n;
    int x = obtenerCubos(y);
    if (y == x)
        cout << "Es un cubo perfecto " << y << " = " << x << "\n";
    else
        cout << "NO es un cubo perfecto " << y << " != " << x << "\n";
}

int main(){
    int num[] = {27, 64, 121, 125, 153, 216, 371};
    for (int i = 0; i < sizeof(num)/sizeof(int); i++){
        comprobar(num[i]);
    }
    return 0;
}

// imprimir 10 numeroos seguidos
