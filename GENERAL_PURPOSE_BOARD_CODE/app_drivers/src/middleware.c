#include "../../app_drivers/inc/middleware.h"

#define RELAY_OFF  (1)
#define RELAY_ON   (0)

uint32_t flag = 0;

extern uint32_t task_1_counter;
extern uint32_t task_2_counter;
extern uint32_t task_3_counter;
extern uint32_t task_4_counter;

int pulse_1;
extern int Flowrate_1;
extern uint32_t current_time_1;
extern uint32_t cloop_time_1;

int pulse_2;
extern int Flowrate_2;
extern uint32_t current_time_2;
extern uint32_t cloop_time_2;

int i;

extern float calib_can_1;
extern float calib_can_2;
extern float calib_can_3;

/**
 * adc_raw_data[6] = A1
 * adc_raw_data[7] = A2
 * adc_raw_data[8] = A3
 * adc_raw_data[9] = A4
 */

message_frame_t frame;

void gpio_init(void)
{
	write_gpio_board_1_ch_1(RELAY_OFF);
	write_gpio_board_1_ch_2(RELAY_OFF);
	write_gpio_board_1_ch_3(RELAY_OFF);
	write_gpio_board_1_ch_4(RELAY_OFF);
	write_gpio_board_1_ch_5(RELAY_OFF);
	write_gpio_board_1_ch_6(RELAY_OFF);
	write_gpio_board_1_ch_7(RELAY_OFF);
	write_gpio_board_1_ch_8(RELAY_OFF);
	write_gpio_board_1_ch_9(RELAY_OFF);
	write_gpio_board_1_ch_10(RELAY_OFF);
	write_gpio_board_1_ch_11(RELAY_OFF);
	write_gpio_board_1_ch_12(RELAY_OFF);
	write_gpio_board_1_ch_13(RELAY_OFF);
	write_gpio_board_1_ch_14(RELAY_OFF);
	write_gpio_board_1_ch_15(RELAY_OFF);
	write_gpio_board_1_ch_16(RELAY_OFF);

	write_gpio_board_2_ch_1(RELAY_OFF);
	write_gpio_board_2_ch_2(RELAY_OFF);
	write_gpio_board_2_ch_3(RELAY_OFF);
	write_gpio_board_2_ch_4(RELAY_OFF);
	write_gpio_board_2_ch_5(RELAY_OFF);
	write_gpio_board_2_ch_6(RELAY_OFF);
	write_gpio_board_2_ch_7(RELAY_OFF);
	write_gpio_board_2_ch_8(RELAY_OFF);
	write_gpio_board_2_ch_9(RELAY_OFF);
	write_gpio_board_2_ch_10(RELAY_OFF);
	write_gpio_board_2_ch_11(RELAY_OFF);
	write_gpio_board_2_ch_12(RELAY_OFF);
	write_gpio_board_2_ch_13(RELAY_OFF);
	write_gpio_board_2_ch_14(RELAY_OFF);
	write_gpio_board_2_ch_15(RELAY_OFF);
	write_gpio_board_2_ch_16(RELAY_OFF);

	write_gpio_board_3_ch_1(RELAY_OFF);
	write_gpio_board_3_ch_2(RELAY_OFF);
	write_gpio_board_3_ch_3(RELAY_OFF);
	write_gpio_board_3_ch_4(RELAY_OFF);
	write_gpio_board_3_ch_5(RELAY_OFF);
	write_gpio_board_3_ch_6(RELAY_OFF);
	write_gpio_board_3_ch_7(RELAY_OFF);
	write_gpio_board_3_ch_8(RELAY_OFF);
	write_gpio_board_3_ch_9(RELAY_OFF);
	write_gpio_board_3_ch_10(RELAY_OFF);
	write_gpio_board_3_ch_11(RELAY_OFF);
	write_gpio_board_3_ch_12(RELAY_OFF);
	write_gpio_board_3_ch_13(RELAY_OFF);
	write_gpio_board_3_ch_14(RELAY_OFF);
	write_gpio_board_3_ch_15(RELAY_OFF);
	write_gpio_board_3_ch_16(RELAY_OFF);


}
float current;
void middleware_variables_input(void)
{

	/*****************DIGITAL_INPUTS TO CAN *********************/
	can_data_gpio_input_1 	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);//1-PA4
	can_data_gpio_input_2	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);//2-PA5
	can_data_gpio_input_3	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6);//3-PA6
	can_data_gpio_input_4	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7);//4-PA7
	can_data_gpio_input_5	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10);//5-PA10
	can_data_gpio_input_6	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12);//6-PA12
	can_data_gpio_input_7	= HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15);//7-PA15
	can_data_gpio_input_8	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);//8-PB1
	can_data_gpio_input_9	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2);//9-PB2
	can_data_gpio_input_10	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8);//10-PB8
	can_data_gpio_input_11	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);//11-PB9
	can_data_gpio_input_12	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10);//12-PB10
	can_data_gpio_input_13	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_11);//13-PB11
	can_data_gpio_input_14	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//14-PB12
	can_data_gpio_input_15	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);//15-PB13
	can_data_gpio_input_16	= HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15);//16-PB15
	can_data_gpio_input_17	= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4);//17-PC4
	can_data_gpio_input_18	= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_5);//18-PC5
	can_data_gpio_input_19	= HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_6);//19-PC6
	can_data_gpio_input_20	= HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_4);//20-PD4
	can_data_gpio_input_21	= HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10);//21-PD10
	can_data_gpio_input_22	= HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_11);//22-PD11
	can_data_gpio_input_23	= HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12);//23-PD12
	can_data_gpio_input_24	= HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13);//24-PD13
	can_data_gpio_input_25	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_3);//25-PF3
	can_data_gpio_input_26	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_5);//26-PF5
	can_data_gpio_input_27	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_9);//27-PF9
	can_data_gpio_input_28	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_10);//28-PF10
	can_data_gpio_input_29	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_11);//29-PF11
	can_data_gpio_input_30	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_12);//30-PF12
	can_data_gpio_input_31	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_13);//31-PF13
	can_data_gpio_input_32	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_14);//32-PF14
	can_data_gpio_input_33	= HAL_GPIO_ReadPin(GPIOF, GPIO_PIN_15);//33-PF15
	can_data_gpio_input_34	= HAL_GPIO_ReadPin(GPIOG, GPIO_PIN_0);//34-PG0

	/************MIDDLEWARE DATA TRANSFER TO CAN ***************/
	/**CAN_TASK_COUNTER**/
	can_data_task_1_counter = task_1_counter;
	can_data_task_2_counter = task_2_counter;
	can_data_task_3_counter = task_3_counter;
	can_data_task_4_counter = task_4_counter;
