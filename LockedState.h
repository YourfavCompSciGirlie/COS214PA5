// Class definition for Component 1 - State (ConcreteState)

/**
 * @file LockedState.h
 * @brief Concrete class representing the "Locked" state of a smart device.
 * 
 * This class inherits from DeviceState and provides the behavior of a device
 * when it is in the "locked" state. It defines how the device should respond to
 * actions when it is in this state.
 */

#ifndef LOCKEDSTATE_H
#define LOCKEDSTATE_H

#include "DeviceState.h"

/**
 * @class LockedState
 * @brief Concrete state representing the "Locked" state of a smart device.
 * 
 * The LockedState class is responsible for handling actions when a device is
 * currently locked. It implements the performAction and getStatus methods for
 * this specific state.
 */

class LockedState : public DeviceState {

    public:

        /**
         * @brief Handles the action when the device is in the "Locked" state.
         * 
         * If the action is "Unlock", the device state is switched to UnlockedState.
         * 
         * @param device A shared pointer to the SmartDevice object.
         * @param action The action to be performed on the device.
         */
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;

        /**
         * @brief Returns the current status of the device in the "Locked" state.
         * 
         * @return A string representing the current status, which is "locked".
         */
        std::string getStatus() const override;
};

#endif // LOCKEDSTATE_H
