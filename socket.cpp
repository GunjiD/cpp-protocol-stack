#include "socket.hpp"
#include "ethernet.hpp"

#include <errno.h>
#include <net/if.h>
#include <netpacket/packet.h>
#include <sys/ioctl.h>

Socket::Socket() {}

Socket::~Socket() {}

void Socket::create(char *interface_name) {

  // インターフェースの設定を行う構造体
  struct ifreq if_req;
  struct sockaddr_ll sa;

  if ((fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) == -1) {
    perror("raw_socket");
    exit(0);
  }

  // set the interface name to ifreq using strncpy
  strncpy(if_req.ifr_name, interface_name, IFNAMSIZ);
  if (ioctl(fd, SIOCGIFINDEX, &if_req) == -1) {
    fprintf(stderr, "SIOCGIFINDEX errno %d %s\n", errno, strerror(errno));
    exit(0);
  }

  // bind to interface
  sa.sll_family = PF_PACKET;
  sa.sll_protocol = htons(ETH_P_ALL);
  sa.sll_ifindex = if_req.ifr_ifindex;
  if (bind(fd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
    perror("bind");
    exit(0);
  }

  // if_req.ifr_flags |= IFF_PROMISC;
  if_req.ifr_flags &= ~IFF_PROMISC;

  // set flag of interface to UP
  if_req.ifr_flags = if_req.ifr_flags | IFF_UP;

  // set flag of interface
  if (ioctl(fd, SIOCGIFFLAGS, &if_req) == -1) {
    fprintf(stderr, "ioctl: errno %d %s\n", errno, strerror(errno));
    exit(0);
  }
}

int Socket::getScoket() { return fd; }
