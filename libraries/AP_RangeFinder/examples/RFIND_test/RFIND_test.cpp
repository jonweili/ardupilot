/*
 *  RangeFinder test code
 */

#include <AP_HAL/AP_HAL.h>
#include <AP_RangeFinder/AP_RangeFinder.h>

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

static AP_SerialManager serial_manager;
static RangeFinder sonar {serial_manager};

void setup()
{
    // print welcome message
    hal.uartD->println("Range Finder library test");

    // setup for analog pin 13
    /*
    AP_Param::set_object_value(&sonar, sonar.var_info, "_TYPE", RangeFinder::RangeFinder_TYPE_PLI2C);
    AP_Param::set_object_value(&sonar, sonar.var_info, "_PIN", -1);
    AP_Param::set_object_value(&sonar, sonar.var_info, "_SCALING", 1.0);
   */

    //steup for analog pin 14 (AD3.3)
    AP_Param::set_object_value(&sonar,sonar.var_info,"_TYPE",RangeFinder::RangeFinder_TYPE_ANALOG);
    AP_Param::set_object_value(&sonar, sonar.var_info, "_PIN", 14);
    AP_Param::set_object_value(&sonar, sonar.var_info, "_SCALING", 1.02354);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_FUNCTION",0);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_RMETRIC",1);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_STOP_PIN",-1);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_MAX_CM",500);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_MIN_CM",30);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_GNDCLEAR",2);
    AP_Param::set_object_value(&sonar,sonar.var_info,"_RNGFND_OFFSET",0.29);


    // initialise sensor, delaying to make debug easier
    hal.scheduler->delay(2000);
    sonar.init();
    hal.uartD->printf("RangeFinder: %d devices detected\n", sonar.num_sensors());
}

void loop()
{
    // Delay between reads  lala
    hal.scheduler->delay(100);
    sonar.update();

    hal.uartD->printf("Primary: status %d distance_cm %d \n", (int)sonar.status(), sonar.distance_cm());
    hal.uartD->printf("All: device_0 type %d status %d distance_cm %d, device_1 type %d status %d distance_cm %d\n",
    (int)sonar._type[0], (int)sonar.status(0), sonar.distance_cm(0), (int)sonar._type[1], (int)sonar.status(1), sonar.distance_cm(1));

}
AP_HAL_MAIN();
