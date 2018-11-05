/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "../asn1_R10.5/S1AP-IEs.asn"
 * 	`asn1c -gen-PER`
 */

#ifndef	_S1ap_UE_associatedLogicalS1_ConnectionItem_H_
#define	_S1ap_UE_associatedLogicalS1_ConnectionItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1ap-MME-UE-S1AP-ID.h"
#include "S1ap-ENB-UE-S1AP-ID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1ap_IE_Extensions;

/* S1ap-UE-associatedLogicalS1-ConnectionItem */
typedef struct S1ap_UE_associatedLogicalS1_ConnectionItem {
	S1ap_MME_UE_S1AP_ID_t	*mME_UE_S1AP_ID	/* OPTIONAL */;
	S1ap_ENB_UE_S1AP_ID_t	*eNB_UE_S1AP_ID	/* OPTIONAL */;
	struct S1ap_IE_Extensions	*iE_Extensions	/* OPTIONAL */;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1ap_UE_associatedLogicalS1_ConnectionItem_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1ap_UE_associatedLogicalS1_ConnectionItem;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "S1ap-IE-Extensions.h"

#endif	/* _S1ap_UE_associatedLogicalS1_ConnectionItem_H_ */
#include <asn_internal.h>
