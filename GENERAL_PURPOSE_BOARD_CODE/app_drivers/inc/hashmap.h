#ifndef LIB_INCLUDE_HASHMAP_H_
#define LIB_INCLUDE_HASHMAP_H_

#include "../../app_drivers/inc/dbc.h"


//#define DATABASE_TEST
//#define DATABASE_LOGS
#define HASHMAP_SIZE (8)
/* struct for storing the handlers in hashmap linked list format*/
typedef struct tracker_node_t
{
	struct tracker_node_t* next;
	message_tracker_t const * tracker_data;
}tracker_node_t;


extern tracker_node_t* can_hashmap[HASHMAP_SIZE];
extern tracker_node_t can_hashmap_data[TOTAL_CAN_MESSAGES];

/* Prototypes */
error_t hashmap_data_allocate(tracker_node_t** node_pointer,tracker_node_t* hashmap_data);
error_t hashmap_print(tracker_node_t** hashmap);
error_t hashmap_builder(const message_tracker_t* array, tracker_node_t** hashmap, tracker_node_t* hashmap_data);
error_t hashmap_init(void);
error_t hashmap_delete(tracker_node_t** hashmap);
error_t hashmap_query(message_frame_t* frame, message_tracker_t const ** handler_data, tracker_node_t** hashmap);
#endif
