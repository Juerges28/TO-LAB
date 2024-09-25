#include <iostream>

using namespace std;

void encontrarDivisores(int N){
    int divisores = 0;
    for(int i=1; i<=N; i++){
        if (N%i==0){
            cout << i << "; ";
            divisores++;
        };
    };
    cout << endl;
    cout << "Cantidad de divisores: " << divisores;
};

int main(){
    int N;
    cout << "Ingrese el numero: ";
    cin >> N;
    encontrarDivisores(N);
    return 0;
};