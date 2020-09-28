#include "weatherdata.h"

WeatherData::WeatherData() : Subject(), QObject() {
    observers = new QList<Observer*>();

    timer = new QTimer();
    timer->setInterval(3000);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
    timer->start();
}

WeatherData::~WeatherData() {
    delete timer;
}

void WeatherData::registerObserver(Observer *o) {
    observers->append(o);
}

void WeatherData::removeObserver(Observer *o) {
    // поиск наблюдателя
    int i = observers->indexOf(o);
    //удаление
    if (i > 0) {
        observers->removeAt(i);
    }
}
void WeatherData::notifyObserver() {
    for (int i = 0; i < observers->size(); i++)   {
        Observer *observer = observers->at(i);
        observer->update(temperature, humidity, pressure);
    }
}
void WeatherData::setMeasurementsChanged(float t, float h, float p) {
    this->temperature = t;
    this->humidity = h;
    this->pressure = p;
    this->notifyObserver();
}

void WeatherData::measurementsChanged() {
    notifyObserver();
}

void WeatherData::onTimer() {
    int t = (qrand() % 70) - 35;
    int h = qrand() % 100;
    int p = (qrand() % 100) + 700;
    setMeasurementsChanged(t, h, p);
}
