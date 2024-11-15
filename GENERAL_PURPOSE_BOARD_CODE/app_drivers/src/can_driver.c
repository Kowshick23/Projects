
#include "../../app_drivers/inc/can_driver.h"

//int can_error_counter=0;

CAN_TxHeaderTypeDef Txheader;
CAN_RxHeaderTypeDef Rxheader;

CAN_TxHeaderTypeDef   TrHeader;



uint32_t              TrMailbox;

extern uint32_t flag;
uint8_t Rxdata[8];

#ifdef CAN_RECEIVE_INTERRUPT
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	can_receive_data1();
	can_frame_wrapper_t buffer = {hcan,CAN_RX_FIFO0};
//    xQueueSendFromISR(can_receive_queue,&buffer,pdFALSE);
//    xSemaphoreGiveFromISR(can_receive_semaphore,pdFALSE);
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
	can_receive_data2();
	can_frame_wrapper_t buffer = {hcan,CAN_RX_FIFO1};
//    xQueueSendFromISR(can_receive_queue,&buffer,pdFALSE);
//    xSemaphoreGiveFromISR(can_receive_semaphore,pdFALSE);
}
#endif

error_t can_main_init(void)
{
	error_t local_error = ER_Success;

	#ifdef CAN_1_START
	HAL_CAN_MspInit(&hcan);
	HAL_CAN_Init(&hcan);
	HAL_CAN_Start(&hcan);
	can_1_init();
	#endif

	#ifdef CAN_2_START
	HAL_CAN_MspInit(&hcan2);
	HAL_CAN_Start(&hcan2);
	can_2_init();
	#endif

	#ifdef CAN_3_START
	HAL_CAN_MspInit(&hcan3);
	HAL_CAN_Start(&hcan3);
	#endif

    return local_error;
}

error_t can_1_init(void)
{
	error_t local_error = ER_Fail;

	CAN_FilterTypeDef canfilterconfig;

	#ifdef CAN_1_FIFO_0
	  canfilterconfig.FilterActivation = CAN_FILTER_ENABLE;
	  canfilterconfig.FilterBank = 10;  // which filter bank to use from the assigned ones
	  canfilterconfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	  canfilterconfig.FilterIdHigh = 0x001<<5;
	  canfilterconfig.FilterIdLow = 0;
	  canfilterconfig.FilterMaskIdHigh = 0x001<<5;
	  canfilterconfig.FilterMaskIdLow = 0x0000;
	  canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
	  canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;
	  canfilterconfig.SlaveStartFilterBank = 13;  // how many filters to assign to the CAN1 (master can)

		   HAL_CAN_ConfigFilter(&hcan, &canfilterconfig);
		local_error = ER_Success;
	#endif

	return local_error;
}



/**
 * @brief  Quick pack a can frame with most recent values in backend
 * @param  pointer to the frame to be packed
 * @param  can message to be packed into the frame
 * @return  Error in case of Failure
 */
error_t can_quick_packer(message_frame_t* frame, dbc_messages_t message)
{
    error_t local_error = ER_Success;
    uint8_t i = 0;
    message_tracker_t const * tracker = &can_tracker_array[message];
    frame->msg_id = tracker->msg_id;

    for(i=0;i<tracker->signal_count;i++)
    {
        local_error |= message_packer( frame,
                                       (signal_attributes_t*)&dbc_signal_attributes[(tracker->signal_offset)+i],
                                       (uint32_t*)can_data_pointer[(tracker->signal_offset)+i]);
    }
    return local_error;
}

/**
 * @brief  Quick unpack a can frame and store the data in backend
 * @param  pointer to the frame to be unpacked
 * @param  can message to be unpacked from the frame
 * @return  Error in case of Failure
 */
