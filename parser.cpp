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
    cout << "Sisesta esimene arv (π=pi): ";
    cin >> aDirty;
    try {
        int res1 = aDirty.compare("pi");
        if (res1 == 0) {
            a = 3.14159265358979323846;
        }else a = stod(aDirty);
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
        cout << "Sisesta teine arv (π=pi): ";
        cin >> bDirty;
        try {
            int res2 = bDirty.compare("pi");
            if (res2 == 0) {
                b = 3.14159265358979323846;
            }else b = stod(bDirty);
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
