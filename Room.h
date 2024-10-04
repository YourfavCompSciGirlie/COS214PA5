// Class definition for Component 1 - Composite (Composite)

/**
 * @file Room.h
 * @brief Header file for the Room class, part of the Composite design pattern.
 * 
 * The Room class represents a composite entity that contains a collection of smart devices.
 * It allows actions to be performed on multiple devices within the room and manages their states.
 */

#ifndef ROOM_H
#define ROOM_H

#include <vector>
#include <memory>
#include <string>
#include "Device.h"
#include "SmartDevice.h"

/**
 * @class Room
 * @brief Composite class representing a room containing smart devices.
 * 
 * The Room class acts as a composite in the Composite design pattern. It allows adding,
 * removing, and managing smart devices within the room. The Room class inherits from
 * the Device class, meaning that actions can be performed on it as well as on the devices it contains.
 */

class Room : public Device { // Room is now a Device (Composite)
    
    private:
        std::vector<std::shared_ptr<SmartDevice>> devices; ///< Collection of smart devices in the room
        std::string roomName;                             ///< Name of the room

    public:

        /**
         * @brief Construct a new Room object.
         * 
         * Initializes a new Room object with a specified name, which serves as an identifier for the room.
         * 
         * @param name The name of the room.
         */
        Room(const std::string& name);                    // Constructor to initialize room name

        /**
         * @brief Add a smart device to the room.
         * 
         * Adds a new SmartDevice to the room's internal collection of devices, allowing
         * actions and status checks to be performed on the device.
         * 
         * @param device A shared pointer to a Device, expected to be of type SmartDevice.
         */
        void add(std::shared_ptr<Device> device) override;   // Add a smart device

        /**
         * @brief Remove a smart device from the room.
         * 
         * Removes a specific smart device from the room's internal collection of devices.
         * 
         * @param device A shared pointer to a Device, expected to be of type SmartDevice.
         */
        void remove(std::shared_ptr<Device> device) override; // Remove a smart device

        /**
         * @brief Get a smart device by its index.
         * 
         * Retrieves a shared pointer to a SmartDevice object from the room's internal collection
         * based on its index, allowing direct access to a specific device.
         * 
         * @param index The index of the device to retrieve.
         * @return std::shared_ptr<Device> A shared pointer to the requested SmartDevice.
         * @throws std::out_of_range if the index is out of the bounds of the device collection.
         */
        std::shared_ptr<Device> getChild(size_t index) const override; // Get a smart device by index

        /**
         * @brief Perform an action on all devices in the room.
         * 
         * Iterates through all devices in the room and delegates the specified action
         * to each device, allowing mass control over the devices in the room.
         * 
         * @param action The action to be performed on all devices in the room.
         */
        void performAction(const std::string& action) override;    // Method to perform action on all devices in the room

        /**
         * @brief Get the status of all devices in the room.
         * 
         * Collects and combines the status of each smart device in the room, providing a summary
         * of the room's overall status.
         * 
         * @return std::string A summary of the statuses of all devices in the room.
         */
        std::string getStatus() const override;             // Method to get the status of all devices in the room

        /**
         * @brief Get the type of device.
         * 
         * Returns a string representing the type of device, which is "Room" for this class.
         * 
         * @return std::string The string "Room".
         */
        std::string getDeviceType() const override { return "Room"; } // Return "Room" as the device type

        /**
         * @brief Get the name of the room.
         * 
         * Retrieves the name of the room.
         * 
         * @return std::string The name of the room.
         */
        std::string getRoomName() const { return roomName; }

        /**
         * @brief Executes a command on the room.
         * 
         * This stub function is part of the Command Design Pattern, and will eventually
         * execute a command on the devices within the room.
         */
        void Room::execute() override {
            // Stub: Implementation for executing commands on the room's devices will go here.
        }

        /**
         * @brief Updates the room based on sensor data.
         * 
         * This stub function is part of the Observer Design Pattern, and will eventually
         * handle updates from sensors, such as temperature or motion detectors, affecting
         * the devices within the room.
         * 
         * @param sensorType The type of sensor that triggered the update.
         * @param sensorData The data provided by the sensor.
         */
        void Room::update(const std::string &sensorType, const std::string &sensorData) override {
            // Stub: Implementation for updating room based on sensor input will go here.
        }
};

#endif // ROOM_H
