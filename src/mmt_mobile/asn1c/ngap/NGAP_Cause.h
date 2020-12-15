/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_Cause_H_
#define	_NGAP_Cause_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_CauseRadioNetwork.h"
#include "NGAP_CauseTransport.h"
#include "NGAP_CauseNas.h"
#include "NGAP_CauseProtocol.h"
#include "NGAP_CauseMisc.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_Cause_PR {
	NGAP_Cause_PR_NOTHING,	/* No components present */
	NGAP_Cause_PR_radioNetwork,
	NGAP_Cause_PR_transport,
	NGAP_Cause_PR_nas,
	NGAP_Cause_PR_protocol,
	NGAP_Cause_PR_misc,
	NGAP_Cause_PR_choice_Extensions
} NGAP_Cause_PR;

/* Forward declarations */
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_Cause */
typedef struct NGAP_Cause {
	NGAP_Cause_PR present;
	union NGAP_Cause_u {
		NGAP_CauseRadioNetwork_t	 radioNetwork;
		NGAP_CauseTransport_t	 transport;
		NGAP_CauseNas_t	 nas;
		NGAP_CauseProtocol_t	 protocol;
		NGAP_CauseMisc_t	 misc;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_Cause_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_Cause;
extern asn_CHOICE_specifics_t asn_SPC_NGAP_Cause_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_Cause_1[6];
extern asn_per_constraints_t asn_PER_type_NGAP_Cause_constr_1;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NGAP_ProtocolIE-SingleContainer.h"

#endif	/* _NGAP_Cause_H_ */
#include <asn_internal.h>
