#include "mmt_core.h"
#include "plugin_defs.h"
#include "extraction_lib.h"
#include "../mmt_common_internal_include.h"
#include "ndn.h"
#include <ctype.h>

/////////////// PROTOCOL INTERNAL CODE GOES HERE ///////////////////

static MMT_PROTOCOL_BITMASK detection_bitmask;
static MMT_PROTOCOL_BITMASK excluded_protocol_bitmask;
static MMT_SELECTION_BITMASK_PROTOCOL_SIZE selection_bitmask;

static void mmt_int_ndn_http_add_connection(ipacket_t * ipacket) {
    debug("NDN_HTTP: mmt_int_ndn_http_add_connection");
    mmt_internal_add_connection(ipacket, PROTO_NDN_HTTP, MMT_REAL_PROTOCOL);
}


int ndn_http_url_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data){
    int offset = get_packet_offset_at_index(ipacket, proto_index);
    char *payload = (char*)&ipacket->data[offset];
    // NDN over Ethernet
    uint32_t payload_len = 0;
    if(proto_index == 2){
        payload_len = ipacket->p_hdr->caplen - offset;
    }else{
        // NDN over TCP
        payload_len = ipacket->internal_packet->payload_packet_len;
    }

    char *ret_v = ndn_name_components_at_index(payload,payload_len,1);
    if(ret_v == NULL){
        return 0;
    }

    if(strcmp(ret_v,"req") == 0){
        char *ret_v2 = ndn_name_components_at_index(payload,payload_len,4);
        if(ret_v2 != NULL){
            extracted_data->data = (void*)ret_v2;
            free(ret_v);
            return 1;
        }    
    }else{
        char *ret_v2 = ndn_name_components_at_index(payload,payload_len,2);
        if(ret_v2 != NULL){
            free(ret_v);
            extracted_data->data = (void*)ret_v2;
            return 1;
        }    
    }
    //             *((uint16_t*)extracted_data->data) = ftp_control->contrl_conn->c_port;
    return 0;
}

int ndn_http_method_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data){
    int offset = get_packet_offset_at_index(ipacket, proto_index);
    char *payload = (char*)&ipacket->data[offset];
    // NDN over Ethernet
    uint32_t payload_len = 0;
    if(proto_index == 2){
        payload_len = ipacket->p_hdr->caplen - offset;
    }else{
        // NDN over TCP
        payload_len = ipacket->internal_packet->payload_packet_len;
    }

    char *ret_v = ndn_name_components_at_index(payload,payload_len,1);
    if(ret_v == NULL){
        return 0;
    }

    if(strcmp(ret_v,"req") == 0){
        char *ret_v2 = ndn_name_components_at_index(payload,payload_len,3);
        if(ret_v2 != NULL){
            extracted_data->data = (void*)ret_v2;
            free(ret_v);
            return 1;
        }    
    }else{
        char *ret_v2 = ndn_name_components_at_index(payload,payload_len,1);
        if(ret_v2 != NULL){
            extracted_data->data = (void*)ret_v2;
            free(ret_v);
            return 1;
        }    
    }
    //             *((uint16_t*)extracted_data->data) = ftp_control->contrl_conn->c_port;
    return 0;
}


int ndn_http_first_gw_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data){
    int offset = get_packet_offset_at_index(ipacket, proto_index);
    char *payload = (char*)&ipacket->data[offset];
    // NDN over Ethernet
    uint32_t payload_len = 0;
    if(proto_index == 2){
        payload_len = ipacket->p_hdr->caplen - offset;
    }else{
        // NDN over TCP
        payload_len = ipacket->internal_packet->payload_packet_len;
    }

    char *ret_v = ndn_name_components_at_index(payload,payload_len,0);
    if(ret_v != NULL){
        extracted_data->data = (void*)ret_v;
        return 1;
    }
    //             *((uint16_t*)extracted_data->data) = ftp_control->contrl_conn->c_port;
    return 0;
}

