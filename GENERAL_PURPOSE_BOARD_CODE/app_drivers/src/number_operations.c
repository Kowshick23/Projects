
#include "../../app_drivers/inc/number_operations.h"

/**
 * @brief		calculates the power of a number
 * @param		number
 * @param		power
 * @return		power of the number calculated
 */
uint64_t power_calculate(uint8_t number, uint8_t power)
{
	uint8_t i = 0;
	uint64_t result = 1;
	for(i=0;i<power;i++)
	{
		result *= number;
	}
	return result;	
}
