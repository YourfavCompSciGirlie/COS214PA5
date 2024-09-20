// Class definition for Component 1 - Composite (Leaf)

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"
#include "DeviceState.h"
#include <memory>
#include <string>

class Thermostat : public SmartDevice {

    public:
        Thermostat();
        
        void performAction(const std::string& action) override;
        std::string getStatus() const override;
        std::string getDeviceType() const override;
};

#endif // THERMOSTAT_H
