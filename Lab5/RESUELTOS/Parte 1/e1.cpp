#include <iostream>

using namespace std;

template <typename mitipo>
mitipo aritmetica(mitipo x, mitipo y){
    return x + y;
}

int main(){
    cout << aritmetica(10, 45) << endl;
    cout << aritmetica(3.45, 8.10) << endl;
    cout << aritmetica(0.14f, 0.147f) << endl;
    return 0;
}