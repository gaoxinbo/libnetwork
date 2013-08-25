// File: socket.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-15
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include "sys/socket.h"
namespace network {

class Socket {
  public:
    Socket();
    Socket(int fd);
    ~Socket();

    bool Create();
    bool isValid();
    
  private:
    int fd_;

  private:
    Socket(const Socket&);
    void operator=(const Socket&);
};

}  // namespace network
#endif  // _SOCKET_H_

