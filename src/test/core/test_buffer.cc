#include "gtest/gtest.h" 
#include "core/buffer.h"
#include <string>
#include <iostream>

using namespace std;
using namespace network;

TEST(Buffer, init){
  Buffer b;
  EXPECT_EQ(b.remain(),2048);
}

TEST(Buffer, RWint){
  Buffer b;
  b.writeInt32(100);
  EXPECT_EQ(b.readable(),4);
  int n = b.readInt32();
  EXPECT_EQ(n,100);
  EXPECT_EQ(b.readable(),0);

  int a[] = {300,67000,10000000};
  for(unsigned int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    b.writeInt32(a[i]);
  }

  for(unsigned int i=0;i<sizeof(a)/sizeof(a[0]);i++){
    n = b.readInt32();
    EXPECT_EQ(n,a[i]);
  }

  EXPECT_EQ(b.readable(),0);
}

TEST(Buffer, RWChar){
  Buffer b;
  for(int i=0;i<26;i++){
    char c = 'a' + i;
    b.writeChar(c);
  }

  for(int i=0;i<26;i++){
    char c = b.readChar();
    EXPECT_EQ(c,'a'+i);
  }
}

TEST(Buffer,RWString){
  Buffer b;
  b.writeString("hello world");
  string s = b.readString();
  EXPECT_EQ(s,"hello world");
}

TEST(Buffer, Peek){
  Buffer b;

  int a[] = {300,67000,10000000};
  for(int i=0;i<sizeof a/sizeof a[0];i++){
    b.writeInt32(a[i]);
    int n = b.peekInt32();
    EXPECT_EQ(b.readable(),4);
    EXPECT_EQ(n,a[i]);
    n = b.readInt32();
    EXPECT_EQ(n,a[i]);
  }

  for(int i=0;i<26;i++){
    b.writeChar('a' + i);
    char c = b.peekChar();
    EXPECT_EQ(c,'a'+i);
    c = b.readChar();
    EXPECT_EQ(c,'a'+i);
  }

  b.writeString("hello world");
  string s = b.peekString();
  EXPECT_EQ(s,"hello world");
  s = b.readString();
  EXPECT_EQ(s,"hello world");
}
