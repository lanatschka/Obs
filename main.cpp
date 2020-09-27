#include <QCoreApplication>
#include "currentconditionsdisplay.h"
#include "weatherdata.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);



    WeatherData *weatherData = new WeatherData();

    CurrentConditionsDisplay *current = new CurrentConditionsDisplay(weatherData);

    weatherData->setMeasurementsChanged(80, 65, 30.4);

    return a.exec();
}
