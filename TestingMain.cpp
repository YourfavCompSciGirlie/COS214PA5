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

#include "House.h"
#include "Room.h"

#include "SmartThermostatIntegrator.h"
#include "LegacyThermostat.h"
#include "Device.h"


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

void compositetesting() {
    // Create a house
    auto myHouse = std::make_shared<House>("My Smart House");

    // Create rooms
    auto livingRoom = std::make_shared<Room>("Living Room");
    auto kitchen = std::make_shared<Room>("Kitchen");

    // Add rooms to the house
    myHouse->add(livingRoom);
    myHouse->add(kitchen);

    // Create smart devices
    auto smartLight = std::make_shared<SmartLight>();
    auto smartThermostat = std::make_shared<SmartThermostat>();
    auto smartDoorLock = std::make_shared<SmartDoorlock>();

    // Add devices to living room
    livingRoom->add(smartLight);
    livingRoom->add(smartThermostat);
    livingRoom->add(smartDoorLock);

    // Test device actions and status
    std::cout << "Testing Smart Devices in Living Room:\n";

    // Perform actions on the light
    std::cout << "Performing action: Turn on the light.\n";
    smartLight->performAction("ToggleOn");
    std::cout << "Light Status: " << smartLight->getStatus() << "\n"; // Expect "on"

    // Perform action on the thermostat
    std::cout << "Performing action: Set temperature to 22°C.\n";
    smartThermostat->performAction("Heat");
    std::cout << "Thermostat Status: " << smartThermostat->getStatus() << "\n"; // Expect "heating"

    // Perform action on the door lock
    std::cout << "Performing action: Lock the front door.\n";
    smartDoorLock->performAction("Lock");
    std::cout << "Door Lock Status: " << smartDoorLock->getStatus() << "\n"; // Expect "locked"

    // Check room status
    std::cout << "Living Room Status: " << livingRoom->getStatus() << "\n"; // Expect combined status

    // Test getDeviceType in Room
    std::cout << "Device Type of Living Room: " << livingRoom->getDeviceType() << "\n"; // Expect "Room"

    // Check house status
    std::cout << "House Status: " << myHouse->getStatus() << "\n"; // Expect combined status of rooms

    // Test getChild in Room
    std::cout << "Testing getChild in Living Room:\n";
    auto retrievedDevice = livingRoom->getChild(0); // Retrieve the first device
    if (retrievedDevice) {
        std::cout << "Retrieved Device Type: " << retrievedDevice->getDeviceType() << "\n"; // Should match type of smartLight
    } else {
        std::cout << "Failed to retrieve device.\n";
    }

    // Test getChild in House
    std::cout << "Testing getChild in House:\n";
    auto retrievedRoom = myHouse->getChild(0); // Retrieve the first room
    if (retrievedRoom) {
        std::cout << "Retrieved Room Name: " << retrievedRoom->getRoomName() << "\n"; // Should call getRoomName()
    } else {
        std::cout << "Failed to retrieve room.\n";
    }

    // Test removing a device from the room
    std::cout << "Removing the thermostat from the Living Room.\n";
    livingRoom->remove(smartThermostat);
    std::cout << "Living Room Status after removal: " << livingRoom->getStatus() << "\n"; // Expect updated status

    // Add another device to kitchen and test
    auto kitchenLight = std::make_shared<SmartLight>();
    kitchen->add(kitchenLight);
    std::cout << "Performing action: Turn on the kitchen light.\n";
    kitchenLight->performAction("ToggleOn");
    std::cout << "Kitchen Light Status: " << kitchenLight->getStatus() << "\n"; // Expect "on"

    // Final check on the entire house status
    std::cout << "Final House Status: " << myHouse->getStatus() << "\n"; // Expect combined status
}

void adaptertesting() {
    // Create a LegacyThermostat
    std::shared_ptr<LegacyThermostat> legacyThermostat = std::make_shared<LegacyThermostat>();
    
    // Create a SmartThermostatIntegrator to adapt the legacy thermostat
    SmartThermostatIntegrator smartThermostat(legacyThermostat);

    // Getting an initial temperature
    std::cout << "Current temperature: " << smartThermostat.getTemperature() << "°C" << std::endl;


    // Setting the temperature
    std::cout << "Setting initial temperature to 20.0°C..." << std::endl;
    smartThermostat.setTemperature(20.0f);
    std::cout << "Current temperature: " << smartThermostat.getTemperature() << "°C" << std::endl;

    // Test getting the temperature
    std::cout << "Getting temperature: " << smartThermostat.getTemperature() << "°C" << std::endl;

    // Multiple increase actions
    for (int i = 0; i < 3; ++i) {
        std::cout << "Increasing temperature by 1°C..." << std::endl;
        smartThermostat.performAction("IncreaseTemperature");
        std::cout << "Current temperature after increase: " << smartThermostat.getTemperature() << "°C" << std::endl;
    }

    // Multiple decrease actions
    for (int i = 0; i < 2; ++i) {
        std::cout << "Decreasing temperature by 1°C..." << std::endl;
        smartThermostat.performAction("DecreaseTemperature");
        std::cout << "Current temperature after decrease: " << smartThermostat.getTemperature() << "°C" << std::endl;
    }

    // Test invalid action
    try {
        std::cout << "Trying to perform an invalid action..." << std::endl;
        smartThermostat.performAction("InvalidAction"); // No handling for this action
    } catch (const std::exception& e) {
        std::cout << "Caught an exception: " << e.what() << std::endl;
    }

    // Output the device type
    std::cout << "Device Type: " << smartThermostat.getDeviceType() << std::endl;

    // Output the status of the SmartThermostatIntegrator
    std::cout << "Status: " << smartThermostat.getStatus() << std::endl;
}




int main () {

    // statetesting();
    // compositetesting();
    adaptertesting();



    return 0;
}