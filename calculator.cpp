#include "calculator.h"
#include "ui_calculator.h"
//TODO check for empty input fields and for number input
Calculator::Calculator(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->clearBtn->setVisible(false);
    this->clerResult();
}

Calculator::~Calculator()
{
    delete ui;
}
/**
 * @brief Calculator::calculateInKm
 * @return result(float);
 */
float Calculator::calculateInKm(){
    //Get input values
    QString distanceVal = ui->distance->text();
    QString fuelVal = ui->fuel->text();

    //Convert values
    float usedFuel = fuelVal.toFloat();
    float traveledD = distanceVal.toFloat();
    float result = usedFuel / traveledD * 100;
    return result;
}

/**
 * @brief Calculator::showResult
 * @describe: The method displays the result into the display box
 */
void Calculator::showResult() {
    float result = this->calculateInKm();
    ui->resultBox->display(result);
    ui->clearBtn->setVisible(true);
}
/**
 * @brief Calculator::clerResult
 * @describe: The method clears the input and display values to their initial state
 */
void Calculator::clerResult() {
    ui->fuel->clear();
    ui->distance->clear();
    ui->resultBox->display(0);
    ui->clearBtn->setVisible(false);
}
/**
 * @brief Calculator::on_calculateBtn_clicked
 * @describe: On click event the showResult() method is being invoked
 */
void Calculator::on_calculateBtn_clicked()
{
    this->showResult();

}
/**
 * @brief Calculator::on_clearBtn_clicked
 * @describe: On click event the clerResult() method is being invoked
 */
void Calculator::on_clearBtn_clicked()
{
    this->clerResult();
}
