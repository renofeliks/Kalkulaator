#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_subtractButton_clicked();
    void on_multiplyButton_clicked();
    void on_divideButton_clicked();
    void on_powerButton_clicked();
    void on_sqrtButton_clicked();
    void on_percentButton_clicked();
    void on_clearButton_clicked();

private:
    bool readTwoOperands(double &a, double &b);
    bool readSingleOperand(double &a);
    void showResult(double result);
    void showError(const QString &message);

    Ui::MainWindow *ui;
    Calculator calc;
};

#endif // MAINWINDOW_H