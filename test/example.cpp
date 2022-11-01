#include "example.h"

#include "gtest/gtest.h"

TEST(example, add) {
  int res;
  res = add_numbers(1, 2);
  ASSERT_EQ(res, 3);
}

TEST(example, subtract) {
  int res;
  res = subtract_numbers(1, 2);
  ASSERT_EQ(res, -1);
}

TEST(example, my_calculate) {
  int res;
  res = my_calculate(1, 2);
  ASSERT_EQ(res, 4);
}
