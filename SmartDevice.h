// Class definition for Component 1 - State (Context)

/**
 * @file SmartDevice.h
 * @brief Defines the SmartDevice class, which acts as the context in the State Pattern.
 * 
 * The SmartDevice class manages the current state of a smart device (e.g., SmartLight, SmartDoorLock, SmartThermostat)
 * and delegates device actions to the active state. It allows state transitions and provides an interface for 
 * performing actions and retrieving the device's status and type.
 */

#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <memory>
#include "Device.h" // Ensure this is included

// Forward declare DeviceState to avoid circular dependency
class DeviceState;

/**
 * @class SmartDevice
 * @brief Context class in the State Pattern that represents a smart device.
 * 
 * The SmartDevice class is the context that interacts with various device states
 * (e.g., OnState, OffState). It allows for state transitions and delegates actions 
 * to the active state. This class provides common functionality for all smart devices
 * by inheriting from the Device class.
 */

class SmartDevice : public Device , public std::enable_shared_from_this<SmartDevice> {

    protected:
        std::shared_ptr<DeviceState> state; ///< Smart pointer to the current state of the device.
        std::string deviceType;             ///< String representing the type of the device (e.g., "SmartLight").

    public:

        /**
         * @brief Constructs a SmartDevice object and sets its initial state.
         * 
         * The constructor initializes the device type and sets the default state
         * (e.g., OffState) for the smart device. It serves as the base class for all
         * specific smart devices (e.g., SmartLight, SmartDoorLock).
         * 
         * @param type A string representing the specific device type (e.g., "SmartLight").
         */
        SmartDevice(const std::string& type); // Constructor to initialize device type and state

        /**
         * @brief Virtual destructor for SmartDevice.
         * 
         * Ensures proper cleanup of derived classes and state pointers.
         */
        virtual ~SmartDevice() = default;

        // State management
        /**
         * @brief Sets a new state for the smart device.
         * 
         * This method changes the current state of the device, allowing it to transition
         * between states (e.g., switching between OnState and OffState).
         * 
         * @param newState A shared pointer to the new DeviceState object representing the new state.
         */
        void setState(const std::shared_ptr<DeviceState>& newState);

        // Concrete methods to be used by device subclasses
        /**
         * @brief Performs an action based on the current state of the device.
         * 
         * This method delegates the action to the current state of the device, such as turning
         * the device on or off, depending on its state.
         * 
         * @param action A string representing the action to be performed (e.g., "TurnOn", "TurnOff").
         */
        virtual void performAction(const std::string& action);

        /**
         * @brief Retrieves the current status of the smart device.
         * 
         * This method queries the current state of the device and returns its status, 
         * such as whether the device is on or off.
         * 
         * @return A string representing the current status of the device (e.g., "On", "Off").
         */
        virtual std::string getStatus() const;

        /**
         * @brief Retrieves the type of the smart device.
         * 
         * This method returns the type of the device, allowing identification of the specific
         * type of smart device (e.g., "SmartLight", "SmartDoorLock").
         * 
         * @return A string representing the device type.
         */
        virtual std::string getDeviceType() const; // Each device specifies its own type
};

#endif // SMARTDEVICE_H
