#ifndef INC_ADC_H_
#define INC_ADC_H_

#include "main.h"

#include "../../app_drivers/inc/common.h"
#include "../../app_drivers/inc/dbc.h"

#define TOTAL_ADC_CHANNELS (10)
#define ADC_TIMEOUT_MSEC (10)

static const uint32_t adc_channels_1[TOTAL_ADC_CHANNELS] = 	{
																ADC_CHANNEL_1,//PA0
																ADC_CHANNEL_2,//PA1
																ADC_CHANNEL_3,//PA2
																ADC_CHANNEL_4,//PA3
																ADC_CHANNEL_5,//PF4
																ADC_CHANNEL_6,//PC0
																ADC_CHANNEL_7,//PC1
																ADC_CHANNEL_8,//PC2
																ADC_CHANNEL_9,//PC3
																ADC_CHANNEL_10,//PF2


															};

extern uint32_t adc_raw_data_1[TOTAL_ADC_CHANNELS];


extern ADC_HandleTypeDef hadc1;

typedef enum
{
	adc1_1  = 0,
	adc1_2  = 1,
	adc1_3  = 2,
	adc1_4  = 3,
	adc1_5  = 4,
	adc1_6  = 5,
	adc1_7  = 6,
	adc1_8  = 7,
	adc1_9  = 8,
	adc1_10 = 9,



}adc_1_pins_t;


/* prototypes */

error_t adc_init(void);
error_t adc_conversion_1(void);

#endif /* INC_ADC_H_ */



