/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "S1AP-IEs"
 * 	found in "./support/s1ap-r16.1.0/36413-g10.asn"
 * 	`asn1c -D ./common -pdu=all -fcompound-names -findirect-choice -no-gen-example`
 */

#ifndef	_S1AP_NB_IoT_PagingTimeWindow_H_
#define	_S1AP_NB_IoT_PagingTimeWindow_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum S1AP_NB_IoT_PagingTimeWindow {
	S1AP_NB_IoT_PagingTimeWindow_s1	= 0,
	S1AP_NB_IoT_PagingTimeWindow_s2	= 1,
	S1AP_NB_IoT_PagingTimeWindow_s3	= 2,
	S1AP_NB_IoT_PagingTimeWindow_s4	= 3,
	S1AP_NB_IoT_PagingTimeWindow_s5	= 4,
	S1AP_NB_IoT_PagingTimeWindow_s6	= 5,
	S1AP_NB_IoT_PagingTimeWindow_s7	= 6,
	S1AP_NB_IoT_PagingTimeWindow_s8	= 7,
	S1AP_NB_IoT_PagingTimeWindow_s9	= 8,
	S1AP_NB_IoT_PagingTimeWindow_s10	= 9,
	S1AP_NB_IoT_PagingTimeWindow_s11	= 10,
	S1AP_NB_IoT_PagingTimeWindow_s12	= 11,
	S1AP_NB_IoT_PagingTimeWindow_s13	= 12,
	S1AP_NB_IoT_PagingTimeWindow_s14	= 13,
	S1AP_NB_IoT_PagingTimeWindow_s15	= 14,
	S1AP_NB_IoT_PagingTimeWindow_s16	= 15
	/*
	 * Enumeration is extensible
	 */
} e_S1AP_NB_IoT_PagingTimeWindow;

/* S1AP_NB-IoT-PagingTimeWindow */
typedef long	 S1AP_NB_IoT_PagingTimeWindow_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_S1AP_NB_IoT_PagingTimeWindow_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_S1AP_NB_IoT_PagingTimeWindow;
extern const asn_INTEGER_specifics_t asn_SPC_S1AP_NB_IoT_PagingTimeWindow_specs_1;
asn_struct_free_f S1AP_NB_IoT_PagingTimeWindow_free;
asn_struct_print_f S1AP_NB_IoT_PagingTimeWindow_print;
asn_constr_check_f S1AP_NB_IoT_PagingTimeWindow_constraint;
ber_type_decoder_f S1AP_NB_IoT_PagingTimeWindow_decode_ber;
der_type_encoder_f S1AP_NB_IoT_PagingTimeWindow_encode_der;
xer_type_decoder_f S1AP_NB_IoT_PagingTimeWindow_decode_xer;
xer_type_encoder_f S1AP_NB_IoT_PagingTimeWindow_encode_xer;
oer_type_decoder_f S1AP_NB_IoT_PagingTimeWindow_decode_oer;
oer_type_encoder_f S1AP_NB_IoT_PagingTimeWindow_encode_oer;
per_type_decoder_f S1AP_NB_IoT_PagingTimeWindow_decode_uper;
per_type_encoder_f S1AP_NB_IoT_PagingTimeWindow_encode_uper;
per_type_decoder_f S1AP_NB_IoT_PagingTimeWindow_decode_aper;
per_type_encoder_f S1AP_NB_IoT_PagingTimeWindow_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _S1AP_NB_IoT_PagingTimeWindow_H_ */
#include <asn_internal.h>
