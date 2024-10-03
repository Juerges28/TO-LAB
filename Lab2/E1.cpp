//. Implementar una calculadora con 3 clases en el lenguaje c++, donde la primera analizará la
// operación matemática (suma, resta….), la segunda administrará las operaciones matemáticas (el
// núcleo de la calculadora), y la tercera procesara la operación ingresada.
// El programa recibirá de entrada una cadena de texto con la operación a realizar
//(“10+37”) (“45+14-42”) (“1+2+3+4+5+6”)
// Como máximo el programa recibe 6 números a operar.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class OperationParser {
public:
    std::vector<int> getNumbers(const std::string& operation) {
        std::vector<int> numbers;
        std::string number;
        for (char c : operation) {
            if (isdigit(c)) {
                number += c;
            } else {
                if (!number.empty()) {
                    numbers.push_back(stoi(number));
                    number.clear();
                    if (numbers.size() == 6) {
                        cout << "Maximo de numeros alcanzado (6)" << endl;
                        break;
                    }
                }
            }
        }
        
        if (!number.empty()) {
            numbers.push_back(stoi(number));
        }
        return numbers;
    }

    std::vector<char> getOperators(const std::string& operation) {
        std::vector<char> operators;
        for (char c : operation) {
            if (c == '+' || c == '-') {
                operators.push_back(c);
            }
        }
        return operators;
    }
};

class CalculatorCore {
public:
    int calculate(const std::vector<int>& numbers, const std::vector<char>& operators) {
        if (numbers.empty()) return 0;
        int result = numbers[0];
        for (size_t i = 1; i < numbers.size(); ++i) {
            switch (operators[i - 1]) {
                case '+':
                    result += numbers[i];
                    break;
                case '-':
                    result -= numbers[i];
                    break;
            }
        }
        return result;
    }
};

class CalculatorProcessor {
public:
    void process(const std::string& input) {
        OperationParser parser;
        CalculatorCore calculator;
        std::vector<int> numbers = parser.getNumbers(input);
        std::vector<char> operators = parser.getOperators(input);

        int result = calculator.calculate(numbers, operators);

        std::cout << "Resultado: " << result << std::endl;
    }
};

int main() {
    CalculatorProcessor processor;
    std::string input;
    cout << "Ingrese operacion: ";
    std::getline(std::cin, input);
    processor.process(input);
    return 0;
}
