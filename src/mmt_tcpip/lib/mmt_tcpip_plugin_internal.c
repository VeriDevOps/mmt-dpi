#include "mmt_common_internal_include.h"

void mmt_add_content_type(ipacket_t * ipacket, uint16_t content_class, uint16_t content_type) {
    if (ipacket->session) {
        ipacket->session->content_info.content_class = content_class;
        ipacket->session->content_info.content_type = content_type;
    }

    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    if (packet) {
        packet->content_info.content_class = content_class;
        packet->content_info.content_type = content_type;
    }
}

void mmt_internal_add_connection(ipacket_t * ipacket, uint16_t detected_protocol, mmt_protocol_type_t protocol_type) {
    struct mmt_internal_tcpip_id_struct *src = ipacket->internal_packet->src;
    struct mmt_internal_tcpip_id_struct *dst = ipacket->internal_packet->dst;

    mmt_change_internal_flow_packet_protocol(ipacket, detected_protocol, protocol_type);

    if (src != NULL) {
        MMT_ADD_PROTOCOL_TO_BITMASK(src->detected_protocol_bitmask, detected_protocol);
    }
    if (dst != NULL) {
        MMT_ADD_PROTOCOL_TO_BITMASK(dst->detected_protocol_bitmask, detected_protocol);
    }
}

void mmt_change_internal_flow_protocol(ipacket_t * ipacket, uint16_t detected_protocol, mmt_protocol_type_t protocol_type) {
    struct mmt_internal_tcpip_session_struct *flow = ipacket->internal_packet->flow;
#if PROTOCOL_HISTORY_SIZE > 1
    uint8_t a;
    uint8_t stack_size;
    uint16_t new_is_real = 0;
    uint16_t preserve_bitmask;
#endif

    if (!flow)
        return;

#if PROTOCOL_HISTORY_SIZE > 1
    stack_size = flow->protocol_stack_info.current_stack_size_minus_one + 1;

    /* here are the rules for stack manipulations:
     * 1.if the new protocol is a real protocol, insert it at the position
     *   of the top-most real protocol or below the last non-unknown correlated
     *   protocol.
     * 2.if the new protocol is not real, put it on top of stack but if there is
     *   a real protocol in the stack, make sure at least one real protocol remains
     *   in the stack
     */

    if (protocol_type == MMT_CORRELATED_PROTOCOL) {
        uint16_t saved_real_protocol = PROTO_UNKNOWN;

        if (stack_size == PROTOCOL_HISTORY_SIZE) {
            /* check whether we will lost real protocol information due to shifting */
            uint16_t real_protocol = flow->protocol_stack_info.entry_is_real_protocol;

            for (a = 0; a < stack_size; a++) {
                if (real_protocol & 1)
                    break;
                real_protocol >>= 1;
            }

            if (a == (stack_size - 1)) {
                /* oh, only one real protocol at the end, store it and insert it later */
                saved_real_protocol = flow->detected_protocol_stack[stack_size - 1];
            }
        } else {
            flow->protocol_stack_info.current_stack_size_minus_one++;
            stack_size++;
        }

        /* now shift and insert */
        for (a = stack_size - 1; a > 0; a--) {
            flow->detected_protocol_stack[a] = flow->detected_protocol_stack[a - 1];
        }

        flow->protocol_stack_info.entry_is_real_protocol <<= 1;

        /* now set the new protocol */

        flow->detected_protocol_stack[0] = detected_protocol;

        /* restore real protocol */
        if (saved_real_protocol != PROTO_UNKNOWN) {
            flow->detected_protocol_stack[stack_size - 1] = saved_real_protocol;
            flow->protocol_stack_info.entry_is_real_protocol |= 1 << (stack_size - 1);
        }
        /* done */
    } else {
        uint8_t insert_at = 0;

        if (!(flow->protocol_stack_info.entry_is_real_protocol & 1)) {
            uint16_t real_protocol = flow->protocol_stack_info.entry_is_real_protocol;

            for (a = 0; a < stack_size; a++) {
                if (real_protocol & 1)
                    break;
                real_protocol >>= 1;
            }

            insert_at = a;
        }

        if (insert_at >= stack_size) {
            /* no real protocol found, insert it at the bottom */

            insert_at = stack_size - 1;
        }

        if (stack_size < PROTOCOL_HISTORY_SIZE) {
            flow->protocol_stack_info.current_stack_size_minus_one++;
            stack_size++;
        }

        /* first shift all stacks */
        for (a = stack_size - 1; a > insert_at; a--) {
            flow->detected_protocol_stack[a] = flow->detected_protocol_stack[a - 1];
        }

        preserve_bitmask = (1 << insert_at) - 1;

        new_is_real = (flow->protocol_stack_info.entry_is_real_protocol & (~preserve_bitmask)) << 1;
        new_is_real |= flow->protocol_stack_info.entry_is_real_protocol & preserve_bitmask;

        flow->protocol_stack_info.entry_is_real_protocol = new_is_real;

        /* now set the new protocol */

        flow->detected_protocol_stack[insert_at] = detected_protocol;

        /* and finally update the additional stack information */

        flow->protocol_stack_info.entry_is_real_protocol |= 1 << insert_at;
    }
#else
    flow->detected_protocol_stack[0] = detected_protocol;
    flow->detected_subprotocol_stack[0] = detected_subprotocol;
#endif
}

