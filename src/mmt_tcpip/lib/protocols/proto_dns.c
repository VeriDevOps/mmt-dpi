#include "mmt_core.h"
#include "plugin_defs.h"
#include "extraction_lib.h"
#include "../mmt_common_internal_include.h"

#define MMT_DNS_SESSION_TIMEOUT_DELAY 15 /**< The DNS session timeout delay */

/////////////// PROTOCOL INTERNAL CODE GOES HERE ///////////////////

/* dns header
           0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                      ID                       |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |QR|   Opcode  |AA|TC|RD|RA|   Z    |   RCODE   |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    QDCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    ANCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    NSCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    ARCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
 */
struct qropcodeaatcrdrazans_authdata_authrcode {
#if BYTE_ORDER == LITTLE_ENDIAN
    uint8_t rd : 1, tc : 1, aa : 1, opcode : 4, qr : 1;
    uint8_t rcode : 4, data_auth : 1, ans_auth : 1, z : 1, ra : 1;
#elif BYTE_ORDER == BIG_ENDIAN
    uint8_t qr : 1, opcode : 4, aa : 1, tc : 1, rd : 1;
    uint8_t ra : 1, z : 1, ans_auth : 1, data_auth : 1, rcode : 4;
#else
#error "BYTE_ORDER must be defined"
#endif
};

static attribute_metadata_t dns_attributes_metadata[DNS_ATTRIBUTES_NB];

static MMT_PROTOCOL_BITMASK detection_bitmask;
static MMT_PROTOCOL_BITMASK excluded_protocol_bitmask;
static MMT_SELECTION_BITMASK_PROTOCOL_SIZE selection_bitmask;


struct dnshdr {
    uint16_t tid;
    uint16_t flags;
    uint16_t qdcount;
    uint16_t ancount;
    uint16_t nscount;
    uint16_t arcount;
};

uint32_t bytes_to_int_extraction(const char *payload,int nb_bytes){
    uint32_t ret = 0,i =0;
    for(i = 0;i < nb_bytes;i++){
        int current_byte = hex2int(payload[i]);
        ret = ret*16 + current_byte;
    }
    return ret;
}

typedef struct dns_name_struct{
    char *value;
    uint16_t length;
    struct dns_name_struct *next;
} dns_name_t;

dns_name_t * dns_new_name(){
    dns_name_t * dns_name;
    dns_name = (dns_name_t *)malloc(sizeof(dns_name_t));
    if(dns_name){
        dns_name->value = NULL;
        dns_name->length = 0;
        dns_name->next = NULL;
    }
    return dns_name;
}

void dns_free_name(dns_name_t * dns_name){
    if(dns_name){
        if(dns_name->value){
            free(dns_name->value);
            dns_name->value = NULL;
        }
        dns_name->length = 0;
    }
}

typedef struct dns_query_struct{
    char *name;
    uint16_t type;
    uint16_t qclass;
    uint16_t qlength;
    struct dns_query_struct *next;
}dns_query_t;

dns_query_t * dns_new_query(){
    dns_query_t * dq;
    dq = (dns_query_t * )malloc(sizeof(dns_query_t));
    if(dq){
        dq->name = NULL;
        dq->type = 0;
        dq->qclass = 0;
        dq->qlength = 0;
        dq->next = NULL;
    }
    return dq;
}

void dns_free_query(dns_query_t * dq){
    if (dq){
        if(dq->name){
            free(dq->name);
            dq->name = NULL;
        }
        dq->type = 0;
        dq->qclass = 0;
        dq->qlength = 0;
        dq->next = NULL;
    }
}

typedef struct dns_answer_struct{
    char *name;
    uint16_t type;
    uint16_t aclass;
    uint32_t a_ttl;
    uint16_t data_length;
    uint16_t a_length;
    void *data;
    struct dns_answer_struct *next;
}dns_answer_t;

dns_answer_t * dns_new_answer(){
    dns_answer_t * da = (dns_answer_t*)malloc(sizeof(dns_answer_t));
    if(da){
        da->name = NULL;
        da->type = 0;
        da->aclass = 0;
        da->a_ttl = 0;
        da->data_length = 0;
        da->a_length = 0;
        da->data = NULL;
        da->next = NULL;
    }
    return da;
}


