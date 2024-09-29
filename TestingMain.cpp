#include <iostream>
#include <memory>

#include "SmartLight.h"
#include "SmartDoorlock.h"
#include "SmartThermostat.h"
#include "OnState.h"
#include "OffState.h"
#include "LockedState.h"
#include "UnlockedState.h"
#include "CoolingState.h"
#include "HeatingState.h"

// Helper function to test device state and actions
void testDevice(const std::shared_ptr<SmartDevice>& device, const std::string& action) {
    std::cout << "Testing device: " << device->getDeviceType() << std::endl;
    std::cout << "Initial Status: " << device->getStatus() << std::endl;
    
    // Perform the action
    device->performAction(action);
    
    std::cout << "After action (" << action << "): " << device->getStatus() << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

void statetesting() {
    std::cout << "===== SMART HOME DEVICE TESTING =====\n" << std::endl;

    // Create smart devices
    std::shared_ptr<SmartLight> smartLight = std::make_shared<SmartLight>();
    std::shared_ptr<SmartDoorlock> smartDoorLock = std::make_shared<SmartDoorlock>();
    std::shared_ptr<SmartThermostat> smartThermostat = std::make_shared<SmartThermostat>();

    // 1. Test SmartLight
    std::cout << "1. Testing SmartLight" << std::endl;
    testDevice(smartLight, "ToggleOn");     // Turn the light on
    testDevice(smartLight, "ToggleOff");    // Turn the light off

    // 2. Test SmartDoorLock
    std::cout << "2. Testing SmartDoorLock" << std::endl;
    testDevice(smartDoorLock, "Lock");      // Lock the door
    testDevice(smartDoorLock, "Unlock");    // Unlock the door

    // 3. Test SmartThermostat
    std::cout << "3. Testing SmartThermostat" << std::endl;
    testDevice(smartThermostat, "Heat");    // Set thermostat to heating mode
    testDevice(smartThermostat, "Cool");    // Set thermostat to cooling mode

    // Additional test cases (toggle back and forth)
    std::cout << "===== ADDITIONAL STATE TRANSITIONS =====" << std::endl;

    // Toggle SmartLight back to On
    std::cout << "4. Toggle SmartLight Back On" << std::endl;
    testDevice(smartLight, "ToggleOn");

    // Lock and Unlock SmartDoorLock again
    std::cout << "5. Lock and Unlock SmartDoorLock" << std::endl;
    testDevice(smartDoorLock, "Lock");
    testDevice(smartDoorLock, "Unlock");

    // Switch between Heating and Cooling modes for SmartThermostat
    std::cout << "6. Switch SmartThermostat Modes" << std::endl;
    testDevice(smartThermostat, "Heat");
    testDevice(smartThermostat, "Cool");

    std::cout << "\n===== TESTING COMPLETE =====\n" << std::endl;
}







int main () {

    statetesting();



    return 0;
}