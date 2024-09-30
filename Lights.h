#include "Device.h"
#include <iostream>

/**
 * @brief Concrete Light class that responds to sensor notifications by turning on/off.
 */
class Lights : public Device 
{
public:
   
   //this is for Obsever  pattern
   Lights(){};
   void execute() override;
    void update(const std::string& sensorType, const std::string& sensorData)override;
};
