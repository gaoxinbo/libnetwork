// Copyright 2013, Xinbo Gao.  All rights reserved.
// Author: Xinbo Gao gaoxinbo1984@gmail.com

#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include "log.h"

using namespace std;

namespace network {

int Log::length_ = 1024;
map<string,Log*> Log::mapper_;

Log::Log(){
  level_ = kINFO;
}

Log::~Log(){
}

void Log::log(LOGLEVEL level, const char * fmt, ...){
  if(level<level_)
    return;
  char buf[length_];
  va_list ap;
  va_start(ap,fmt);
  vsnprintf(buf,length_,fmt,ap);
  va_end(ap);

  time_t now = time(NULL);
  tm * t = localtime(&now);

  char time_buf[100];
  strftime(time_buf,100,"%Y-%m-%d %H:%M:%S",t);

  cout<<time_buf<<" - "<<level_msg[level]<<" - "<<buf<<endl;
}

Log * Log::getLog(string name){
  if(mapper_.count(name) == 0){
    mapper_[name] = new Log();
  }
  return mapper_[name];
}
}  // namespace network

