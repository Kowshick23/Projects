#include "../../app_drivers/inc/message_support.h"


/**
 * @brief   unpacker function for reading can packet data received
 *      stores value in destination and uses reference for dbc attributes
 * @param   can_frame to pick the can data from
 * @param   reference to dbc attributes for the given case
 * @param   destination to store the raw backend data,
 *      stored as float in for of uint32_t,
 *      typecast with uint32_t pointer and deference while writing
 * @return  report error in case of failure
 */


error_t message_unpacker(   message_frame_t* frame,
                const signal_attributes_t* reference,
                volatile uint32_t* destination)
{
    error_t local_error = ER_Success;
    if((frame == NULL)||(reference == NULL)||(destination == NULL))
    {
        local_error = ER_Null;
        #ifdef MESSAGE_SUPPORT_LOGS
        log_event("Null detected");
        #endif
    }
    else
    {
	    float accumulator_float;
		uint32_t mask = 1;
		uint32_t accumulator = 0;
		int32_t accumulator_s32 = 0;
		uint32_t whole_data = 0;
        int8_t index_pointer = reference->start / 8; /* pointer to the correct byte in the frame */
        uint8_t bits_pointer = reference->start % 8;  /* pointer to the correct bit in the byte pointed by index pointer */
	    uint8_t byte_buffer = 0;
	    uint8_t bits_copied = 0;
	    uint8_t bits_to_be_copied = 0;


        while((bits_copied < reference->cache->length)&&(index_pointer < BITS_IN_A_BYTE)) /* open - replace with CAN standard DLC */
        {
            bits_to_be_copied =  minimum_of( reference->cache->length - bits_copied, BITS_IN_A_BYTE - bits_pointer);
            /*
             * "BITS_IN_A_BYTE - bits_pointer" handles if start bit is not a multiple of BITS_IN_A_BYTE
             * "reference->cache->length - bits_copied" handles if length is not a multiple of BITS_IN_A_BYTE
             * together they handle a permutations of both
             * */
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("bits_copied:%d, reference->cache->length:%d, bits_to_be_copied:%d"
                    ,bits_copied ,reference->cache->length,bits_to_be_copied);

            #endif
            byte_buffer = frame->data[index_pointer];
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("raw: byte_buffer:0x%x, data[i]:0x%x"
                                ,byte_buffer,frame -> data[index_pointer]);

            #endif
            byte_buffer >>= bits_pointer;
            byte_buffer &= (ALL_F_8 >> ( BITS_IN_A_BYTE - bits_to_be_copied ));
            whole_data = byte_buffer;
            accumulator |= (whole_data << bits_copied);
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("byte_buffer:0x%x, data[i]:0x%x, accumulator:0x%08x"
                    ,byte_buffer,frame -> data[index_pointer], accumulator);
            #endif
            bits_copied += bits_to_be_copied;
            bits_pointer = 0;

            if( reference->cache->format == Intel )
            {
                index_pointer++;
            }
            else if( reference->cache->format == Motorola )
            {
                index_pointer--;
            }
            else
            {
                local_error |= ER_Fail | ER_Mismatch ;
                break;
            }

            if((( index_pointer > BITS_IN_A_BYTE )||( index_pointer < ZERO )) && (bits_copied < reference->cache->length))
            {
                local_error |= ER_Fail | ER_Overflow ;
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Size Error while final unpacking data from data[]");
                #endif
                break;
            }
        }

        if(local_error == ER_Success)
        {
            if((reference->cache->sign == Signed_float)||(reference->cache->sign == Unsigned_float))
            {
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Data type Floating");
                #endif

                accumulator_s32 = *((int32_t*)&accumulator);

                if((reference->cache->length != BITS_IN_UINT32)&&(reference->cache->sign == Signed_float))
                {
                    mask = 0x1 << (reference->cache->length - 1);
                    if( accumulator_s32 & mask)
                    {
                        accumulator_s32 |= (ALL_F_32 << reference->cache->length);
                    }
                }
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("signed_pick:0x%lx",accumulator_s32);

                #endif

                accumulator_float = (accumulator_s32 * reference->cache->factor) + reference->cache->offset;

                #ifdef RANGE_CHECK
                if( (accumulator_float < reference->cache->minimum)||(accumulator_float > reference->cache->maximum))
                {
                    local_error |= ER_Out_of_range;
                    #ifdef MESSAGE_SUPPORT_LOGS
                    log_event("data out of range, data:%ld, min:%f max:%f"
                            ,accumulator_float,reference->cache->minimum,reference->cache->maximum);

                    #endif
                }
                else
                {
                    accumulator = *((uint32_t*)&accumulator_float);
                }
                #else
                accumulator = *((uint32_t*)&accumulator_float);
                #endif
            }
            else if(reference->cache->sign == Signed)
            {
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Data type Signed");
                #endif

                accumulator_s32 = *((int32_t*)&accumulator);
                if(reference->cache->length != BITS_IN_UINT32)
                {
                    mask = 0x1 << (reference->cache->length - 1);
                    if( accumulator_s32 & mask)
                    {
                        accumulator_s32 |= (ALL_F_32 << reference->cache->length);
                    }
                }

                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("signed_pick:0x%lx",accumulator_s32);

                #endif

                accumulator_s32 = (accumulator_s32 * reference->cache->factor) + reference->cache->offset;

                #ifdef RANGE_CHECK
                if( ((float)accumulator_s32 < reference->cache->minimum)||((float)accumulator_s32 > reference->cache->maximum))
                {
                    local_error |= ER_Out_of_range;
                    #ifdef MESSAGE_SUPPORT_LOGS
                    log_event("data out of range, data:%ld, min:%f max:%f"
                        ,accumulator_s32,reference->cache->minimum,reference->cache->maximum);

                    #endif
                }
                else
                {
                    accumulator = *((uint32_t*)&accumulator_s32);
                }
                #else
                accumulator = *((uint32_t*)&accumulator_s32);
                #endif

            }
            else
            {
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Data type Unsigned");
                #endif

                accumulator = (accumulator * reference->cache->factor) + reference->cache->offset;

                #ifdef RANGE_CHECK
                if( ((float)accumulator < reference->cache->minimum)||
                    ((float)accumulator > reference->cache->maximum))
                {
                    local_error |= ER_Out_of_range;
                    #ifdef MESSAGE_SUPPORT_LOGS
                    log_event("data out of range, data:%ld, min:%f max:%f"
                            ,accumulator,reference->cache->minimum,reference->cache->maximum);

                    #endif
                }
                #endif

            }
        }

        if(local_error == ER_Success)
        {
            *destination = *((uint32_t*)&accumulator);
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("msg_id:0x%03x,\tdatatype:%d,\tdata:%016x"
            ,frame->msg_id,destination->datatype,destination->data);

            #endif
        }
    }
    return local_error;
}

