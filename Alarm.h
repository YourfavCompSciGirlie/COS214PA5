#include "Device.h"
#include <iostream>

/**
 * @brief Concrete Alarm class that responds to sensor notifications by triggering an alarm.
 */
class Alarm : public Device 
{
public:
    //For Observer  pattern
    void execute() override;
     void update(const std::string& sensorType, const std::string& sensorData);
};
