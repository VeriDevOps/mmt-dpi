/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_DRBStatusDL_H_
#define	_NGAP_DRBStatusDL_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_DRBStatusDL_PR {
	NGAP_DRBStatusDL_PR_NOTHING,	/* No components present */
	NGAP_DRBStatusDL_PR_dRBStatusDL12,
	NGAP_DRBStatusDL_PR_dRBStatusDL18,
	NGAP_DRBStatusDL_PR_choice_Extensions
} NGAP_DRBStatusDL_PR;

/* Forward declarations */
struct NGAP_DRBStatusDL12;
struct NGAP_DRBStatusDL18;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_DRBStatusDL */
typedef struct NGAP_DRBStatusDL {
	NGAP_DRBStatusDL_PR present;
	union NGAP_DRBStatusDL_u {
		struct NGAP_DRBStatusDL12	*dRBStatusDL12;
		struct NGAP_DRBStatusDL18	*dRBStatusDL18;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_DRBStatusDL_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_DRBStatusDL;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_DRBStatusDL_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_DRBStatusDL_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_DRBStatusDL_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NGAP_DRBStatusDL12.h"
#include "NGAP_DRBStatusDL18.h"
#include "NGAP_ProtocolIE-SingleContainer.h"

#endif	/* _NGAP_DRBStatusDL_H_ */
#include <asn_internal.h>
