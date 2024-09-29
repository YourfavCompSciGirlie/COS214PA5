// Class definition for Component 1 - State (ConcreteState)

/**
 * @file CoolingState.h
 * @brief Concrete class representing the "Cooling" state of a smart device.
 * 
 * This class inherits from DeviceState and provides the behavior of a device
 * when it is in the "cooling" state. It defines how the device should respond to
 * actions when it is in this state.
 */

#ifndef COOLINGSTATE_H
#define COOLINGSTATE_H

#include "DeviceState.h"

/**
 * @class CoolingState
 * @brief Concrete state representing the "Cooling" state of a smart device.
 * 
 * The CoolingState class is responsible for handling actions when a device is
 * currently cooling. It implements the performAction and getStatus methods for
 * this specific state.
 */

class CoolingState : public DeviceState {
    
    public:

        /**
         * @brief Handles the action when the device is in the "Cooling" state.
         * 
         * If the action is "Heat", the device state is switched to the HeatingState.
         * 
         * @param device A shared pointer to the SmartDevice object.
         * @param action The action to be performed on the device.
         */
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;

        /**
         * @brief Returns the current status of the device in the "Cooling" state.
         * 
         * @return A string representing the current status, which is "cooling".
         */
        std::string getStatus() const override;
};

#endif // COOLINGSTATE_H
