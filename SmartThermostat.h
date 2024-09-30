// Class definition for Component 1 - Composite (Leaf)

/**
 * @file SmartThermostat.h
 * @brief Header file for the SmartThermostat class, representing a smart thermostat device.
 * 
 * The SmartThermostat class is a leaf in the Composite design pattern and represents a 
 * single smart thermostat device. It performs actions based on its current state, such as 
 * switching between heating and cooling modes.
 */

#ifndef SMARTTHERMOSTAT_H
#define SMARTTHERMOSTAT_H

#include "SmartDevice.h"
#include "DeviceState.h"
#include <memory>
#include <string>

/**
 * @class SmartThermostat
 * @brief A concrete class representing a smart thermostat device.
 * 
 * The SmartThermostat class inherits from SmartDevice and represents a single smart thermostat. 
 * It implements methods for performing actions and retrieving the current status based on the state pattern.
 */

class SmartThermostat : public SmartDevice {

    public:

        /**
         * @brief Construct a new SmartThermostat object.
         * 
         * The constructor initializes the smart thermostat with a cooling state.
         */
        SmartThermostat();
        
         /**
         * @brief Perform an action on the smart thermostat.
         * 
         * This method delegates the provided action to the current state of the smart thermostat.
         * Possible actions include switching between heating and cooling modes.
         * 
         * @param action The action to be performed on the smart thermostat.
         */
        void performAction(const std::string& action) override;

        /**
         * @brief Get the current status of the smart thermostat.
         * 
         * This method retrieves the status of the smart thermostat based on its current state,
         * such as whether it is in heating or cooling mode.
         * 
         * @return std::string The current status of the smart thermostat (e.g., "cooling" or "heating").
         */
        std::string getStatus() const override;

        /**
         * @brief Get the device type of the smart thermostat.
         * 
         * This method returns the type of device, which is "SmartThermostat" for this class.
         * 
         * @return std::string The string "SmartThermostat".
         */
        std::string getDeviceType() const override;
};

#endif // SMARTTHERMOSTAT_H
