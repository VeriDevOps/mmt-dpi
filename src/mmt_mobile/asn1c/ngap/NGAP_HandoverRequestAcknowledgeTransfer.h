/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r15.2.0/Information-Element-Definitions.asn1"
 * 	`asn1c -D ./common -gen-PER -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-example`
 */

#ifndef	_NGAP_HandoverRequestAcknowledgeTransfer_H_
#define	_NGAP_HandoverRequestAcknowledgeTransfer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_UPTransportLayerInformation.h"
#include "NGAP_QosFlowSetupResponseListHOReqAck.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct NGAP_UPTransportLayerInformation;
struct NGAP_SecurityResult;
struct NGAP_QosFlowList;
struct NGAP_DataForwardingResponseDRBList;
struct NGAP_ProtocolExtensionContainer;

/* NGAP_HandoverRequestAcknowledgeTransfer */
typedef struct NGAP_HandoverRequestAcknowledgeTransfer {
	NGAP_UPTransportLayerInformation_t	 dL_NGU_UP_TNLInformation;
	struct NGAP_UPTransportLayerInformation	*dLForwardingUP_TNLInformation;	/* OPTIONAL */
	struct NGAP_SecurityResult	*securityResult;	/* OPTIONAL */
	NGAP_QosFlowSetupResponseListHOReqAck_t	 qosFlowSetupResponseList;
	struct NGAP_QosFlowList	*qosFlowFailedToSetupList;	/* OPTIONAL */
	struct NGAP_DataForwardingResponseDRBList	*dataForwardingResponseDRBList;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_HandoverRequestAcknowledgeTransfer_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_HandoverRequestAcknowledgeTransfer;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_HandoverRequestAcknowledgeTransfer_H_ */
#include <asn_internal.h>
