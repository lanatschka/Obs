#include "forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
    currentPressure = 29.92;

    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(100, 400, 250, 200);
    this->setWindowTitle("Текущие значения");

    curPressure = new QLabel(this);
    curPressure->setText("Текущее давление:");
    curPressure->setGeometry(10,10, 150, 30);
    curPressure->setParent(this);

    currentPressureLCD = new QLCDNumber(this);
    currentPressureLCD->setGeometry(200, 10, 40, 30);
    currentPressureLCD->setPalette(Qt::green);
    currentPressureLCD->setParent(this);


    lPressure = new QLabel(this);
    lPressure->setText("Предшествующее давление:");
    lPressure->setGeometry(10,40, 150, 30);
    lPressure->setParent(this);

    lastPressureLCD = new QLCDNumber(this);
    lastPressureLCD->setGeometry(200, 50, 40, 30);
    lastPressureLCD->setPalette(Qt::green);
    lastPressureLCD->setParent(this);

    text = new QLabel(this);
    text->setText("Прогноз: ");
    text->setGeometry(10,70, 400, 30);
    text->setParent(this);

this->show();
}

void ForecastDisplay::update(float t, float h, float p) {
    lastPressure = currentPressure;
    currentPressure = p;
    this->display();
}

void ForecastDisplay::display() {

    currentPressureLCD->display(QString::number(currentPressure));
    lastPressureLCD->display(QString::number(lastPressure));

    /*cout << "Forecast: ";*/
    if (currentPressure > lastPressure) {
        text->setText("Improving weather on the way!");
        /*cout << "Improving weather on the way!" << endl;*/

    }
    else if (currentPressure == lastPressure) {
        text->setText("More of the same");
       /* cout <<"More of the same" << endl;*/

    }
    else if (currentPressure < lastPressure) {
        text->setText("Watch out for cooler, rainy weather");
        /*cout << "Watch out for cooler, rainy weather" << endl;*/
    }
}
