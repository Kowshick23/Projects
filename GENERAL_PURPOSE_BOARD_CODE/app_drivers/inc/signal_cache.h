
#ifndef INCLUDE_SIGNAL_CACHE_H_
#define INCLUDE_SIGNAL_CACHE_H_

#include "../../app_drivers/inc/message_support.h"

#define SIGNAL_CACHE_SIZE	(5)

/* unique signal attributes stored in cache, access with pointers in dbc.h, dbl.h */ 
static signal_attribute_cache_t signal_attribute_cache[SIGNAL_CACHE_SIZE]=
{
	{12,0,1.0,0.0,0.0,4095.0,Unsigned,Intel},	/* 0 */
	{16,0,0.01,0.0,-327.68,327.67,Signed_float,Intel},	/* 1 */
	{16,0,0.0001,0.0,-3.2768,3.2767,Signed_float,Intel},	/* 2 */
	{1,0,1.0,0.0,0.0,1.0,Unsigned,Intel},	/* 3 */
	{8,0,1.0,0.0,0.0,255.0,Unsigned,Intel},	/* 4 */
};

#endif
