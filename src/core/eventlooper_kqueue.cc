// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#ifdef __APPLE__

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/event.h>
#include <pthread.h>
#include <iostream>

#include "eventlooper.h"

using namespace std;

namespace network {
 
EventLooper::EventLooper(){
  fd_ = kqueue();
  number_ = 256;
  events_ = new struct kevent[number_];
  stop_ = false;
}

EventLooper::~EventLooper(){
  close(fd_);
  delete [] events_;
}

void EventLooper::run(){
  while(!stop_){
    timespec tv;
    tv.tv_nsec = 200*1000;
    tv.tv_sec = 0;
    int num = kevent(fd_, NULL, 0, events_, number_, &tv);
    if(num == -1){
      cout<<strerror(errno)<<endl;
      break;
    }

    for(int i=0;i<num;i++){
      if(events_[i].filter == EVFILT_READ){
        IOchannel * channel = (IOchannel *)events_[i].udata;
        channel->handleRead();
      }

      if(events_[i].filter == EVFILT_WRITE){
        IOchannel * channel = (IOchannel*)events_[i].udata;
        channel->handleWrite();
      }
    }
  }
}

void EventLooper::stop(){
  stop_ = true;
  pthread_join(pid_,NULL);
}

int EventLooper::delEvent(int fd){

  struct kevent ke;
  EV_SET(&ke, fd, EVFILT_WRITE, EV_DELETE, 0, 0, NULL);
  kevent(fd_, &ke, 1, NULL, 0, NULL);

  EV_SET(&ke, fd, EVFILT_READ, EV_DELETE, 0, 0, NULL);
  kevent(fd_, &ke, 1, NULL, 0, NULL);

  return 0;
}

int EventLooper::addEvent(int fd, IOchannel * channel, ioevent how){

  struct kevent ke;
  if(how & kREAD){
    EV_SET(&ke, fd, EVFILT_READ, EV_ADD, 0, 0, channel);
    kevent(fd_, &ke, 1, NULL, 0, NULL);
  }
  if(how & kWRITE){
    EV_SET(&ke, fd, EVFILT_WRITE, EV_ADD, 0, 0, channel);
    kevent(fd_, &ke, 1, NULL, 0, NULL);
  }
  return 0;
}

void * EventLooper::run(void *arg){
  if(arg==NULL)
      return NULL;
  EventLooper * looper = (EventLooper *) arg;  
  looper->run();
  return NULL;
}

void EventLooper::start(){
  pthread_create(&pid_,NULL,EventLooper::run,this);
}

}  // namespace network

#endif
