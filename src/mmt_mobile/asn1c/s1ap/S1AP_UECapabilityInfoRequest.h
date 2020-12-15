/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_UECapabilityInfoRequest_H_
#define	_S1AP_UECapabilityInfoRequest_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_UECapabilityInfoRequest {
	S1AP_UECapabilityInfoRequest_requested	= 0
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_UECapabilityInfoRequest;

/* S1AP_UECapabilityInfoRequest */
typedef long	 S1AP_UECapabilityInfoRequest_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_S1AP_UECapabilityInfoRequest;
asn_struct_free_f S1AP_UECapabilityInfoRequest_free;
asn_struct_print_f S1AP_UECapabilityInfoRequest_print;
asn_constr_check_f S1AP_UECapabilityInfoRequest_constraint;
ber_type_decoder_f S1AP_UECapabilityInfoRequest_decode_ber;
der_type_encoder_f S1AP_UECapabilityInfoRequest_encode_der;
xer_type_decoder_f S1AP_UECapabilityInfoRequest_decode_xer;
xer_type_encoder_f S1AP_UECapabilityInfoRequest_encode_xer;
oer_type_decoder_f S1AP_UECapabilityInfoRequest_decode_oer;
oer_type_encoder_f S1AP_UECapabilityInfoRequest_encode_oer;
per_type_decoder_f S1AP_UECapabilityInfoRequest_decode_uper;
per_type_encoder_f S1AP_UECapabilityInfoRequest_encode_uper;
per_type_decoder_f S1AP_UECapabilityInfoRequest_decode_aper;
per_type_encoder_f S1AP_UECapabilityInfoRequest_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_UECapabilityInfoRequest_H_ */
#include <asn_internal.h>
