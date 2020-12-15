/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#include "S1AP_TAIBasedQMC.h"

asn_TYPE_member_t asn_MBR_S1AP_TAIBasedQMC_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_TAIBasedQMC, tAIListforQMC),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_TAIListforQMC,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"tAIListforQMC"
		},
	{ ATF_POINTER, 1, offsetof(struct S1AP_TAIBasedQMC, iE_Extensions),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_ProtocolExtensionContainer_7378P123,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"iE-Extensions"
		},
};
static const int asn_MAP_S1AP_TAIBasedQMC_oms_1[] = { 1 };
static const ber_tlv_tag_t asn_DEF_S1AP_TAIBasedQMC_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_S1AP_TAIBasedQMC_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* tAIListforQMC */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* iE-Extensions */
};
asn_SEQUENCE_specifics_t asn_SPC_S1AP_TAIBasedQMC_specs_1 = {
	sizeof(struct S1AP_TAIBasedQMC),
	offsetof(struct S1AP_TAIBasedQMC, _asn_ctx),
	asn_MAP_S1AP_TAIBasedQMC_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_S1AP_TAIBasedQMC_oms_1,	/* Optional members */
	1, 0,	/* Root/Additions */
	2,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_S1AP_TAIBasedQMC = {
	"TAIBasedQMC",
	"TAIBasedQMC",
	&asn_OP_SEQUENCE,
	asn_DEF_S1AP_TAIBasedQMC_tags_1,
	sizeof(asn_DEF_S1AP_TAIBasedQMC_tags_1)
		/sizeof(asn_DEF_S1AP_TAIBasedQMC_tags_1[0]), /* 1 */
	asn_DEF_S1AP_TAIBasedQMC_tags_1,	/* Same as above */
	sizeof(asn_DEF_S1AP_TAIBasedQMC_tags_1)
		/sizeof(asn_DEF_S1AP_TAIBasedQMC_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_S1AP_TAIBasedQMC_1,
	2,	/* Elements count */
	&asn_SPC_S1AP_TAIBasedQMC_specs_1	/* Additional specs */
};