/**
 * @brief   packer function for writing to can packet data
 *      picks value from source and uses reference for dbc attributes
 * @param   frame to store the final value calculated
 * @param   reference to dbc attributes for the given case
 * @param   source from where to pick the raw backend data,
 *      stored as float in for of uint32_t,
 *      typecast with float pointer and deference while reading
 * @return  report error in case of failure
 */
error_t message_packer( message_frame_t* frame,
                const signal_attributes_t* reference,
                volatile uint32_t* source)
{
    error_t local_error = ER_Success;
    if((frame == NULL)||(reference == NULL)||(source == NULL))
    {
        local_error |= ER_Null;
        #ifdef MESSAGE_SUPPORT_LOGS
        log_event("NULL error detected");
        #endif
    }
    else
    {
        uint32_t accumulator = 0;
        int32_t  accumulator_s32 = 0;
        float accumulator_float = 0;
        int8_t index_pointer = 0;
        uint8_t bits_pointer = 0;
        uint8_t mask = 0;
        uint8_t byte_buffer = 0;
        uint8_t bits_copied = 0;
        uint8_t bits_to_be_copied = 0;

        if((reference->cache->sign == Signed_float)||(reference->cache->sign == Unsigned_float))
        {
            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("Data type Floating");
            #endif

            accumulator_float = *((float*)source);

            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("accumulator_float, %f",accumulator_float);

            #endif

            #ifdef RANGE_CHECK
            if( (accumulator_float < reference->cache->minimum)||(accumulator_float > reference->cache->maximum))
            {
                local_error |= ER_Out_of_range;
                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("data out of range, data:%ld, min:%f max:%f"
                                        ,accumulator_float,reference->cache->minimum,reference->cache->maximum);

                #endif
            }
            else
            {
            #endif


                if(reference->cache->sign == Signed_float)
                {
                    accumulator_s32 = ((float)(accumulator_float - reference->cache->offset )
                        / reference->cache->factor);

                    #ifdef MESSAGE_SUPPORT_LOGS_2
                    log_event("accumulator_s32, 0x%lx",accumulator_s32);

                    #endif
                    if(accumulator_s32 < 0)
                    {
                        accumulator_s32 &= ( ALL_F_32 >>
                            ( BITS_IN_UINT32 - reference->cache->length ));

                    }
                    accumulator = *((uint32_t*)&accumulator_s32);
                }
                else
                {
                    accumulator = ((float)(accumulator_float - reference->cache->offset )
                            / reference->cache->factor);
                }
            #ifdef RANGE_CHECK
            }
            #endif
        }
        else if(reference->cache->sign == Signed)
        {
            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("Data type Signed");
            #endif
            memcpy(&accumulator_s32,(const void*)source,SIZE_OF_UINT32);

            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("accumulator_s32, %d",accumulator_s32);

            #endif

            #ifdef RANGE_CHECK
            if( ((float)accumulator_s32 < reference->cache->minimum)||((float)accumulator_s32 > reference->cache->maximum))
            {
                local_error |= ER_Out_of_range;
                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("data out of range, data:%ld, min:%f max:%f"
                                        ,accumulator_s32,reference->cache->minimum,reference->cache->maximum);

                #endif
            }
            else
            {
            #endif
                accumulator_s32 = ( accumulator_s32 - reference->cache->offset ) / reference->cache->factor;
                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("accumulator_s32, 0x%lx",accumulator_s32);

                #endif
                if(accumulator_s32 < 0)
                {
                    accumulator_s32 &= ( ALL_F_32 >>
                        ( BITS_IN_UINT32 - reference->cache->length ));

                }
                accumulator = *((uint32_t*)&accumulator_s32);
            #ifdef RANGE_CHECK
            }
            #endif
        }
        else
        {
            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("Data type Unsigned");
            #endif

            memcpy(&accumulator,(const void*)source,SIZE_OF_UINT32);

            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("accumulator, %d",accumulator);

            #endif


            #ifdef RANGE_CHECK
            if( ((float)accumulator < reference->cache->minimum)|| ((float)accumulator > reference->cache->maximum))
            {
                local_error |= ER_Out_of_range;
                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("data out of range, data:%ld, min:%f max:%f"
                                        ,accumulator,reference->cache->minimum,reference->cache->maximum);

                #endif
            }
            else
            {
                accumulator = ( accumulator - reference->cache->offset ) / reference->cache->factor;
            }
            #else
            accumulator = ( accumulator - reference->cache->offset )
                                / reference->cache->factor;

            #endif
        }

        if(local_error == ER_Success)
        {
            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("accumulator before: 0x%lx",accumulator);

            #endif

            index_pointer = reference->start / 8;
            bits_pointer = reference->start % 8;

            while((bits_copied < reference->cache->length)&&(index_pointer < BITS_IN_A_BYTE ))
            {
                bits_to_be_copied =  minimum_of( reference->cache->length - bits_copied, BITS_IN_A_BYTE - bits_pointer);
                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("bits_copied:%d, reference->cache->length:%d, bits_to_be_copied:%d"
                        ,bits_copied ,reference->cache->length,bits_to_be_copied);

                #endif

                mask = power_calculate(2,bits_to_be_copied)-1;
                mask <<= bits_pointer;
                frame -> data[index_pointer] &= ~mask;
                byte_buffer = accumulator;
                byte_buffer <<= bits_pointer;
                byte_buffer &= mask;
                frame -> data[index_pointer] |= byte_buffer;

                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("mask:0x%x, byte_buffer:0x%x, data[i]:0x%x"
                        ,mask ,byte_buffer,frame -> data[index_pointer]);

                #endif

                accumulator >>= bits_to_be_copied;
                bits_copied += bits_to_be_copied;
                bits_pointer = 0;

                #ifdef MESSAGE_SUPPORT_LOGS_2
                log_event("accumulator:0x%x",accumulator);

                #endif
                if( reference->cache->format == Intel )
                {
                    index_pointer++;
                }
                else if( reference->cache->format == Motorola )
                {
                    index_pointer--;
                }
                else
                {
                    local_error |= ER_Fail | ER_Mismatch ;
                    break;
                }

                if((( index_pointer > BITS_IN_A_BYTE )||( index_pointer < ZERO )) && (bits_copied < reference->cache->length))
                {
                    local_error = ER_Fail;

                    #ifdef MESSAGE_SUPPORT_LOGS_2
                    log_event("Size Error while final packing data in data[]");
                    #endif

                    break;
                }
            }


            #ifdef MESSAGE_SUPPORT_LOGS_2
            log_event("final_can_data: 0x%08x%08x ",frame->data32[1],frame->data32[0]);

            #endif
        }
    }
    return local_error;
}


