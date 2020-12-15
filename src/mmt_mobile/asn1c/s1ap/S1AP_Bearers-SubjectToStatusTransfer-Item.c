/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#include "S1AP_Bearers-SubjectToStatusTransfer-Item.h"

static asn_TYPE_member_t asn_MBR_S1AP_Bearers_SubjectToStatusTransfer_Item_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_Bearers_SubjectToStatusTransfer_Item, e_RAB_ID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_E_RAB_ID,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"e-RAB-ID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_Bearers_SubjectToStatusTransfer_Item, uL_COUNTvalue),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_COUNTvalue,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"uL-COUNTvalue"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_Bearers_SubjectToStatusTransfer_Item, dL_COUNTvalue),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_COUNTvalue,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"dL-COUNTvalue"
		},
	{ ATF_POINTER, 2, offsetof(struct S1AP_Bearers_SubjectToStatusTransfer_Item, receiveStatusofULPDCPSDUs),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_ReceiveStatusofULPDCPSDUs,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"receiveStatusofULPDCPSDUs"
		},
	{ ATF_POINTER, 1, offsetof(struct S1AP_Bearers_SubjectToStatusTransfer_Item, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_ProtocolExtensionContainer_7378P25,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_S1AP_Bearers_SubjectToStatusTransfer_Item_oms_1[] = { 3, 4 };
static const ber_tlv_tag_t asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_S1AP_Bearers_SubjectToStatusTransfer_Item_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* e-RAB-ID */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* uL-COUNTvalue */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dL-COUNTvalue */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* receiveStatusofULPDCPSDUs */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* iE-Extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_S1AP_Bearers_SubjectToStatusTransfer_Item_specs_1 = {
	sizeof(struct S1AP_Bearers_SubjectToStatusTransfer_Item),
	offsetof(struct S1AP_Bearers_SubjectToStatusTransfer_Item, _asn_ctx),
	asn_MAP_S1AP_Bearers_SubjectToStatusTransfer_Item_tag2el_1,
	5,	/* Count of tags in the map */
	asn_MAP_S1AP_Bearers_SubjectToStatusTransfer_Item_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	5,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item = {
	"Bearers-SubjectToStatusTransfer-Item",
	"Bearers-SubjectToStatusTransfer-Item",
	&asn_OP_SEQUENCE,
	asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1,
	sizeof(asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1)
		/sizeof(asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1[0]), /* 1 */
	asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1,	/* Same as above */
	sizeof(asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1)
		/sizeof(asn_DEF_S1AP_Bearers_SubjectToStatusTransfer_Item_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_S1AP_Bearers_SubjectToStatusTransfer_Item_1,
	5,	/* Elements count */
	&asn_SPC_S1AP_Bearers_SubjectToStatusTransfer_Item_specs_1	/* Additional specs */
};

