// Class definition for Component 1 - Composite (Leaf)

/**
 * @file SmartLight.h
 * @brief Header file for the SmartLight class, which represents a smart light device.
 * 
 * The SmartLight class is a leaf in the Composite design pattern and represents a 
 * single smart light device. It can perform actions based on its current state, 
 * which could be "on" or "off", and provides status information about the device.
 */

#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H

#include "SmartDevice.h"
#include <memory>
#include <string>

/**
 * @class SmartLight
 * @brief A concrete class representing a smart light device.
 * 
 * The SmartLight class inherits from SmartDevice and represents a single smart light. 
 * It implements methods for performing actions and getting the current status based on the state pattern.
 */

class SmartLight : public SmartDevice {
    
    public:

        /**
         * @brief Construct a new SmartLight object.
         * 
         * The constructor initializes the smart light with an "off" state.
         */
        SmartLight();
        
        /**
         * @brief Perform an action on the smart light.
         * 
         * This method delegates the action to the current state of the smart light.
         * Possible actions include toggling the state from on to off or vice versa.
         * 
         * @param action The action to be performed on the smart light.
         */
        void performAction(const std::string& action) override;

        /**
         * @brief Get the current status of the smart light.
         * 
         * This method retrieves the status of the smart light based on its current state.
         * The status could indicate whether the light is on or off.
         * 
         * @return std::string The current status of the smart light (e.g., "on" or "off").
         */
        std::string getStatus() const override;

        /**
         * @brief Get the device type of the smart light.
         * 
         * This method returns the type of device, which is "SmartLight" for this class.
         * 
         * @return std::string The string "SmartLight".
         */
        std::string getDeviceType() const override;
};

#endif // SMARTLIGHT_H
