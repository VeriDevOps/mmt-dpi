/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-PDU"
 * 	found in "./support/s1ap-r10.5.0/S1AP-PDU.asn"
 * 	`asn1c -D ./s1ap -gen-PER -fcompound-names`
 */

#include "S1ap-E-RABReleaseIndication.h"

static int
memb_s1ap_E_RABReleaseIndication_ies_constraint_1(const asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	size_t size;
	
	if(!sptr) {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	/* Determine the number of elements */
	size = _A_CSEQUENCE_FROM_VOID(sptr)->count;
	
	if((size <= 65535)) {
		/* Perform validation of the inner elements */
		return td->encoding_constraints.general_constraints(td, sptr, ctfailcb, app_key);
	} else {
		ASN__CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_oer_constraints_t asn_OER_type_s1ap_E_RABReleaseIndication_ies_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..65535)) */};
static asn_per_constraints_t asn_PER_type_s1ap_E_RABReleaseIndication_ies_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (SIZE(0..65535)) */,
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_memb_s1ap_E_RABReleaseIndication_ies_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1	/* (SIZE(0..65535)) */};
static asn_per_constraints_t asn_PER_memb_s1ap_E_RABReleaseIndication_ies_constr_2 CC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 16,  16,  0,  65535 }	/* (SIZE(0..65535)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_s1ap_E_RABReleaseIndication_ies_2[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (16 << 2)),
		0,
		&asn_DEF_S1ap_IE,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		""
		},
};
static const ber_tlv_tag_t asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_s1ap_E_RABReleaseIndication_ies_specs_2 = {
	sizeof(struct S1ap_E_RABReleaseIndication__s1ap_E_RABReleaseIndication_ies),
	offsetof(struct S1ap_E_RABReleaseIndication__s1ap_E_RABReleaseIndication_ies, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_s1ap_E_RABReleaseIndication_ies_2 = {
	"s1ap-E-RABReleaseIndication-ies",
	"s1ap-E-RABReleaseIndication-ies",
	&asn_OP_SEQUENCE_OF,
	asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2,
	sizeof(asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2)
		/sizeof(asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2[0]) - 1, /* 1 */
	asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2,	/* Same as above */
	sizeof(asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2)
		/sizeof(asn_DEF_s1ap_E_RABReleaseIndication_ies_tags_2[0]), /* 2 */
	{ &asn_OER_type_s1ap_E_RABReleaseIndication_ies_constr_2, &asn_PER_type_s1ap_E_RABReleaseIndication_ies_constr_2, SEQUENCE_OF_constraint },
	asn_MBR_s1ap_E_RABReleaseIndication_ies_2,
	1,	/* Single element */
	&asn_SPC_s1ap_E_RABReleaseIndication_ies_specs_2	/* Additional specs */
};

static asn_TYPE_member_t asn_MBR_S1ap_E_RABReleaseIndication_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct S1ap_E_RABReleaseIndication, s1ap_E_RABReleaseIndication_ies),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		0,
		&asn_DEF_s1ap_E_RABReleaseIndication_ies_2,
		0,
		{ &asn_OER_memb_s1ap_E_RABReleaseIndication_ies_constr_2, &asn_PER_memb_s1ap_E_RABReleaseIndication_ies_constr_2,  memb_s1ap_E_RABReleaseIndication_ies_constraint_1 },
		0, 0, /* No default value */
		"s1ap-E-RABReleaseIndication-ies"
		},
};
static const ber_tlv_tag_t asn_DEF_S1ap_E_RABReleaseIndication_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_S1ap_E_RABReleaseIndication_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* s1ap-E-RABReleaseIndication-ies */
};
static asn_SEQUENCE_specifics_t asn_SPC_S1ap_E_RABReleaseIndication_specs_1 = {
	sizeof(struct S1ap_E_RABReleaseIndication),
	offsetof(struct S1ap_E_RABReleaseIndication, _asn_ctx),
	asn_MAP_S1ap_E_RABReleaseIndication_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_S1ap_E_RABReleaseIndication = {
	"S1ap-E-RABReleaseIndication",
	"S1ap-E-RABReleaseIndication",
	&asn_OP_SEQUENCE,
	asn_DEF_S1ap_E_RABReleaseIndication_tags_1,
	sizeof(asn_DEF_S1ap_E_RABReleaseIndication_tags_1)
		/sizeof(asn_DEF_S1ap_E_RABReleaseIndication_tags_1[0]), /* 1 */
	asn_DEF_S1ap_E_RABReleaseIndication_tags_1,	/* Same as above */
	sizeof(asn_DEF_S1ap_E_RABReleaseIndication_tags_1)
		/sizeof(asn_DEF_S1ap_E_RABReleaseIndication_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_S1ap_E_RABReleaseIndication_1,
	1,	/* Elements count */
	&asn_SPC_S1ap_E_RABReleaseIndication_specs_1	/* Additional specs */
};

