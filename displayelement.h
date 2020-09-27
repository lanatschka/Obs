#ifndef DISPLAYELEMENT_H
#define DISPLAYELEMENT_H
#include <QWidget>
#include <QLabel>

class DisplayElement

{

public:
    DisplayElement();
    virtual void display() = 0;
};

#endif // DISPLAYELEMENT_H
