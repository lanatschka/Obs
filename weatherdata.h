#ifndef WEATHERDATA_H
#define WEATHERDATA_H

#include "subject.h"
#include <QObject>
#include <QList>
#include <QTimer>

class WeatherData : public QObject, public Subject {
    Q_OBJECT
private:
    QList<Observer*> *observers;
    float temperature;
    float humidity;
    float pressure;
    QTimer *timer;
public:
    WeatherData();
    virtual ~WeatherData();
    virtual void registerObserver(Observer *o);
    virtual void removeObserver(Observer *o);
    virtual void notifyObserver();
    void setMeasurementsChanged(float t, float h, float p);
    void measurementsChanged();
public slots:
    void onTimer();
};

#endif // WEATHERDATA_H
