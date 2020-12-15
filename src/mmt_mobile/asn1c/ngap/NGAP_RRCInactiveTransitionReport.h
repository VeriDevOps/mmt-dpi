/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-PDU-Contents"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_RRCInactiveTransitionReport_H_
#define	_NGAP_RRCInactiveTransitionReport_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_RRCInactiveTransitionReport */
typedef struct NGAP_RRCInactiveTransitionReport {
	NGAP_ProtocolIE_Container_6976P18_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_RRCInactiveTransitionReport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_RRCInactiveTransitionReport;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_RRCInactiveTransitionReport_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_RRCInactiveTransitionReport_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_RRCInactiveTransitionReport_H_ */
#include <asn_internal.h>
