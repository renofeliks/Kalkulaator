//
// Created by renof on 4/23/2025.
//

#include "parser.h"
#include <iostream>
using namespace std;

void Parser::showMenu() {
    cout << "\nVali tehe:\n"
        << "1 : Liitmine\n"
        << "2 : Lahutamine\n"
        << "3 : Korrutamine\n"
        << "4 : Jagamine\n"
        << "5 : Astendamine\n"
        << "6 : Ruutjuur\n"
        << "7 : Protsent\n"
        << "0 : Lõpeta\n";
}

int Parser::getChoice() {
    int choice;
    cout << "Sisesta valik: ";
    cin >> choice;
    return choice;
}

void Parser::getOperand(double &a, double &b, bool oneOperand) {
    cout << "Sisesta arv 1: ";
    cin >> a;
    if (!oneOperand) {
        cout << "Sisesta arv 2: ";
        cin >> b;
    }
}

void Parser::getOperandForPercentage(double &a, double &b) {
    cout << "Sisesta arv: ";
    cin >> a;
    cout << "Sisesta protsent: ";
    cin >> b;
}
