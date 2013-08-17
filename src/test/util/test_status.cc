#include "gtest/gtest.h"
#include "util/status.h"

using namespace network;

TEST(status, ok) {
  Status s;
  EXPECT_EQ(true, s.isOK());
}
