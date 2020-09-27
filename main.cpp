#include <QApplication>
#include "currentconditionsdisplay.h"
#include "weatherdata.h"
#include <QThread>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    WeatherData *weatherData = new WeatherData();

    CurrentConditionsDisplay *current = new CurrentConditionsDisplay(weatherData);
    current->show();


    weatherData->setMeasurementsChanged(80, 65, 30.4);

    return a.exec();
}
