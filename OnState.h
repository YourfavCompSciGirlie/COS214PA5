// Class defintion for Component 1 - State (ConcreteState)

/**
 * @file OnState.h
 * @brief Concrete class representing the "On" state of a smart device.
 * 
 * This class inherits from DeviceState and provides the behavior of a device
 * when it is in the "on" state. It defines how the device should respond to
 * actions when it is "on".
 */

#ifndef ONSTATE_H
#define ONSTATE_H

#include "DeviceState.h"

/**
 * @class OnState
 * @brief Concrete state representing the "On" state of a smart device.
 * 
 * The OnState class is responsible for handling actions when a device is
 * currently in the "on" state. It implements the performAction and getStatus 
 * methods for this specific state.
 */

class OnState : public DeviceState {
    
    public:

        /**
         * @brief Handles the action when the device is in the "On" state.
         * 
         * If the action is "ToggleOff", the device state is switched to the OffState.
         * 
         * @param device A shared pointer to the SmartDevice object.
         * @param action The action to be performed on the device.
         */
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;

        /**
         * @brief Returns the current status of the device in the "On" state.
         * 
         * @return A string representing the current status, which is "on".
         */
        std::string getStatus() const override;
};

#endif // ONSTATE_H
