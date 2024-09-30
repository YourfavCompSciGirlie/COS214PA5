// Class implementation for Component 1 - Composite (Composite)

/**
 * @file Room.cpp
 * @brief Implementation of the Room class.
 * 
 * This file contains the implementation of the methods defined in Room.h, providing
 * functionality for managing smart devices within a room as part of a composite structure.
 * The Room class serves as the composite in the Composite design pattern, allowing
 * actions and state management for multiple devices within the room.
 */

#include "Room.h"
#include "SmartDevice.h"
#include <algorithm>
#include <stdexcept>


/**
 * @brief Construct a new Room object.
 * 
 * Initializes a new Room object with a specified name, which is stored for future identification.
 * 
 * @param name The name of the room.
 */
Room::Room(const std::string& name) : roomName(name) {}

// Add a smart device to the room
/**
 * @brief Add a smart device to the room.
 * 
 * Adds a new SmartDevice to the room, allowing actions to be performed on it
 * as part of the room's composite structure. Only devices of type SmartDevice
 * are accepted.
 * 
 * @param device A shared pointer to a Device, expected to be of type SmartDevice.
 */
void Room::add(std::shared_ptr<Device> device) {
    devices.push_back(std::dynamic_pointer_cast<SmartDevice>(device)); // Only allow SmartDevices
}

// Remove a smart device from the room
/**
 * @brief Remove a smart device from the room.
 * 
 * Removes a specific smart device from the room's internal collection, preventing
 * further actions from being performed on the device as part of the room composite.
 * 
 * @param device A shared pointer to a Device, expected to be of type SmartDevice.
 */
void Room::remove(std::shared_ptr<Device> device) {
    devices.erase(std::remove(devices.begin(), devices.end(), std::dynamic_pointer_cast<SmartDevice>(device)), devices.end());
}

// Get a smart device by index
/**
 * @brief Get a smart device by index.
 * 
 * Retrieves a shared pointer to a SmartDevice object from the room's internal collection
 * based on its index, allowing direct access to a specific device.
 * 
 * @param index The index of the device to retrieve.
 * @return std::shared_ptr<Device> A shared pointer to the requested SmartDevice.
 * @throws std::out_of_range if the index is out of the bounds of the device collection.
 */
std::shared_ptr<Device> Room::getChild(size_t index) const {
    if (index >= devices.size()) {
        throw std::out_of_range("Index out of range");
    }
    return std::static_pointer_cast<Device>(devices[index]); // Cast to shared_ptr<Device>
}

// Perform an action on all smart devices in the room
/**
 * @brief Perform an action on all smart devices in the room.
 * 
 * Iterates through all smart devices in the room and delegates the specified action
 * to each device, allowing mass control over the devices in the room.
 * 
 * @param action The action to be performed on all devices in the room.
 */
void Room::performAction(const std::string& action) {
    for (auto& device : devices) {
        device->performAction(action); // Delegate action to each smart device
    }
}

// Get the status of all smart devices in the room
/**
 * @brief Get the status of all smart devices in the room.
 * 
 * Gathers and combines the statuses of all smart devices in the room into a
 * summary of the room's overall status. This includes the status of each individual device.
 * 
 * @return std::string A summary of the statuses of all smart devices in the room.
 */
std::string Room::getStatus() const {
    std::string status = "Room: " + roomName + " Status:\n";
    for (const auto& device : devices) {
        status += device->getStatus() + "\n"; // Collect statuses of all devices
    }
    return status;
}
