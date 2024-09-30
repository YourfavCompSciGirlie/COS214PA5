#include "MotionSensor.h"


void MotionSensor::addDevice(Device* device) 
{
    devices.push_back(device);
}


void MotionSensor::removeDevice(Device* device) 
{
    devices.erase(std::remove(devices.begin(), devices.end(), device), devices.end());
}


void MotionSensor::notifyDevices() 
{
    for (Device* device : devices) {
        device->update("motion", sensorState);
    }
}


void MotionSensor::detectMotion() 
{
    sensorState = "detected";
    notifyDevices();
}


void MotionSensor::clearMotion() 
{
    sensorState = "clear";
    notifyDevices();
}
