// Class implementation for Component 1 - Composite (Leaf)

/**
 * @file SmartThermostat.cpp
 * @brief Implementation of the SmartThermostat class.
 * 
 * This file contains the implementation of the methods defined in SmartThermostat.h,
 * providing the behavior for a smart thermostat device. The SmartThermostat class uses 
 * the state pattern to handle actions and maintain heating and cooling states.
 */

#include "SmartThermostat.h"
#include "CoolingState.h"
#include "HeatingState.h"


/**
 * @brief Construct a new SmartThermostat object.
 * 
 * Initializes a new SmartThermostat device and sets its initial state to "cooling" 
 * by associating it with the CoolingState object. The device can transition between 
 * heating and cooling states using the performAction method.
 */
SmartThermostat::SmartThermostat() : SmartDevice("SmartThermostat") {
    // Initialize the Thermostat with a CoolingState
    this->setState(std::make_shared<CoolingState>());
}


/**
 * @brief Perform an action on the smart thermostat.
 * 
 * This method delegates the provided action to the current state of the smart thermostat.
 * Depending on the action, the state may toggle between heating and cooling modes.
 * 
 * @param action The action to be performed, such as "SwitchToHeating" or "SwitchToCooling".
 */
void SmartThermostat::performAction(const std::string& action) {
    // Delegate action to the current state
    state->performAction(shared_from_this(), action);
}


/**
 * @brief Get the current status of the smart thermostat.
 * 
 * This method retrieves and returns the current status of the smart thermostat,
 * which is determined by the device's current state. The possible statuses
 * include "cooling" or "heating".
 * 
 * @return std::string The current status of the smart thermostat.
 */
std::string SmartThermostat::getStatus() const {
    return state->getStatus(); // Return the current state status
}


/**
 * @brief Get the device type of the smart thermostat.
 * 
 * This method returns a string indicating the type of device, which is "SmartThermostat".
 * 
 * @return std::string The string "SmartThermostat".
 */
std::string SmartThermostat::getDeviceType() const {
    return "SmartThermostat";
}
