/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_UEPagingIdentity_H_
#define	_NGAP_UEPagingIdentity_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_UEPagingIdentity_PR {
	NGAP_UEPagingIdentity_PR_NOTHING,	/* No components present */
	NGAP_UEPagingIdentity_PR_fiveG_S_TMSI,
	NGAP_UEPagingIdentity_PR_choice_Extensions
} NGAP_UEPagingIdentity_PR;

/* Forward declarations */
struct NGAP_FiveG_S_TMSI;
struct NGAP_ProtocolIE_SingleContainer;

/* NGAP_UEPagingIdentity */
typedef struct NGAP_UEPagingIdentity {
	NGAP_UEPagingIdentity_PR present;
	union NGAP_UEPagingIdentity_u {
		struct NGAP_FiveG_S_TMSI	*fiveG_S_TMSI;
		struct NGAP_ProtocolIE_SingleContainer	*choice_Extensions;
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_UEPagingIdentity_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_UEPagingIdentity;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NGAP_FiveG-S-TMSI.h"
#include "NGAP_ProtocolIE-SingleContainer.h"

#endif	/* _NGAP_UEPagingIdentity_H_ */
#include <asn_internal.h>