//	can_data_task_5_counter = task_5_counter;

	/************FLOWRATE TO CAN  ***************/

	can_data_flowrate_1 = Flowrate_1 ;
	can_data_flowrate_2 = Flowrate_2 ;

	/************ FOR ANALOG_VALUES TO CAN GO TO ADC.C  ***************/

	/************ THERMISTOR_TEMP TO CAN  ***************/

	can_data_ten_k_thermistor_1 = temp_10k_Sensor_1 ;
	can_data_ten_k_thermistor_2 = temp_10k_Sensor_2 ;
	can_data_ten_k_thermistor_3 = temp_10k_Sensor_3 ;

	/************ BATTERY VOLTAGE TO CAN  ***************/

	can_data_batt_volt_1 = voltage_1 ;
	can_data_batt_volt_2 = voltage_2 ;
	can_data_batt_volt_3 = voltage_3 ;

	/************  CAN TO BATTERY VOLTAGE CALIB  ***************/
	if((flag == 1))
	{
		calib_can_1 = can_data_batt_volt_1_gain_set;
		can_data_batt_volt_1_gain_feedback = calib_can_1;

		calib_can_2 = can_data_batt_volt_2_gain_set;
		can_data_batt_volt_2_gain_feedback = calib_can_2;

		calib_can_3 = can_data_batt_volt_3_gain_set;
		can_data_batt_volt_3_gain_feedback = calib_can_3;
	}
	else
	{
		can_data_batt_volt_1_gain_feedback = calib_can_1;
		can_data_batt_volt_2_gain_feedback = calib_can_2;
		can_data_batt_volt_3_gain_feedback = calib_can_3;
	}








}

