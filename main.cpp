#include <QApplication>
#include "weatherdata.h"
#include "currentconditionsdisplay.h"
#include "statisticsdisplay.h"
#include "forecastdisplay.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WeatherData *weatherData = new WeatherData();

    CurrentConditionsDisplay *current = new CurrentConditionsDisplay(weatherData);
    StatisticsDisplay *stat = new StatisticsDisplay(weatherData);
    ForecastDisplay *forecast = new ForecastDisplay(weatherData);

    return a.exec();
}
