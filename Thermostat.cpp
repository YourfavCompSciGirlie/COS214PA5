#include "Thermostat.h"
#include <iostream>

// Implementation of Thermostat
void Thermostat::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "temperature" && sensorData == "high") {
        std::cout << "Thermostat: High temperature detected! Adjusting to cooler settings.\n";
    } else if (sensorType == "temperature" && sensorData == "low") {
        std::cout << "Thermostat: Low temperature detected! Adjusting to warmer settings.\n";
    }
}


void Thermostat::execute() 
{
    std::cout << "Thermostat: Executing temperature adjustment based on sensor notification.\n";
}