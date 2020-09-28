#include "forecastdisplay.h"

ForecastDisplay::ForecastDisplay(Subject *weatherData) {
    currentPressure = 29.92;

    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(100, 100, 200, 200);
    this->setWindowTitle("Текущие значения");

    curPressure = new QLabel(this);
    curPressure->setText("Текущее давление:");
    curPressure->setGeometry(10,10, 90, 30);
    curPressure->setParent(this);

    currentPressureLCD = new QLCDNumber(this);
    currentPressureLCD->setGeometry(200, 10, 40, 30);
    currentPressureLCD->setPalette(Qt::green);
    currentPressureLCD->setParent(this);


    lPressure = new QLabel(this);
    lPressure->setText("Предыдущее давление:");
    lPressure->setGeometry(10,10, 90, 30);
    lPressure->setParent(this);

    lastPressureLCD = new QLCDNumber(this);
    lastPressureLCD->setGeometry(200, 50, 40, 30);
    lastPressureLCD->setPalette(Qt::green);
    lastPressureLCD->setParent(this);


}

void ForecastDisplay::update(float t, float h, float p) {
    lastPressure = currentPressure;
    currentPressure = p;
    this->display();
}

void ForecastDisplay::display() {

   currentPressureLCD->display(QString::number(currentPressure));
   lastPressureLCD->display(QString::number( lastPressure));
    /*cout << "Forecast: ";
    if (currentPressure > lastPressure) {
        cout << "Improving weather on the way!" << endl;
    }
    else if (currentPressure == lastPressure) {
        cout << "More of the same" << endl;
    }
    else if (currentPressure < lastPressure) {
        cout << "Watch out for cooler, rainy weather" << endl;
    }*/
}
