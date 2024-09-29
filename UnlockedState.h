// Class definition for Component 1 - State (ConcreteState)

/**
 * @file UnlockedState.h
 * @brief Concrete class representing the "Unlocked" state of a smart device.
 * 
 * This class inherits from DeviceState and provides the behavior of a device
 * when it is in the "unlocked" state. It defines how the device should respond to
 * actions when it is in this state.
 */

#ifndef UNLOCKEDSTATE_H
#define UNLOCKEDSTATE_H

#include "DeviceState.h"

/**
 * @class UnlockedState
 * @brief Concrete state representing the "Unlocked" state of a smart device.
 * 
 * The UnlockedState class is responsible for handling actions when a device is
 * currently unlocked. It implements the performAction and getStatus methods for
 * this specific state.
 */

class UnlockedState : public DeviceState {

    public:

        /**
         * @brief Handles the action when the device is in the "Unlocked" state.
         * 
         * If the action is "Lock", the device state is switched to LockedState.
         * 
         * @param device A shared pointer to the SmartDevice object.
         * @param action The action to be performed on the device.
         */
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;

        /**
         * @brief Returns the current status of the device in the "Unlocked" state.
         * 
         * @return A string representing the current status, which is "unlocked".
         */
        std::string getStatus() const override;
};

#endif // UNLOCKEDSTATE_H