void dns_free_answer(dns_answer_t *da){
    if(da){
        if(da->name){
            free(da->name);
            da->name = NULL;
        }

        if(da->data){
            free(da->data);
            da->data = NULL;
        }
        da->type = 0;
        da->aclass = 0;
        da->a_ttl = 0;
        da->data_length = 0;
        da->a_length = 0;
    }
}

dns_name_t * dns_extract_name(const char* dns_name_payload, const char* dns_payload){
    uint16_t str_length = hex2int(dns_name_payload[0]);
    if(str_length == 0){
        return NULL;
    }else if(str_length == 192){
        int offset_name = hex2int(dns_name_payload[1]);
        dns_name_t * original_name = dns_extract_name(dns_payload + offset_name,dns_payload);
        if(original_name){
            dns_name_t * dns_name;
            dns_name = dns_new_name();    
            if(dns_name){
                
            }
        }else{
            return NULL;
        }
    }else{
        dns_name_t * dns_name;
        dns_name = dns_new_name();
        if(dns_name){
            dns_name->value = malloc(str_length + 1);
            memcpy(dns_name->value,dns_name_payload + 1,str_length);
            dns_name->value[str_length]='\0';
            dns_name->length = str_length;
            dns_name->next = dns_extract_name(dns_name_payload + str_length + 1);
        }   
        return dns_name; 
    }
}

dns_name_t * dns_extract_name_value(const char *dns_name_payload,const char* dns_payload){
    if(dns_name_payload == NULL) return NULL;
    dns_name_t * q_name = dns_new_name();
    if(q_name){
        dns_name_t * ext_name = dns_extract_name(dns_name_payload,dns_payload);
        if(ext_name){
            int q_name_length = 0;
            dns_name_t * current_name = ext_name;
            while(current_name){
                q_name_length += current_name->length + 1;
                current_name = current_name->next;
            }
            q_name->length = q_name_length;
            q_name->value = malloc((q_name_length+1) * sizeof(char));
            memcpy(q_name->value,dns_name_payload,q_name_length);
            q_name->value[q_name_length] = '\0';
        }
    }
    return q_name;
}


dns_query_t * dns_extract_queries(const char * dns_queries_payload,int nb_queries){
    if(nb_queries == 0) return NULL;
    dns_name_t * current_name = dns_extract_name_value(dns_queries_payload);
    if(current_name){
        dns_query_t * dq = dns_new_query();
        if(dq == NULL) return NULL;
        dq->name = current_name->value;
        dq->type = bytes_to_int_extraction(dns_queries_payload + current_name->length + 1,2);
        dq->qclass = bytes_to_int_extraction(dns_queries_payload + current_name->length + 3,2);
        dq->qlength = current_name->length + 5;
        dq->next = dns_extract_queries(dns_queries_payload + dq->qlength,nb_queries - 1); 
        return dq;
    }
    return NULL;
}

int dns_get_answers_offset(const ipacket_t * ipacket, unsigned proto_index){
    /* Get the protocol offset */
    int answer_payload_offset = 12;

    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    
    // Get number of queries
    int qdcount_offset = 4;
    uint16_t qdcount = bytes_to_int_extraction(ipacket->data + proto_offset + qdcount_offset,2);
    if(qdcount == 0){
        return 0;
    }else{
        dns_query_t * dq = dns_extract_queries(ipacket->data + proto_offset + answer_payload_offset,qdcount);
        if(dq){
            dns_query_t * current_query = dq;
            while(current_query){
                answer_payload_offset += dq->qlength;   
                dns_query_t * qnext = current_query->next;
                dns_free_query(current_query);
                current_query = qnext;
            }
        }
    }
    return answer_payload_offset;
}

