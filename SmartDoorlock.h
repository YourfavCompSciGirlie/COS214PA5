// Class definition for Component 1 - Composite (Leaf)

/**
 * @file SmartDoorlock.h
 * @brief Header file for the SmartDoorlock class, representing a smart door lock device.
 *
 * The SmartDoorlock class is a leaf in the Composite design pattern and represents a
 * single smart door lock device. It performs actions based on its current state, such as
 * locking or unlocking the door.
 */

#ifndef SMARTDOORLOCK_H
#define SMARTDOORLOCK_H

#include "SmartDevice.h"
#include "DeviceState.h"
#include <memory>
#include <string>

/**
 * @class SmartDoorlock
 * @brief A concrete class representing a smart door lock device.
 *
 * The SmartDoorlock class inherits from SmartDevice and represents a single smart door lock.
 * It implements methods for performing actions and retrieving the current status based on the state pattern.
 */

class SmartDoorlock : public SmartDevice
{

public:
    /**
     * @brief Construct a new SmartDoorlock object.
     *
     * The constructor initializes the smart door lock with an unlocked state.
     */
    SmartDoorlock();

    /**
     * @brief Perform an action on the smart door lock.
     *
     * This method delegates the provided action to the current state of the smart door lock.
     * Possible actions include locking or unlocking the door.
     *
     * @param action The action to be performed on the smart door lock.
     */
    void performAction(const std::string &action) override;

    /**
     * @brief Get the current status of the smart door lock.
     *
     * This method retrieves the status of the smart door lock based on its current state,
     * such as whether the door is locked or unlocked.
     *
     * @return std::string The current status of the smart door lock (e.g., "locked" or "unlocked").
     */
    std::string getStatus() const override;

    /**
     * @brief Get the device type of the smart door lock.
     *
     * This method returns the type of device, which is "SmartDoorLock" for this class.
     *
     * @return std::string The string "SmartDoorLock".
     */
    std::string getDeviceType() const override;
};

#endif // SMARTDOORLOCK_H