int ndn_http_second_gw_extraction(const ipacket_t * ipacket, unsigned proto_index,
        attribute_t * extracted_data){
    int offset = get_packet_offset_at_index(ipacket, proto_index);
    char *payload = (char*)&ipacket->data[offset];
    // NDN over Ethernet
    uint32_t payload_len = 0;
    if(proto_index == 2){
        payload_len = ipacket->p_hdr->caplen - offset;
    }else{
        // NDN over TCP
        payload_len = ipacket->internal_packet->payload_packet_len;
    }

    char *ret_v = ndn_name_components_at_index(payload,payload_len,1);
    if(ret_v == NULL){
        return 0;
    }

    if(strcmp(ret_v,"req") == 0){
        char *ret_v2 = ndn_name_components_at_index(payload,payload_len,2);
        if(ret_v2 != NULL){
            extracted_data->data = (void*)ret_v2;
            free(ret_v);
            return 1;
        }    
    }
    free(ret_v);
    //             *((uint16_t*)extracted_data->data) = ftp_control->contrl_conn->c_port;
    return 0;
}


//////////////////////////// EXTRACTION ///////////////////////////////////////


static attribute_metadata_t ndn_attributes_metadata[NDN_ATTRIBUTES_NB] = {
    // {NDN_IMPLICIT_SHA256_DIGEST_COMPONENT,NDN_IMPLICIT_SHA256_DIGEST_COMPONENT_ALIAS,MMT_DATA_POINTER,sizeof(void*),POSITION_NOT_KNOWN,SCOPE_SESSION,ndn_implicit_sha256_digest_component_extraction},
    {NDN_LIST_SESSIONS,NDN_LIST_SESSIONS_ALIAS,MMT_DATA_POINTER,sizeof(void*),POSITION_NOT_KNOWN,SCOPE_SESSION,ndn_list_sessions_extraction},
    {NDN_PACKET_TYPE,NDN_PACKET_TYPE_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_packet_type_extraction},
    {NDN_PACKET_LENGTH,NDN_PACKET_LENGTH_ALIAS,MMT_U32_DATA,sizeof(int),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_packet_length_extraction},
    {NDN_NAME_COMPONENTS,NDN_NAME_COMPONENTS_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_name_components_extraction},
    {NDN_INTEREST_NONCE,NDN_INTEREST_NONCE_ALIAS,MMT_U32_DATA,sizeof(int),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_nonce_extraction},
    {NDN_INTEREST_LIFETIME,NDN_INTEREST_LIFETIME_ALIAS,MMT_U32_DATA,sizeof(int),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_lifetime_extraction},
    {NDN_INTEREST_MIN_SUFFIX_COMPONENT,NDN_INTEREST_MIN_SUFFIX_COMPONENT_ALIAS,MMT_U32_DATA,sizeof(int),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_min_suffix_component_extraction},
    {NDN_INTEREST_MAX_SUFFIX_COMPONENT,NDN_INTEREST_MAX_SUFFIX_COMPONENT_ALIAS,MMT_U32_DATA,sizeof(int),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_max_suffix_component_extraction},
    {NDN_INTEREST_PUBLISHER_PUBLICKEY_LOCATOR,NDN_INTEREST_PUBLISHER_PUBLICKEY_LOCATOR_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_publisher_publickey_locator_extraction},
    {NDN_INTEREST_EXCLUDE,NDN_INTEREST_EXCLUDE_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_exclude_extraction},
    {NDN_INTEREST_CHILD_SELECTOR,NDN_INTEREST_CHILD_SELECTOR_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_child_selector_extraction},
    {NDN_INTEREST_MUST_BE_FRESH,NDN_INTEREST_MUST_BE_FRESH_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_must_be_fresh_extraction},
    {NDN_INTEREST_ANY,NDN_INTEREST_ANY_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_interest_any_extraction},
    {NDN_DATA_CONTENT,NDN_DATA_CONTENT_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_content_extraction},
    {NDN_DATA_SIGNATURE_VALUE,NDN_DATA_SIGNATURE_VALUE_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_signature_value_extraction},
    {NDN_DATA_CONTENT_TYPE,NDN_DATA_CONTENT_TYPE_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_content_type_extraction},
    {NDN_DATA_FRESHNESS_PERIOD,NDN_DATA_FRESHNESS_PERIOD_ALIAS,MMT_U32_DATA,sizeof(int),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_freshness_period_extraction},
    {NDN_DATA_FINAL_BLOCK_ID,NDN_DATA_FINAL_BLOCK_ID_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_final_block_id_extraction},
    {NDN_DATA_SIGNATURE_TYPE,NDN_DATA_SIGNATURE_TYPE_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_signature_type_extraction},
    {NDN_DATA_KEY_LOCATOR,NDN_DATA_KEY_LOCATOR_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_key_locator_extraction},
    {NDN_HTTP_URL,NDN_HTTP_URL_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_http_url_extraction},
    {NDN_HTTP_METHOD,NDN_HTTP_METHOD_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_http_method_extraction},
    {NDN_HTTP_FIRST_GW,NDN_HTTP_FIRST_GW_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_http_first_gw_extraction},
    {NDN_HTTP_SECOND_GW,NDN_HTTP_SECOND_GW_ALIAS,MMT_STRING_DATA_POINTER,sizeof(char*),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_http_second_gw_extraction},
    // // {NDN_DATA_KEY_DIGEST,NDN_DATA_KEY_DIGEST_ALIAS,MMT_U8_DATA,sizeof(char),POSITION_NOT_KNOWN,SCOPE_PACKET,ndn_data_key_digest_extraction},
};

