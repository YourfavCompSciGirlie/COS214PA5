// Class implementation for Component 1 - State (Context)

/**
 * @file SmartDevice.cpp
 * @brief Implements the SmartDevice class methods.
 * 
 * This file provides the implementation for the SmartDevice class, defining how
 * devices manage their state and perform actions in their current state.
 */

#include "SmartDevice.h"
#include "OffState.h"


/**
 * @brief Constructs a SmartDevice object and sets its initial state to OffState.
 * 
 * @param type A string representing the type of the smart device.
 */
SmartDevice::SmartDevice(const std::string& type) : deviceType(type) {
    // Initialize the device with a default state (OffState)
    this->state = std::make_shared<OffState>();
}


/**
 * @brief Sets a new state for the device.
 * 
 * This method changes the current state of the device to a new state by updating
 * the state pointer.
 * 
 * @param newState A shared pointer to the new state to which the device will transition.
 */
void SmartDevice::setState(const std::shared_ptr<DeviceState>& newState) {
    state = newState;
}


/**
 * @brief Performs an action based on the current state.
 * 
 * This method passes the action to the current state, which determines how the
 * device should behave in response.
 * 
 * @param action A string representing the action (e.g., "ToggleOn").
 */
void SmartDevice::performAction(const std::string& action) {
    // Delegate the action to the current state
    state->performAction(shared_from_this(), action);
}


/**
 * @brief Retrieves the current status of the device.
 * 
 * This method queries the current state of the device and returns its status as a string.
 * 
 * @return A string representing the current status (e.g., "on" or "off").
 */
std::string SmartDevice::getStatus() const {
    return state->getStatus();
}

/**
 * @brief Retrieves the type of the device.
 * 
 * @return A string representing the type of the smart device (e.g., "SmartLight").
 */
std::string SmartDevice::getDeviceType() const {
    return deviceType;
}