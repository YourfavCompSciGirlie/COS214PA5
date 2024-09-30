//Class defintion for Component 4  - Observer(ConcreteObserver)

#include "Dehumidifier.h"
#include <iostream>


void Dehumidifier::update(const std::string& sensorType, const std::string& sensorData) 
{
    if (sensorType == "humidity" && sensorData == "high") {
        std::cout << "Dehumidifier: High humidity detected! Activating dehumidifier.\n";
    } else if (sensorType == "humidity" && sensorData == "low") {
        std::cout << "Dehumidifier: Humidity at normal level. Deactivating dehumidifier.\n";
    }
    
}


void Dehumidifier::execute() {
    std::cout << "Dehumidifier: Executing humidity control based on sensor notification.\n";
}
