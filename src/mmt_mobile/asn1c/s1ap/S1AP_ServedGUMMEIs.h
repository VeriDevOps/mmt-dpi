/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_ServedGUMMEIs_H_
#define	_S1AP_ServedGUMMEIs_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1AP_ServedGUMMEIsItem;

/* S1AP_ServedGUMMEIs */
typedef struct S1AP_ServedGUMMEIs {
	A_SEQUENCE_OF(struct S1AP_ServedGUMMEIsItem) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_ServedGUMMEIs_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_ServedGUMMEIs;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "S1AP_ServedGUMMEIsItem.h"

#endif	/* _S1AP_ServedGUMMEIs_H_ */
#include <asn_internal.h>
