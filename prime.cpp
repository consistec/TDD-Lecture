#include <gtest/gtest.h>
#include <cmath>
#include <list>

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

std::list<unsigned int> primeFactors(unsigned int i) {
  std::list<unsigned int> result;

  result.push_back(2);
  return result;
}

TEST_F(CTestPrime, PrimeFactors) {
  std::list<unsigned int> factors2 = {2};
  std::list<unsigned int> factors3 = {3};

  ASSERT_EQ(factors2, primeFactors(2));
  ASSERT_EQ(factors3, primeFactors(3));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int res = RUN_ALL_TESTS();
  return res;
}
