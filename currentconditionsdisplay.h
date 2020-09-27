#ifndef CURRENTCONDITIONSDISPLAY_H
#define CURRENTCONDITIONSDISPLAY_H


#include "observer.h"
#include "displayelement.h"
#include "subject.h"

class CurrentConditionsDisplay : public Observer, public DisplayElement, public QWidget
{
private:
    float temperature;
    float humidity;
    float pressure;
    Subject *weatherData;
    QLabel *temp;
    QLabel *hum;
    QLabel *press;
public:
    CurrentConditionsDisplay(Subject *weatherData);
    virtual void update(float t, float h, float p);
    virtual void display();

};

#endif // CURRENTCONDITIONSDISPLAY_H
