
#include "../../app_drivers/inc/dbc.h"

/* Backend data storage global variables */
volatile uint32_t	can_data_adc_low_volt_1;
volatile uint32_t	can_data_adc_low_volt_2;
volatile uint32_t	can_data_adc_low_volt_3;
volatile uint32_t	can_data_adc_low_volt_4;
volatile float_t 	can_data_batt_volt_1;
volatile float_t 	can_data_batt_volt_2;
volatile float_t 	can_data_batt_volt_3;
volatile float_t 	can_data_batt_volt_1_gain_feedback;
volatile float_t 	can_data_batt_volt_2_gain_feedback;
volatile float_t 	can_data_batt_volt_3_gain_feedback;
volatile float_t 	can_data_batt_volt_1_gain_set;
volatile float_t 	can_data_batt_volt_2_gain_set;
volatile float_t 	can_data_batt_volt_3_gain_set;
volatile uint32_t	can_data_gpio_input_1;
volatile uint32_t	can_data_gpio_input_2;
volatile uint32_t	can_data_gpio_input_3;
volatile uint32_t	can_data_gpio_input_4;
volatile uint32_t	can_data_gpio_input_5;
volatile uint32_t	can_data_gpio_input_6;
volatile uint32_t	can_data_gpio_input_7;
volatile uint32_t	can_data_gpio_input_8;
volatile uint32_t	can_data_gpio_input_9;
volatile uint32_t	can_data_gpio_input_10;
volatile uint32_t	can_data_gpio_input_11;
volatile uint32_t	can_data_gpio_input_12;
volatile uint32_t	can_data_gpio_input_13;
volatile uint32_t	can_data_gpio_input_14;
volatile uint32_t	can_data_gpio_input_15;
volatile uint32_t	can_data_gpio_input_16;
volatile uint32_t	can_data_gpio_input_17;
volatile uint32_t	can_data_gpio_input_18;
volatile uint32_t	can_data_gpio_input_19;
volatile uint32_t	can_data_gpio_input_20;
volatile uint32_t	can_data_gpio_input_21;
volatile uint32_t	can_data_gpio_input_22;
volatile uint32_t	can_data_gpio_input_23;
volatile uint32_t	can_data_gpio_input_24;
volatile uint32_t	can_data_gpio_input_25;
volatile uint32_t	can_data_gpio_input_26;
volatile uint32_t	can_data_gpio_input_27;
volatile uint32_t	can_data_gpio_input_28;
volatile uint32_t	can_data_gpio_input_29;
volatile uint32_t	can_data_gpio_input_30;
volatile uint32_t	can_data_gpio_input_31;
volatile uint32_t	can_data_gpio_input_32;
volatile uint32_t	can_data_gpio_input_33;
volatile uint32_t	can_data_gpio_input_34;
volatile uint32_t	can_data_gpio_input_35;
volatile uint32_t	can_data_gpio_input_36;
volatile uint32_t	can_data_flowrate_1;
volatile uint32_t	can_data_flowrate_2;
volatile uint32_t	can_data_a1;
volatile uint32_t	can_data_a2;
volatile uint32_t	can_data_a3;
volatile uint32_t	can_data_a4;
volatile uint32_t	can_data_a5;
volatile uint32_t	can_data_a6;
volatile uint32_t	can_data_a7;
volatile uint32_t	can_data_a8;
volatile uint32_t	can_data_a9;
volatile uint32_t	can_data_a10;
volatile uint32_t	can_data_a11;
volatile uint32_t	can_data_a12;
volatile uint32_t	can_data_a13;
volatile uint32_t	can_data_a14;
volatile uint32_t	can_data_a15;
volatile uint32_t	can_data_a16;
volatile uint32_t	can_data_b1;
volatile uint32_t	can_data_b2;
volatile uint32_t	can_data_b3;
volatile uint32_t	can_data_b4;
volatile uint32_t	can_data_b5;
volatile uint32_t	can_data_b6;
volatile uint32_t	can_data_b7;
volatile uint32_t	can_data_b8;
volatile uint32_t	can_data_b9;
volatile uint32_t	can_data_b10;
volatile uint32_t	can_data_b11;
volatile uint32_t	can_data_b12;
volatile uint32_t	can_data_b13;
volatile uint32_t	can_data_b14;
volatile uint32_t	can_data_b15;
volatile uint32_t	can_data_b16;
volatile uint32_t	can_data_c1;
volatile uint32_t	can_data_c2;
volatile uint32_t	can_data_c3;
volatile uint32_t	can_data_c4;
volatile uint32_t	can_data_c5;
volatile uint32_t	can_data_c6;
volatile uint32_t	can_data_c7;
volatile uint32_t	can_data_c8;
volatile uint32_t	can_data_c9;
volatile uint32_t	can_data_c10;
volatile uint32_t	can_data_c11;
volatile uint32_t	can_data_c12;
volatile uint32_t	can_data_c13;
volatile uint32_t	can_data_c14;
volatile uint32_t	can_data_c15;
volatile uint32_t	can_data_c16;
volatile uint32_t	can_data_task_1_counter;
volatile uint32_t	can_data_task_2_counter;
volatile uint32_t	can_data_task_3_counter;
volatile uint32_t	can_data_task_4_counter;
volatile uint32_t	can_data_task_5_counter;
volatile float_t 	can_data_ten_k_thermistor_1;
volatile float_t 	can_data_ten_k_thermistor_2;
volatile float_t 	can_data_ten_k_thermistor_3;

/**
* @brief    initialize the backend data with initial values from attributes
* @return   return error in case of failure
*/
error_t dbc_init(void)
{
        uint16_t i = 0;
        for(i=0;i<TOTAL_CAN_SIGNALS;i++)
        {
                *can_data_pointer[i]=0;
        }
        return ER_Success;
}

