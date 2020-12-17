/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r15.2.0/Information-Element-Definitions.asn1"
 * 	`asn1c -D ./common -gen-PER -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-example`
 */

#ifndef	_NGAP_EmergencyAreaIDListForRestart_H_
#define	_NGAP_EmergencyAreaIDListForRestart_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_EmergencyAreaID.h"
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_EmergencyAreaIDListForRestart */
typedef struct NGAP_EmergencyAreaIDListForRestart {
	A_SEQUENCE_OF(NGAP_EmergencyAreaID_t) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_EmergencyAreaIDListForRestart_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_EmergencyAreaIDListForRestart;
extern asn_SET_OF_specifics_t asn_SPC_NGAP_EmergencyAreaIDListForRestart_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_EmergencyAreaIDListForRestart_1[1];
extern asn_per_constraints_t asn_PER_type_NGAP_EmergencyAreaIDListForRestart_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_EmergencyAreaIDListForRestart_H_ */
#include <asn_internal.h>