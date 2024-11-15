#ifndef LIB_INCLUDE_NUMBER_OPERATIONS_H_
#define LIB_INCLUDE_NUMBER_OPERATIONS_H_

#include "stdint.h"

#include "../../app_drivers/inc/common.h"

#define is_a_number(x) (((x >= '0') && (x <= '9'))? pdTRUE:pdFALSE)
#define is_a_hex(x) ((((x >= '0') && (x <= '9'))|| ((x >= 'a') && (x <= 'f'))|| ((x >= 'A') && (x <= 'F')))? pdTRUE:pdFALSE)
#define is_a_letter(x) ((((x >= 'a') && (x <= 'z'))|| ((x >= 'A') && (x <= 'Z')))? pdTRUE:pdFALSE)
#define float_tolerance(x) (((x >= (FLOAT_TOLERANCE*(-1)))&&(x <= (FLOAT_TOLERANCE)))?pdTRUE:pdFALSE)
#define maximum_of(x,y) ((x>y)?x:y)
#define minimum_of(x,y) ((x<y)?x:y)
#define minimum_of_three(x,y,z) (minimum_of(x,minimum_of(y,z)))
#define maximum_of_three(x,y,z) (maximum_of(x,maximum_of(y,z)))
#define i2c(x) (((x>=0x0)&&(x<=0x9))? (x+'0'):(((x>=0xa)&&(x<=0xf))?(x+'a'-(0xa)):(-1)))
#define c2i(x) (((x>='0')&&(x<='9'))? (x-'0'):(((x>='a')&&(x<='f'))?(x-'a'+(0xa)):((((x>='A')&&(x<='F'))?(x-'A'+(0xa)):(-1)))))
#define compliment_8_1s(x)  (x^ALL_F_8)
#define compliment_8_2s(x)  ((x^ALL_F_8)+1)
#define compliment_16_1s(x) (x^ALL_F_16)
#define compliment_16_2s(x) ((x^ALL_F_16)+1)
#define compliment_32_1s(x) (x^ALL_F_32)
#define compliment_32_2s(x) ((x^ALL_F_32)+1)


/* function prototypes for functions based on pick_number*/

uint64_t power_calculate(uint8_t number, uint8_t power);

#endif /* LIB_INCLUDE_PICK_NUMBER_H_ */
