#ifndef IP_H_
#define IP_H_

#include <arpa/inet.h>
#include <sys/socket.h>

#include "inet.hpp"

const int IP_CHAR_LEN = 16;
const int HEX = 0;
const int INTEGER = 1;

struct ip_hdr {
  uint8_t version : 4;
  uint8_t ihl : 4;
  uint8_t type_of_service;
  uint16_t total_length;
  uint16_t identification;
  uint16_t fragment_offset;
  uint8_t ttl;
  uint8_t protocol;
  uint16_t hdr_checksum;
  uint32_t source_address;
  uint32_t destination_address;
};

void ipHdrDbg(unsigned char *buf, int dump_form);

#endif
