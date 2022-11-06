#include "example.h"

#include "stub.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

int my_multiply(int a, int b) { return 1; }

TEST(cpp_stub, my_calculate) {
  Stub stub;
  stub.set(multiply_numbers, my_multiply);
  // 实际测试函数
  ASSERT_EQ(multiply_numbers(1, 2), 1);
  ASSERT_EQ(my_calculate(1, 2), 1);
}
