
#ifndef INCLUDE_DBC_H_
#define INCLUDE_DBC_H_

#include "../../app_drivers/inc/signal_cache.h"
extern CAN_HandleTypeDef hcan;

#define TOTAL_CAN_SIGNALS	(107)
#define TOTAL_CAN_MESSAGES	(8)

/* enum definition for all signals in dbc file */
typedef enum
{
	can_signal_adc_low_volt_1 = 0,
	can_signal_adc_low_volt_2 = 1,
	can_signal_adc_low_volt_3 = 2,
	can_signal_adc_low_volt_4 = 3,
	can_signal_batt_volt_1 = 4,
	can_signal_batt_volt_2 = 5,
	can_signal_batt_volt_3 = 6,
	can_signal_batt_volt_1_gain_feedback = 7,
	can_signal_batt_volt_2_gain_feedback = 8,
	can_signal_batt_volt_3_gain_feedback = 9,
	can_signal_batt_volt_1_gain_set = 10,
	can_signal_batt_volt_2_gain_set = 11,
	can_signal_batt_volt_3_gain_set = 12,
	can_signal_gpio_input_1 = 13,
	can_signal_gpio_input_2 = 14,
	can_signal_gpio_input_3 = 15,
	can_signal_gpio_input_4 = 16,
	can_signal_gpio_input_5 = 17,
	can_signal_gpio_input_6 = 18,
	can_signal_gpio_input_7 = 19,
	can_signal_gpio_input_8 = 20,
	can_signal_gpio_input_9 = 21,
	can_signal_gpio_input_10 = 22,
	can_signal_gpio_input_11 = 23,
	can_signal_gpio_input_12 = 24,
	can_signal_gpio_input_13 = 25,
	can_signal_gpio_input_14 = 26,
	can_signal_gpio_input_15 = 27,
	can_signal_gpio_input_16 = 28,
	can_signal_gpio_input_17 = 29,
	can_signal_gpio_input_18 = 30,
	can_signal_gpio_input_19 = 31,
	can_signal_gpio_input_20 = 32,
	can_signal_gpio_input_21 = 33,
	can_signal_gpio_input_22 = 34,
	can_signal_gpio_input_23 = 35,
	can_signal_gpio_input_24 = 36,
	can_signal_gpio_input_25 = 37,
	can_signal_gpio_input_26 = 38,
	can_signal_gpio_input_27 = 39,
	can_signal_gpio_input_28 = 40,
	can_signal_gpio_input_29 = 41,
	can_signal_gpio_input_30 = 42,
	can_signal_gpio_input_31 = 43,
	can_signal_gpio_input_32 = 44,
	can_signal_gpio_input_33 = 45,
	can_signal_gpio_input_34 = 46,
	can_signal_gpio_input_35 = 47,
	can_signal_gpio_input_36 = 48,
	can_signal_flowrate_1 = 49,
	can_signal_flowrate_2 = 50,
	can_signal_a1 = 51,
	can_signal_a2 = 52,
	can_signal_a3 = 53,
	can_signal_a4 = 54,
	can_signal_a5 = 55,
	can_signal_a6 = 56,
	can_signal_a7 = 57,
	can_signal_a8 = 58,
	can_signal_a9 = 59,
	can_signal_a10 = 60,
	can_signal_a11 = 61,
	can_signal_a12 = 62,
	can_signal_a13 = 63,
	can_signal_a14 = 64,
	can_signal_a15 = 65,
	can_signal_a16 = 66,
	can_signal_b1 = 67,
	can_signal_b2 = 68,
	can_signal_b3 = 69,
	can_signal_b4 = 70,
	can_signal_b5 = 71,
	can_signal_b6 = 72,
	can_signal_b7 = 73,
	can_signal_b8 = 74,
	can_signal_b9 = 75,
	can_signal_b10 = 76,
	can_signal_b11 = 77,
	can_signal_b12 = 78,
	can_signal_b13 = 79,
	can_signal_b14 = 80,
	can_signal_b15 = 81,
	can_signal_b16 = 82,
	can_signal_c1 = 83,
	can_signal_c2 = 84,
	can_signal_c3 = 85,
	can_signal_c4 = 86,
	can_signal_c5 = 87,
	can_signal_c6 = 88,
	can_signal_c7 = 89,
	can_signal_c8 = 90,
	can_signal_c9 = 91,
	can_signal_c10 = 92,
	can_signal_c11 = 93,
	can_signal_c12 = 94,
	can_signal_c13 = 95,
	can_signal_c14 = 96,
	can_signal_c15 = 97,
	can_signal_c16 = 98,
	can_signal_task_1_counter = 99,
	can_signal_task_2_counter = 100,
	can_signal_task_3_counter = 101,
	can_signal_task_4_counter = 102,
	can_signal_task_5_counter = 103,
	can_signal_ten_k_thermistor_1 = 104,
	can_signal_ten_k_thermistor_2 = 105,
	can_signal_ten_k_thermistor_3 = 106,
}dbc_signals_t;

