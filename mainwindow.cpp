#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Ühenda nupp signaaliga
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->subtractButton, &QPushButton::clicked, this, &MainWindow::on_subtractButton_clicked);
    connect(ui->multiplyButton, &QPushButton::clicked, this, &MainWindow::on_multiplyButton_clicked);
    connect(ui->divideButton, &QPushButton::clicked, this, &MainWindow::on_divideButton_clicked);
    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::on_powerButton_clicked);
    connect(ui->sqrtButton, &QPushButton::clicked, this, &MainWindow::on_sqrtButton_clicked);
    connect(ui->percentButton, &QPushButton::clicked, this, &MainWindow::on_percentButton_clicked);
    connect(ui->clearButton, &QPushButton::clicked, this, &MainWindow::on_clearButton_clicked);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_addButton_clicked() {
    double a, b;
    if (!readTwoOperands(a, b)) return;
    showResult(calc.add(a, b));
}

void MainWindow::on_subtractButton_clicked() {
    double a, b;
    if (!readTwoOperands(a, b)) return;
    showResult(calc.subtract(a, b));
}

void MainWindow::on_multiplyButton_clicked() {
    double a, b;
    if (!readTwoOperands(a, b)) return;
    showResult(calc.multiply(a, b));
}

void MainWindow::on_divideButton_clicked() {
    double a, b;
    if (!readTwoOperands(a, b)) return;
    try {
        showResult(calc.divide(a, b));
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void MainWindow::on_powerButton_clicked() {
    double a, b;
    if (!readTwoOperands(a, b)) return;
    showResult(calc.power(a, b));
}

void MainWindow::on_sqrtButton_clicked() {
    double a;
    if (!readSingleOperand(a)) return;
    try {
        showResult(calc.squareRoot(a));
    } catch (const std::exception &e) {
        showError(e.what());
    }
}

void MainWindow::on_percentButton_clicked() {
    double a, b;
    if (!readTwoOperands(a, b)) return;
    showResult(calc.percentage(a, b));
}

void MainWindow::on_clearButton_clicked() {
    ui->input1LineEdit->clear();
    ui->input2LineEdit->clear();
    ui->resultLabel->setText("Vastus:");
}

// Abimeetodid

bool MainWindow::readTwoOperands(double &a, double &b) {
    bool ok1, ok2;
    a = ui->input1LineEdit->text().toDouble(&ok1);
    b = ui->input2LineEdit->text().toDouble(&ok2);
    if (!ok1 || !ok2) {
        showError("Vigane sisend!");
        return false;
    }
    return true;
}

bool MainWindow::readSingleOperand(double &a) {
    bool ok;
    a = ui->input1LineEdit->text().toDouble(&ok);
    if (!ok) {
        showError("Vigane sisend!");
        return false;
    }
    ui->input2LineEdit->clear();
    return true;
}

void MainWindow::showResult(double result) {
    ui->resultLabel->setText("Vastus: " + QString::number(result));
}

void MainWindow::showError(const QString &message) {
    QMessageBox::critical(this, "Viga", message);
}

