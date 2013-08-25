// File: acceptor.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-15
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _ACCEPTOR_H_
#define _ACCEPTOR_H_

#include "core/socket.h"
#include "core/address.h"
#include "util/status.h"
#include "iochannel.h"

namespace network {

class Acceptor : public IOchannel{
  public:
    Acceptor();
    virtual ~Acceptor();

    virtual void handleRead();
    virtual void handleWrite();

    Status listen(short port);
    int accept();
    int getFD(){
      return sock_.getFD();
    }

  private:
    Socket sock_;
    Address addr_;
  private:
    Acceptor(const Acceptor&);
    Acceptor & operator=(const Acceptor&);
};

}  // namespace network
#endif  // _ACCEPTOR_H_

