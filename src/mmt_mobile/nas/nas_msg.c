/*
 * nas_msg.c
 *
 *  Created on: Nov 7, 2018
 *          by: Huu-Nghia
 */


#include "nas_msg.h"
#include "util/decoder.h"


static inline int _nas_msg_plain_decode(
		const uint8_t                   *buffer,
		nas_msg_plain_t                 *msg,
		int                             length)
{
	int size = 0, byte = 0;
	DECODE_U8( buffer, *(uint8_t *)& msg->emm.header, size );

	switch ( msg->emm.header.protocol_discriminator ){
	case NAS_EPS_MOBILITY_MANAGEMENT_MESSAGE:
		DECODE_U8( buffer+size, msg->emm.header.message_type, size );

		/* Decode EPS Mobility Management L3 message */
		byte = nas_emm_decode_msg(&msg->emm, buffer + size, length - size);
		break;
	case NAS_EPS_SESSION_MANAGEMENT_MESSAGE:

		DECODE_U8( buffer+size, msg->esm.header.procedure_transaction_identity, size );
		DECODE_U8( buffer+size, msg->esm.header.message_type, size );

		/* Decode EPS Session Management L3 message */
		byte = nas_esm_decode_msg(&msg->esm, buffer+size, length - size);
		break;
	default:
		LOG("Unknown protocol discriminator %d", msg->emm.header.protocol_discriminator );
		return DECODE_PROTOCOL_NOT_SUPPORTED;
	}

	if( byte < 0 )
		return byte;
	return (size + byte );
}

/**
 * Decrypt security-protected NAS message
 */
static inline const uint8_t* _nas_msg_decrypt(
		const uint8_t      *src,
		uint8_t             security_header_type,
		uint32_t            code,
		uint8_t             seq,
		int                 length
		//  const emm_security_context_t * const emm_security_context
)
{
	const uint8_t *dest = NULL;
	int size = 0;
	switch (security_header_type) {
	case NAS_SECURITY_HEADER_TYPE_NOT_PROTECTED:
	case NAS_SECURITY_HEADER_TYPE_SERVICE_REQUEST:
	case NAS_SECURITY_HEADER_TYPE_INTEGRITY_PROTECTED:
	case NAS_SECURITY_HEADER_TYPE_INTEGRITY_PROTECTED_NEW:
		dest = src;
		break;

	case NAS_SECURITY_HEADER_TYPE_INTEGRITY_PROTECTED_CYPHERED:
	case NAS_SECURITY_HEADER_TYPE_INTEGRITY_PROTECTED_CYPHERED_NEW:
		//TODO: decrypt
		dest = src;
		break;
	default:
		LOG("Unknown security header type %u", security_header_type);
		return (0);
	};

	return dest;

}

/**
 * Decode security-protected NAS message.
 *
 * @inputs:
 *
 * @outputs:
 * - msg: Decoded NAS message
 *
 * @return:
 * - A positive number of bytes in the buffer if the data have been successfully decoded
 * - A negative number representing error code, otherwise.
 */
static inline int _nas_msg_protected_decode(
		const uint8_t                 *buffer,
		nas_msg_security_protected_t  *msg,
		int                            length
		//  const emm_security_context_t * const emm_security_context
)
{
	//ensure buffer is big enough to contain nas_msg_security_header_t
	CHECK_PDU_POINTER_AND_LENGTH_DECODER( buffer, NAS_MESSAGE_SECURITY_HEADER_SIZE, length );

	int size = 0;
	int bytes = DECODE_BUFFER_TOO_SHORT;

	//decode security-protected header
	nas_msg_security_header_t *header = &msg->header;
	/* Decode the first octet of the header (security header type or EPS bearer
	 * identity, and protocol discriminator) */
	DECODE_U8(buffer, *(uint8_t*)(header), size);
	 /* Decode the message authentication code */
	DECODE_U32(buffer+size, header->message_authentication_code, size);
	/* Decode the sequence number */
	DECODE_U8(buffer+size, header->sequence_number, size);


	/* Decrypt the security protected NAS message */
	 const uint8_t* plain_msg = _nas_msg_decrypt(
					buffer + size,
					header->security_header_type,
					header->message_authentication_code,
					header->sequence_number,
					length - size );

	 if( unlikely( plain_msg == NULL ))
		 return DECODE_MAC_MISMATCH;

	/* Decode the decrypted message as plain NAS message */
	bytes = _nas_msg_plain_decode(plain_msg, &msg->msg, length - size);

	//in case of error
	if (bytes < 0)
		return (bytes);

	return (size + bytes);
}

int nas_decode( nas_msg_t *msg, const uint8_t *buffer, int length ){
	/* Decode the header */

	CHECK_PDU_POINTER_AND_LENGTH_DECODER( buffer, 3, length );

	//1. if the message is security-protected?
	nas_msg_header_t *header = &msg->header;

	/* Decode the first octet of the header (security header type or EPS bearer
	 * identity, and protocol discriminator) */
	*(uint8_t*)(header) = *buffer;

	/*
	 * EMM Service Request message is an exception that breaks the normal rules
	 * since it has been tweaked to fit into a single initial RRC message
	 * and hence optimizing the performance of the system.
	 */

	if( header->security_header_type == NAS_SECURITY_HEADER_TYPE_SERVICE_REQUEST ){
		return 0;
	}
	else if ( nas_is_security_protected_msg( msg )){
		//we are going to decode security-protected NAS message
		return _nas_msg_protected_decode(buffer,
				&msg->protected_msg,
				length
				//, emm_security_context
		);
	}
	else{

		/* Decode plain NAS message */
		return _nas_msg_plain_decode(buffer,
				&msg->plain_msg,
				length);
	}
}
