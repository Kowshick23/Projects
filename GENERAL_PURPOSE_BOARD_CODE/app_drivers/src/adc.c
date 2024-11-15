
#include "../../app_drivers/inc/adc.h"

#define ADC_SAMPLES 500 //500


uint32_t adc_raw_data_1[TOTAL_ADC_CHANNELS];
uint16_t data_1;

error_t adc_init(void)
{
	 HAL_ADC_Start(&hadc1);
	 return ER_Success;
}

error_t adc_conversion_1(void)
{
	error_t local_error = ER_Success;
	uint8_t i =0;
	/** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	*/
	ADC_ChannelConfTypeDef sConfig = {0};
	sConfig.Rank = 1;
	sConfig.SamplingTime = ADC_SAMPLETIME_61CYCLES_5;

	for(i=0;i<TOTAL_ADC_CHANNELS;i++)
	   {
		sConfig.Channel = adc_channels_1[i];
		if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
		{
//			Error_Handler();
			local_error |= ER_Fail;
		}
		 for (int j = 0; j < ADC_SAMPLES; j++)
		 {
			HAL_ADC_Start(&hadc1);
			data_1 = HAL_ADC_PollForConversion(&hadc1, ADC_TIMEOUT_MSEC);
			if (data_1 == 0)
			{
				adc_raw_data_1[i] += HAL_ADC_GetValue(&hadc1);
//				HAL_Delay(1);
			}
			HAL_ADC_Stop(&hadc1);
		 }
			 adc_raw_data_1[i] = adc_raw_data_1[i] / ADC_SAMPLES;

			/************ANALOG_VALUES TO CAN  ***************/
			 can_data_adc_low_volt_1 = adc_raw_data_1[6] ;
			 can_data_adc_low_volt_2 = adc_raw_data_1[7] ;
			 can_data_adc_low_volt_3 = adc_raw_data_1[8] ;
			 can_data_adc_low_volt_4 = adc_raw_data_1[9] ;
			}

	return local_error;
}
