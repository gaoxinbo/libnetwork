// File: acceptor.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-15
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _ACCEPTOR_H_
#define _ACCEPTOR_H_

#include "iochannel.h"

namespace network {

class acceptor : public IOchannel{
  public:
    acceptor();
    virtual ~acceptor();

    virtual void handleRead();
    virtual void handleWrite();

  private:
    acceptor(const acceptor&);
    void operator=(const acceptor&);
};

}  // namespace network
#endif  // _ACCEPTOR_H_

