#include "../ethernet.hpp"
#include "../inet.hpp"
#include "../ip.hpp"
#include "../socket.hpp"

#include <iostream>
#include <iterator>
#include <ostream>
#include <sys/socket.h>
#include <sys/types.h>

// 受信したパケットのバイト数を格納
ssize_t recv_byte;

int main(int argc, char *argv[]) {

  // プロトコルの情報が格納される
  struct sockaddr saddr;
  socklen_t saddr_len = sizeof(saddr);

  // パケットを受信する
  unsigned char *buffer = (unsigned char *)malloc(BUF_SIZ);
  memset(buffer, 0, BUF_SIZ);

  Socket socket;
  IpProtocol ip;

  std::cout << "ソケットを作成します" << std::endl;

  socket.create("wlp8s0");

  std::cout << "パケットの受信を開始します" << std::endl;

  while (1) {

    recv_byte =
        recvfrom(socket.getScoket(), buffer, BUF_SIZ, 0, &saddr, &saddr_len);
    // 受信したパケットを ethdr にキャストして代入する
    // ethhdr については if_ether.h を参照
    ethernet_hdr *eth_h = (ethernet_hdr *)(buffer);

    struct ip_hdr *ip_h = (struct ip_hdr *)(buffer + sizeof(ethernet_hdr));

    eth_hdr_dbg(eth_h, recv_byte);

    switch (ntohs(eth_h->ethehertype)) {
      /*
    case ETH_T_ARP: {
      arp_hdr *arp_h = (arp_hdr *)(buffer + sizeof(ethernet_hdr));
      arp_dbg(arp_h);
    } break;
      */
    default:
      ip.HdrDbg(buffer, INTEGER);
      // ip_hdr_dbg(ip_h, INTEGER);
      // ip_hdr_dbg(ip_h, HEX);
      break;
    }
  }
}
