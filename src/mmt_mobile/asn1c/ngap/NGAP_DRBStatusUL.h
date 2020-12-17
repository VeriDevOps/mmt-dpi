/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r15.2.0/Information-Element-Definitions.asn1"
 * 	`asn1c -D ./common -gen-PER -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-example`
 */

#ifndef	_NGAP_DRBStatusUL_H_
#define	_NGAP_DRBStatusUL_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_DRBStatusUL_PR {
	NGAP_DRBStatusUL_PR_NOTHING,	/* No components present */
	NGAP_DRBStatusUL_PR_dRBStatusUL12,
	NGAP_DRBStatusUL_PR_dRBStatusUL18,
	NGAP_DRBStatusUL_PR_choice_Extensions
} NGAP_DRBStatusUL_PR;

/* Forward declarations */
struct NGAP_DRBStatusUL12;
struct NGAP_DRBStatusUL18;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_DRBStatusUL */
typedef struct NGAP_DRBStatusUL {
	NGAP_DRBStatusUL_PR present;
	union NGAP_DRBStatusUL_u {
		struct NGAP_DRBStatusUL12	*dRBStatusUL12;
		struct NGAP_DRBStatusUL18	*dRBStatusUL18;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_DRBStatusUL_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_DRBStatusUL;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_DRBStatusUL_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_DRBStatusUL_1[3];
extern asn_per_constraints_t asn_PER_type_NGAP_DRBStatusUL_constr_1;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_DRBStatusUL_H_ */
#include <asn_internal.h>