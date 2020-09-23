#include "currentconditionsdisplay.h"

CurrentConditionsDisplay::CurrentConditionsDisplay()
{

}
void CurrentConditionsDisplay::update(float t, float h, float p){
    this -> temperature = t;
    this -> humidity = h;
    this -> pressure = p;
}
void CurrentConditionsDisplay::display(){
    cout <<"Current condition:"<< endl <<"\t"
        << temperature <<"˚C" << endl
        << "%" << humidity << endl
        << pressure << "mm Hg" << endl;
}
