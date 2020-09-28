#include "statisticsdisplay.h"

StatisticsDisplay::StatisticsDisplay(Subject *weatherData) {
    maxTemp = 0.0;
    minTemp = 200.0;
    tempSum = 0.0;
    numReadings = 0;

    this->weatherData = weatherData;
    weatherData->registerObserver(this);
    this->setGeometry(400, 100, 250, 200);
    this->setWindowTitle("Показатели температуры");

    maxtem = new QLabel(this);
    maxtem->setText("Максимум:");
    maxtem->setGeometry(10,10, 100, 30);
    maxtem->setParent(this);
    maxtemLCD = new QLCDNumber(this);
    maxtemLCD->setGeometry(160, 10, 40, 30);
    maxtemLCD->setPalette(Qt::green);
    maxtemLCD->setParent(this);

    mintem = new QLabel(this);
    mintem->setText("Минимум:");
    mintem->setGeometry(10,60, 100, 30);
    mintem->setParent(this);
    mintemLCD = new QLCDNumber(this);
    mintemLCD->setGeometry(160, 60, 40, 30);
    mintemLCD->setPalette(Qt::green);
    mintemLCD->setParent(this);

    temps = new QLabel(this);
    temps->setText("Среднее значение:");
    temps->setGeometry(10,120, 100, 30);
    temps->setParent(this);
    tempsLCD = new QLCDNumber(this);
    tempsLCD->setGeometry(160, 110, 40, 30);
    tempsLCD->setPalette(Qt::green);
    tempsLCD->setParent(this);

     this->show();
}

void StatisticsDisplay::update(float t, float h, float p) {
    tempSum += t;
    numReadings++;

    if (t > maxTemp) {
        maxTemp = t;
    }

    if (t < minTemp) {
        minTemp = t;
    }
    this->display();
}

void StatisticsDisplay::display() {
    maxtemLCD->display(QString::number(maxTemp));
    mintemLCD->display(QString::number(minTemp));
    tempsLCD->display(QString::number(tempSum / numReadings));
    /*cout << "Avg/Max/Min temperature = " << tempSum / numReadings << " / "
         << maxTemp << " / " << minTemp << endl;*/
}
