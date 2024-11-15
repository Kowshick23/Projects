#ifndef LIB_INCLUDE_MESSAGE_SUPPORT_H_
#define LIB_INCLUDE_MESSAGE_SUPPORT_H_


#include "../../app_drivers/inc/number_operations.h"

#define RANGE_CHECK

extern CAN_HandleTypeDef hcan;
//extern CAN_HandleTypeDef hcan2;
//extern CAN_HandleTypeDef hcan3;


typedef enum
{
	Unsigned_1 = 0,
	Signed_1	= 1,
	Floating = 2,
}can_datatype_t;

typedef struct
{
    uint32_t msg_id;
    uint8_t data[8];
    CAN_RxHeaderTypeDef rx_header;
    CAN_TxHeaderTypeDef tx_header;

}message_frame_t;


typedef struct
{
    uint32_t msg_id_lin;
    uint8_t data_lin[8];
//    CAN_RxHeaderTypeDef rx_header;
//    CAN_TxHeaderTypeDef tx_header;
}message_frame_lin_t;




/* structure used for saving handler functions for all can messages */
typedef struct
{
    uint32_t msg_id;
    uint8_t signal_count;
    uint16_t signal_offset;
    direction_t direction;
    CAN_HandleTypeDef* port;
}message_tracker_t;

typedef struct __attribute__ ((__packed__))
{
    uint8_t     length;
    uint32_t    initial_value;
    float       factor;
    float       offset;
    float       minimum;
    float       maximum;
    datatype_t  sign;
    format_t    format;
}signal_attribute_cache_t;

/* structure used for saving can dbc attributes for each signal*/
typedef struct __attribute__ ((__packed__))
{
    uint32_t    msg_id;
    uint8_t     start;
    signal_attribute_cache_t* cache;          /* signed:1 unsigned:0 *can_dbc_standard_trd_t;*/
}signal_attributes_t;


/* Function Prototypes */

error_t message_unpacker(message_frame_t* can_frame,
				const signal_attributes_t* reference,
				volatile uint32_t* destination);

error_t message_packer(message_frame_t* can_frame,
				const signal_attributes_t* reference,
				volatile uint32_t* source);
#endif

