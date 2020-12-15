/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#include "NGAP_HandoverResourceAllocationUnsuccessfulTransfer.h"

static asn_TYPE_member_t asn_MBR_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct NGAP_HandoverResourceAllocationUnsuccessfulTransfer, cause),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_NGAP_Cause,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cause"
		},
	{ ATF_POINTER, 2, offsetof(struct NGAP_HandoverResourceAllocationUnsuccessfulTransfer, criticalityDiagnostics),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_CriticalityDiagnostics,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"criticalityDiagnostics"
		},
	{ ATF_POINTER, 1, offsetof(struct NGAP_HandoverResourceAllocationUnsuccessfulTransfer, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NGAP_ProtocolExtensionContainer_7027P70,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_oms_1[] = { 1, 2 };
static const ber_tlv_tag_t asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* cause */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* criticalityDiagnostics */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_specs_1 = {
	sizeof(struct NGAP_HandoverResourceAllocationUnsuccessfulTransfer),
	offsetof(struct NGAP_HandoverResourceAllocationUnsuccessfulTransfer, _asn_ctx),
	asn_MAP_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tag2el_1,
	3,	/* Count of tags in the map */
	asn_MAP_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	3,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer = {
	"HandoverResourceAllocationUnsuccessfulTransfer",
	"HandoverResourceAllocationUnsuccessfulTransfer",
	&asn_OP_SEQUENCE,
	asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1,
	sizeof(asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1)
		/sizeof(asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1[0]), /* 1 */
	asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1,	/* Same as above */
	sizeof(asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1)
		/sizeof(asn_DEF_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_1,
	3,	/* Elements count */
	&asn_SPC_NGAP_HandoverResourceAllocationUnsuccessfulTransfer_specs_1	/* Additional specs */
};

