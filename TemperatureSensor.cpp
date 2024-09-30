#include "TemperatureSensor.h"


void TemperatureSensor::addDevice(Device* device) 
{
    devices.push_back(device);
}


void TemperatureSensor::removeDevice(Device* device) 
{
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}


void TemperatureSensor::notifyDevices() 
{
    for (Device* device : devices) {
        device->update("temperature", sensorState);
    }
}


void TemperatureSensor::detectHighTemperature() 
{
    sensorState = "high";
    notifyDevices();
}


void TemperatureSensor::detectLowTemperature() 
{
    sensorState = "low";
    notifyDevices();
}
