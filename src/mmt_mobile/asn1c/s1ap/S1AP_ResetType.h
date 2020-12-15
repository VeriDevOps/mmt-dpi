/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU-Contents"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_ResetType_H_
#define	_S1AP_ResetType_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1AP_ResetAll.h"
#include <constr_CHOICE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_ResetType_PR {
	S1AP_ResetType_PR_NOTHING,	/* No components present */
	S1AP_ResetType_PR_s1_Interface,
	S1AP_ResetType_PR_partOfS1_Interface
	/* Extensions may appear below */
	
} S1AP_ResetType_PR;

/* Forward declarations */
struct S1AP_UE_associatedLogicalS1_ConnectionListRes;

/* S1AP_ResetType */
typedef struct S1AP_ResetType {
	S1AP_ResetType_PR present;
	union S1AP_ResetType_u {
		S1AP_ResetAll_t	 s1_Interface;
		struct S1AP_UE_associatedLogicalS1_ConnectionListRes	*partOfS1_Interface;
		/*
		 * This type is extensible,
		 * possible extensions are below.
		 */
	} choice;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_ResetType_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_ResetType;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "S1AP_UE-associatedLogicalS1-ConnectionListRes.h"

#endif	/* _S1AP_ResetType_H_ */
#include <asn_internal.h>
