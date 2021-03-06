// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#ifdef __linux__

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <iostream>

#include "eventlooper.h"

using namespace std;

namespace network {
 
EventLooper::EventLooper(){
  fd_ = epoll_create(256);
  number_ = 256;
  events_ = new epoll_event[number_];
  stop_ = false;
}

EventLooper::~EventLooper(){
  close(fd_);
  delete [] events_;
}

void EventLooper::run(){
  while(!stop_){
    int num = epoll_wait(fd_, events_, number_, 200);
    if(num == -1){
      cout<<strerror(errno)<<endl;
      break;
    }

    for(int i=0;i<num;i++){
      if(events_[i].events & EPOLLIN){
        IOchannel * channel = (IOchannel *)events_[i].data.ptr;
        channel->handleRead();
      }

      if(events_[i].events & EPOLLOUT){
        IOchannel * channel = (IOchannel*)events_[i].data.ptr;
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
  int ret = epoll_ctl(fd_, EPOLL_CTL_DEL,fd,NULL);
  return ret;
}

int EventLooper::addEvent(int fd, IOchannel * channel, ioevent how){

  epoll_event e;
  e.events = 0;
  if(how & kREAD);
    e.events  |= EPOLLIN; 
  if(how & kWRITE)
    e.events  |= EPOLLOUT; 

  e.data.fd = fd;
  e.data.ptr = channel;

  int ret = epoll_ctl(fd_,EPOLL_CTL_ADD,fd,&e);
  if(ret == -1 && errno == EEXIST){
    ret = epoll_ctl(fd_,EPOLL_CTL_MOD,fd,&e);
  }

  return ret;
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
