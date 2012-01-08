#include <gtest/gtest.h>
#include <cmath>

class CTestPrime : public ::testing::Test {
};

bool isPrime(unsigned int i) {
  if (i==1) return false;
  for (int j=2; j<=sqrt(i); j++) {
    if (i % j==0) return false;
  }
  return true;
}

TEST_F(CTestPrime, TestOne) {
  ASSERT_FALSE(isPrime(1));
  ASSERT_TRUE(isPrime(2));
  ASSERT_FALSE(isPrime(4));
  ASSERT_TRUE(isPrime(7));
  ASSERT_TRUE(isPrime(41));
  ASSERT_TRUE(isPrime(43));
  ASSERT_FALSE(isPrime(49));
  ASSERT_TRUE(isPrime(1000000007));
  ASSERT_FALSE(isPrime(1000000003));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int res = RUN_ALL_TESTS();
  return res;
}
