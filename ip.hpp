#ifndef IP_H_
#define IP_H_

#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include "ethernet.hpp"

#define IP_CHAR_LEN 16
#define HEX 0
#define INTEGER 1
#define BUF_SIZ 65535

class IpProtocol {
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
  //    options
  //    padding
public:
  void Dbg(IpProtocol IpHdr, int dump_form);
};

#endif