void mmt_change_internal_packet_protocol(ipacket_t * ipacket, uint16_t detected_protocol, mmt_protocol_type_t protocol_type) {
    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    /* NOTE: everything below is identically to change_flow_protocol
     *        except flow->packet If you want to change something here,
     *        don't! Change it for the flow function and apply it here
     *        as well */
#if PROTOCOL_HISTORY_SIZE > 1
    uint8_t a;
    uint8_t stack_size;
    uint16_t new_is_real = 0;
    uint16_t preserve_bitmask;
#endif

    if (!packet)
        return;

#if PROTOCOL_HISTORY_SIZE > 1
    stack_size = packet->protocol_stack_info.current_stack_size_minus_one + 1;

    /* here are the rules for stack manipulations:
     * 1.if the new protocol is a real protocol, insert it at the position
     *   of the top-most real protocol or below the last non-unknown correlated
     *   protocol.
     * 2.if the new protocol is not real, put it on top of stack but if there is
     *   a real protocol in the stack, make sure at least one real protocol remains
     *   in the stack
     */

    if (protocol_type == MMT_CORRELATED_PROTOCOL) {
        uint16_t saved_real_protocol = PROTO_UNKNOWN;

        if (stack_size == PROTOCOL_HISTORY_SIZE) {
            /* check whether we will lost real protocol information due to shifting */
            uint16_t real_protocol = packet->protocol_stack_info.entry_is_real_protocol;

            for (a = 0; a < stack_size; a++) {
                if (real_protocol & 1)
                    break;
                real_protocol >>= 1;
            }

            if (a == (stack_size - 1)) {
                /* oh, only one real protocol at the end, store it and insert it later */
                saved_real_protocol = packet->detected_protocol_stack[stack_size - 1];
            }
        } else {
            packet->protocol_stack_info.current_stack_size_minus_one++;
            stack_size++;
        }

        /* now shift and insert */
        for (a = stack_size - 1; a > 0; a--) {
            packet->detected_protocol_stack[a] = packet->detected_protocol_stack[a - 1];
        }

        packet->protocol_stack_info.entry_is_real_protocol <<= 1;

        /* now set the new protocol */

        packet->detected_protocol_stack[0] = detected_protocol;

        /* restore real protocol */
        if (saved_real_protocol != PROTO_UNKNOWN) {
            packet->detected_protocol_stack[stack_size - 1] = saved_real_protocol;
            packet->protocol_stack_info.entry_is_real_protocol |= 1 << (stack_size - 1);
        }
        /* done */
    } else {
        uint8_t insert_at = 0;

        if (!(packet->protocol_stack_info.entry_is_real_protocol & 1)) {
            uint16_t real_protocol = packet->protocol_stack_info.entry_is_real_protocol;

            for (a = 0; a < stack_size; a++) {
                if (real_protocol & 1)
                    break;
                real_protocol >>= 1;
            }

            insert_at = a;
        }

        if (insert_at >= stack_size) {
            /* no real protocol found, insert it at the first unknown protocol */

            insert_at = stack_size - 1;
        }

        if (stack_size < PROTOCOL_HISTORY_SIZE) {
            packet->protocol_stack_info.current_stack_size_minus_one++;
            stack_size++;
        }

        /* first shift all stacks */
        for (a = stack_size - 1; a > insert_at; a--) {
            packet->detected_protocol_stack[a] = packet->detected_protocol_stack[a - 1];
        }

        preserve_bitmask = (1 << insert_at) - 1;

        new_is_real = (packet->protocol_stack_info.entry_is_real_protocol & (~preserve_bitmask)) << 1;
        new_is_real |= packet->protocol_stack_info.entry_is_real_protocol & preserve_bitmask;

        packet->protocol_stack_info.entry_is_real_protocol = new_is_real;

        /* now set the new protocol */

        packet->detected_protocol_stack[insert_at] = detected_protocol;

        /* and finally update the additional stack information */

        packet->protocol_stack_info.entry_is_real_protocol |= 1 << insert_at;
    }
#else
    packet->detected_protocol_stack[0] = detected_protocol;
    packet->detected_subprotocol_stack[0] = detected_subprotocol;
#endif
}

