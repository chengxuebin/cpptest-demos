#include "example.h"

#include "../third_party/fff/fff.h"
#include "gtest/gtest.h"

DEFINE_FFF_GLOBALS;

FAKE_VALUE_FUNC(int, multiply_numbers, int, int);

TEST(fff, my_calculate) {
  multiply_numbers_fake.return_val = 1;
  // 实际测试函数
  ASSERT_EQ(multiply_numbers(1, 2), 1);
  ASSERT_EQ(my_calculate(1, 2), 1);
}