// Class definition for Component 1 - State (Context)

/**
 * @file SmartDevice.h
 * @brief Defines the SmartDevice class, which acts as the context in the State Pattern.
 * 
 * The SmartDevice class manages the current state of a device and delegates
 * actions to the active state. It provides an interface for interacting with
 * various device types (e.g., SmartLight, SmartDoorLock).
 */

#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>
#include <memory>

// Forward declare DeviceState to avoid circular dependency
class DeviceState;

/**
 * @class SmartDevice
 * @brief Context class in the State Pattern that represents a smart device.
 * 
 * The SmartDevice class holds a reference to the current state of the device
 * and allows for transitioning between states. It provides methods for performing
 * actions and retrieving the status and type of the device.
 */

class SmartDevice : public std::enable_shared_from_this<SmartDevice> {

    protected:
        std::shared_ptr<DeviceState> state; ///< Smart pointer to the current state of the device.
        std::string deviceType;             ///< String representing the type of the device (e.g., "SmartLight").

    public:

        /**
         * @brief Constructs a SmartDevice object and sets its initial state.
         * 
         * The constructor initializes the device type and sets the device's
         * default state (e.g., OffState).
         * 
         * @param type A string representing the device type.
         */
        SmartDevice(const std::string& type); // Constructor to initialize device type and state

        /**
         * @brief Virtual destructor for SmartDevice.
         */
        virtual ~SmartDevice() = default;

        // State management
        /**
         * @brief Sets a new state for the device.
         * 
         * This method changes the current state of the device to a new state.
         * 
         * @param newState A shared pointer to the new DeviceState object.
         */
        void setState(const std::shared_ptr<DeviceState>& newState);

        // Concrete methods to be used by device subclasses
         /**
         * @brief Performs an action based on the current state.
         * 
         * This method delegates the action to the current state of the device.
         * 
         * @param action A string representing the action to be performed.
         */
        virtual void performAction(const std::string& action);

        /**
         * @brief Retrieves the current status of the device.
         * 
         * This method queries the current state of the device and returns its status.
         * 
         * @return A string representing the current status of the device.
         */
        virtual std::string getStatus() const;

        /**
         * @brief Retrieves the type of the device.
         * 
         * @return A string representing the device type (e.g., "SmartLight").
         */
        virtual std::string getDeviceType() const; // Each device specifies its own type
};

#endif // SMARTDEVICE_H
