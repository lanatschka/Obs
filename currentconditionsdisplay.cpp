#include "currentconditionsdisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay(Subject *weatherData)
{
    this->weatherData = weatherData;
    weatherData->registerObserver(this);
}
void CurrentConditionsDisplay::update(float t, float h, float p){
    this -> temperature = t;
    this -> humidity = h;
    this -> pressure = p;
    this->display();
}
void CurrentConditionsDisplay::display(){
    cout << "Current conditions:" << endl << "\t"
         << temperature << "°C" << endl
         << "\t%" << humidity << endl
         << "\t" << pressure << " mm Hg" << endl;
}
