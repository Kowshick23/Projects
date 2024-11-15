
 #include "../../app_drivers/inc/hashmap.h"
 
tracker_node_t* can_hashmap[HASHMAP_SIZE];
tracker_node_t can_hashmap_data[TOTAL_CAN_MESSAGES];
/**
 * @brief   allocate data for the hashmap nodes
 * @param   double pointer to store the pointer allocated
 * @return  report error in case of failure
*/
error_t hashmap_data_allocate(tracker_node_t** node_pointer,tracker_node_t* hashmap_data)
{
    error_t local_error = ER_Success;
    static uint16_t memory_counter = 0;
    if(node_pointer == NULL)
    {
        local_error = ER_Null;
    }
    else if(memory_counter >= TOTAL_CAN_MESSAGES)
    {
        local_error = ER_Fail;
    }
    else
    {
        *node_pointer = &hashmap_data[memory_counter];
        memory_counter++;
    }
    return local_error;
}

/**
 * @brief	print the hashmap created earlier
 * @return	report error in case of failure
 */ 
error_t hashmap_print(tracker_node_t** hashmap)
{
	error_t local_error = ER_Success;
	uint32_t i = 0;
	tracker_node_t* node;
	
	for(i=0;i<HASHMAP_SIZE;i++)
	{
		node = hashmap[i];
		#ifdef HASHMAP_LOGS
		log_hex("node:",i);
		#endif
		
		if(node == NULL)
		{
			
			#ifdef HASHMAP_LOGS
			log_event("Null node detected");
			#endif
		}
		else
		{
			while(node!=NULL)
			{
                #ifdef HASHMAP_LOGS
			    log_hex("",node->tracker_data->msg_id);
                #endif
				node = node -> next;
			}
		}
	}
	
	return local_error;
}


/**
 * @brief   Build a hashmap for storing handler array nodes
 * @param   Handler array data set
 * @return  report error in case of failure
 */
error_t hashmap_builder(const message_tracker_t* array, tracker_node_t** hashmap, tracker_node_t* hashmap_data)
{
    error_t local_error = ER_Success;
    uint32_t i = 0;
    uint16_t id = 0;
    uint16_t hash_id;
    tracker_node_t* node;

    for(i=0;i<TOTAL_CAN_MESSAGES;i++)
    {
        id = array[i].msg_id;
        hash_id = id % HASHMAP_SIZE;

        if(hashmap[hash_id]==NULL)
        {
            #ifdef HASHMAP_LOGS
            log_hex("Creating node in hashmap at",hash_id);

            #endif
            local_error |= hashmap_data_allocate(&hashmap[hash_id],hashmap_data);
            if(local_error == ER_Success)
            {
                node = hashmap[hash_id];
            }
        }
        else
        {
            node = hashmap[hash_id];
            while(node -> next != NULL)
            {
                node = node -> next;
            }
            local_error |= hashmap_data_allocate(&(node -> next),hashmap_data);
            if(local_error == ER_Success)
            {
                node = node -> next;
            }
        }

        if(local_error == ER_Success)
        {
            node -> tracker_data = &array[i];
        }
    }
    return local_error;
}

/**
 * @brief	create hashmap for storing handler array data
 *		the data is stored as a hashmap + linked list data structure
 *		hash_id points to the head node of each linklist, 
 *		store the handler function pointer that points to 
 *		static handler_array defined in dbc.h
 * @return	report error in case of failure
 */ 
error_t hashmap_init()
{
	error_t local_error = ER_Success;
	local_error |=  hashmap_builder(can_tracker_array,(tracker_node_t**)&can_hashmap,(tracker_node_t*)&can_hashmap_data);
	return local_error;
}

/**
 * @brief	check the hashmap + linked list for msg_id in the can packet
 *		return success if found and store the handler function pointer
 *		that points to static handler_array defined in dbc.h
 * @param	frame of the can packet to be checked in hashmap
 * @param	handler data to store packer unpacker for given msg_id
 * @return	report error in case of failure
 */ 
error_t hashmap_query(message_frame_t* frame, message_tracker_t const **  handler_data, tracker_node_t** hashmap)
{
	error_t local_error = ER_Fail;
	uint16_t hash_id = frame->msg_id % HASHMAP_SIZE;
	tracker_node_t* node = hashmap[hash_id];
    while(node != NULL)
    {
        if(frame->msg_id == node->tracker_data->msg_id)
        {
            *handler_data = node->tracker_data;
            local_error = ER_Success;
            #ifdef HASHMAP_LOGS
            log_hex("msg_id found in hashmap" ,frame->msg_id);

            #endif
            break;
        }
        node = node->next;
    }
	return local_error;
}

/**
 * @brief	delete the hashmap created and free pointers 
 * @return	report error in case of failure
 */ 
error_t hashmap_delete(tracker_node_t** hashmap)
{
	error_t local_error = ER_Success;
	uint32_t i = 0;
	tracker_node_t* node;
	tracker_node_t* prev;
	
	for(i=0;i<HASHMAP_SIZE;i++)
	{
		node = hashmap[i];
		while(node != NULL)
		{
			prev = node;
			node = node -> next;
			#ifdef HASHMAP_LOGS
			log_hex("Free node in hashmap at "
				,prev->tracker_data->msg_id);
			
			#endif
			free(prev);
			prev = NULL;
		}

		hashmap[i] = NULL;
	}
	
	#ifdef HASHMAP_LOGS
	log_event("Hashmap_deleted");
	#endif
	return local_error;
}