inline static uint64_t _get_proto_by_tcp_port_number(uint16_t port_number,const u_char * payload, int payload_packet_len){
    switch(port_number){
        case 443:
        return PROTO_SSL;

        case 80:
        case 8080:
        return PROTO_HTTP;

        case 22:
        return PROTO_SSH;

        case 23:
        return PROTO_TELNET;

        case 25:
        return PROTO_SMTP;

        case 465:
        return PROTO_SMTPS;

        case 110:
        return PROTO_POP;

        case 995:
        return PROTO_POPS;

        case 143:
        return PROTO_IMAP;

        case 993:
        return PROTO_IMAPS;

        case 445:
        return PROTO_SMB;

        case 88:
        return PROTO_KERBEROS;

        case 135:
        return PROTO_DCERPC;

        case 389:
        return PROTO_LDAP;

        case 554:
        return PROTO_RTSP;

        case 500:
        return PROTO_IPSEC;

        case 5800:
        case 5900:
        case 5901:
        return PROTO_VNC;

        case 5222:
        return PROTO_UNENCRYPED_JABBER;

        case 1935:
        return PROTO_FLASH;

        case 3128:
        return PROTO_HTTP_PROXY;

        case 2598:
        case 1494:
        return PROTO_CITRIX;/* http://support.citrix.com/article/CTX104147 */

    }
    return PROTO_UNKNOWN;
}

inline static uint64_t _get_proto_by_udp_port_number(uint16_t port_number,const u_char * payload, int payload_packet_len){
    switch(port_number){
        case 67:
        case 68:
        return PROTO_DHCP;

        case 137:
        case 138:
        return PROTO_NETBIOS;

        case 161:
        case 162:
        return PROTO_SNMP;

        case 5353:
        case 5354:
        return PROTO_MDNS;

        case 53:
        return PROTO_DNS;

        case 88:
        return PROTO_KERBEROS;

        case 500:
        return PROTO_IPSEC;

        case 5355:
        return PROTO_LLMNR;
        case 1883:
        case 8883:
        return PROTO_MQTT;
    }
    return PROTO_UNKNOWN;
}
// unsigned int mmt_get_protocol_by_port_number(uint8_t proto, uint16_t sport, uint16_t dport) {
//     uint64_t proto_id = PROTO_UNKNOWN;
//     if (proto == IPPROTO_UDP) {
//         proto_id = _get_proto_by_udp_port_number(sport);
//         if(proto_id == PROTO_UNKNOWN){
//              proto_id = _get_proto_by_udp_port_number(dport);
//         }
//     } else if (proto == IPPROTO_TCP) {
//         proto_id = _get_proto_by_tcp_port_number(sport);
//         if(proto_id == PROTO_UNKNOWN){
//              proto_id = _get_proto_by_tcp_port_number(dport);
//         }
//     }

//     return (proto_id);
// }

unsigned int mmt_guess_protocol_by_port_number(ipacket_t * ipacket) {
    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    uint64_t proto_id = PROTO_UNKNOWN;
    uint16_t sport, dport;
    if (packet->tcp) {
        sport = htons(packet->tcp->source);
        dport = htons(packet->tcp->dest);
        proto_id = _get_proto_by_tcp_port_number(sport,packet->payload,packet->payload_packet_len);
        if(proto_id == PROTO_UNKNOWN){
             proto_id = _get_proto_by_tcp_port_number(dport,packet->payload,packet->payload_packet_len);
        }
    } else if(packet->udp) {
        sport = htons(packet->udp->source);
        dport = htons(packet->udp->dest);
        proto_id = _get_proto_by_udp_port_number(sport,packet->payload,packet->payload_packet_len);
        if(proto_id == PROTO_UNKNOWN){
             proto_id = _get_proto_by_udp_port_number(dport,packet->payload,packet->payload_packet_len);
        }
    }
    return (proto_id);
}

