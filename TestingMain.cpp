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
#include "Device.h"
#include <iostream>


void testingCommand()
{
    
    std::cout << "=== Testing Smart Door Lock System ===" << std::endl;
    SmartDoorLockSystem doorLockSystem;
    LockAllDoors lockDoorsCommand(&doorLockSystem);
    lockDoorsCommand.execute();  // This should lock all doors and print status

    std::cout << std::endl;

    
    std::cout << "=== Testing Smart Lighting System ===" << std::endl;
    SmartLightingSystem lightingSystem;
    TurnOffAllLights turnOffLightsCommand(&lightingSystem);
    turnOffLightsCommand.execute();  // This should turn off all lights and print status

    std::cout << std::endl;

   
    std::cout << "=== Testing Macro Routine ===" << std::endl;
    MacroRoutine macro("Night Routine");

    
    macro.addProcedure(&lockDoorsCommand);
    macro.addProcedure(&turnOffLightsCommand);

    
    MacroRoutine::saveMacro("Night Routine", &macro);

    
    MacroRoutine::listSavedMacros();

    std::cout << std::endl;

    
    std::cout << "=== Testing Loaded Macro ===" << std::endl;
    std::cout << "\nLoading and executing the saved Goodnight Routine..." << std::endl;
    MacroRoutine* loadedMacro = MacroRoutine::loadMacro("Goodnight");
    if (loadedMacro) {
        loadedMacro->execute();
    }

    std::cout << std::endl;

   
    std::cout << "=== Testing Removing Procedures from Macro ===" << std::endl;
    macro.removeProcedure(&lockDoorsCommand);
    macro.removeProcedure(&turnOffLightsCommand);

    // Ensure macros still list correctly after removal
    MacroRoutine::listSavedMacros();
}

void testingObserver()
{
    std::cout << "----- Testing Motion Sensor -----\n";

    
    MotionSensor motionSensor;
    Lights light;
    Alarm alarm;

    
    motionSensor.addDevice(&light);
    motionSensor.addDevice(&alarm);

   
    std::cout << "\nTesting motion detected...\n";
    motionSensor.detectMotion();  // Expect both SmartLight and SmartAlarm to react

   
    std::cout << "\nTesting motion cleared...\n";
    motionSensor.clearMotion();  // Expect both SmartLight and SmartAlarm to react

    
    std::cout << "\nTesting after removing SmartAlarm...\n";
    motionSensor.removeDevice(&alarm);
    motionSensor.detectMotion();  // Expect only SmartLight to react


    std::cout << "\n----- Testing Temperature Sensor -----\n";

    
    TemperatureSensor tempSensor;
    Thermostat thermostat;

    
    tempSensor.addDevice(&thermostat);

    
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
int main() 
{
   std::cout << "TESTING COMMAND DESIGN PATTERN " << std::endl;
    testingCommand();
   std::cout << "TESTING OBSERVER DESIGN PATTERN " << std::endl;
   testingObserver();
    return 0;
}
