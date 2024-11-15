
#include "../../app_drivers/inc/sensor.h"

#include "main.h"

double temp_10k_Sensor_2;
double temp_10k_Sensor_1;
double temp_10k_Sensor_3;
float vref = 3.30;

float calib_can_1 = 1;
float calib_can_2 = 1;
float calib_can_3 = 1 ;

float voltage_1;
float voltage_2;
float voltage_3;

float calib_1 = 0.9933;
float calib_2 = 0.9933;
float calib_3 = 0.9933;

const float voltages[] = {
    1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5, 5.0, 5.5, 6.0, 6.5, 7.0, 7.5, 8.0, 8.5, 9.0, 9.5, 10.0, 10.5,
    11.0, 11.5, 12.0, 12.5, 13.0, 13.5, 14.0, 14.5, 15.0, 15.5, 16.0, 16.5, 17.0, 17.5, 18.0, 18.5, 19.0, 19.5,
    20.0, 20.5, 21.0, 21.5, 22.0, 22.5, 23.0, 23.5, 24.0, 24.5, 25.0, 25.5, 26.0, 26.5, 27.0, 27.5, 28.0, 28.5,
    29.0, 29.5, 30.0, 30.5, 31.0, 31.5, 32.0, 32.5, 33.0, 33.5, 34.0, 34.5, 35.0, 35.5, 36.0, 36.5, 37.0, 37.5,
    38.0, 38.5, 39.0, 39.5, 40.0, 40.25, 40.5, 40.75, 41.0, 41.25, 41.5, 41.75, 42.0, 42.25, 42.5, 42.75, 43.0,
    43.25, 43.5, 43.75, 44.0, 44.25, 44.5, 44.75, 45.0, 45.25, 45.5, 45.75, 46.0, 46.25, 46.5, 46.75, 47.0,
    47.25, 47.5, 47.75, 48.0, 48.25, 48.5, 48.75, 49.0, 49.25, 49.5, 49.75, 50.0, 50.25, 50.5, 50.75, 51.0,
    51.25, 51.5, 51.75, 52.0, 52.25, 52.5, 52.75, 53.0, 53.25, 53.5, 53.75, 54.0, 54.25, 54.5, 54.75, 55.0,
    55.25, 55.5, 55.75, 56.0, 56.25, 56.5, 56.75, 57.0, 57.25, 57.5, 57.75, 58.0, 58.25, 58.5, 58.75, 59.0,
    59.25, 59.5, 59.75, 60.0, 60.25, 60.5, 60.75, 61.0
};

const uint32_t adcValues[] = {
    0, 31, 63, 96, 128, 160, 193, 226, 258, 290, 323, 355, 388, 420, 453, 486, 518, 551, 583, 615,
    648, 680, 713, 745, 778, 811, 843, 876, 908, 940, 973, 1006, 1038, 1071, 1103, 1136, 1169, 1201,
    1234, 1267, 1299, 1331, 1364, 1396, 1429, 1461, 1494, 1527, 1559, 1592, 1624, 1657, 1689, 1722,
    1755, 1787, 1820, 1852, 1885, 1918, 1950, 1983, 2016, 2048, 2081, 2114, 2146, 2179, 2211, 2244,
    2277, 2309, 2342, 2375, 2407, 2440, 2473, 2506, 2538, 2555, 2572, 2588, 2604, 2621, 2637, 2653,
    2670, 2686, 2703, 2719, 2736, 2752, 2769, 2785, 2802, 2819, 2835, 2851, 2868, 2884, 2901, 2918,
    2934, 2950, 2967, 2984, 3000, 3016, 3032, 3049, 3065, 3082, 3096, 3116, 3132, 3149, 3165, 3182,
    3198, 3214, 3231, 3247, 3263, 3280, 3297, 3314, 3330, 3346, 3363, 3379, 3396, 3412, 3429, 3445,
    3462, 3479, 3495, 3512, 3527, 3544, 3560, 3577, 3594, 3610, 3627, 3643, 3659, 3676, 3692, 3709,
    3726, 3743, 3759, 3776, 3792, 3809, 3825, 3841, 3858, 3874, 3891, 3905, 3922
};

/****
 * 4136-3.36v
 *2.6883645V -2.8416324V
 */

