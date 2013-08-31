// File: connection.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-25
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _CONNECTION_H_
#define _CONNECTION_H_

#include "core/socket.h"
#include "core/address.h"
#include "iochannel.h"

namespace network {

class Connection : public IOchannel {
  public:
    Connection();
    Connection(Socket *sock,Address addr);
    virtual ~Connection();

    virtual void handleRead();
    virtual void handleWrite();

    int getFD();
    Status connect(std::string, short);

    static Connection * connect(const Address & addr);

  private:
    Socket *sock_;
    Address addr_;
  private:
    Connection(const Connection&);
    Connection & operator=(const Connection&);
};

}  // namespace network
#endif  // _CONNECTION_H_