/* enum definition for all messages in dbc file */
typedef enum
{
	can_message_adc_values = 0,
	can_message_battery_voltage = 1,
	can_message_battery_voltage_gain_feedback = 2,
	can_message_battery_voltage_gain_set = 3,
	can_message_gpio_inputs_flowrate = 4,
	can_message_relay_board_control = 5,
	can_message_relay_board_heartbeat = 6,
	can_message_thermistors = 7,
}dbc_messages_t;

/* Backend data storage global variables */
extern volatile uint32_t	can_data_adc_low_volt_1;
extern volatile uint32_t	can_data_adc_low_volt_2;
extern volatile uint32_t	can_data_adc_low_volt_3;
extern volatile uint32_t	can_data_adc_low_volt_4;
extern volatile float_t 	can_data_batt_volt_1;
extern volatile float_t 	can_data_batt_volt_2;
extern volatile float_t 	can_data_batt_volt_3;
extern volatile float_t 	can_data_batt_volt_1_gain_feedback;
extern volatile float_t 	can_data_batt_volt_2_gain_feedback;
extern volatile float_t 	can_data_batt_volt_3_gain_feedback;
extern volatile float_t 	can_data_batt_volt_1_gain_set;
extern volatile float_t 	can_data_batt_volt_2_gain_set;
extern volatile float_t 	can_data_batt_volt_3_gain_set;
extern volatile uint32_t	can_data_gpio_input_1;
extern volatile uint32_t	can_data_gpio_input_2;
extern volatile uint32_t	can_data_gpio_input_3;
extern volatile uint32_t	can_data_gpio_input_4;
extern volatile uint32_t	can_data_gpio_input_5;
extern volatile uint32_t	can_data_gpio_input_6;
extern volatile uint32_t	can_data_gpio_input_7;
extern volatile uint32_t	can_data_gpio_input_8;
extern volatile uint32_t	can_data_gpio_input_9;
extern volatile uint32_t	can_data_gpio_input_10;
extern volatile uint32_t	can_data_gpio_input_11;
extern volatile uint32_t	can_data_gpio_input_12;
extern volatile uint32_t	can_data_gpio_input_13;
extern volatile uint32_t	can_data_gpio_input_14;
extern volatile uint32_t	can_data_gpio_input_15;
extern volatile uint32_t	can_data_gpio_input_16;
extern volatile uint32_t	can_data_gpio_input_17;
extern volatile uint32_t	can_data_gpio_input_18;
extern volatile uint32_t	can_data_gpio_input_19;
extern volatile uint32_t	can_data_gpio_input_20;
extern volatile uint32_t	can_data_gpio_input_21;
extern volatile uint32_t	can_data_gpio_input_22;
extern volatile uint32_t	can_data_gpio_input_23;
extern volatile uint32_t	can_data_gpio_input_24;
extern volatile uint32_t	can_data_gpio_input_25;
extern volatile uint32_t	can_data_gpio_input_26;
extern volatile uint32_t	can_data_gpio_input_27;
extern volatile uint32_t	can_data_gpio_input_28;
extern volatile uint32_t	can_data_gpio_input_29;
extern volatile uint32_t	can_data_gpio_input_30;
extern volatile uint32_t	can_data_gpio_input_31;
extern volatile uint32_t	can_data_gpio_input_32;
extern volatile uint32_t	can_data_gpio_input_33;
extern volatile uint32_t	can_data_gpio_input_34;
extern volatile uint32_t	can_data_gpio_input_35;
extern volatile uint32_t	can_data_gpio_input_36;
extern volatile uint32_t	can_data_flowrate_1;
extern volatile uint32_t	can_data_flowrate_2;
extern volatile uint32_t	can_data_a1;
extern volatile uint32_t	can_data_a2;
extern volatile uint32_t	can_data_a3;
extern volatile uint32_t	can_data_a4;
extern volatile uint32_t	can_data_a5;
extern volatile uint32_t	can_data_a6;
extern volatile uint32_t	can_data_a7;
extern volatile uint32_t	can_data_a8;
extern volatile uint32_t	can_data_a9;
extern volatile uint32_t	can_data_a10;
extern volatile uint32_t	can_data_a11;
extern volatile uint32_t	can_data_a12;
extern volatile uint32_t	can_data_a13;
extern volatile uint32_t	can_data_a14;
extern volatile uint32_t	can_data_a15;
extern volatile uint32_t	can_data_a16;
extern volatile uint32_t	can_data_b1;
extern volatile uint32_t	can_data_b2;
extern volatile uint32_t	can_data_b3;
extern volatile uint32_t	can_data_b4;
extern volatile uint32_t	can_data_b5;
extern volatile uint32_t	can_data_b6;
extern volatile uint32_t	can_data_b7;
extern volatile uint32_t	can_data_b8;
extern volatile uint32_t	can_data_b9;
extern volatile uint32_t	can_data_b10;
extern volatile uint32_t	can_data_b11;
extern volatile uint32_t	can_data_b12;
extern volatile uint32_t	can_data_b13;
extern volatile uint32_t	can_data_b14;
extern volatile uint32_t	can_data_b15;
extern volatile uint32_t	can_data_b16;
extern volatile uint32_t	can_data_c1;
extern volatile uint32_t	can_data_c2;
extern volatile uint32_t	can_data_c3;
extern volatile uint32_t	can_data_c4;
extern volatile uint32_t	can_data_c5;
extern volatile uint32_t	can_data_c6;
extern volatile uint32_t	can_data_c7;
extern volatile uint32_t	can_data_c8;
extern volatile uint32_t	can_data_c9;
extern volatile uint32_t	can_data_c10;
extern volatile uint32_t	can_data_c11;
extern volatile uint32_t	can_data_c12;
extern volatile uint32_t	can_data_c13;
extern volatile uint32_t	can_data_c14;
extern volatile uint32_t	can_data_c15;
extern volatile uint32_t	can_data_c16;
extern volatile uint32_t	can_data_task_1_counter;
extern volatile uint32_t	can_data_task_2_counter;
extern volatile uint32_t	can_data_task_3_counter;
extern volatile uint32_t	can_data_task_4_counter;
extern volatile uint32_t	can_data_task_5_counter;
extern volatile float_t 	can_data_ten_k_thermistor_1;
extern volatile float_t 	can_data_ten_k_thermistor_2;
extern volatile float_t 	can_data_ten_k_thermistor_3;

