#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "Device.h"

// Concrete Observer (Thermostat)
class Thermostat : public Device {
public:
    void execute() override;
    void update(const std::string& sensorType, const std::string& sensorData) override;
};

#endif 
