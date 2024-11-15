#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_

#include "main.h"

#include "../../app_drivers/inc/adc.h"
#include "../../app_drivers/inc/common.h"
#include "../../app_drivers/inc/dbc.h"
#include "../../app_drivers/inc/middleware.h"

extern double temp_10k_Sensor_2;
extern double temp_10k_Sensor_1;
extern double temp_10k_Sensor_3;

extern float voltage_1;
extern float voltage_2;
extern float voltage_3;

extern float calib_1;
extern float calib_2;
extern float calib_3;

void battery_voltage(void);
void temp_Sensor_1(void);
void temp_Sensor_2(void);
void temp_Sensor_3(void);
void ACS712_20A(void);
void adc_control(void);

float mapADCValueToVoltage(uint32_t adcValue);

#endif /* INC_SENSOR_H_ */