/*************************************************/


error_t message_unpacker_lin(   message_frame_lin_t* frame,
                const signal_attributes_t* reference,
                volatile uint32_t* destination)
{
    error_t local_error = ER_Success;
    if((frame == NULL)||(reference == NULL)||(destination == NULL))
    {
        local_error = ER_Null;
        #ifdef MESSAGE_SUPPORT_LOGS
        log_event("Null detected");
        #endif
    }
    else
    {
	    float accumulator_float;
		uint32_t mask = 1;
		uint32_t accumulator = 0;
		int32_t accumulator_s32 = 0;
		uint32_t whole_data = 0;
        int8_t index_pointer = reference->start / 8; /* pointer to the correct byte in the frame */
        uint8_t bits_pointer = reference->start % 8;  /* pointer to the correct bit in the byte pointed by index pointer */
	    uint8_t byte_buffer = 0;
	    uint8_t bits_copied = 0;
	    uint8_t bits_to_be_copied = 0;


        while((bits_copied < reference->cache->length)&&(index_pointer < BITS_IN_A_BYTE)) /* open - replace with CAN standard DLC */
        {
            bits_to_be_copied =  minimum_of( reference->cache->length - bits_copied, BITS_IN_A_BYTE - bits_pointer);
            /*
             * "BITS_IN_A_BYTE - bits_pointer" handles if start bit is not a multiple of BITS_IN_A_BYTE
             * "reference->cache->length - bits_copied" handles if length is not a multiple of BITS_IN_A_BYTE
             * together they handle a permutations of both
             * */
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("bits_copied:%d, reference->cache->length:%d, bits_to_be_copied:%d"
                    ,bits_copied ,reference->cache->length,bits_to_be_copied);

            #endif
            byte_buffer = frame->data_lin[index_pointer];
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("raw: byte_buffer:0x%x, data[i]:0x%x"
                                ,byte_buffer,frame -> data[index_pointer]);

            #endif
            byte_buffer >>= bits_pointer;
            byte_buffer &= (ALL_F_8 >> ( BITS_IN_A_BYTE - bits_to_be_copied ));
            whole_data = byte_buffer;
            accumulator |= (whole_data << bits_copied);
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("byte_buffer:0x%x, data[i]:0x%x, accumulator:0x%08x"
                    ,byte_buffer,frame -> data[index_pointer], accumulator);
            #endif
            bits_copied += bits_to_be_copied;
            bits_pointer = 0;

            if( reference->cache->format == Intel )
            {
                index_pointer++;
            }
            else if( reference->cache->format == Motorola )
            {
                index_pointer--;
            }
            else
            {
                local_error |= ER_Fail | ER_Mismatch ;
                break;
            }

            if((( index_pointer > BITS_IN_A_BYTE )||( index_pointer < ZERO )) && (bits_copied < reference->cache->length))
            {
                local_error |= ER_Fail | ER_Overflow ;
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Size Error while final unpacking data from data[]");
                #endif
                break;
            }
        }

        if(local_error == ER_Success)
        {
            if((reference->cache->sign == Signed_float)||(reference->cache->sign == Unsigned_float))
            {
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Data type Floating");
                #endif

                accumulator_s32 = *((int32_t*)&accumulator);

                if((reference->cache->length != BITS_IN_UINT32)&&(reference->cache->sign == Signed_float))
                {
                    mask = 0x1 << (reference->cache->length - 1);
                    if( accumulator_s32 & mask)
                    {
                        accumulator_s32 |= (ALL_F_32 << reference->cache->length);
                    }
                }
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("signed_pick:0x%lx",accumulator_s32);

                #endif

                accumulator_float = (accumulator_s32 * reference->cache->factor) + reference->cache->offset;

                #ifdef RANGE_CHECK
                if( (accumulator_float < reference->cache->minimum)||(accumulator_float > reference->cache->maximum))
                {
                    local_error |= ER_Out_of_range;
                    #ifdef MESSAGE_SUPPORT_LOGS
                    log_event("data out of range, data:%ld, min:%f max:%f"
                            ,accumulator_float,reference->cache->minimum,reference->cache->maximum);

                    #endif
                }
                else
                {
                    accumulator = *((uint32_t*)&accumulator_float);
                }
                #else
                accumulator = *((uint32_t*)&accumulator_float);
                #endif
            }
            else if(reference->cache->sign == Signed)
            {
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Data type Signed");
                #endif

                accumulator_s32 = *((int32_t*)&accumulator);
                if(reference->cache->length != BITS_IN_UINT32)
                {
                    mask = 0x1 << (reference->cache->length - 1);
                    if( accumulator_s32 & mask)
                    {
                        accumulator_s32 |= (ALL_F_32 << reference->cache->length);
                    }
                }

                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("signed_pick:0x%lx",accumulator_s32);

                #endif

                accumulator_s32 = (accumulator_s32 * reference->cache->factor) + reference->cache->offset;

                #ifdef RANGE_CHECK
                if( ((float)accumulator_s32 < reference->cache->minimum)||((float)accumulator_s32 > reference->cache->maximum))
                {
                    local_error |= ER_Out_of_range;
                    #ifdef MESSAGE_SUPPORT_LOGS
                    log_event("data out of range, data:%ld, min:%f max:%f"
                        ,accumulator_s32,reference->cache->minimum,reference->cache->maximum);

                    #endif
                }
                else
                {
                    accumulator = *((uint32_t*)&accumulator_s32);
                }
                #else
                accumulator = *((uint32_t*)&accumulator_s32);
                #endif

            }
            else
            {
                #ifdef MESSAGE_SUPPORT_LOGS
                log_event("Data type Unsigned");
                #endif

                accumulator = (accumulator * reference->cache->factor) + reference->cache->offset;

                #ifdef RANGE_CHECK
                if( ((float)accumulator < reference->cache->minimum)||
                    ((float)accumulator > reference->cache->maximum))
                {
                    local_error |= ER_Out_of_range;
                    #ifdef MESSAGE_SUPPORT_LOGS
                    log_event("data out of range, data:%ld, min:%f max:%f"
                            ,accumulator,reference->cache->minimum,reference->cache->maximum);

                    #endif
                }
                #endif

            }
        }

        if(local_error == ER_Success)
        {
            *destination = *((uint32_t*)&accumulator);
            #ifdef MESSAGE_SUPPORT_LOGS
            log_event("msg_id:0x%03x,\tdatatype:%d,\tdata:%016x"
            ,frame->msg_id,destination->datatype,destination->data);

            #endif
        }
    }
    return local_error;
}

