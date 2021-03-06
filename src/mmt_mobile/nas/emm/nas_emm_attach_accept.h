/*
 * nas_emm_attach_accept.h
 *
 *  Created on: Nov 12, 2018
 *          by: Huu-Nghia
 */

#ifndef SRC_MMT_5G_NAS_EMM_NAS_EMM_ATTACH_ACCEPT_H_
#define SRC_MMT_5G_NAS_EMM_NAS_EMM_ATTACH_ACCEPT_H_

#include <stdlib.h>
#include <stdint.h>

#include "nas_emm_msg_header.h"
#include "../util/octet_string.h"
#include "../ies/tracking_area_identity_list.h"
#include "../ies/esp_mobile_identity.h"

#define NAS_EMM_ATTACH_ACCEPT_MIN_LEN 10
#define NAS_EMM_ATTACH_ACCEPT_MAX_LEN 100
typedef struct {
	/* Mandatory fields */
	nas_emm_msg_header_t               header;
	uint8_t                            eps_attach_result;
	uint8_t                            t3412value;
	nas_tracking_area_identity_list_t  tailist;
	nas_octet_string_t                 esm_message_container;
	/*optional*/
	nas_eps_mobile_identity_t          guti;
	//FURTHER: Need to examine other fields

} nas_emm_attach_accept_t;

int nas_emm_decode_attach_accept(nas_emm_attach_accept_t *attach_accept, const uint8_t *buffer, uint32_t len);



#endif /* SRC_MMT_5G_NAS_EMM_NAS_EMM_ATTACH_ACCEPT_H_ */