//////////////////////////// END OF EXTRACTION /////////////////////////////////


///////////////////////////////// SESSION DATA ANALYSE ////////////////////////////////////////

int mmt_check_ndn_http(ipacket_t * ipacket, unsigned index) {
    debug("NDN_HTTP: mmt_check_ndn_http");
    struct mmt_tcpip_internal_packet_struct *packet = ipacket->internal_packet;
    if ((selection_bitmask & packet->mmt_selection_packet) == selection_bitmask
            && MMT_BITMASK_COMPARE(excluded_protocol_bitmask, packet->flow->excluded_protocol_bitmask) == 0
            && MMT_BITMASK_COMPARE(detection_bitmask, packet->detection_bitmask) != 0) {
            
            // debug("NDN_HTTP: checking ndn payload %lu",ipacket->packet_id);
            int offset = get_packet_offset_at_index(ipacket, index + 1);
            char * payload = (char*)&ipacket->data[offset];
            uint32_t payload_len = ipacket->internal_packet->payload_packet_len;

            if(payload_len==0){
                // debug("NDN_HTTP: payload_len == 0");
                MMT_ADD_PROTOCOL_TO_BITMASK(packet->flow->excluded_protocol_bitmask, PROTO_NDN_HTTP);
                return 0;
            }

            if(mmt_check_ndn_payload(payload,payload_len)!=0){
                // debug("NDN_HTTP: found ndn packet %lu",ipacket->packet_id);
                if(mmt_check_payload_ndn_http(payload,payload_len)==1){
                    mmt_int_ndn_http_add_connection(ipacket);
                    return 1;    
                }
            }
    }
    MMT_ADD_PROTOCOL_TO_BITMASK(packet->flow->excluded_protocol_bitmask, PROTO_NDN_HTTP);
    return 0;
}

void mmt_init_classify_me_ndn_http() {
    selection_bitmask = MMT_SELECTION_BITMASK_PROTOCOL_V4_V6_TCP_OR_UDP_WITH_PAYLOAD_WITHOUT_RETRANSMISSION;
    MMT_SAVE_AS_BITMASK(detection_bitmask, PROTO_UNKNOWN);
    MMT_ADD_PROTOCOL_TO_BITMASK(detection_bitmask, PROTO_NDN_HTTP);
    MMT_SAVE_AS_BITMASK(excluded_protocol_bitmask, PROTO_NDN_HTTP);
}

/////////////// END OF PROTOCOL INTERNAL CODE    ///////////////////

int init_proto_ndn_http_struct() {
    
    debug("NDN_HTTP: init_proto_ndn_http_struct");

    protocol_t * protocol_struct = init_protocol_struct_for_registration(PROTO_NDN_HTTP, PROTO_NDN_HTTP_ALIAS);
    if (protocol_struct != NULL) {
        int i = 0;
        for (; i < NDN_ATTRIBUTES_NB; i++) {
            register_attribute_with_protocol(protocol_struct, &ndn_attributes_metadata[i]);
        }
        // register_pre_post_classification_functions(protocol_struct, NULL, NULL);
        register_proto_context_init_cleanup_function(protocol_struct, setup_ndn_context, cleanup_ndn_context, NULL);
        register_session_data_analysis_function(protocol_struct, ndn_session_data_analysis);
        mmt_init_classify_me_ndn_http();

        return register_protocol(protocol_struct, PROTO_NDN_HTTP);
    } else {
        return 0;
    }
}


