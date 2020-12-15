/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-CommonDataTypes"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_TriggeringMessage_H_
#define	_S1AP_TriggeringMessage_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_TriggeringMessage {
	S1AP_TriggeringMessage_initiating_message	= 0,
	S1AP_TriggeringMessage_successful_outcome	= 1,
	S1AP_TriggeringMessage_unsuccessfull_outcome	= 2
} e_S1AP_TriggeringMessage;

/* S1AP_TriggeringMessage */
typedef long	 S1AP_TriggeringMessage_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_S1AP_TriggeringMessage_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_S1AP_TriggeringMessage;
extern const asn_INTEGER_specifics_t asn_SPC_S1AP_TriggeringMessage_specs_1;
asn_struct_free_f S1AP_TriggeringMessage_free;
asn_struct_print_f S1AP_TriggeringMessage_print;
asn_constr_check_f S1AP_TriggeringMessage_constraint;
ber_type_decoder_f S1AP_TriggeringMessage_decode_ber;
der_type_encoder_f S1AP_TriggeringMessage_encode_der;
xer_type_decoder_f S1AP_TriggeringMessage_decode_xer;
xer_type_encoder_f S1AP_TriggeringMessage_encode_xer;
oer_type_decoder_f S1AP_TriggeringMessage_decode_oer;
oer_type_encoder_f S1AP_TriggeringMessage_encode_oer;
per_type_decoder_f S1AP_TriggeringMessage_decode_uper;
per_type_encoder_f S1AP_TriggeringMessage_encode_uper;
per_type_decoder_f S1AP_TriggeringMessage_decode_aper;
per_type_encoder_f S1AP_TriggeringMessage_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_TriggeringMessage_H_ */
#include <asn_internal.h>
