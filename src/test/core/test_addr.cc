#include <arpa/inet.h>

#include "gtest/gtest.h"

#include "core/address.h"

using namespace network;
using namespace std;

TEST(address,init) {
  Address addr;
  EXPECT_EQ(0,addr.getPort());
  EXPECT_EQ("",addr.getIP());

  Address addr1(800);
  EXPECT_EQ(800,addr1.getPort());
  EXPECT_EQ("",addr1.getIP());

  Address addr2("192.168.1.1:8080");
  EXPECT_EQ(8080,addr2.getPort());
  EXPECT_EQ("192.168.1.1",addr2.getIP());
}

