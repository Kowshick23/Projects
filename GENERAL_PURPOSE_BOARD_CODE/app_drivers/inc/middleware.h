#ifndef MIDDLEWARE_H_
#define MIDDLEWARE_H_

#include "main.h"

#include "../../app_drivers/inc/adc.h"
#include "../../app_drivers/inc/can_driver.h"
#include "../../app_drivers/inc/dbc.h"
#include "../../app_drivers/inc/gpio.h"
#include "../../app_drivers/inc/sensor.h"

 void pwm_init(void);
 void flowrate_init(void);
void middleware_variables_input(void);
void middleware_variables_output(void);
void can_control(void);
long map(long in_value, long in_min, long in_max, long out_min, long out_max) ;
void gpio_input_test(void);
void gpio_output_test(void);
void flowrate_time(void);
void pwm_output_test(void);
#endif

