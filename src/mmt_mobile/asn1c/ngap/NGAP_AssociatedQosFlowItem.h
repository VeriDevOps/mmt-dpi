/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_AssociatedQosFlowItem_H_
#define	_NGAP_AssociatedQosFlowItem_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_QosFlowIdentifier.h"
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum NGAP_AssociatedQosFlowItem__qosFlowMappingIndication {
	NGAP_AssociatedQosFlowItem__qosFlowMappingIndication_ul	= 0,
	NGAP_AssociatedQosFlowItem__qosFlowMappingIndication_dl	= 1
	/*
	 * Enumeration is extensible
	 */
} e_NGAP_AssociatedQosFlowItem__qosFlowMappingIndication;

/* Forward declarations */
struct NGAP_ProtocolExtensionContainer;

/* NGAP_AssociatedQosFlowItem */
typedef struct NGAP_AssociatedQosFlowItem {
	NGAP_QosFlowIdentifier_t	 qosFlowIdentifier;
	long	*qosFlowMappingIndication;	/* OPTIONAL */
	struct NGAP_ProtocolExtensionContainer	*iE_Extensions;	/* OPTIONAL */
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} NGAP_AssociatedQosFlowItem_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_NGAP_qosFlowMappingIndication_3;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_AssociatedQosFlowItem;
extern asn_SEQUENCE_specifics_t asn_SPC_NGAP_AssociatedQosFlowItem_specs_1;
extern asn_TYPE_member_t asn_MBR_NGAP_AssociatedQosFlowItem_1[3];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "NGAP_ProtocolExtensionContainer.h"

#endif	/* _NGAP_AssociatedQosFlowItem_H_ */
#include <asn_internal.h>
