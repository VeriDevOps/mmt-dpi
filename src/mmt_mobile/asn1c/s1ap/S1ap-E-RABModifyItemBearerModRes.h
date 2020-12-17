/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r10.5.0/S1AP-IEs.asn"
 * 	`asn1c -D ./s1ap -gen-PER -fcompound-names`
 */

#ifndef	_S1ap_E_RABModifyItemBearerModRes_H_
#define	_S1ap_E_RABModifyItemBearerModRes_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1ap-E-RAB-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1ap_IE_Extensions;

/* S1ap-E-RABModifyItemBearerModRes */
typedef struct S1ap_E_RABModifyItemBearerModRes {
	S1ap_E_RAB_ID_t	 e_RAB_ID;
	struct S1ap_IE_Extensions	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1ap_E_RABModifyItemBearerModRes_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1ap_E_RABModifyItemBearerModRes;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "S1ap-IE-Extensions.h"

#endif	/* _S1ap_E_RABModifyItemBearerModRes_H_ */
#include <asn_internal.h>