static volatile uint32_t* const can_data_pointer[TOTAL_CAN_SIGNALS]=
{
	(uint32_t*)&can_data_adc_low_volt_1, /*0*/
	(uint32_t*)&can_data_adc_low_volt_2, /*1*/
	(uint32_t*)&can_data_adc_low_volt_3, /*2*/
	(uint32_t*)&can_data_adc_low_volt_4, /*3*/
	(uint32_t*)&can_data_batt_volt_1, /*4*/
	(uint32_t*)&can_data_batt_volt_2, /*5*/
	(uint32_t*)&can_data_batt_volt_3, /*6*/
	(uint32_t*)&can_data_batt_volt_1_gain_feedback, /*7*/
	(uint32_t*)&can_data_batt_volt_2_gain_feedback, /*8*/
	(uint32_t*)&can_data_batt_volt_3_gain_feedback, /*9*/
	(uint32_t*)&can_data_batt_volt_1_gain_set, /*10*/
	(uint32_t*)&can_data_batt_volt_2_gain_set, /*11*/
	(uint32_t*)&can_data_batt_volt_3_gain_set, /*12*/
	(uint32_t*)&can_data_gpio_input_1, /*13*/
	(uint32_t*)&can_data_gpio_input_2, /*14*/
	(uint32_t*)&can_data_gpio_input_3, /*15*/
	(uint32_t*)&can_data_gpio_input_4, /*16*/
	(uint32_t*)&can_data_gpio_input_5, /*17*/
	(uint32_t*)&can_data_gpio_input_6, /*18*/
	(uint32_t*)&can_data_gpio_input_7, /*19*/
	(uint32_t*)&can_data_gpio_input_8, /*20*/
	(uint32_t*)&can_data_gpio_input_9, /*21*/
	(uint32_t*)&can_data_gpio_input_10, /*22*/
	(uint32_t*)&can_data_gpio_input_11, /*23*/
	(uint32_t*)&can_data_gpio_input_12, /*24*/
	(uint32_t*)&can_data_gpio_input_13, /*25*/
	(uint32_t*)&can_data_gpio_input_14, /*26*/
	(uint32_t*)&can_data_gpio_input_15, /*27*/
	(uint32_t*)&can_data_gpio_input_16, /*28*/
	(uint32_t*)&can_data_gpio_input_17, /*29*/
	(uint32_t*)&can_data_gpio_input_18, /*30*/
	(uint32_t*)&can_data_gpio_input_19, /*31*/
	(uint32_t*)&can_data_gpio_input_20, /*32*/
	(uint32_t*)&can_data_gpio_input_21, /*33*/
	(uint32_t*)&can_data_gpio_input_22, /*34*/
	(uint32_t*)&can_data_gpio_input_23, /*35*/
	(uint32_t*)&can_data_gpio_input_24, /*36*/
	(uint32_t*)&can_data_gpio_input_25, /*37*/
	(uint32_t*)&can_data_gpio_input_26, /*38*/
	(uint32_t*)&can_data_gpio_input_27, /*39*/
	(uint32_t*)&can_data_gpio_input_28, /*40*/
	(uint32_t*)&can_data_gpio_input_29, /*41*/
	(uint32_t*)&can_data_gpio_input_30, /*42*/
	(uint32_t*)&can_data_gpio_input_31, /*43*/
	(uint32_t*)&can_data_gpio_input_32, /*44*/
	(uint32_t*)&can_data_gpio_input_33, /*45*/
	(uint32_t*)&can_data_gpio_input_34, /*46*/
	(uint32_t*)&can_data_gpio_input_35, /*47*/
	(uint32_t*)&can_data_gpio_input_36, /*48*/
	(uint32_t*)&can_data_flowrate_1, /*49*/
	(uint32_t*)&can_data_flowrate_2, /*50*/
	(uint32_t*)&can_data_a1, /*51*/
	(uint32_t*)&can_data_a2, /*52*/
	(uint32_t*)&can_data_a3, /*53*/
	(uint32_t*)&can_data_a4, /*54*/
	(uint32_t*)&can_data_a5, /*55*/
	(uint32_t*)&can_data_a6, /*56*/
	(uint32_t*)&can_data_a7, /*57*/
	(uint32_t*)&can_data_a8, /*58*/
	(uint32_t*)&can_data_a9, /*59*/
	(uint32_t*)&can_data_a10, /*60*/
	(uint32_t*)&can_data_a11, /*61*/
	(uint32_t*)&can_data_a12, /*62*/
	(uint32_t*)&can_data_a13, /*63*/
	(uint32_t*)&can_data_a14, /*64*/
	(uint32_t*)&can_data_a15, /*65*/
	(uint32_t*)&can_data_a16, /*66*/
	(uint32_t*)&can_data_b1, /*67*/
	(uint32_t*)&can_data_b2, /*68*/
	(uint32_t*)&can_data_b3, /*69*/
	(uint32_t*)&can_data_b4, /*70*/
	(uint32_t*)&can_data_b5, /*71*/
	(uint32_t*)&can_data_b6, /*72*/
	(uint32_t*)&can_data_b7, /*73*/
	(uint32_t*)&can_data_b8, /*74*/
	(uint32_t*)&can_data_b9, /*75*/
	(uint32_t*)&can_data_b10, /*76*/
	(uint32_t*)&can_data_b11, /*77*/
	(uint32_t*)&can_data_b12, /*78*/
	(uint32_t*)&can_data_b13, /*79*/
	(uint32_t*)&can_data_b14, /*80*/
	(uint32_t*)&can_data_b15, /*81*/
	(uint32_t*)&can_data_b16, /*82*/
	(uint32_t*)&can_data_c1, /*83*/
	(uint32_t*)&can_data_c2, /*84*/
	(uint32_t*)&can_data_c3, /*85*/
	(uint32_t*)&can_data_c4, /*86*/
	(uint32_t*)&can_data_c5, /*87*/
	(uint32_t*)&can_data_c6, /*88*/
	(uint32_t*)&can_data_c7, /*89*/
	(uint32_t*)&can_data_c8, /*90*/
	(uint32_t*)&can_data_c9, /*91*/
	(uint32_t*)&can_data_c10, /*92*/
	(uint32_t*)&can_data_c11, /*93*/
	(uint32_t*)&can_data_c12, /*94*/
	(uint32_t*)&can_data_c13, /*95*/
	(uint32_t*)&can_data_c14, /*96*/
	(uint32_t*)&can_data_c15, /*97*/
	(uint32_t*)&can_data_c16, /*98*/
	(uint32_t*)&can_data_task_1_counter, /*99*/
	(uint32_t*)&can_data_task_2_counter, /*100*/
	(uint32_t*)&can_data_task_3_counter, /*101*/
	(uint32_t*)&can_data_task_4_counter, /*102*/
	(uint32_t*)&can_data_task_5_counter, /*103*/
	(uint32_t*)&can_data_ten_k_thermistor_1, /*104*/
	(uint32_t*)&can_data_ten_k_thermistor_2, /*105*/
	(uint32_t*)&can_data_ten_k_thermistor_3, /*106*/
};

