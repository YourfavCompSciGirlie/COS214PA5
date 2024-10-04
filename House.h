// Class definition for Component 1 - Composite (Composite)

/**
 * @file House.h
 * @brief Definition of the House class, which represents a composite structure of rooms.
 * 
 * The House class inherits from the Device class and acts as a container for multiple Room objects. 
 * It enables operations on the entire house as well as individual rooms, facilitating 
 * both composite design and device management within a smart home environment.
 */

#ifndef HOUSE_H
#define HOUSE_H

#include <vector>
#include <memory>
#include <string>
#include "Device.h"
#include "Room.h"

/**
 * @class House
 * @brief Represents a composite of rooms in a smart house.
 * 
 * The House class serves as a composite element in the design pattern, allowing for the 
 * management and operation of multiple rooms. Each room can contain various devices, and the 
 * House class provides methods to add, remove, and perform actions on these rooms collectively.
 */

class House : public Device {  // House is now a Device (Composite)
private:
    std::vector<std::shared_ptr<Room>> rooms; ///< Collection of rooms in the house
    std::string houseName;                    ///< Name of the house

public:

    /**
     * @brief Construct a new House object.
     * 
     * Initializes a House with the given name.
     * 
     * @param name The name of the house, used for identification.
     */
    House(const std::string& name);           // Constructor to initialize house name

    /**
     * @brief Add a room to the house.
     * 
     * This method adds a room to the house's collection of rooms. Only Room objects 
     * can be added, ensuring type safety.
     * 
     * @param room A shared pointer to a Device, which should be a Room.
     */
    void add(std::shared_ptr<Device> room) override;   // Add a room

    /**
     * @brief Remove a room from the house.
     * 
     * This method removes a specified room from the house's collection of rooms.
     * 
     * @param room A shared pointer to a Device, which should be a Room.
     */
    void remove(std::shared_ptr<Device> room) override; // Remove a room

    /**
     * @brief Remove a room from the house.
     * 
     * This method removes a specified room from the house's collection of rooms.
     * 
     * @param room A shared pointer to a Device, which should be a Room.
     */
    std::shared_ptr<Device> getChild(size_t index) const override; // Get a room by index

    /**
     * @brief Perform an action on all rooms in the house.
     * 
     * This method iterates through all rooms and delegates the specified action 
     * to each room.
     * 
     * @param action The action to be performed on each room.
     */
    void performAction(const std::string& action) override; // Method to perform action on all devices in the house

    /**
     * @brief Get the status of all rooms in the house.
     * 
     * Collects the status of each room and combines them into a single status report.
     * 
     * @return std::string The combined status of all rooms within the house.
     */
    std::string getStatus() const override;   // Method to get the status of all devices in the house

    /**
     * @brief Get the type of device.
     * 
     * This method indicates the type of device represented by this class.
     * 
     * @return std::string "House", specifying the device type.
     */
    std::string getDeviceType() const override { return "House"; } // Return "House" as the device type

    /**
     * @brief Executes a command on the house.
     * 
     * This stub function is part of the Command Design Pattern, and will eventually
     * execute a command that affects all rooms in the house.
     */
    void House::execute() override {
        // Stub: Implementation for executing commands on the house's rooms will go here.
    }

    /**
     * @brief Updates the house based on sensor data.
     * 
     * This stub function is part of the Observer Design Pattern, and will eventually
     * handle updates from sensors, affecting the rooms and devices in the house.
     * 
     * @param sensorType The type of sensor that triggered the update.
     * @param sensorData The data provided by the sensor.
     */
    void House::update(const std::string &sensorType, const std::string &sensorData) override {
        // Stub: Implementation for updating house based on sensor input will go here.
    }
};

#endif // HOUSE_H

