#include "statisticsdisplay.h"

StatisticsDisplay::StatisticsDisplay(Subject *weatherData) {
    maxTemp = 0.0;
    minTemp = 200.0;
    tempSum = 0.0;
    numReadings = 0;

    this->weatherData = weatherData;
    weatherData->registerObserver(this);
}

void StatisticsDisplay::update(float t, float h, float p) {
    tempSum += t;
    numReadings++;

    if (t > maxTemp) {
        maxTemp = t;
    }

    if (t < minTemp) {
        minTemp = t;
    }
    this->display();
}

void StatisticsDisplay::display() {
    cout << "Avg/Max/Min temperature = " << tempSum / numReadings << " / "
         << maxTemp << " / " << minTemp << endl;
}
