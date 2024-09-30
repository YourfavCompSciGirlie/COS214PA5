#include "Lights.h"


/**
 * @brief Responds to a sensor notification.
 * 
 * This function simulates the light turning on in response to movement detected by a sensor. 
 * It could also print different levels of brightness depending on the time of day.
 */
void Lights::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "motion" && sensorData == "detected") {
        std::cout << "SmartLight: Motion detected! Turning on light and adjusting brightness.\n";
    } else if (sensorType == "motion" && sensorData == "clear") {
        std::cout << "SmartLight: No motion detected. Dimming lights.\n";
    }
}


void Lights::execute() 
{
    std::cout << "SmartLight: Executing light adjustment based on sensor notification.\n";
}