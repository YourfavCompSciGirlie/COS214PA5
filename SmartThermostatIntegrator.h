// Class definition for Component 2 - Adapter (Adapter)

/**
 * @file SmartThermostatIntegrator.h
 * @brief Definition of the SmartThermostatIntegrator class.
 * 
 * This class adapts the interface of a legacy thermostat to the new smart
 * device interface. It allows smart home systems to interact with legacy
 * thermostats seamlessly.
 */

#ifndef SMARTTHERMOSTATINTEGRATOR_H
#define SMARTTHERMOSTATINTEGRATOR_H

#include "Device.h"
#include "LegacyThermostat.h"
#include <memory>
#include <string>
#include <iomanip> // Include this header for std::fixed and std::setprecision
#include <sstream>

/**
 * @class SmartThermostatIntegrator
 * @brief Integrates a legacy thermostat into the smart home system.
 * 
 * The SmartThermostatIntegrator class adapts the legacy thermostat's interface
 * to the new smart device interface, allowing smart devices to interact with
 * legacy thermostats. It provides methods to set and get temperature and perform actions.
 */

class SmartThermostatIntegrator : public Device {

    private:
        std::shared_ptr<LegacyThermostat> legacyThermostat;  ///< Pointer to the legacy thermostat.

    public:
       
        /**
         * @brief Constructor that initializes the SmartThermostatIntegrator with a legacy thermostat.
         * 
         * @param legacyThermostat Shared pointer to the legacy thermostat.
         */
        SmartThermostatIntegrator(std::shared_ptr<LegacyThermostat> legacyThermostat);

        /**
         * @brief Sets the temperature on the integrated legacy thermostat.
         * 
         * This method delegates the temperature setting to the legacy thermostat.
         * 
         * @param temp The temperature to set (in degrees Celsius).
         */
        void setTemperature(float temp);

        /**
         * @brief Gets the current temperature reading from the integrated legacy thermostat.
         * 
         * This method retrieves the current temperature from the legacy thermostat.
         * 
         * @return The current temperature (in degrees Celsius).
         */
        float getTemperature() const;

        // Override Device interface methods
        /**
         * @brief Performs an action on the device.
         * 
         * This method handles actions such as increasing or decreasing
         * the temperature of the legacy thermostat.
         * 
         * @param action The action to perform, such as "IncreaseTemperature" or "DecreaseTemperature".
         */
        void performAction(const std::string& action) override;

        /**
         * @brief Gets the status of the SmartThermostatIntegrator.
         * 
         * This method returns a string representing the current status of the
         * SmartThermostatIntegrator, including the current temperature.
         * 
         * @return A string representing the current status.
         */
        std::string getStatus() const override;

        /**
         * @brief Gets the type of the device.
         * 
         * This method returns the type of the device as a string.
         * 
         * @return A string representing the device type.
         */
        std::string getDeviceType() const override;
};

#endif // SMARTTHERMOSTATINTEGRATOR_H
