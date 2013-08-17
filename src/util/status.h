// File: status.h
// Author: Xinbo Gao gaoxinbo1984@gmail.com
// Version: 1.0
// Date: 2013-08-17
// Copyright 2013, Xinbo Gao.  All rights reserved.

#ifndef _STATUS_H_
#define _STATUS_H_

#include <string>

namespace network {
enum error_type{
  kOK,
  kIOERROR,
  kINVALID_PARAM,
  kERROR_LENTH,
};

class Status {
  public:
    Status();
    Status(error_type type, std::string err, std::string msg);
    ~Status();

    bool isOK();
    std::string What();

    Status(const Status&);
    Status & operator=(const Status&);

    static Status IOErrorStatus(std::string err, std::string msg){
      return Status(kIOERROR,err,msg);
    }
    
    static Status InvalidParamStatus(std::string err, std::string msg){
      return Status(kINVALID_PARAM,err,msg);
    }
  private:
    error_type type_;
    std::string msg_;
    std::string stderror_;
};

}  // namespace network
#endif  // _STATUS_H_

