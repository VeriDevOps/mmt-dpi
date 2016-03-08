#include "mmt_core.h"
#include "plugin_defs.h"
#include "extraction_lib.h"
#include "../mmt_common_internal_include.h"

/**
 * Was generated automatically by MMTCrawler on 08/03/2016
 * Author @luongnv89  
 *
 */

/////////////// PROTOCOL INTERNAL CODE GOES HERE ///////////////////

/////////////// END OF PROTOCOL INTERNAL CODE    ///////////////////

int init_proto_windream_struct() {
	 protocol_t * protocol_struct = init_protocol_struct_for_registration(PROTO_WINDREAM, PROTO_WINDREAM_ALIAS);
	 if (protocol_struct != NULL) {  
		 return register_protocol(protocol_struct, PROTO_WINDREAM);
	 } else {  
		 return 0;  
	 }  
}