error_t can_quick_unpacker(message_frame_t* frame, dbc_messages_t message)
{
    error_t local_error = ER_Success;
    uint8_t i = 0;
    message_tracker_t const * tracker = &can_tracker_array[message];
    frame->msg_id = tracker->msg_id;

    for(i=0;i<tracker->signal_count;i++)
    {
        local_error |= message_unpacker( frame,
                                       (signal_attributes_t*)&dbc_signal_attributes[(tracker->signal_offset)+i],
                                       (uint32_t*)can_data_pointer[(tracker->signal_offset)+i]);
    }

    return local_error;
}



error_t can_send_data(dbc_messages_t message)
{
	  error_t local_error = ER_Success;
      message_frame_t frame;
      message_tracker_t const * tracker;
      can_frame_wrapper_t buffer;
      uint8_t i = 0;
	  HAL_CAN_Start(&hcan);
      if(message > TOTAL_CAN_MESSAGES )
      {
          #ifdef CAN_LOGS
          log_event("message not found in dbc.h");
          #endif
          local_error = ER_Out_of_range;
      }
      else
      {
          clear_data((uint8_t*)&frame,sizeof(frame));
          tracker = &can_tracker_array[message];
          frame.msg_id = tracker->msg_id;
          buffer.port = tracker->port;

          frame.tx_header.DLC = CAN_DEFAULT_DLC;
          if(frame.msg_id <= CAN_STANDARD_FRAME_MAX_ID)
          {
        	  frame.tx_header.IDE = CAN_ID_STD;
              frame.tx_header.StdId = frame.msg_id;
          }
          else
          {
        	  frame.tx_header.IDE = CAN_ID_EXT;
              frame.tx_header.ExtId = frame.msg_id;
          }

          for(i=0;i<tracker->signal_count;i++)
          {
              local_error |= message_packer( &frame,
                                             (signal_attributes_t*)&dbc_signal_attributes[(tracker->signal_offset)+i],
                                             (uint32_t*)can_data_pointer[(tracker->signal_offset)+i]);
          }

          HAL_CAN_AddTxMessage(buffer.port, &frame.tx_header, frame.data, &buffer.mailbox); /* open - verify frame.data for pointer error */

      }
      return local_error;
}

error_t can_receive_processing(message_frame_t* frame)
{
	uint16_t i=0;
	error_t local_error = ER_Success;
	message_tracker_t const * tracker; /* open - check for data corruption */


	if(frame->rx_header.ExtId)
	{
		frame->msg_id = frame->rx_header.ExtId;
		local_error |= hashmap_query(frame,&tracker,can_hashmap);
	}
	else
	{
		frame->msg_id = frame->rx_header.StdId;
		local_error |= hashmap_query(frame,&tracker,can_hashmap);
	}

	if(local_error == ER_Success)
	{
		 for(i=0;i<tracker->signal_count;i++)
		{
			local_error |= message_unpacker( frame,
											 (signal_attributes_t*)&dbc_signal_attributes[(tracker->signal_offset)+i],
											 (uint32_t*)can_data_pointer[(tracker->signal_offset)+i]);


		}
	}

    return local_error;
}
extern message_frame_t frame;
error_t can_receive_data_can_1(void)
{
	error_t local_error = ER_Success;
	uint8_t transaction_counter = 0;
	clear_data((uint8_t*)&frame.data,8);
	clear_data((uint8_t*)&frame.rx_header,sizeof(CAN_RxHeaderTypeDef));
	message_tracker_t const * tracker;
	#ifdef CAN_1_FIFO_0
	transaction_counter = 0;
	if(	(HAL_CAN_GetRxFifoFillLevel(&hcan,CAN_RX_FIFO0))
			&&(transaction_counter < CAN_RX_TRANSACTION_THRESOHOLD))
	{

		HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &frame.rx_header, (uint8_t*)&frame.data);

		if((frame.rx_header.StdId == 1 )|| (frame.rx_header.StdId == 7 ))
		{
		local_error |= hashmap_query(&frame,&tracker,can_hashmap);
		local_error |= can_receive_processing(&frame);
		}
		transaction_counter++;

	}
	#endif


		if(frame.msg_id == 7)
		{
			flag = 1;

		}
		else
		{
			flag = 0;
			frame.msg_id = 0;

		}

return local_error;
}
