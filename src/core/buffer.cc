// Copyright 2013, Gao Xinbo.  All rights reserved.
// Author: Gao Xinbo gaoxinbo1984@gmail.com

#include "buffer.h"

using namespace std;

namespace network {

Buffer::Buffer():buf_(2048){
  start_ = 0;
  end_ = 0;
}

Buffer::~Buffer(){
}

Buffer::Buffer(int n):buf_(n){
  start_ = 0;
  end_ = 0;
}

int Buffer::remain(){
  return buf_.size() - end_;
}

int Buffer::expand(int length){
  if(remain()>=length)
    return buf_.size(); 

  buf_.resize(buf_.size() + length - remain());
  return buf_.size();
}

void Buffer::writeChar(char c){
  expand(sizeof c);
  buf_[end_++] = c; 
  return;
}

void Buffer::writeInt32(int n){
  expand(sizeof n);
  buf_[end_++] = n; 
  buf_[end_++] = n >> 8;
  buf_[end_++] = n >> 16;
  buf_[end_++] = n >> 24; 
}

void Buffer::writeString(const string &s){
  expand(s.size() + 4);
  writeInt32(s.size());
  for(unsigned int i=0;i<s.size();i++){
    buf_[end_++] = s[i];
  }
  return;
}

int Buffer::readable(){
  return end_ - start_;
}

// make sure readable is larger than sizeof char
char Buffer::readChar(){
  char c;
  c = buf_[start_++];
  return c;
}

int Buffer::readInt32(){
  int n = 0;
  n |= buf_[start_++];
  n |= buf_[start_++]<<8;
  n |= buf_[start_++]<<16;
  n |= buf_[start_++]<<24;
  return n;
}

string Buffer::readString(){
  int n = readInt32();
  string s;
  for(int i=0;i<n;i++){
    s += buf_[start_++];
  }
  return s;
}


}  // namespace network

