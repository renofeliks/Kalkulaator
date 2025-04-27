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
    string aDirty, bDirty;
    cout << "Sisesta arv 1: ";
    //cin >> a;
    cin >> aDirty;
    try {
        a = stod(aDirty);
    } catch (const invalid_argument &e) {
        cout << "Vale sisend! Proovi uuesti.\n";
        getOperand(a, b, oneOperand);
        return;
    } catch (const out_of_range &e) {
        cout << "Sisestatud arv on liiga suur! Proovi uuesti.\n";
        getOperand(a, b, oneOperand);
        return;
    }
    if (!oneOperand) {
        cout << "Sisesta arv 2: ";
        //cin >> b;
        cin >> bDirty;
        try {
            b = stod(bDirty);
        } catch (const invalid_argument &e) {
            cout << "Vale sisend! Proovi uuesti.\n";
            getOperand(a, b, oneOperand);
            return;
        } catch (const out_of_range &e) {
            cout << "Sisestatud arv on liiga suur! Proovi uuesti.\n";
            getOperand(a, b, oneOperand);
            return;
        }
    }
}

void Parser::getOperandForPercentage(double &a, double &b) {
    string aDirty, bDirty;
    cout << "Sisesta arv: ";
    cin >> aDirty;
    try {
        a = stod(aDirty);
    } catch (const invalid_argument &e) {
        cout << "Vale sisend! Proovi uuesti.\n";
        getOperandForPercentage(a, b);
        return;
    } catch (const out_of_range &e) {
        cout << "Sisestatud arv on liiga suur! Proovi uuesti.\n";
        getOperandForPercentage(a, b);
        return;
    }
    cout << "Sisesta protsent: ";
    cin >> bDirty;
        try {
            b = stod(bDirty);
        } catch (const invalid_argument &e) {
            cout << "Vale sisend! Proovi uuesti.\n";
            getOperandForPercentage(a, b);
            return;
        } catch (const out_of_range &e) {
            cout << "Sisestatud arv on liiga suur! Proovi uuesti.\n";
            getOperandForPercentage(a, b);
            return;
        }
}
