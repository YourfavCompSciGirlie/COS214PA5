//Class defintion for Component 4  - Observer(ConcreteObserver)

#ifndef DEHUMIDIFIER_H
#define DEHUMIDIFIER_H

#include "Device.h"

class Dehumidifier : public Device 
{
public:
    void update(const std::string& sensorType, const std::string& sensorData) override;
    void execute() override;
};
#endif 
