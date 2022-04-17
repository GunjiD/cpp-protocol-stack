#ifndef SOCKET_H_
#define SOCKET_H_

class Socket {

private:
  // return file descriptor
  int fd;

public:
  Socket();
  ~Socket();

  void create(char *interface_name);
  int getScoket();
};

#endif
