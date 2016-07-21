#include "mmt_core.h"
#include "plugin_defs.h"
#include "extraction_lib.h"
#include "../mmt_common_internal_include.h"


/////////////// PROTOCOL INTERNAL CODE GOES HERE ///////////////////
static MMT_PROTOCOL_BITMASK detection_bitmask;
static MMT_PROTOCOL_BITMASK excluded_protocol_bitmask;
static MMT_SELECTION_BITMASK_PROTOCOL_SIZE selection_bitmask;

static void mmt_int_pando_add_connection(ipacket_t * ipacket)
{
	mmt_internal_add_connection(ipacket, PROTO_PANDO, MMT_REAL_PROTOCOL);
}

static uint8_t search_pando(ipacket_t * ipacket)
{
  struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;

	if (packet->tcp != NULL) {

		if (packet->payload_packet_len == 63 && memcmp(&packet->payload[1], "Pando protocol", 14) == 0) {
			MMT_LOG(PROTO_PANDO, MMT_LOG_DEBUG, "Pando download detected\n");
			goto end_pando_found;
		}

	} else if (packet->udp != NULL) {
		if (packet->payload_packet_len > 20
			&& packet->payload_packet_len < 100
			&& packet->payload[0] == 0x00
			&& packet->payload[1] == 0x00
			&& packet->payload[2] == 0x00
			&& packet->payload[3] == 0x09 && packet->payload[4] == 0x00 && packet->payload[5] == 0x00) {
			// bypass the detection because one packet has at a specific place the word Pando in it
			if (packet->payload_packet_len == 87 && memcmp(&packet->payload[25], "Pando protocol", 14) == 0) {
				MMT_LOG(PROTO_PANDO, MMT_LOG_DEBUG,
						"Pando UDP packet detected --> Pando in payload\n");
				goto end_pando_found;
			} else if (packet->payload_packet_len == 92 && memcmp(&packet->payload[72], "Pando", 5) == 0) {
				MMT_LOG(PROTO_PANDO, MMT_LOG_DEBUG,
						"Pando UDP packet detected --> Pando in payload\n");
				goto end_pando_found;
			}
			goto end_pando_maybe_found;
		}
	}

	goto end_pando_nothing_found;

  end_pando_found:
	mmt_int_pando_add_connection(ipacket);
	return 1;

  end_pando_maybe_found:
	return 2;

  end_pando_nothing_found:
	return 0;
}

void mmt_classify_me_pando(ipacket_t * ipacket, unsigned index) {
  struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
  struct mmt_internal_tcpip_session_struct *flow = packet->flow;

	if (search_pando(ipacket) != 0)
		return;

	MMT_ADD_PROTOCOL_TO_BITMASK(flow->excluded_protocol_bitmask, PROTO_PANDO);

}

int mmt_check_pando(ipacket_t * ipacket, unsigned index) {
    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    if ((selection_bitmask & packet->mmt_selection_packet) == selection_bitmask
            && MMT_BITMASK_COMPARE(excluded_protocol_bitmask, packet->flow->excluded_protocol_bitmask) == 0
            && MMT_BITMASK_COMPARE(detection_bitmask, packet->detection_bitmask) != 0) {

        mmt_classify_me_pando(ipacket, index); //BW: TODO: split it into udp and tcp functions
    }
    return 2;
}

void mmt_init_classify_me_pando() {
    selection_bitmask = MMT_SELECTION_BITMASK_PROTOCOL_V4_V6_TCP_OR_UDP_WITH_PAYLOAD_WITHOUT_RETRANSMISSION;
    MMT_SAVE_AS_BITMASK(detection_bitmask, PROTO_UNKNOWN);
    MMT_SAVE_AS_BITMASK(excluded_protocol_bitmask, PROTO_PANDO);
}

/////////////// END OF PROTOCOL INTERNAL CODE    ///////////////////

int init_proto_pando_struct() {
    protocol_t * protocol_struct = init_protocol_struct_for_registration(PROTO_PANDO, PROTO_PANDO_ALIAS);
    if (protocol_struct != NULL) {

        mmt_init_classify_me_pando();
        
        return register_protocol(protocol_struct, PROTO_PANDO);
    } else {
        return 0;
    }
}


