//Contar los números impares y menores de 20 de un vector de números enteros generados de forma
//aleatoria (la solución puede usar el método std :: count_if ) 

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    vector<int> numbers(100);
    generate(numbers.begin(), numbers.end(), []() { return rand() % 100; });

    int count = count_if(numbers.begin(), numbers.end(), [](int num) {
        return num < 20 && num % 2 != 0;
    });

    for(int i=0; i<numbers.size(); i++) {
        cout << numbers[i] << " ";
    }

    cout << "Cuenta de numeros impares y menores a 20: " << count << endl;

    return 0;
}