/* structures to save attributes of signals in dbc file*/
static const signal_attributes_t dbc_signal_attributes[TOTAL_CAN_SIGNALS]=
{
	{0x4a1,0,&signal_attribute_cache[0]},	/* adc_low_volt_1  0 */
	{0x4a1,12,&signal_attribute_cache[0]},	/* adc_low_volt_2  1 */
	{0x4a1,24,&signal_attribute_cache[0]},	/* adc_low_volt_3  2 */
	{0x4a1,36,&signal_attribute_cache[0]},	/* adc_low_volt_4  3 */
	{0x4a2,0,&signal_attribute_cache[1]},	/* batt_volt_1  4 */
	{0x4a2,16,&signal_attribute_cache[1]},	/* batt_volt_2  5 */
	{0x4a2,32,&signal_attribute_cache[1]},	/* batt_volt_3  6 */
	{0x4a3,0,&signal_attribute_cache[2]},	/* batt_volt_1_gain_feedback  7 */
	{0x4a3,16,&signal_attribute_cache[2]},	/* batt_volt_2_gain_feedback  8 */
	{0x4a3,32,&signal_attribute_cache[2]},	/* batt_volt_3_gain_feedback  9 */
	{0x7,0,&signal_attribute_cache[2]},	/* batt_volt_1_gain_set  10 */
	{0x7,16,&signal_attribute_cache[2]},	/* batt_volt_2_gain_set  11 */
	{0x7,32,&signal_attribute_cache[2]},	/* batt_volt_3_gain_set  12 */
	{0x4a4,0,&signal_attribute_cache[3]},	/* gpio_input_1  13 */
	{0x4a4,1,&signal_attribute_cache[3]},	/* gpio_input_2  14 */
	{0x4a4,2,&signal_attribute_cache[3]},	/* gpio_input_3  15 */
	{0x4a4,3,&signal_attribute_cache[3]},	/* gpio_input_4  16 */
	{0x4a4,4,&signal_attribute_cache[3]},	/* gpio_input_5  17 */
	{0x4a4,5,&signal_attribute_cache[3]},	/* gpio_input_6  18 */
	{0x4a4,6,&signal_attribute_cache[3]},	/* gpio_input_7  19 */
	{0x4a4,7,&signal_attribute_cache[3]},	/* gpio_input_8  20 */
	{0x4a4,8,&signal_attribute_cache[3]},	/* gpio_input_9  21 */
	{0x4a4,9,&signal_attribute_cache[3]},	/* gpio_input_10  22 */
	{0x4a4,10,&signal_attribute_cache[3]},	/* gpio_input_11  23 */
	{0x4a4,11,&signal_attribute_cache[3]},	/* gpio_input_12  24 */
	{0x4a4,12,&signal_attribute_cache[3]},	/* gpio_input_13  25 */
	{0x4a4,13,&signal_attribute_cache[3]},	/* gpio_input_14  26 */
	{0x4a4,14,&signal_attribute_cache[3]},	/* gpio_input_15  27 */
	{0x4a4,15,&signal_attribute_cache[3]},	/* gpio_input_16  28 */
	{0x4a4,16,&signal_attribute_cache[3]},	/* gpio_input_17  29 */
	{0x4a4,17,&signal_attribute_cache[3]},	/* gpio_input_18  30 */
	{0x4a4,18,&signal_attribute_cache[3]},	/* gpio_input_19  31 */
	{0x4a4,19,&signal_attribute_cache[3]},	/* gpio_input_20  32 */
	{0x4a4,20,&signal_attribute_cache[3]},	/* gpio_input_21  33 */
	{0x4a4,21,&signal_attribute_cache[3]},	/* gpio_input_22  34 */
	{0x4a4,22,&signal_attribute_cache[3]},	/* gpio_input_23  35 */
	{0x4a4,23,&signal_attribute_cache[3]},	/* gpio_input_24  36 */
	{0x4a4,24,&signal_attribute_cache[3]},	/* gpio_input_25  37 */
	{0x4a4,25,&signal_attribute_cache[3]},	/* gpio_input_26  38 */
	{0x4a4,26,&signal_attribute_cache[3]},	/* gpio_input_27  39 */
	{0x4a4,27,&signal_attribute_cache[3]},	/* gpio_input_28  40 */
	{0x4a4,28,&signal_attribute_cache[3]},	/* gpio_input_29  41 */
	{0x4a4,29,&signal_attribute_cache[3]},	/* gpio_input_30  42 */
	{0x4a4,30,&signal_attribute_cache[3]},	/* gpio_input_31  43 */
	{0x4a4,31,&signal_attribute_cache[3]},	/* gpio_input_32  44 */
	{0x4a4,32,&signal_attribute_cache[3]},	/* gpio_input_33  45 */
	{0x4a4,33,&signal_attribute_cache[3]},	/* gpio_input_34  46 */
	{0x4a4,34,&signal_attribute_cache[3]},	/* gpio_input_35  47 */
	{0x4a4,35,&signal_attribute_cache[3]},	/* gpio_input_36  48 */
	{0x4a4,40,&signal_attribute_cache[4]},	/* flowrate_1  49 */
	{0x4a4,48,&signal_attribute_cache[4]},	/* flowrate_2  50 */
	{0x1,0,&signal_attribute_cache[3]},	/* a1  51 */
	{0x1,1,&signal_attribute_cache[3]},	/* a2  52 */
	{0x1,2,&signal_attribute_cache[3]},	/* a3  53 */
	{0x1,3,&signal_attribute_cache[3]},	/* a4  54 */
	{0x1,4,&signal_attribute_cache[3]},	/* a5  55 */
	{0x1,5,&signal_attribute_cache[3]},	/* a6  56 */
	{0x1,6,&signal_attribute_cache[3]},	/* a7  57 */
	{0x1,7,&signal_attribute_cache[3]},	/* a8  58 */
	{0x1,8,&signal_attribute_cache[3]},	/* a9  59 */
	{0x1,9,&signal_attribute_cache[3]},	/* a10  60 */
	{0x1,10,&signal_attribute_cache[3]},	/* a11  61 */
	{0x1,11,&signal_attribute_cache[3]},	/* a12  62 */
	{0x1,12,&signal_attribute_cache[3]},	/* a13  63 */
	{0x1,13,&signal_attribute_cache[3]},	/* a14  64 */
	{0x1,14,&signal_attribute_cache[3]},	/* a15  65 */
	{0x1,15,&signal_attribute_cache[3]},	/* a16  66 */
	{0x1,16,&signal_attribute_cache[3]},	/* b1  67 */
	{0x1,17,&signal_attribute_cache[3]},	/* b2  68 */
	{0x1,18,&signal_attribute_cache[3]},	/* b3  69 */
	{0x1,19,&signal_attribute_cache[3]},	/* b4  70 */
	{0x1,20,&signal_attribute_cache[3]},	/* b5  71 */
	{0x1,21,&signal_attribute_cache[3]},	/* b6  72 */
	{0x1,22,&signal_attribute_cache[3]},	/* b7  73 */
	{0x1,23,&signal_attribute_cache[3]},	/* b8  74 */
	{0x1,24,&signal_attribute_cache[3]},	/* b9  75 */
	{0x1,25,&signal_attribute_cache[3]},	/* b10  76 */
	{0x1,26,&signal_attribute_cache[3]},	/* b11  77 */
	{0x1,27,&signal_attribute_cache[3]},	/* b12  78 */
	{0x1,28,&signal_attribute_cache[3]},	/* b13  79 */
	{0x1,29,&signal_attribute_cache[3]},	/* b14  80 */
	{0x1,30,&signal_attribute_cache[3]},	/* b15  81 */
	{0x1,31,&signal_attribute_cache[3]},	/* b16  82 */
	{0x1,32,&signal_attribute_cache[3]},	/* c1  83 */
	{0x1,33,&signal_attribute_cache[3]},	/* c2  84 */
	{0x1,34,&signal_attribute_cache[3]},	/* c3  85 */
	{0x1,35,&signal_attribute_cache[3]},	/* c4  86 */
	{0x1,36,&signal_attribute_cache[3]},	/* c5  87 */
	{0x1,37,&signal_attribute_cache[3]},	/* c6  88 */
	{0x1,38,&signal_attribute_cache[3]},	/* c7  89 */
	{0x1,39,&signal_attribute_cache[3]},	/* c8  90 */
	{0x1,40,&signal_attribute_cache[3]},	/* c9  91 */
	{0x1,41,&signal_attribute_cache[3]},	/* c10  92 */
	{0x1,42,&signal_attribute_cache[3]},	/* c11  93 */
	{0x1,43,&signal_attribute_cache[3]},	/* c12  94 */
	{0x1,44,&signal_attribute_cache[3]},	/* c13  95 */
	{0x1,45,&signal_attribute_cache[3]},	/* c14  96 */
	{0x1,46,&signal_attribute_cache[3]},	/* c15  97 */
	{0x1,47,&signal_attribute_cache[3]},	/* c16  98 */
	{0x4a5,0,&signal_attribute_cache[4]},	/* task_1_counter  99 */
	{0x4a5,8,&signal_attribute_cache[4]},	/* task_2_counter  100 */
	{0x4a5,16,&signal_attribute_cache[4]},	/* task_3_counter  101 */
	{0x4a5,24,&signal_attribute_cache[4]},	/* task_4_counter  102 */
	{0x4a5,32,&signal_attribute_cache[4]},	/* task_5_counter  103 */
	{0x4a6,0,&signal_attribute_cache[1]},	/* ten_k_thermistor_1  104 */
	{0x4a6,16,&signal_attribute_cache[1]},	/* ten_k_thermistor_2  105 */
	{0x4a6,32,&signal_attribute_cache[1]},	/* ten_k_thermistor_3  106 */
};

/* array of tracker functions wrt msg_id for can packer unpacker for Front Motor */
static const message_tracker_t can_tracker_array[TOTAL_CAN_MESSAGES]={
	{0x4a1,4,0,tx,&hcan},	/* adc_values  0 */
	{0x4a2,3,4,tx,&hcan},	/* battery_voltage  1 */
	{0x4a3,3,7,tx,&hcan},	/* battery_voltage_gain_feedback  2 */
	{0x7,3,10,tx,&hcan},	/* battery_voltage_gain_set  3 */
	{0x4a4,38,13,tx,&hcan},	/* gpio_inputs_flowrate  4 */
	{0x1,48,51,tx,&hcan},	/* relay_board_control  5 */
	{0x4a5,5,99,tx,&hcan},	/* relay_board_heartbeat  6 */
	{0x4a6,3,104,tx,&hcan},	/* thermistors  7 */
};
//750, 751, 752, 753, 754, 755
/*prototypes*/

error_t dbc_init(void);

#endif
