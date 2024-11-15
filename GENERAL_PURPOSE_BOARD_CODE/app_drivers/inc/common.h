#ifndef COMMON_H_
#define COMMON_H_

/* Free rtos includes */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "croutine.h"
#include "event_groups.h"
#include "mpu_wrappers.h"
#include "portmacro.h"

/* C standard includes */
#include <math.h>
#include "strings.h"
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "stm32f3xx_hal.h"


#define SIZE_OF_INT8  (1)
#define SIZE_OF_INT16 (2)
#define SIZE_OF_INT32 (4)
#define SIZE_OF_INT64 (8)
#define SIZE_OF_UINT8  (1)
#define SIZE_OF_UINT16 (2)
#define SIZE_OF_UINT32 (4)
#define SIZE_OF_UINT64 (8)
#define SIZE_OF_FLOAT  (4)

#define BITS_IN_UINT8  (8)
#define BITS_IN_UINT16 (16)
#define BITS_IN_UINT32 (32)
#define BITS_IN_UINT64 (64)
#define BITS_IN_A_NIBBLE (4)
#define BITS_IN_A_BYTE (8)

#define SEM_INIT_ZERO (0)
#define SEM_INIT_ONE (1)
#define ASCII_SPACE (32)

#define SEC_IN_AN_HOUR (3600)
#define MSEC_IN_SEC (1000)
#define USEC_IN_MSEC (1000)
#define NSEC_IN_USEC (1000)
#define USEC_IN_SEC (USEC_IN_MSEC * MSEC_IN_SEC)
#define NSEC_IN_SEC (NSEC_IN_USEC  * USEC_IN_MSEC * MSEC_IN_SEC)
#define MILLI_AMPS_IN_AMP ((float)1000.0)
#define MILLI_VOLTS_IN_VOLT ((float)1000.0)
#define OHMS_IN_KOHM (1000)
#define ABSOLUTE_ZERO_KELVIN_IN_CELCIUS ((float)-273.15)

#define ALL_F_4  (0xF)
#define ALL_F_8  (0xFF)
#define ALL_F_16 (0xFFFF)
#define ALL_F_24 (0xFFFFFF)
#define ALL_F_32 (0xFFFFFFFF)
#define SET (1)
#define CLEAR (0)
#define ZERO (0)
#define TRUE (1)
#define FALSE (1)
#define OFF   (1)
#define ON    (0)
#define UPDATED (0)
#define BASE_2  (2)
#define BASE_8  (8)
#define BASE_10 (10)
#define BASE_16 (16)
#define PWM_ZERO    (0)
#define PWM_HUNDRED (100)
#define MESSAGE_SIZE (80)

#define FLOAT_SIGNIFICANT_POWER     (10e6)
#define FLOAT_TOLERANCE             ((float)0.001)
#define FREE_RTOS_TICK_FREQUENCY_HZ      (1000)
#define STM32_CLOCK (12228000)

/** enums for error handling */
typedef enum
{
    ER_Success  = 0x0000, /* Default Success condition */
    ER_Fail     = 0x0001, /* Report Failure Default */
    ER_Null     = 0x0002, /* Report error if a NULL pointer is caught */
    ER_Timeout  = 0x0004, /* Report error if Timeout is caught, unsynced */
    ER_Overflow = 0x0008, /* Report error in case of data overflow */
    ER_Mismatch = 0x0010, /* Report error if data or variable is mismatched */
    ER_Out_of_range = 0x0020, /* Report error if enum or data is out of range */
    ER_Corrupt  = 0x0040, /* Report error if data is corrupted */
    ER_Critical = 0x0080, /* Report error in case of critical error  */
    ER_Segmentation     = 0x0100, /* Report error if a segmentation fault is caught/anticipated  */
    ER_Stack_overflow   = 0x0200, /* Report errot if stack overflow is caught/anticipated */
    ER_Recursion_limit  = 0x0400, /* Report error if recursion limit is reached in a function */
    ER_Mathematical     = 0x0800, /* Report error in case of wrong mathematical result or implementation */
    ER_Resource_Busy    = 0x1000, /* Report error if a resource is busy */
    ER_Dynamic          = 0x2000, /* Report error if dynamic heap or memory is not allocated */
    ER_Memory_leak      = 0x4000, /* Report error if memory leakage is detected in the code */
    ER_Hardware         = 0x8000, /* Report error in case of Electronic Hardware Failure */
}error_t;

typedef enum
{
    Unsigned = 0,
    Signed  = 1,
    Unsigned_float = 2,
    Signed_float = 3
}datatype_t;

typedef enum
{
    Intel = 0,
    Motorola  = 1,
}format_t;

typedef enum
{

	rx= 0,
	tx = 1
}direction_t;

/* prototypes */
uint8_t assert_set(uint8_t x);
uint8_t assert_clear(uint8_t x);
uint8_t assert_zero(uint8_t x);
uint8_t assert_equal(uint32_t x,uint32_t y);
uint8_t assert_not_equal(uint32_t x,uint32_t y);
uint8_t assert_success(error_t x);
uint8_t assert_critical(error_t x);
uint8_t assert_null(void* x);
uint8_t assert_not_null(void* x);

error_t clear_data(uint8_t* data,uint32_t size);
void reverse(uint8_t* str, int len);
#endif
