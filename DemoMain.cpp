#include <iostream>
#include <memory>
#include <thread>
#include <chrono>

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

#include "LockAllDoors.h"
#include "TurnOffAllLights.h"
#include "MacroRoutine.h"
#include "SmartDoorLockSystem.h"
#include "SmartLightingSystem.h"
#include "Lights.h"
#include "Alarm.h"
#include "Thermostat.h"
#include "MotionSensor.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "Dehumidifier.h"

void showWelcomeMessage() {
    std::cout << "\n🌟 Welcome to the Smart Home Test Suite 🌟\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "🔧 Prepare to test various Design Patterns used in this Smart Home System! 🔧\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    std::cout << "🏡 Let's get started! 🏡\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void showLoadingAnimation() {
    std::string loading = "Loading";
    for (int i = 0; i < 3; ++i) {
        std::cout << loading;
        for (int j = 0; j < 3; ++j) {
            std::cout << ".";
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        }
        std::cout << "\r" << std::string(loading.size() + 3, ' ') << "\r";
    }
    std::cout << "Ready! ✅\n" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}

void displayMenu() {
    std::cout << "Please select a Design Pattern to test:\n";
    std::cout << "1️⃣  State Pattern\n";
    std::cout << "2️⃣  Composite Pattern\n";
    std::cout << "3️⃣  Adapter Pattern\n";
    std::cout << "4️⃣  Command Pattern\n";
    std::cout << "5️⃣  Observer Pattern\n";
    std::cout << "6️⃣  Exit\n";
    std::cout << "👉 Enter your choice: ";
}
// Helper function to simulate a loading animation
void loadingAnimation(const std::string& message) {
    std::cout << message << " ";
    for (int i = 0; i < 3; ++i) {
        std::cout << ".";
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << " ✅\n";
}

// Helper function to test device state and actions
void testDevice(const std::shared_ptr<SmartDevice>& device, const std::string& action) {
    std::cout << "🔍 Testing device: " << device->getDeviceType() << " 🔧" << std::endl;
    std::cout << "💡 Initial Status: " << device->getStatus() << std::endl;

    // Perform the action with animation
    loadingAnimation("⏳ Performing action");

    device->performAction(action);

    std::cout << "🔄 After action (" << action << "): " << device->getStatus() << std::endl;
    std::cout << "------------------------------------\n";
}

void adaptertesting() {
    // Create a LegacyThermostat instance (legacy device)
    std::shared_ptr<LegacyThermostat> legacyThermostat = std::make_shared<LegacyThermostat>();

    // Use SmartThermostatIntegrator to adapt the legacy thermostat
    SmartThermostatIntegrator smartThermostat(legacyThermostat);

    // Display the initial temperature
    std::cout << "🌡️  Initial temperature: " << smartThermostat.getTemperature() << "°C\n\n";

    // Set the temperature to 20.0°C
    std::cout << "🔧 Setting temperature to 20.0°C...\n";
    smartThermostat.setTemperature(20.0f);
    std::cout << "🌡️  Updated temperature: " << smartThermostat.getTemperature() << "°C\n\n";

    // Get the temperature
    std::cout << "🔍 Checking current temperature...\n";
    std::cout << "🌡️  Temperature: " << smartThermostat.getTemperature() << "°C\n\n";

    // Perform multiple temperature increase actions
    std::cout << "⬆️ Increasing temperature by 1°C, 3 times...\n";
    for (int i = 0; i < 3; ++i) {
        smartThermostat.performAction("IncreaseTemperature");
        std::cout << "🌡️  Temperature after increase: " << smartThermostat.getTemperature() << "°C\n";
    }
    std::cout << std::endl;

    // Perform multiple temperature decrease actions
    std::cout << "⬇️ Decreasing temperature by 1°C, 2 times...\n";
    for (int i = 0; i < 2; ++i) {
        smartThermostat.performAction("DecreaseTemperature");
        std::cout << "🌡️  Temperature after decrease: " << smartThermostat.getTemperature() << "°C\n";
    }
    std::cout << std::endl;

    // Test handling of an invalid action
    std::cout << "❗ Attempting an invalid action...\n";
    try {
        smartThermostat.performAction("InvalidAction");
    } catch (const std::exception& e) {
        std::cout << "⚠️  Exception caught: " << e.what() << "\n\n";
    }

    // Output device information
    std::cout << "📟 Device Type: " << smartThermostat.getDeviceType() << "\n";
    std::cout << "ℹ️  Status: " << smartThermostat.getStatus() << "\n\n";
}

void statetesting() {
    std::cout << "🏠 ===== SMART HOME DEVICE TESTING =====\n" << std::endl;

    // Create smart devices
    std::shared_ptr<SmartLight> smartLight = std::make_shared<SmartLight>();
    std::shared_ptr<SmartDoorlock> smartDoorLock = std::make_shared<SmartDoorlock>();
    std::shared_ptr<SmartThermostat> smartThermostat = std::make_shared<SmartThermostat>();

    // 1. Test SmartLight
    std::cout << "1️⃣  Testing SmartLight 💡" << std::endl;
    testDevice(smartLight, "ToggleOn");     // Turn the light on
    testDevice(smartLight, "ToggleOff");    // Turn the light off

    // 2. Test SmartDoorLock
    std::cout << "2️⃣  Testing SmartDoorLock 🔒" << std::endl;
    testDevice(smartDoorLock, "Lock");      // Lock the door
    testDevice(smartDoorLock, "Unlock");    // Unlock the door

    // 3. Test SmartThermostat
    std::cout << "3️⃣  Testing SmartThermostat 🌡️" << std::endl;
    testDevice(smartThermostat, "Heat");    // Set thermostat to heating mode
    testDevice(smartThermostat, "Cool");    // Set thermostat to cooling mode

    // Additional test cases (toggle back and forth)
    std::cout << "===== 🔄 ADDITIONAL STATE TRANSITIONS 🔄 =====" << std::endl;

    // Toggle SmartLight back to On
    std::cout << "4️⃣  Toggle SmartLight Back On 💡" << std::endl;
    testDevice(smartLight, "ToggleOn");

    // Lock and Unlock SmartDoorLock again
    std::cout << "5️⃣  Lock and Unlock SmartDoorLock 🔒" << std::endl;
    testDevice(smartDoorLock, "Lock");
    testDevice(smartDoorLock, "Unlock");

    // Switch between Heating and Cooling modes for SmartThermostat
    std::cout << "6️⃣  Switch SmartThermostat Modes 🌡️" << std::endl;
    testDevice(smartThermostat, "Heat");
    testDevice(smartThermostat, "Cool");

    std::cout << "\n🏁 ===== TESTING COMPLETE ===== 🏁\n" << std::endl;
}

void compositetesting() {
    std::cout << "🏗️ Creating Smart Home Setup...\n";

    // Create a house
    auto myHouse = std::make_shared<House>("My Smart House 🏠");

    // Create rooms
    auto livingRoom = std::make_shared<Room>("Living Room 🛋️");
    auto kitchen = std::make_shared<Room>("Kitchen 🍳");

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

    std::cout << "🛠️ Testing Smart Devices in Living Room:\n";

    // Perform actions on the light
    std::cout << "💡 Turning on the light...\n";
    loadingAnimation("⏳ Action in progress");
    smartLight->performAction("ToggleOn");
    std::cout << "💡 Light Status: " << smartLight->getStatus() << "\n";

    // Perform action on the thermostat
    std::cout << "🌡️ Setting thermostat to 22°C...\n";
    loadingAnimation("⏳ Adjusting temperature");
    smartThermostat->performAction("Heat");
    std::cout << "🌡️ Thermostat Status: " << smartThermostat->getStatus() << "\n";

    // Perform action on the door lock
    std::cout << "🔒 Locking the door...\n";
    loadingAnimation("⏳ Locking");
    smartDoorLock->performAction("Lock");
    std::cout << "🔒 Door Lock Status: " << smartDoorLock->getStatus() << "\n";

    // Final check on the entire house status
    std::cout << "🏡 House Status: " << myHouse->getStatus() << "\n";
}

void testingCommand() {
    std::cout << "🔑 === Testing Smart Door Lock System ===\n";
    SmartDoorLockSystem doorLockSystem;
    LockAllDoors lockDoorsCommand(&doorLockSystem);
    loadingAnimation("🔒 Locking all doors");
    lockDoorsCommand.execute();

    std::cout << "\n💡 === Testing Smart Lighting System ===\n";
    SmartLightingSystem lightingSystem;
    TurnOffAllLights turnOffLightsCommand(&lightingSystem);
    loadingAnimation("💡 Turning off all lights");
    turnOffLightsCommand.execute();

    std::cout << "\n🔄 === Testing Macro Routine ===\n";
    MacroRoutine macro("Night Routine 🌙");

    macro.addProcedure(&lockDoorsCommand);
    macro.addProcedure(&turnOffLightsCommand);

    MacroRoutine::saveMacro("Night Routine", &macro);

    MacroRoutine::listSavedMacros();

    std::cout << "\n📂 === Testing Loaded Macro ===\n";
    loadingAnimation("📥 Loading saved Goodnight Routine");
    MacroRoutine* loadedMacro = MacroRoutine::loadMacro("Goodnight");
    if (loadedMacro) {
        loadedMacro->execute();
    }
}

void testingObserver() {
    std::cout << "👁️ ----- Testing Motion Sensor -----\n";

    MotionSensor motionSensor;
    Lights light;
    Alarm alarm;

    motionSensor.addDevice(&light);
    motionSensor.addDevice(&alarm);

    std::cout << "\n🎯 Detecting motion...\n";
    loadingAnimation("⏳ Motion detected");
    motionSensor.detectMotion();

    std::cout << "\n❌ Clearing motion...\n";
    loadingAnimation("⏳ Motion cleared");
    motionSensor.clearMotion();

    std::cout << "\n🔕 Removing Alarm and detecting motion again...\n";
    motionSensor.removeDevice(&alarm);
    motionSensor.detectMotion();

    std::cout << "\n🌡️ ----- Testing Temperature Sensor -----\n";
    TemperatureSensor tempSensor;
    Thermostat thermostat;
     
    std::cout << "\nTesting high temperature detected...\n";
    tempSensor.detectHighTemperature();  // Expect Thermostat to react to high temperature

    
    std::cout << "\nTesting low temperature detected...\n";
    tempSensor.detectLowTemperature(); 

    std::cout << "\n----- Testing Humidity Sensor -----\n";

    
    HumiditySensor humiditySensor;
    Dehumidifier dehumidifier;

   
    humiditySensor.addDevice(&dehumidifier);

    
    std::cout << "\nTesting high humidity detected...\n";
    humiditySensor.detectHighHumidity();  // Expect Dehumidifier to react to high humidity

    
    std::cout << "\nTesting low humidity detected...\n";
    humiditySensor.detectLowHumidity(); 
}

void executeChoice(int choice) {
    switch (choice) {
        case 1:
            std::cout << "\n🟢 Testing State Pattern 🟢\n" << std::endl;
            showLoadingAnimation();
            statetesting();
            break;
        case 2:
            std::cout << "\n🏗️  Testing Composite Pattern 🏗️\n" << std::endl;
            showLoadingAnimation();
            compositetesting();
            break;
        case 3:
            std::cout << "\n🔌 Testing Adapter Pattern 🔌\n" << std::endl;
            showLoadingAnimation();
            adaptertesting();
            break;
        case 4:
            std::cout << "\n🎛️  Testing Command Pattern 🎛️\n" << std::endl;
            showLoadingAnimation();
            testingCommand();
            break;
        case 5:
            std::cout << "\n🔍 Testing Observer Pattern 🔍\n" << std::endl;
            showLoadingAnimation();
            testingObserver();
            break;
        case 6:
            std::cout << "\n👋 Exiting the Test Suite. Goodbye! 👋\n";
            break;
        default:
            std::cout << "\n❌ Invalid choice! Please select a valid option. ❌\n";
            break;
    }
}

int main() 
{
    showWelcomeMessage();

    int choice = 0;

    while (choice != 6) {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // clear error flag
            std::cin.ignore(10000, '\n'); // discard invalid input
            std::cout << "\n❌ Invalid input! Please enter a number between 1 and 6. ❌\n";
            continue;
        }

        executeChoice(choice);

        if (choice != 6) {
            std::cout << "\n🏡 Returning to the main menu... 🏡\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    return 0;
}