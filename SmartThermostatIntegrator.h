// Class definition for Component 2 - Adapter (Adapter)

#ifndef SMARTTHERMOSTATINTEGRATOR_H
#define SMARTTHERMOSTATINTEGRATOR_H

#include "Device.h"
#include "LegacyThermostat.h"
#include <memory>
#include <string>
#include <iomanip> // Include this header for std::fixed and std::setprecision
#include <sstream>

class SmartThermostatIntegrator : public Device {

    private:
        std::shared_ptr<LegacyThermostat> legacyThermostat;  ///< Pointer to the legacy thermostat.

    public:
       
        SmartThermostatIntegrator(std::shared_ptr<LegacyThermostat> legacyThermostat);

 
        void setTemperature(float temp);


        float getTemperature() const;

        // Override Device interface methods


        void performAction(const std::string& action) override;


        std::string getStatus() const override;


        std::string getDeviceType() const override;
};

#endif // SMARTTHERMOSTATINTEGRATOR_H