void battery_voltage(void)
{

	voltage_1 = mapADCValueToVoltage(adc_raw_data_1[adc1_1])*calib_1*calib_can_1;

	voltage_2 = mapADCValueToVoltage(adc_raw_data_1[adc1_2])*calib_2*calib_can_2;

	voltage_3 = mapADCValueToVoltage(adc_raw_data_1[adc1_3])*calib_3*calib_can_3;

}
float mapADCValueToVoltage(uint32_t adcValue)
{

    int size = sizeof(adcValues) / sizeof(adcValues[0]);

    if (adcValue <= adcValues[0])
    {
        return voltages[0];
    }

    if (adcValue >= adcValues[size - 1])
    {
        return voltages[size - 1];
    }

    for (int i = 0; i < size - 1; i++)
    {
        if (adcValue >= adcValues[i] && adcValue <= adcValues[i + 1])
        {
            float slope = (voltages[i + 1] - voltages[i]) / (adcValues[i + 1] - adcValues[i]);
            return voltages[i] + slope * (adcValue - adcValues[i]);
        }
    }

    return 0.0; // Default return value in case of an error
}


void temp_Sensor_1(void)
{
	float temp_out;
	float temperature_out, T_out, therm_res_ln_out;
    temp_out =  adc_raw_data_1[adc1_4];
    temp_out = ( (temp_out * 3.30) / 4080.0 );
    temperature_out = ((temp_out*10)/(3.30 - temp_out))/2; /* Resistance in kilo ohms */
    temperature_out = temperature_out * 1000 ;
    therm_res_ln_out = log(temperature_out);
    T_out = ( 1 / ( 0.001125308852122 + ( 0.000234711863267 * therm_res_ln_out ) + ( 0.000000088063516 * therm_res_ln_out * therm_res_ln_out * therm_res_ln_out ) ) ); /* Temperature in Kelvin */
    temp_10k_Sensor_1 = T_out - 273.15 ;

}

void temp_Sensor_2(void)
{

    float temp_in;
    float temperature, T_IN, therm_res_ln;
    temp_in = adc_raw_data_1[adc1_5];
    temp_in = ( (temp_in * 3.30) / 4080.0 );
    temperature = ((temp_in*10)/(3.30 - temp_in))/2; /* Resistance in kilo ohms */
    temperature = temperature * 1000 ;
    therm_res_ln = log(temperature);
    T_IN = ( 1 / ( 0.001125308852122 + ( 0.000234711863267 * therm_res_ln ) + ( 0.000000088063516 * therm_res_ln * therm_res_ln * therm_res_ln ) ) ); /* Temperature in Kelvin */
    temp_10k_Sensor_2 = T_IN - 273.15;

}

void temp_Sensor_3(void)
{
	float temp_amb;
    float temperature_amb, T_amb, therm_res_ln_amb;
    temp_amb =  adc_raw_data_1[adc1_6];
    temp_amb = ( (temp_amb * 3.30) / 4080.0 );
    temperature_amb = ((temp_amb*10)/(3.30 - temp_amb))/2; /* Resistance in kilo ohms */
    temperature_amb = temperature_amb * 1000 ;
    therm_res_ln_amb = log(temperature_amb);
    T_amb = ( 1 / ( 0.001125308852122 + ( 0.000234711863267 * therm_res_ln_amb ) + ( 0.000000088063516 * therm_res_ln_amb * therm_res_ln_amb * therm_res_ln_amb ) ) ); /* Temperature in Kelvin */
    temp_10k_Sensor_3 = T_amb - 273.15;



}
void adc_control(void)
{
	adc_conversion_1();
	battery_voltage();
	temp_Sensor_1();
	temp_Sensor_2();
	temp_Sensor_3();
//	ACS712_20A();


}
//0.0979999974

float sensitivity = 0.1; // 0.34 FOR 5A; // 0.1 for 20A Model
float rawVoltage;
extern float current;
uint8_t flag_current_sensor = 0;
void ACS712_20A(void)
{

    rawVoltage = (float) adc_raw_data_1[adc1_1] * 3.3/ 4040;
    // If rawVoltage is not 2.5Volt, multiply by a factor.In my case it is 1.035
    // This is due to tolerance in voltage divider resister & ADC accuracy
    current =(rawVoltage - 2.5)/sensitivity;

    if(current > 6 )
    {
    	flag_current_sensor = 1;
    }
    else
    {
    	flag_current_sensor = 0;
    }

}
