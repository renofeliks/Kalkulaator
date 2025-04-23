//
// Created by renof on 4/23/2025.
//

#ifndef KALKULAATOR_PARSER_H
#define KALKULAATOR_PARSER_H

class Parser {
public:
    static void showMenu();
    static int getChoice();
    static void getOperand(double &a, double &b, bool oneOperand = false);
    static void getOperandForPercentage(double &a, double &b);
};

#endif //KALKULAATOR_PARSER_H
