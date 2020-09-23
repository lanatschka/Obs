#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H
#include "observer.h"
#include "displayelement.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement
{
private:
    float temperature;
    float humidity;
    float pressure;
public:
    CurrentConditionsDisplay();
    virtual void update(float t, float h, float p);
    virtual void display();

};

#endif // CURRENTCONDITIONSDISPLAY_H
