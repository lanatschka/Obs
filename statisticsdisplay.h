#ifndef STATISTICSDISPLAY_H
#define STATISTICSDISPLAY_H

#include "observer.h"
#include "displayelement.h"
#include "subject.h"

class StatisticsDisplay : public Observer, public DisplayElement, public QWidget {
private:
    float maxTemp;
    float minTemp;
    float tempSum;
    int numReadings;
    Subject *weatherData;
public:
    StatisticsDisplay(Subject *weatherData);
    virtual void update(float t, float h, float p);
    virtual void display();

signals:

public slots:
};

#endif // STATISTICSDISPLAY_H
