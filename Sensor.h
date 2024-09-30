//Class defintion for Component 4  - Observer(Subject)
#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include <algorithm>
#include "Device.h"


class Sensor 
{
public:
    virtual void addDevice(Device* device) = 0;
    virtual void removeDevice(Device* device) = 0;
    virtual void notifyDevices() = 0;
    virtual ~Sensor() {}
};

#endif 
