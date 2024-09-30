#include "Alarm.h"


/**
 * @brief Responds to a sensor notification.
 * 
 * This function simulates an alarm triggering in response to movement detected by a sensor. 
 * It prints creative messages based on the type of alert triggered (e.g., mild warning or full alarm).
 */
void Alarm::update(const std::string& sensorType, const std::string& sensorData) {
    if (sensorType == "motion" && sensorData == "detected") {
        std::cout << "SmartAlarm: Motion detected! Sounding alarm.\n";
    } else if (sensorType == "motion" && sensorData == "clear") {
        std::cout << "SmartAlarm: Motion clear. Alarm deactivated.\n";
    }
}


void Alarm::execute() {
    std::cout << "SmartAlarm: Executing alarm activation/deactivation based on sensor notification.\n";
}