dns_answer_t * dns_extract_answers(const char *dns_answers_payload,int nb_answers,const char * dns_payload){
    if(nb_answers == 0) return NULL;
    dns_name_t * current_name = dns_extract_name_value(dns_answers_payload,dns_payload);
    if(current_name){
        dns_answer_t * da = dns_new_answer();
        if(da == NULL) return NULL;
        da->name = current_name->value;
        da->type = bytes_to_int_extraction(dns_answers_payload + current_name->length + 1,2);
        da->aclass = bytes_to_int_extraction(dns_answers_payload + current_name->length + 3,2);
        da->a_ttl =  bytes_to_int_extraction(dns_answers_payload + current_name->length + 5,4);
        da->data_length = bytes_to_int_extraction(dns_answers_payload + current_name->length + 9,2);
        da->data = dns_answers_payload + current_name->length + 11;
        da->a_length = dns_answers_payload + current_name->length + 11 + da->data_length;
        da->next = dns_extract_answers(dns_answers_payload + da->a_length,nb_answers - 1,dns_payload); 
        return da;
    }
    return NULL;
}

/*
 * DNS data extraction routines
 */
int dns_qr_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[1].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[1].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;
    *((uint16_t *) extracted_data->data) = (flags & 0x8000)?1:0;
    return 1;
}

int dns_opcode_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[2].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[2].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;
    *((uint16_t *) extracted_data->data) = (flags & 0x7800) >> 11;
    return 1;
}

int dns_aa_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[3].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[3].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;
    if (flags & 0x8000) {
        *((uint16_t *) extracted_data->data) = (flags & 0x0400)?1:0;
        return 1;
    }
    return 0;
}

int dns_tc_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[4].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[4].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;
    *((uint16_t *) extracted_data->data) = (flags & 0x0200)?1:0;
    return 1;
}

int dns_rd_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[5].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[5].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;
    *((uint16_t *) extracted_data->data) = (flags & 0x0100)?1:0;
    return 1;
}

int dns_ra_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[6].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[6].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;

    if (flags & 0x8000) {
        *((uint16_t *) extracted_data->data) = (flags & 0x0080)?1:0;
        return 1;
    }
    return 0;
}

int dns_z_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[7].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[7].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;
    *((uint16_t *) extracted_data->data) = (flags & 0x0040)?1:0;
    return 1;
}

int dns_ans_auth_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[8].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[8].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;

    if (flags & 0x8000) {
        *((uint16_t *) extracted_data->data) = (flags & 0x0020)?1:0;
        return 1;
    }
    return 0;
}

int dns_data_auth_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[9].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[9].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;

    if (flags & 0x8000) {
        *((uint16_t *) extracted_data->data) = (flags & 0x0010)?1:0;
        return 1;
    }
    return 0;
}

int dns_rcode_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    int attribute_offset = dns_attributes_metadata[10].position_in_packet;
    /* unused
    int attribute_length = dns_attributes_metadata[10].data_len;
    */
    uint16_t flags = ntohs(*(uint16_t *) & ipacket->data[proto_offset + attribute_offset]);
    //struct qropcodeaatcrdrazans_authdata_authrcode * temp_qropcodeaatcrdrazans_authdata_authrcode = (struct qropcodeaatcrdrazans_authdata_authrcode *) & flags;

    if (flags & 0x8000) {
        *((uint16_t *) extracted_data->data) = flags & 0x000F;
        return 1;
    }
    return 0;
}

int dns_queries_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    
    // Get number of queries
    int qdcount_offset = 4;
    uint16_t qdcount = bytes_to_int_extraction(ipacket->data + proto_offset + qdcount_offset,2);
    if(qdcount == 0){
        return 0;
    }else{
        int queries_payload_offset = 12;
        dns_query_t * dq = dns_extract_queries(ipacket->data + proto_offset + queries_payload_offset,qdcount,ipacket->data + proto_offset);
        if(dq == NULL){
            return 0;
        }else{
            extracted_data->data = (void*)dq;
            return 1;
        }
    }
}

int dns_answers_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data) {
    /* Get the protocol offset */
    int proto_offset = get_packet_offset_at_index(ipacket, proto_index);
    
    // Get number of queries
    int ancount_offset = 6;
    uint16_t ancount = bytes_to_int_extraction(ipacket->data + proto_offset + ancount_offset,2);
    if(ancount == 0){
        return 0;
    }else{
        int answer_payload_offset = dns_get_answers_offset(ipacket,proto_index);
        dns_answer_t * da = dns_extract_answers(ipacket->data + proto_offset + answer_payload_offset,ancount,ipacket->data + proto_offset);
        if(da == NULL){
            return 0;
        }else{
            extracted_data->data = (void*)da;
            return 1;
        }
    }
}


