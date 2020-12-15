/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_PDUSessionResourceSetupItemHOReq_H_
#define	_NGAP_PDUSessionResourceSetupItemHOReq_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_PDUSessionID.h"
#include "NGAP_S-NSSAI.h"
#include <OCTET_STRING.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_PDUSessionResourceSetupItemHOReq */
typedef struct NGAP_PDUSessionResourceSetupItemHOReq {
	NGAP_PDUSessionID_t	 pDUSessionID;
	NGAP_S_NSSAI_t	 s_NSSAI;
	OCTET_STRING_t	 handoverRequestTransfer;
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_PDUSessionResourceSetupItemHOReq_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_PDUSessionResourceSetupItemHOReq;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_PDUSessionResourceSetupItemHOReq_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_PDUSessionResourceSetupItemHOReq_1[4];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NGAP_ProtocolExtensionContainer.h"

#endif	/* _NGAP_PDUSessionResourceSetupItemHOReq_H_ */
#include <asn_internal.h>
