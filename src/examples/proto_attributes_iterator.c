#include <stdio.h>
#include <stdlib.h>
#include "mmt_core.h"

void attributes_iterator(attribute_metadata_t * attribute, uint32_t proto_id, void * args) {
  printf("\tAttribute id %i --- Name %s \n", attribute->id, attribute->alias);
}

void protocols_iterator(uint32_t proto_id, void * args) {
  printf("Protocol id %i --- Name %s\n", proto_id, get_protocol_name_by_id(proto_id));
  iterate_through_protocol_attributes(proto_id, attributes_iterator, NULL);
}

int main(int argc, char** argv) {

  init_extraction();

  iterate_through_protocols(protocols_iterator, NULL);

  close_extraction();

  return (EXIT_SUCCESS);
}

