/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU-Contents"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_DownlinkNonUEAssociatedLPPaTransport_H_
#define	_S1AP_DownlinkNonUEAssociatedLPPaTransport_H_


#include <asn_application.h>

/* Including external dependencies */
#include "S1AP_ProtocolIE-Container.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* S1AP_DownlinkNonUEAssociatedLPPaTransport */
typedef struct S1AP_DownlinkNonUEAssociatedLPPaTransport {
	S1AP_ProtocolIE_Container_7327P75_t	 protocolIEs;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} S1AP_DownlinkNonUEAssociatedLPPaTransport_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_DownlinkNonUEAssociatedLPPaTransport;
extern asn_SEQUENCE_specifics_t asn_SPC_S1AP_DownlinkNonUEAssociatedLPPaTransport_specs_1;
extern asn_TYPE_member_t asn_MBR_S1AP_DownlinkNonUEAssociatedLPPaTransport_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_DownlinkNonUEAssociatedLPPaTransport_H_ */
#include <asn_internal.h>
