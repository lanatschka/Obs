#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>
using namespace std;

class Observer
{
public:
    Observer();
    virtual void update(float t, float h, float p) = 0;
};

#endif // OBSERVER_H
