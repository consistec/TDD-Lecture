#include <gtest/gtest.h>

class CTestSum : public ::testing::Test {
};

int sum(int a, int b) {
  int j=b;
  int sum = a;
  while (j>0) {
    sum++;
    j--;
  }
  return sum;
}

TEST_F(CTestSum, sum) {
  ASSERT_EQ(5, sum(2,3));
  ASSERT_EQ(-1, sum(2,-3));
}
