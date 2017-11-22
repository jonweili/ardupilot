/*
  simple hello world sketch
  Andrew Tridgell September 2011
*/

#include <AP_HAL/AP_HAL.h>

const AP_HAL::HAL& hal = AP_HAL::get_HAL();

void setup() {
	hal.uartD->println("hello world");
}

void loop()
{
	hal.scheduler->delay(1000);
	hal.uartD->println("*");
}

AP_HAL_MAIN();