static attribute_metadata_t dns_attributes_metadata[DNS_ATTRIBUTES_NB] = {
    {DNS_TID, DNS_TID_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 0, SCOPE_PACKET, general_short_extraction_with_ordering_change},
    {DNS_QR, DNS_QR_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_qr_extraction},
    {DNS_OPCODE, DNS_OPCODE_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_opcode_extraction},
    {DNS_AA, DNS_AA_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_aa_extraction},
    {DNS_TC, DNS_TC_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_tc_extraction},
    {DNS_RD, DNS_RD_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_rd_extraction},
    {DNS_RA, DNS_RA_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_ra_extraction},
    {DNS_Z, DNS_Z_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_z_extraction},
    {DNS_ANS_AUTH, DNS_ANS_AUTH_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_ans_auth_extraction},
    {DNS_DATA_AUTH, DNS_DATA_AUTH_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_data_auth_extraction},
    {DNS_RCODE, DNS_RCODE_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 2, SCOPE_PACKET, dns_rcode_extraction},
    {DNS_QDCOUNT, DNS_QDCOUNT_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 4, SCOPE_PACKET, general_short_extraction_with_ordering_change},
    {DNS_ANCOUNT, DNS_ANCOUNT_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 6, SCOPE_PACKET, general_short_extraction_with_ordering_change},
    {DNS_NSCOUNT, DNS_NSCOUNT_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 8, SCOPE_PACKET, general_short_extraction_with_ordering_change},
    {DNS_ARCOUNT, DNS_ARCOUNT_ALIAS, MMT_U16_DATA, sizeof (uint16_t), 10, SCOPE_PACKET, general_short_extraction_with_ordering_change},
    {DNS_QUERIES, DNS_QUERIES_ALIAS, MMT_DATA_POINTER, sizeof(void*), POSITION_NOT_KNOWN, SCOPE_PACKET, dns_queries_extraction},
    {DNS_ANSWERS, DNS_ANSWERS_ALIAS, MMT_DATA_POINTER, sizeof(void*), POSITION_NOT_KNOWN, SCOPE_PACKET, dns_answers_extraction},
};

void dns_session_data_init(ipacket_t * ipacket, unsigned index) {
    /* User specific code goes here */
}

void dns_session_data_cleanup(mmt_session_t * session, unsigned index) {
    /* User specific code goes here */
}

int dns_session_data_analysis(ipacket_t * ipacket, unsigned index) {
    /* User specific code goes here */
    return MMT_CONTINUE;
}

static void mmt_int_dns_add_connection(ipacket_t * ipacket) {
    mmt_internal_add_connection(ipacket, PROTO_DNS, MMT_REAL_PROTOCOL);
    set_session_timeout_delay(ipacket->session, MMT_DNS_SESSION_TIMEOUT_DELAY);
}

