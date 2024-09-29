// Class definition for Component 1 - Composite (Leaf)

#ifndef SMARTTHERMOSTAT_H
#define SMARTTHERMOSTAT_H

#include "SmartDevice.h"
#include "DeviceState.h"
#include <memory>
#include <string>

class SmartThermostat : public SmartDevice {

    public:
        SmartThermostat();
        
        void performAction(const std::string& action) override;
        std::string getStatus() const override;
        std::string getDeviceType() const override;
};

#endif // SMARTTHERMOSTAT_H
