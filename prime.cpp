#include <gtest/gtest.h>

class CTestPrime : public ::testing::Test {
};

bool isPrime(unsigned int i) {
  if (i==1) return false;
  return true;
}

TEST_F(CTestPrime, TestOne) {
  ASSERT_FALSE(isPrime(1));
  ASSERT_TRUE(isPrime(2));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int res = RUN_ALL_TESTS();
  return res;
}
