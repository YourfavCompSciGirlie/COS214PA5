//Class defintion for Component 4  - Observer(ConcreteSubject)
#include "HumiditySensor.h"


void HumiditySensor::addDevice(Device* device) 
{
    devices.push_back(device);
}


void HumiditySensor::removeDevice(Device* device) 
{
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}


void HumiditySensor::notifyDevices() 
{
    for (Device* device : devices) {
        device->update("humidity", sensorState);
    }
}


void HumiditySensor::detectHighHumidity() 
{
    sensorState = "high";
    notifyDevices();
}


void HumiditySensor::detectLowHumidity() 
{
    sensorState = "low";
    notifyDevices();
}
