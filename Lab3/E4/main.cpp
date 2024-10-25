#include "BinaryExpressionTree.h"

int precedencia(char op) {
    if (op == '+') return 1;
    if (op == '*') return 2;
    return 0;
}

string infijaAPostfija(const string& expresion) {
    stack<char> operadores;
    stringstream salida;
    for (size_t i = 0; i < expresion.length(); ++i) {
        char c = expresion[i];
        if (isdigit(c)) {
            while (i < expresion.length() && isdigit(expresion[i])) {
                salida << expresion[i++];
            }
            salida << ' ';
            --i;
        } else if (c == '+' || c == '*') {
            while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(c)) {
                salida << operadores.top() << ' ';
                operadores.pop();
            }
            operadores.push(c);
        }
    }
    while (!operadores.empty()) {
        salida << operadores.top() << ' ';
        operadores.pop();
    }
    return salida.str();
}

int main() {
    string expresion = "3+4+2*7+10*2";  // 3 + 4 + (2 * 7) + (10 * 2) = 3 + 4 + 14 + 20 = 41
    string postfija = infijaAPostfija(expresion);
    cout << "Expresion postfija: " << postfija << endl;

    BinaryExpressionTree arbol;
    arbol.construirArbol(postfija);
    cout << "Resultado de la expresion: " << arbol.evaluar() << endl;

    return 0;
}