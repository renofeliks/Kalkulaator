#include <iostream>
#include "calculator.h"
#include "parser.h"
using namespace std;

int main() {
    Calculator calc;
    int choice;
    double a, b;

    while (choice != 0) {
        Parser::showMenu();
        choice = Parser::getChoice();

        try {
            switch (choice) {
                case 1:
                    Parser::getOperand(a, b);
                    cout << a << " + " << b << " = " << calc.add(a, b) << endl;
                    break;
                case 2:
                    Parser::getOperand(a, b);
                    cout << a << " - " << b << " = " << calc.subtract(a, b) << endl;
                    break;
                case 3:
                    Parser::getOperand(a, b);
                    cout << a << " * " << b << " = " << calc.multiply(a, b) << endl;
                    break;
                case 4:
                    Parser::getOperand(a, b);
                    cout << a << " / " << b << " = " << calc.divide(a, b) << endl;
                    break;
                case 5:
                    Parser::getOperand(a, b);
                    cout << a << " ** " << b << " = " << calc.power(a, b) << endl;
                    break;
                case 6:
                    Parser::getOperand(a, b, true);
                    cout << "Ruutjuur " << a << "-st on " << calc.squareRoot(a) << endl;
                    break;
                case 7:
                    Parser::getOperandForPercentage(a, b);
                    cout << a << "-st " << b << "% on " << calc.percentage(a, b) << endl;
                    break;
                case 0:
                    cout << "Lõpetan!" << endl;
                    break;
                default:
                    cout << "Pole sobiv valik!" << endl;
            }
        } catch (const exception &e) {
            cerr << "Viga: " << e.what() << endl;
        }
    }
    return 0;
}