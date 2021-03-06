#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <netpacket/packet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>

#include "ethernet.hpp"

/*
char EthernetProtocol::*dest_addr(ethernet_hdr *eth_hdr) {
  char *str;
  sprintf(str, "%.2X-%.2X-%.2X-%.2X-%.2X-%.2X", eth_hdr->dest[0],
          eth_hdr->dest[1], eth_hdr->dest[2], eth_hdr->dest[3],
          eth_hdr->dest[4], eth_hdr->dest[5]);
  return str;
}

char EthernetProtocol::*src_addr(ethernet_hdr *eth_hdr) {
  char *str;
  sprintf(str, "%.2X-%.2X-%.2X-%.2X-%.2X-%.2X", eth_hdr->src[0],
          eth_hdr->src[1], eth_hdr->src[2], eth_hdr->src[3], eth_hdr->src[4],
          eth_hdr->src[5]);
  return str;
}
*/

void ethHdrDbg(unsigned char *buf, ssize_t recv_byte) {

  ethernet_hdr *eth_header = (ethernet_hdr *)(buf);

  // Ethernet Header の解析
  printf("Ethernet Header\n");
  // 宛先アドレスの MAC アドレスを表示
  printf("destination address : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
         eth_header->dest[0], eth_header->dest[1], eth_header->dest[2],
         eth_header->dest[3], eth_header->dest[4], eth_header->dest[5]);
  printf("source address      : %.2X-%.2X-%.2X-%.2X-%.2X-%.2X\n",
         eth_header->src[0], eth_header->src[1], eth_header->src[2],
         eth_header->src[3], eth_header->src[4], eth_header->src[5]);
  printf("Packet Type ID : %2x\n", ntohs(eth_header->ethehertype));
  printf("packet %lu bytes\n", recv_byte);
  printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}
