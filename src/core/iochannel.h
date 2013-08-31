// File: iochannel.h
// Author: Gao Xinbo gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-15
// Copyright 2013, Gao Xinbo.  All rights reserved.

#ifndef _IOCHANNEL_H_
#define _IOCHANNEL_H_

#include "eventlooper.h"
namespace network {


class EventLooper;

class IOchannel {
  public:
    IOchannel();
    virtual ~IOchannel() = 0;

    virtual void handleRead() = 0;
    virtual void handleWrite() = 0;

    void setLooper(EventLooper *looper);

  protected:
    EventLooper * looper_;

  private:
    IOchannel(const IOchannel&);
    void operator=(const IOchannel&);
};

}  // namespace network
#endif  // _IOCHANNEL_H_

