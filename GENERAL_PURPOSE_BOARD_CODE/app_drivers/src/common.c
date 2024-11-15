
#include "../../app_drivers/inc/common.h"

uint8_t assert_set(uint8_t  x)
{
    return  ((SET==x)?TRUE:FALSE);
}

uint8_t assert_clear(uint8_t  x)
{
    return  ((CLEAR==x)?TRUE:FALSE);
}

uint8_t assert_zero(uint8_t  x)
{
    return  ((ZERO==x)?TRUE:FALSE);
}

uint8_t assert_equal(uint32_t x,uint32_t y)
{
    return  ((y==x)?TRUE:FALSE);
}

uint8_t assert_not_equal(uint32_t x,uint32_t y)
{
    return  ((y==x)?FALSE:TRUE);
}

uint8_t assert_success(error_t x)
{
    return  ((ER_Success==x)?TRUE:FALSE);
}

uint8_t assert_critical(error_t x)
{
    return  ((ER_Critical==x)?TRUE:FALSE);
}

uint8_t assert_null(void* x)
{
    return  ((NULL==x)?TRUE:FALSE);
}

uint8_t assert_not_null(void* x)
{
    return  ((NULL==x)?FALSE:TRUE);
}


/**
 * @brief		clears data 
 * @param		data to be cleared
 * @param		size of data to be cleared
 * @return		report error in case of failure
 */
error_t clear_data( uint8_t * data, uint32_t size)
{
	uint32_t i=0;
	error_t local_error = ER_Success;
	for(i = 0 ; i < size; i++)
	{
		if( data + i == NULL)
		{
			local_error = ER_Fail;
			break;
		}
		else
		{
			*(data + i) = 0x00;
		}
	}
	return local_error;
}

/*
 *
 * @brief       reverse a string.
 * @param       string to be reversed
 * @param       length of string
 *
 *
 */
void reverse(uint8_t * str, int len)
{
    int i = 0, j = len - 1;
    uint8_t  temp = 0;
    while (i < j)
    {
         temp = *(str + i);
         *(str + i) = *(str + j);
         *(str + j) = temp;
     i++;
     j--;
    }
}

void reverse_bits_in_a_byte(uint8_t * byte)
{
    uint8_t  i=0, temp = 0;
    for(i=0;i<BITS_IN_A_BYTE;i++)
    {
        if(*byte & 0x01)
        {
            temp |= (0x80 >> i);
        }
        *byte = *byte >> 1;
    }
    *byte = temp;
}
