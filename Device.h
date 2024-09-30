// Class defintion for Component 3  - Command(Command)

#ifndef DEVICE_H
#define DEVICE_H
#include <string>

/**
 * @brief Abstract Device class representing a device that responds to sensor notifications.
 */

class Device
{
public:
   // for the Command Design Pattern
   virtual void execute() = 0;
   virtual ~Device() {}

   // for the Observer Design Pattern
   virtual void update(const std::string &sensorType, const std::string &sensorData) = 0;
};
#endif
