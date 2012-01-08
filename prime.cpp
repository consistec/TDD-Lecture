#include <gtest/gtest.h>
#include <cmath>
#include <list>

class CTestPrime : public ::testing::Test {
};

unsigned int firstPrimeFactor(unsigned int i) {
  for (int j=2; j<i; j++) {
    if (i % j==0) {
      return j;
    }
  }
  return i;
}

TEST_F(CTestPrime, firstPrimeFactor) {
  ASSERT_EQ(2, firstPrimeFactor(2));
}

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

  if (isPrime(i)) {
    result.push_back(i);
  } else {
    for (int j=2; j<=sqrt(i); j++) {
      if (i % j==0) {
        result.push_back(j);
        result.splice(result.end(), primeFactors(i / j));
        break;
      }
    }
  }

  return result;
}

TEST_F(CTestPrime, PrimeFactors) {
  std::list<unsigned int> factors2 = {2};
  std::list<unsigned int> factors3 = {3};
  std::list<unsigned int> factors4 = {2,2};
  std::list<unsigned int> factors12 = {2,2,3};
  std::list<unsigned int> factors400400 = {2,2,2,2,5,5,7,11,13};
 
  ASSERT_EQ(factors2, primeFactors(2));
  ASSERT_EQ(factors3, primeFactors(3));
  ASSERT_EQ(factors4, primeFactors(4));
  ASSERT_EQ(factors12, primeFactors(12));
  ASSERT_EQ(factors400400, primeFactors(400400));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  int res = RUN_ALL_TESTS();
  return res;
}
