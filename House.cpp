// Class implementation for Component 1 - Composite (Composite)

/**
 * @file House.cpp
 * @brief Implementation of the House class.
 * 
 * This file contains the implementation of the methods defined in House.h, providing
 * functionality for managing rooms as part of a composite structure in a smart house.
 * The House class serves as the composite in the Composite design pattern, allowing
 * actions and state to be applied across multiple rooms.
 */

#include "House.h"
#include "Room.h"

#include <algorithm> // for std::remove


/**
 * @brief Construct a new House object.
 * 
 * Initializes a new House object with a specified name. The house
 * will act as a container for Room objects and allow actions and
 * status checks across all contained rooms.
 * 
 * @param name The name of the house for identification purposes.
 */
House::House(const std::string& name) : houseName(name) {}

// Add a room to the house
/**
 * @brief Add a room to the house.
 * 
 * Adds a new Room object to the house, enabling the house to perform actions
 * on the room as part of its composite structure. The room is added to an
 * internal collection of rooms.
 * 
 * @param room A shared pointer to a Device, which is expected to be of type Room.
 */
void House::add(std::shared_ptr<Device> room) {
    rooms.push_back(std::dynamic_pointer_cast<Room>(room)); // Only allow rooms
}

// Remove a room from the house
/**
 * @brief Remove a room from the house.
 * 
 * Removes a specific room from the house's internal collection. This prevents
 * further actions from being performed on the room as part of the house composite.
 * 
 * @param room A shared pointer to a Device, which is expected to be of type Room.
 */
void House::remove(std::shared_ptr<Device> room) {
    rooms.erase(std::remove(rooms.begin(), rooms.end(), std::dynamic_pointer_cast<Room>(room)), rooms.end());
}

// Get a room by index
/**
 * @brief Get a room by its index.
 * 
 * Retrieves a shared pointer to a Room object from the house's internal collection
 * based on its index. This allows direct access to a specific room.
 * 
 * @param index The index of the room to retrieve.
 * @return std::shared_ptr<Device> A shared pointer to the requested Room.
 * @throws std::out_of_range if the index is out of the bounds of the room collection.
 */
std::shared_ptr<Device> House::getChild(size_t index) const {
    if (index >= rooms.size()) {
        throw std::out_of_range("Index out of range");
    }
    return rooms[index]; // Return the room at the given index
}

// Perform an action on all rooms in the house
/**
 * @brief Perform an action on all rooms in the house.
 * 
 * Iterates through all rooms in the house and delegates the specified action
 * to each room. This enables actions (such as turning on devices) to be performed
 * across all rooms simultaneously.
 * 
 * @param action The action to be performed on all rooms in the house.
 */
void House::performAction(const std::string& action) {
    for (auto& room : rooms) {
        room->performAction(action); // Delegate action to each room
    }
}

// Get the status of all rooms in the house
/**
 * @brief Get the status of all rooms in the house.
 * 
 * Gathers and combines the status of each room in the house to form a summary
 * of the house's overall status. This includes the status of all devices in each room.
 * 
 * @return std::string A summary of the statuses of all rooms in the house.
 */
std::string House::getStatus() const {
    std::string status = "House Status:\n";
    for (const auto& room : rooms) {
        status += room->getStatus() + "\n"; // Collect statuses of all rooms
    }
    return status;
}
