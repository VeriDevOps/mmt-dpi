/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_Cdma2000OneXSRVCCInfo_H_
#define	_S1AP_Cdma2000OneXSRVCCInfo_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1AP_Cdma2000OneXMEID.h"
#include "S1AP_Cdma2000OneXMSI.h"
#include "S1AP_Cdma2000OneXPilot.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct S1AP_ProtocolExtensionContainer;

/* S1AP_Cdma2000OneXSRVCCInfo */
typedef struct S1AP_Cdma2000OneXSRVCCInfo {
	S1AP_Cdma2000OneXMEID_t	 cdma2000OneXMEID;
	S1AP_Cdma2000OneXMSI_t	 cdma2000OneXMSI;
	S1AP_Cdma2000OneXPilot_t	 cdma2000OneXPilot;
	struct S1AP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_Cdma2000OneXSRVCCInfo_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_Cdma2000OneXSRVCCInfo;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "S1AP_ProtocolExtensionContainer.h"

#endif	/* _S1AP_Cdma2000OneXSRVCCInfo_H_ */
#include <asn_internal.h>
