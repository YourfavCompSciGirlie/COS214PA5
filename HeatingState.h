// Class definition for Component 1 - State (ConcreteState)

/**
 * @file HeatingState.h
 * @brief Concrete class representing the "Heating" state of a smart device.
 * 
 * This class inherits from DeviceState and provides the behavior of a device
 * when it is in the "heating" state. It defines how the device should respond to
 * actions when it is in this state.
 */

#ifndef HEATINGSTATE_H
#define HEATINGSTATE_H

#include "DeviceState.h"

/**
 * @class HeatingState
 * @brief Concrete state representing the "Heating" state of a smart device.
 * 
 * The HeatingState class is responsible for handling actions when a device is
 * currently heating. It implements the performAction and getStatus methods for
 * this specific state.
 */

class HeatingState : public DeviceState {

    public:

        /**
         * @brief Handles the action when the device is in the "Heating" state.
         * 
         * If the action is "Cool", the device state is switched to the CoolingState.
         * 
         * @param device A shared pointer to the SmartDevice object.
         * @param action The action to be performed on the device.
         */
        void performAction(std::shared_ptr<SmartDevice> device, const std::string& action) override;

        /**
         * @brief Returns the current status of the device in the "Heating" state.
         * 
         * @return A string representing the current status, which is "heating".
         */
        std::string getStatus() const override;
};

#endif // HEATINGSTATE_H
