// Class defintion for Component 1 - State (ConcreteState)

/**
 * @file OffState.h
 * @brief Concrete class representing the "Off" state of a smart device.
 * 
 * This class inherits from DeviceState and provides the behavior of a device
 * when it is in the "off" state. It defines how the device should respond to
 * actions when it is "off".
 */

#ifndef OFFSTATE_H
#define OFFSTATE_H

#include "DeviceState.h"

/**
 * @class OffState
 * @brief Concrete state representing the "Off" state of a smart device.
 * 
 * The OffState class is responsible for handling actions when a device is
 * currently in the "off" state. It implements the performAction and getStatus 
 * methods for this specific state.
 */

class OffState : public DeviceState {
    
    public:

        /**
         * @brief Handles the action when the device is in the "Off" state.
         * 
         * If the action is "ToggleOn", the device state is switched to the OnState.
         * 
         * @param device A shared pointer to the SmartDevice object.
         * @param action The action to be performed on the device.
         */
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;

        /**
         * @brief Returns the current status of the device in the "Off" state.
         * 
         * @return A string representing the current status, which is "off".
         */
        std::string getStatus() const override;
};

#endif // OFFSTATE_H
