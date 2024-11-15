#ifndef INC_CAN_DRIVER_H_
#define INC_CAN_DRIVER_H_

#include "../../app_drivers/inc/hashmap.h"

#define CAN_ON
#ifdef CAN_ON
#define CAN_1_START
#ifdef 	CAN_1_START
#define CAN_1_FIFO_0
//#define CAN_1_FIFO_1
#endif

//#define	CAN_2_START
#ifdef 	CAN_2_START
//#define CAN_2_FIFO_0
#define CAN_2_FIFO_1
#endif


//#define CAN_3_START
#ifdef  CAN_3_START
#define CAN_3_FIFO_0
//#define CAN_3_FIFO_1
#endif
#endif


//#define CAN_UNIT_TEST
//#define CAN_RECEIVE_INTERRUPT
#define CAN_RX_TRANSACTION_THRESOHOLD (100)
#define CAN_RECEIVE_QUEUE_SIZE (256)
#define CAN_STANDARD_FRAME_MAX_ID (0x7FF)
#define CAN_DEFAULT_DLC (8)
#define CAN_QUEUE_WAIT_TICKS (2)

extern CAN_HandleTypeDef hcan;
#define CAN_FLAG_CHECK() 	 (	CAN_IT_TX_MAILBOX_EMPTY     | CAN_IT_RX_FIFO0_MSG_PENDING      | \
                                CAN_IT_RX_FIFO0_FULL        | CAN_IT_RX_FIFO0_OVERRUN          | \
                                CAN_IT_RX_FIFO1_MSG_PENDING | CAN_IT_RX_FIFO1_FULL             | \
                                CAN_IT_RX_FIFO1_OVERRUN     | CAN_IT_WAKEUP                    | \
                                CAN_IT_SLEEP_ACK            | CAN_IT_ERROR_WARNING             | \
                                CAN_IT_ERROR_PASSIVE        | CAN_IT_BUSOFF                    | \
                                CAN_IT_LAST_ERROR_CODE      | CAN_IT_ERROR	)

//extern QueueHandle_t can_receive_queue;
//extern QueueHandle_t can_receive_semaphore;
//extern QueueHandle_t can_send_semaphore;
//extern volatile error_tracker_t can_error_tracker[TOTAL_CAN_MESSAGES];


typedef struct
{
	CAN_HandleTypeDef* port;
	uint32_t mailbox;
}can_frame_wrapper_t;


void CAN_RxInterrupt(void);

error_t can_1_init(void);
error_t can_2_init(void);
error_t can_3_init(void);
error_t can_main_init(void);
error_t can_send_data(dbc_messages_t message);
error_t can_receive_processing(message_frame_t* frame);
error_t can_receive_data_can_1(void);
error_t can_receive_data_can_2(void);
error_t can_quick_packer(message_frame_t* frame, dbc_messages_t message);
error_t can_quick_unpacker(message_frame_t* frame, dbc_messages_t message);

extern void CAN_ReadRxBuffer(void);
error_t CANSPI_send_data(dbc_messages_t message);
error_t CANSPI_Receive_data(void);
#ifdef CAN_UNIT_TEST
error_t database_test_1(void);
error_t database_test_2(void);
error_t can_tx_test_3(void);
error_t can_tx_test_4(void);
error_t can_tx_test_1(void);
error_t can_tx_test_2(void);
#endif

#endif /* INC_CAN_DRIVER_H_ */
