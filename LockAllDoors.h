//Class defintion for Component 3  - Command(ConcreteCommand)

#ifndef LOCKALLDOORS_H
#define LOCKALLDOORS_H

#include "SmartDoorLockSystem.h"
#include "Device.h"

/**
 * @brief Command to lock all doors in a smart door lock system.
 */
class LockAllDoors : public Device
{
public:
    /**
     * @brief Constructs a LockAllDoors command.
     * @param locks Pointer to the SmartDoorLockSystem that manages the locks.
     */
    LockAllDoors(SmartDoorLockSystem* locks);

    /**
     * @brief Executes the command to lock all doors.
     * This function locks all doors in the SmartDoorLockSystem.
     */
    void execute();

    void update(const std::string& sensorType, const std::string& sensorData);

    // New methods for stubbing
    void performAction(const std::string& action) override;
    std::string getDeviceType() const override;
    std::string getStatus() const override;

private:
    SmartDoorLockSystem* locks; ///< Pointer to the smart door lock system.
};

#endif 

