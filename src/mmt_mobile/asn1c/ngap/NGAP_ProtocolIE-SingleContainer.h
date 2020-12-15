/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-Containers"
 * 	found in "./support/ngap-r16.1.0/38413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_NGAP_ProtocolIE_SingleContainer_H_
#define	_NGAP_ProtocolIE_SingleContainer_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NGAP_ProtocolIE-Field.h"

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_ProtocolIE-SingleContainer */
typedef NGAP_AMFPagingTarget_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P0_t;
typedef NGAP_BroadcastCancelledAreaList_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P1_t;
typedef NGAP_BroadcastCompletedAreaList_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P2_t;
typedef NGAP_Cause_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P3_t;
typedef NGAP_CellIDListForRestart_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P4_t;
typedef NGAP_CPTransportLayerInformation_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P5_t;
typedef NGAP_DRBStatusDL_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P6_t;
typedef NGAP_DRBStatusUL_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P7_t;
typedef NGAP_GlobalRANNodeID_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P8_t;
typedef NGAP_GNB_ID_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P9_t;
typedef NGAP_LastVisitedCellInformation_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P10_t;
typedef NGAP_N3IWF_ID_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P11_t;
typedef NGAP_NgENB_ID_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P12_t;
typedef NGAP_NGRAN_CGI_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P13_t;
typedef NGAP_OverloadResponse_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P14_t;
typedef NGAP_PWSFailedCellIDList_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P15_t;
typedef NGAP_QosCharacteristics_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P16_t;
typedef NGAP_ResetType_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P17_t;
typedef NGAP_SONInformation_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P18_t;
typedef NGAP_TargetID_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P19_t;
typedef NGAP_UEIdentityIndexValue_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P20_t;
typedef NGAP_UE_NGAP_IDs_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P21_t;
typedef NGAP_UEPagingIdentity_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P22_t;
typedef NGAP_UPTransportLayerInformation_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P23_t;
typedef NGAP_UserLocationInformation_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P24_t;
typedef NGAP_WarningAreaList_ExtIEs_t	 NGAP_ProtocolIE_SingleContainer_6979P25_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P0;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P0_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P0_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P0_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P0_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P0_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P0_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P0_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P0_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P0_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P0_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P0_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P0_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P0_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P1;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P1_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P1_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P1_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P1_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P1_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P1_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P1_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P1_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P1_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P1_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P1_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P1_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P1_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P2;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P2_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P2_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P2_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P2_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P2_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P2_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P2_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P2_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P2_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P2_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P2_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P2_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P2_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P3;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P3_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P3_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P3_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P3_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P3_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P3_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P3_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P3_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P3_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P3_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P3_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P3_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P3_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P4;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P4_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P4_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P4_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P4_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P4_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P4_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P4_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P4_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P4_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P4_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P4_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P4_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P4_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P5;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P5_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P5_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P5_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P5_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P5_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P5_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P5_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P5_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P5_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P5_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P5_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P5_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P5_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P6;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P6_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P6_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P6_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P6_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P6_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P6_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P6_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P6_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P6_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P6_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P6_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P6_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P6_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P7;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P7_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P7_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P7_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P7_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P7_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P7_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P7_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P7_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P7_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P7_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P7_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P7_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P7_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P8;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P8_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P8_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P8_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P8_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P8_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P8_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P8_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P8_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P8_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P8_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P8_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P8_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P8_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P9;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P9_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P9_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P9_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P9_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P9_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P9_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P9_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P9_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P9_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P9_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P9_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P9_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P9_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P10;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P10_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P10_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P10_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P10_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P10_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P10_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P10_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P10_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P10_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P10_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P10_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P10_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P10_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P11;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P11_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P11_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P11_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P11_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P11_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P11_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P11_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P11_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P11_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P11_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P11_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P11_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P11_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P12;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P12_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P12_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P12_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P12_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P12_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P12_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P12_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P12_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P12_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P12_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P12_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P12_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P12_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P13;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P13_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P13_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P13_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P13_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P13_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P13_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P13_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P13_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P13_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P13_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P13_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P13_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P13_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P14;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P14_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P14_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P14_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P14_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P14_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P14_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P14_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P14_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P14_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P14_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P14_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P14_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P14_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P15;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P15_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P15_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P15_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P15_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P15_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P15_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P15_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P15_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P15_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P15_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P15_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P15_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P15_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P16;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P16_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P16_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P16_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P16_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P16_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P16_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P16_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P16_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P16_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P16_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P16_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P16_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P16_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P17;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P17_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P17_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P17_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P17_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P17_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P17_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P17_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P17_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P17_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P17_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P17_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P17_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P17_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P18;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P18_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P18_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P18_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P18_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P18_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P18_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P18_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P18_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P18_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P18_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P18_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P18_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P18_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P19;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P19_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P19_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P19_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P19_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P19_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P19_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P19_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P19_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P19_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P19_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P19_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P19_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P19_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P20;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P20_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P20_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P20_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P20_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P20_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P20_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P20_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P20_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P20_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P20_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P20_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P20_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P20_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P21;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P21_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P21_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P21_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P21_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P21_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P21_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P21_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P21_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P21_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P21_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P21_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P21_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P21_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P22;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P22_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P22_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P22_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P22_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P22_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P22_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P22_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P22_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P22_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P22_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P22_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P22_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P22_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P23;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P23_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P23_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P23_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P23_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P23_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P23_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P23_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P23_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P23_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P23_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P23_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P23_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P23_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P24;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P24_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P24_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P24_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P24_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P24_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P24_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P24_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P24_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P24_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P24_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P24_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P24_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P24_encode_aper;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_ProtocolIE_SingleContainer_6979P25;
asn_struct_free_f NGAP_ProtocolIE_SingleContainer_6979P25_free;
asn_struct_print_f NGAP_ProtocolIE_SingleContainer_6979P25_print;
asn_constr_check_f NGAP_ProtocolIE_SingleContainer_6979P25_constraint;
ber_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P25_decode_ber;
der_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P25_encode_der;
xer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P25_decode_xer;
xer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P25_encode_xer;
oer_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P25_decode_oer;
oer_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P25_encode_oer;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P25_decode_uper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P25_encode_uper;
per_type_decoder_f NGAP_ProtocolIE_SingleContainer_6979P25_decode_aper;
per_type_encoder_f NGAP_ProtocolIE_SingleContainer_6979P25_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_ProtocolIE_SingleContainer_H_ */
#include <asn_internal.h>
