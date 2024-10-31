#include <iostream>

using namespace std;

template <typename Tipo> Tipo mayorDe(Tipo a, Tipo b) {
    return (a > b ? a : b);
}

int main(){
    char x = mayorDe<char>('j', 'a');
    int y = mayorDe<int>(9, 4);

    cout << "caracter mayor: " << x << endl;
    cout << "entero mayor: " << y << endl;
}