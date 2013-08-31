// File: eventlooper.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-25
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _EVENTLOOPER_H_
#define _EVENTLOOPER_H_

#include <sys/epoll.h>
#include "core/iochannel.h"

namespace network {

class IOchannel;
enum ioevent{
  kREAD = 1,
  kWRITE = 2,
};

class EventLooper {
  public:
    EventLooper();
    ~EventLooper();

    int addEvent(int fd, IOchannel * channel, ioevent t);
    int delEvent(int fd);
  
    void run();
    void start();
    void stop();
    static void *run(void *arg);

  private:
    int fd_;
    epoll_event * events_;
    int number_;
    pthread_t pid_;
    bool stop_;
  private:
    EventLooper(const EventLooper&);
    EventLooper & operator=(const EventLooper&);
};

}  // namespace network
#endif  // _EVENTLOOPER_H_