void mmt_classify_me_dns(ipacket_t * ipacket, unsigned index) {


    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    struct mmt_internal_tcpip_session_struct *flow = packet->flow;


    uint16_t dport = 0;

#define IPOQUE_MAX_DNS_REQUESTS			16

    MMT_LOG(PROTO_DNS, MMT_LOG_DEBUG, "search DNS.\n");


    if (packet->udp != NULL) {
        //      const u16 sport=ntohs(packet->udp->source);
        dport = ntohs(packet->udp->dest);
        MMT_LOG(PROTO_DNS, MMT_LOG_DEBUG, "calculated dport over UDP.\n");
    }
    if (packet->tcp != NULL) {
        //      const u16 sport=ntohs(packet->tcp->source);
        dport = ntohs(packet->tcp->dest);
        MMT_LOG(PROTO_DNS, MMT_LOG_DEBUG, "calculated dport over tcp.\n");
    }

    /*check standard DNS to port 53 */
    if (dport == 53 && packet->payload_packet_len >= 12) {

        MMT_LOG(PROTO_DNS, MMT_LOG_DEBUG, "dport==53, packet-payload-packet-len>=12.\n");

        /* dns header
           0  1  2  3  4  5  6  7  8  9  0  1  2  3  4  5
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                      ID                       |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |QR|   Opcode  |AA|TC|RD|RA|   Z    |   RCODE   |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    QDCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    ANCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    NSCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
           |                    ARCOUNT                    |
           +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
         *
         * dns query check: query: QR set, ancount = 0, nscount = 0, QDCOUNT < MAX_DNS, ARCOUNT < MAX_DNS
         *
         */

        if (((packet->payload[2] & 0x80) == 0 &&
                ntohs(get_u16(packet->payload, 4)) <= IPOQUE_MAX_DNS_REQUESTS &&
                ntohs(get_u16(packet->payload, 4)) != 0 &&
                ntohs(get_u16(packet->payload, 6)) == 0 &&
                ntohs(get_u16(packet->payload, 8)) == 0 && ntohs(get_u16(packet->payload, 10)) <= IPOQUE_MAX_DNS_REQUESTS)
                ||
                ((ntohs(get_u16(packet->payload, 0)) == packet->payload_packet_len - 2) &&
                (packet->payload[4] & 0x80) == 0 &&
                ntohs(get_u16(packet->payload, 6)) <= IPOQUE_MAX_DNS_REQUESTS &&
                ntohs(get_u16(packet->payload, 6)) != 0 &&
                ntohs(get_u16(packet->payload, 8)) == 0 &&
                ntohs(get_u16(packet->payload, 10)) == 0 &&
                packet->payload_packet_len >= 14 && ntohs(get_u16(packet->payload, 12)) <= IPOQUE_MAX_DNS_REQUESTS)) {

            MMT_LOG(PROTO_DNS, MMT_LOG_DEBUG, "found DNS.\n");

            mmt_int_dns_add_connection(ipacket);
            return;
        }
    }

    MMT_LOG(PROTO_DNS, MMT_LOG_DEBUG, "exclude DNS.\n");
    MMT_ADD_PROTOCOL_TO_BITMASK(flow->excluded_protocol_bitmask, PROTO_DNS);

}

int mmt_check_dns(ipacket_t * ipacket, unsigned index) {
    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    if ((selection_bitmask & packet->mmt_selection_packet) == selection_bitmask
            && MMT_BITMASK_COMPARE(excluded_protocol_bitmask, packet->flow->excluded_protocol_bitmask) == 0
            && MMT_BITMASK_COMPARE(detection_bitmask, packet->detection_bitmask) != 0) {

        mmt_classify_me_dns(ipacket, index);
    }
    return 1;
}

void mmt_init_classify_me_dns() {
    selection_bitmask = MMT_SELECTION_BITMASK_PROTOCOL_V4_V6_TCP_OR_UDP_WITH_PAYLOAD_WITHOUT_RETRANSMISSION;
    MMT_SAVE_AS_BITMASK(detection_bitmask, PROTO_UNKNOWN);
    MMT_SAVE_AS_BITMASK(excluded_protocol_bitmask, PROTO_DNS);
}

/////////////// END OF PROTOCOL INTERNAL CODE    ///////////////////

int init_proto_dns_struct() {
    protocol_t * protocol_struct = init_protocol_struct_for_registration(PROTO_DNS, PROTO_DNS_ALIAS);
    if (protocol_struct != NULL) {
        int i = 0;
        for (; i < DNS_ATTRIBUTES_NB; i++) {
            register_attribute_with_protocol(protocol_struct, &dns_attributes_metadata[i]);
        }

        mmt_init_classify_me_dns();

        /* Session context specific initializations */
        register_session_data_initialization_function(protocol_struct, dns_session_data_init);
        register_session_data_cleanup_function(protocol_struct, dns_session_data_cleanup);
        register_session_data_analysis_function(protocol_struct, dns_session_data_analysis);

        return register_protocol(protocol_struct, PROTO_DNS);
    } else {
        return 0;
    }
}


