// Class implementation for Component 1 - Composite (Leaf)

/**
 * @file SmartLight.cpp
 * @brief Implementation of the SmartLight class.
 * 
 * This file contains the implementation of the methods defined in SmartLight.h, providing
 * the behavior for a smart light device. The SmartLight class uses the state pattern to
 * handle actions and maintain its on/off state.
 */

#include "SmartLight.h"
#include "OnState.h"
#include "OffState.h"


/**
 * @brief Construct a new SmartLight object.
 * 
 * Initializes a new SmartLight device and sets its initial state to "off" by associating it
 * with the OffState object. The device can transition between states using the performAction method.
 */
SmartLight::SmartLight() : SmartDevice("SmartLight") {
    // Initialize the SmartLight with an OffState
    this->setState(std::make_shared<OffState>());
}


/**
 * @brief Perform an action on the smart light.
 * 
 * This method delegates the provided action to the current state of the smart light.
 * Depending on the action, the state may toggle between on and off. The state pattern
 * is used to determine the appropriate response based on the current state of the device.
 * 
 * @param action The action to be performed, such as "ToggleOn" or "ToggleOff".
 */
void SmartLight::performAction(const std::string& action) {
    // Delegate the action to the current state
    state->performAction(shared_from_this(), action);
}


/**
 * @brief Get the current status of the smart light.
 * 
 * This method retrieves and returns the current status of the smart light,
 * which is determined by the device's current state. The possible statuses
 * include "on" or "off".
 * 
 * @return std::string The current status of the smart light.
 */
std::string SmartLight::getStatus() const {
    return state->getStatus(); // Return the current state status (on/off)
}


/**
 * @brief Get the device type of the smart light.
 * 
 * This method returns a string indicating the type of device, which is "SmartLight".
 * 
 * @return std::string The string "SmartLight".
 */
std::string SmartLight::getDeviceType() const {
    return "SmartLight";
}
