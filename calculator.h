#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QWidget>
#include <QString>
#include <QLCDNumber>
#include <QTextStream>
#include <QDebug>

namespace Ui {
class Calculator;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void on_calculateBtn_clicked();

    void on_clearBtn_clicked();

private:
    Ui::Calculator *ui;
    float calculateInKm();
    float calculateInMpg();
    void clerResult();
    void showResult();
};

#endif // CALCULATOR_H
