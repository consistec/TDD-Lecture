#include <gtest/gtest.h>

class CTestPrime : public ::testing::Test {
};

TEST_F(CTestPrime, TestOne) {
  ASSERT_FALSE(isPrime(1));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int res = RUN_ALL_TESTS();
  return res;
}
