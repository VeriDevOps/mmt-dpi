/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#include "S1AP_MeasurementThresholdA2.h"

static asn_oer_constraints_t asn_OER_type_S1AP_MeasurementThresholdA2_constr_1 CC_NOTUSED = {
	{ 0, 0 },
	-1};
asn_per_constraints_t asn_PER_type_S1AP_MeasurementThresholdA2_constr_1 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  1,  1,  0,  1 }	/* (0..1,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
asn_TYPE_member_t asn_MBR_S1AP_MeasurementThresholdA2_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_MeasurementThresholdA2, choice.threshold_RSRP),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_Threshold_RSRP,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"threshold-RSRP"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct S1AP_MeasurementThresholdA2, choice.threshold_RSRQ),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_S1AP_Threshold_RSRQ,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"threshold-RSRQ"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_S1AP_MeasurementThresholdA2_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* threshold-RSRP */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* threshold-RSRQ */
};
asn_CHOICE_specifics_t asn_SPC_S1AP_MeasurementThresholdA2_specs_1 = {
	sizeof(struct S1AP_MeasurementThresholdA2),
	offsetof(struct S1AP_MeasurementThresholdA2, _asn_ctx),
	offsetof(struct S1AP_MeasurementThresholdA2, present),
	sizeof(((struct S1AP_MeasurementThresholdA2 *)0)->present),
	asn_MAP_S1AP_MeasurementThresholdA2_tag2el_1,
	2,	/* Count of tags in the map */
	0, 0,
	2	/* Extensions start */
};
asn_TYPE_descriptor_t asn_DEF_S1AP_MeasurementThresholdA2 = {
	"MeasurementThresholdA2",
	"MeasurementThresholdA2",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_S1AP_MeasurementThresholdA2_constr_1, &asn_PER_type_S1AP_MeasurementThresholdA2_constr_1, CHOICE_constraint },
	asn_MBR_S1AP_MeasurementThresholdA2_1,
	2,	/* Elements count */
	&asn_SPC_S1AP_MeasurementThresholdA2_specs_1	/* Additional specs */
};

