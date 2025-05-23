#include <iostream>
#include "calculator.h"
#include "parser.h"

#include <QApplication>
#include "mainwindow.h"

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow w;
    w.show();
    return app.exec();
}