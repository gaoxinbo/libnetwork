// File: log.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-22
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _LOG_H_
#define _LOG_H_

#include <string> 
#include <map>

namespace network {

#define LOG_INFO(logger, fmt...) Log::getLog(logger)->log(kINFO, fmt);
#define LOG_ERROR(logger, fmt...) Log::getLog(logger)->log(kERROR, fmt);
#define LOG_WARN(logger, fmt...) Log::getLog(logger)->log(kWARN, fmt);

enum LOGLEVEL{
  kINFO,
  kWARN,
  kERROR,
  kLENGTH,
};

__attribute__((unused)) static const char * level_msg [kLENGTH]= {
  "INFO",
  "WARN",
  "ERROR",
};

class Log {
  public:
    Log();
    ~Log();

    void log(LOGLEVEL,const char * fmt, ...);
    static Log* getLog(std::string name);

  private:
    LOGLEVEL level_;
    static int length_;
    static std::map<std::string,Log*> mapper_;

  private:
    Log(const Log&);
    void operator=(const Log&);
};

}  // namespace network
#endif  // _LOG_H_

