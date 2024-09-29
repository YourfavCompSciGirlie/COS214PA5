// Class defintion for Component 1 - State (State)

/**
 * @file DeviceState.h
 * @brief Abstract class representing the state of a smart device in the Smart Home Automation System.
 * 
 * This class defines the interface for different states that a SmartDevice can be in. Each
 * concrete state (such as OnState, OffState, etc.) will inherit from this class and implement
 * its own behavior for the methods declared here. It uses the State design pattern.
 */

#ifndef DEVICESTATE_H
#define DEVICESTATE_H

#include <memory>
#include <string>

class SmartDevice; // Forward declaration

/**
 * @class DeviceState
 * @brief Abstract base class representing a generic state of a smart device.
 * 
 * The DeviceState class is part of the State design pattern, providing an interface
 * for various states a smart device can be in. Concrete state classes will inherit from 
 * this class and define specific behaviors for devices.
 */

class DeviceState {

    public:

        /**
         * @brief Pure virtual function that performs an action on the SmartDevice.
         * 
         * This function is responsible for performing state-specific actions on the device. 
         * The concrete state classes will define how the device should behave for a given action.
         * 
         * @param device A shared pointer to the SmartDevice that this state belongs to.
         * @param action The action to be performed (e.g., "ToggleOn", "ToggleOff").
         */
        virtual void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) = 0;

        /**
         * @brief Pure virtual function that returns the current status of the state.
         * 
         * This function is responsible for providing the current status of the state (e.g., "on", "off").
         * 
         * @return A string representing the status of the state.
         */
        virtual std::string getStatus() const = 0;

        /**
         * @brief Virtual destructor.
         * 
         * The virtual destructor ensures that the destructor of the derived class is called when
         * a DeviceState pointer is deleted, allowing proper cleanup of resources.
         */
        virtual ~DeviceState() = default;
};

#endif // DEVICESTATE_H