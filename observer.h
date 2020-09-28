#ifndef OBSERVER_H
#define OBSERVER_H

#include <iostream>
#include <QObject>
using namespace std;

class Observer
{
public:
    Observer();
    virtual void update(float t, float h, float p) = 0;
public slots:
    void upd();
};

#endif // OBSERVER_H
