// Class definition for Component 1 - Composite (Component)
// Class definition for Component 2 - Adapter (Target)

/**
 * @file Device.h
 * @brief Defines the abstract Device class, which acts as the Component in the Composite Pattern.
 * 
 * The Device class provides an abstract interface for all devices in the composite structure, 
 * representing both individual devices (leaves) and collections of devices (composites). 
 * It includes methods for performing actions, retrieving status, and managing the composite 
 * hierarchy (adding/removing/getting child devices).
 */

#ifndef DEVICE_H
#define DEVICE_H

#include <string>
#include <memory>
#include <iostream>

/**
 * @class Device
 * @brief Abstract base class for all devices in the composite structure.
 * 
 * The Device class serves as the Component in the Composite Pattern, providing common functionality 
 * for both leaf and composite nodes. It defines abstract methods for performing actions, retrieving 
 * status, and managing device types. Additionally, it provides virtual methods for adding, removing, 
 * and retrieving child devices, which can be overridden by composite classes (e.g., Room, House).
 */

class Device {
    
    public:

        /**
         * @brief Pure virtual method to perform an action on the device.
         * 
         * This method must be implemented by derived classes to perform an action (e.g., turning a device on/off).
         * 
         * @param action A string representing the action to be performed on the device.
         */
        virtual void performAction(const std::string& action) = 0; // Abstract method for action

        /**
         * @brief Pure virtual method to retrieve the current status of the device.
         * 
         * This method must be implemented by derived classes to return the status of the device (e.g., on/off).
         * 
         * @return A string representing the current status of the device.
         */
        virtual std::string getStatus() const = 0;                 // Abstract method for status

        /**
         * @brief Pure virtual method to retrieve the device type.
         * 
         * This method must be implemented by derived classes to return the type of the device (e.g., "SmartLight").
         * 
         * @return A string representing the device type.
         */
        virtual std::string getDeviceType() const = 0;             // Abstract method for device type

        /**
         * @brief Virtual destructor for the Device class.
         * 
         * Ensures that derived classes are properly destroyed.
         */
        virtual ~Device() = default;                                 // Virtual destructor

        // Virtual methods for managing composite structure
        /**
         * @brief Virtual method to add a child device.
         * 
         * This method can be overridden by composite classes to add a device to a collection (e.g., adding a SmartDevice to a Room).
         * The default implementation throws an exception, as leaf devices do not support this operation.
         * 
         * @param device A shared pointer to the device to be added.
         * @throws std::runtime_error If the operation is not supported by the device (i.e., for leaf nodes).
         */
        virtual void add(std::shared_ptr<Device> device) {
            (void)device; // Mark parameter as unused
            // Default implementation for leaf nodes (optional)
            throw std::runtime_error("This operation is not supported for leaf nodes.");
        }


        /**
         * @brief Virtual method to remove a child device.
         * 
         * This method can be overridden by composite classes to remove a device from a collection.
         * The default implementation throws an exception, as leaf devices do not support this operation.
         * 
         * @param device A shared pointer to the device to be removed.
         * @throws std::runtime_error If the operation is not supported by the device (i.e., for leaf nodes).
         */
        virtual void remove(std::shared_ptr<Device> device) {
            (void)device; // Mark parameter as unused
            // Default implementation for leaf nodes (optional)
            throw std::runtime_error("This operation is not supported for leaf nodes.");
        }


        /**
         * @brief Virtual method to get a child device by index.
         * 
         * This method can be overridden by composite classes to retrieve a child device from a collection.
         * The default implementation throws an exception, as leaf devices do not support this operation.
         * 
         * @param index The index of the child device.
         * @return A shared pointer to the child device at the specified index.
         * @throws std::runtime_error If the operation is not supported by the device (i.e., for leaf nodes).
         */
        virtual std::shared_ptr<Device> getChild(size_t index) const {
            (void)index; // Mark parameter as unused
            // Default implementation for leaf nodes (optional)
            throw std::runtime_error("This operation is not supported for leaf nodes.");
        }

        // Add the virtual function for getting the room name
        /**
         * @brief Virtual method to retrieve the name of the room the device is in.
         * 
         * The default implementation returns "Room", which can be overridden by composite classes such as Room
         * to return the specific room name.
         * 
         * @return A string representing the room name.
         */
        virtual std::string getRoomName() const { return "Room"; } // Default implementation
};

#endif // DEVICE_H
