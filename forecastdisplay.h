#ifndef FORECASTDISPLAY_H
#define FORECASTDISPLAY_H

#include "observer.h"
#include "displayelement.h"
#include "subject.h"

class ForecastDisplay : public Observer, public DisplayElement, public QWidget {
private:
    float currentPressure;
    float lastPressure;
    Subject *weatherData;

    QLabel *curPressure;
    QLabel *lPressure;
    QLabel *text;
    QLCDNumber *currentPressureLCD;
    QLCDNumber *lastPressureLCD;



public:
    ForecastDisplay(Subject *weatherData);
    virtual void update(float t, float h, float p);
    virtual void display();
};

#endif // FORECASTDISPLAY_H
