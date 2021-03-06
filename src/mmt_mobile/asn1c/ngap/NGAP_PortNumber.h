/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NGAP-IEs"
 * 	found in "./support/ngap-r15.2.0/Information-Element-Definitions.asn1"
 * 	`asn1c -D ./common -gen-PER -pdu=all -fcompound-names -findirect-choice -fno-include-deps -no-gen-example`
 */

#ifndef	_NGAP_PortNumber_H_
#define	_NGAP_PortNumber_H_


#include <asn_application.h>

/* Including external dependencies */
#include <OCTET_STRING.h>

#ifdef __cplusplus
extern "C" {
#endif

/* NGAP_PortNumber */
typedef OCTET_STRING_t	 NGAP_PortNumber_t;

/* Implementation */
extern asn_per_constraints_t asn_PER_type_NGAP_PortNumber_constr_1;
extern asn_TYPE_descriptor_t asn_DEF_NGAP_PortNumber;
asn_struct_free_f NGAP_PortNumber_free;
asn_struct_print_f NGAP_PortNumber_print;
asn_constr_check_f NGAP_PortNumber_constraint;
ber_type_decoder_f NGAP_PortNumber_decode_ber;
der_type_encoder_f NGAP_PortNumber_encode_der;
xer_type_decoder_f NGAP_PortNumber_decode_xer;
xer_type_encoder_f NGAP_PortNumber_encode_xer;
oer_type_decoder_f NGAP_PortNumber_decode_oer;
oer_type_encoder_f NGAP_PortNumber_encode_oer;
per_type_decoder_f NGAP_PortNumber_decode_uper;
per_type_encoder_f NGAP_PortNumber_encode_uper;
per_type_decoder_f NGAP_PortNumber_decode_aper;
per_type_encoder_f NGAP_PortNumber_encode_aper;

#ifdef __cplusplus
}
#endif

#endif	/* _NGAP_PortNumber_H_ */
#include <asn_internal.h>
