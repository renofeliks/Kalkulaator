//
// Created by renof on 4/23/2025.
//

#include "calculator.h"
#include <cmath>
#include <stdexcept>
using namespace std;

double Calculator::add(double a, double b) {
    return a + b;
}

double Calculator::subtract(double a, double b) {
    return a - b;
}

double Calculator::multiply(double a, double b) {
    return a * b;
}

double Calculator::divide(double a, double b) {
    if (b == 0) throw runtime_error("Nulliga ei saa jagada!");
    return a / b;
}

double Calculator::power(double a, double b) {
    return pow(a, b);
}

double Calculator::squareRoot(double a) {
    if (a < 0) throw runtime_error("Negatiivsest arvust ei saa ruutjuurt võtta!");
    return sqrt(a);
}

double Calculator::percentage(double a, double percentage) {
    return (a * percentage) / 100.0;
}
