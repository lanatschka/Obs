#include "currentconditionsdisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject *weatherData)
{
    this->weatherData = weatherData;
    weatherData->registerObserver(this);

    this->setGeometry(100,100,200,200);
    this->setWindowTitle("Текущие значения");

    temp = new QLabel(this);
    temp->setText("Температура: НЕТ ДАННЫХ");
    temp->setGeometry(10,10,190,20);
    temp->setParent(this);

    hum = new QLabel(this);
    hum->setText("Влажность: НЕТ ДАННЫХ");
    hum->setGeometry(10,30,190,20);
    hum->setParent(this);

    press = new QLabel(this);
    press->setText("Давление: НЕТ ДАННЫХ");
    press->setGeometry(10,50,190,20);
    press->setParent(this);

}
void CurrentConditionsDisplay::update(float t, float h, float p){
    this -> temperature = t;
    this -> humidity = h;
    this -> pressure = p;
    this->display();
}
void CurrentConditionsDisplay::display(){
    temp->setText("Температура: " + QString::number(temperature));
    hum->setText("Влажность: " + QString::number(humidity));
    press->setText("Давление: " + QString::number(pressure));
   /* cout << "Current conditions:" << endl << "\t"
         << temperature << " C" << endl
         << "\t%" << humidity << endl
         << "\t" << pressure << " mm Hg" << endl;*/
}
