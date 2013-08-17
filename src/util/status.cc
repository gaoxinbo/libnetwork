// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "status.h"

using namespace std;

namespace network{

Status::Status(){
  type_ = kOK;
  msg_ = "";
  stderror_ = "";
}

Status::~Status(){
}

Status::Status(error_type type, std::string err, std::string msg){
  type_ = type;
  stderror_ = err;
  msg_ = msg;
}

Status::Status(const Status & s){
  type_ = s.type_;
  msg_ = s.msg_;
  stderror_ = s.stderror_;
}

Status & Status::operator=(const Status &s){
  if(this == &s){
    return *this;
  }

  type_ = s.type_;
  stderror_ = s.stderror_;
  msg_ = s.msg_;
  return *this;


}

bool Status::isOK(){
  return type_ == kOK;
}

string Status::What(){
  static string reasons [kERROR_LENTH] = {
    "ok",
    "IOError",
    "Invalid Params"
  };
  string result;

  if(!isOK()){
    result = reasons[type_];
    result += " - " + msg_;
    result += " : " + stderror_;
  }
  else
    result = reasons[0]; 

  return result;

}

/*
static Status Status::IOErrorStatus(string err, string msg){
  return Status(kIOERROR,err,msg);
}

static Status Status::InvalidParamStatus(string err, string msg){
  return Status(kINVALID_PARAM,err,msg);
}
*/

} // namespace network
