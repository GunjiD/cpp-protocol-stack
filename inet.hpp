#ifndef BYTE_ORDER_H
#define BYTE_ORDER_H

#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int ETH_P_ALL = 0x0003;
const int MAC_LEN = 6;

const int ETH_T_ARP = 0x0806;

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

struct ethernet_hdr {
  uint8_t dest[MAC_LEN];
  uint8_t src[MAC_LEN];
  uint16_t ethehertype;
};

int host_byte_order(void);
uint16_t byte_swap16(uint16_t x);
uint32_t byte_swap32(uint32_t x);
uint16_t packet_ntohs(uint16_t network_short);
uint32_t packet_ntohl(uint32_t network_long);
uint16_t packet_htons(uint16_t host_short);
uint32_t packet_htonl(uint32_t host_long);
void ntop(uint32_t src, char *dest);
void ip_hdr_ntoh(struct ip_hdr *ip_header);

#endif