void middleware_variables_output(void)
{

	 /**RELAY_CONTROL BOARD_1**/
	 write_gpio_board_1_ch_1(!can_data_a1);
	 write_gpio_board_1_ch_2(!can_data_a2);
	 write_gpio_board_1_ch_3(!can_data_a3);
	 write_gpio_board_1_ch_4(!can_data_a4);
	 write_gpio_board_1_ch_5(!can_data_a5);
	 write_gpio_board_1_ch_6(!can_data_a6);
	 write_gpio_board_1_ch_7(!can_data_a7);
	 write_gpio_board_1_ch_8(!can_data_a8);
	 write_gpio_board_1_ch_9(!can_data_a9);
	 write_gpio_board_1_ch_10(!can_data_a10);
	 write_gpio_board_1_ch_11(!can_data_a11);
	 write_gpio_board_1_ch_12(!can_data_a12);
	 write_gpio_board_1_ch_13(!can_data_a13);
	 write_gpio_board_1_ch_14(!can_data_a14);
	 write_gpio_board_1_ch_15(!can_data_a15);
	 write_gpio_board_1_ch_16(!can_data_a16);

	 /**RELAY_CONTROL BOARD_2**/
	 write_gpio_board_2_ch_1(!can_data_b1);
	 write_gpio_board_2_ch_2(!can_data_b2);
	 write_gpio_board_2_ch_3(!can_data_b3);
	 write_gpio_board_2_ch_4(!can_data_b4);
	 write_gpio_board_2_ch_5(!can_data_b5);
	 write_gpio_board_2_ch_6(!can_data_b6);
	 write_gpio_board_2_ch_7(!can_data_b7);
	 write_gpio_board_2_ch_8(!can_data_b8);
	 write_gpio_board_2_ch_9(!can_data_b9);
	 write_gpio_board_2_ch_10(!can_data_b10);
	 write_gpio_board_2_ch_11(!can_data_b11);
	 write_gpio_board_2_ch_12(!can_data_b12);
	 write_gpio_board_2_ch_13(!can_data_b13);
	 write_gpio_board_2_ch_14(!can_data_b14);
	 write_gpio_board_2_ch_15(!can_data_b15);
	 write_gpio_board_2_ch_16(!can_data_b16);

	 /**RELAY_CONTROL BOARD_3**/
	 write_gpio_board_3_ch_1(!can_data_c1);
	 write_gpio_board_3_ch_2(!can_data_c2);
	 write_gpio_board_3_ch_3(!can_data_c3);
	 write_gpio_board_3_ch_4(!can_data_c4);
	 write_gpio_board_3_ch_5(!can_data_c5);
	 write_gpio_board_3_ch_6(!can_data_c6);
	 write_gpio_board_3_ch_7(!can_data_c7);
	 write_gpio_board_3_ch_8(!can_data_c8);
	 write_gpio_board_3_ch_9(!can_data_c9);
	 write_gpio_board_3_ch_10(!can_data_c10);
	 write_gpio_board_3_ch_11(!can_data_c11);
	 write_gpio_board_3_ch_12(!can_data_c12);
	 write_gpio_board_3_ch_13(!can_data_c13);
	 write_gpio_board_3_ch_14(!can_data_c14);
	 write_gpio_board_3_ch_15(!can_data_c15);
	 write_gpio_board_3_ch_16(!can_data_c16);



//		gpio_output_test();

}

void can_control(void)
{
		can_main_init();
		can_send_data(can_message_adc_values);
		vTaskDelay(1);
		can_send_data(can_message_battery_voltage);
		vTaskDelay(1);
		can_send_data(can_message_battery_voltage_gain_feedback);
		vTaskDelay(1);
		can_send_data(can_message_gpio_inputs_flowrate);
		vTaskDelay(1);
		can_send_data(can_message_relay_board_heartbeat);
		vTaskDelay(1);
		can_send_data(can_message_thermistors);
		vTaskDelay(1);
}

void flowrate_time(void)
{
	 current_time_1 = HAL_GetTick();

	 if(current_time_1 >= (cloop_time_1 + 1000))
	 {
		 cloop_time_1 = current_time_1;
		 Flowrate_1 = pulse_1;
		 pulse_1 = 0;
	 }
	 current_time_2 = HAL_GetTick();

	 if(current_time_2 >= (cloop_time_2 + 1000))
	 {
		 cloop_time_2 = current_time_2;
		 Flowrate_2 = pulse_2;
		 pulse_2 = 0;
	 }
}

long map(long in_value, long in_min, long in_max, long out_min, long out_max) {

	return ((in_value - in_min) * (out_max - out_min)) / ((in_max - in_min) + out_min);
}
/********************test_functions*********************/



void gpio_output_test(void)
{
	int u = 0;

	write_gpio_board_1_ch_1(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_2(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_3(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_4(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_5(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_6(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_7(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_8(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_9(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_10(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_11(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_12(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_13(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_14(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_15(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_16(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_1(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_2(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_3(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_4(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_5(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_6(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_7(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_8(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_9(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_10(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_11(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_12(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_13(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_14(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_15(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_16(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_1(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_2(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_3(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_4(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_5(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_6(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_7(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_8(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_9(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_10(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_11(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_12(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_13(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_14(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_15(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_16(u);

	vTaskDelay(2000);
	u =1;

	write_gpio_board_1_ch_1(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_2(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_3(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_4(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_5(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_6(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_7(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_8(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_9(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_10(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_11(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_12(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_13(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_14(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_15(u);
	vTaskDelay(200);
	write_gpio_board_1_ch_16(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_1(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_2(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_3(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_4(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_5(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_6(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_7(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_8(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_9(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_10(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_11(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_12(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_13(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_14(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_15(u);
	vTaskDelay(200);
	write_gpio_board_2_ch_16(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_1(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_2(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_3(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_4(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_5(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_6(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_7(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_8(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_9(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_10(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_11(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_12(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_13(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_14(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_15(u);
	vTaskDelay(200);
	write_gpio_board_3_ch_16(u);

	vTaskDelay(2000);

}
