#include "example.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <gmock-global/gmock-global.h>

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;

MOCK_GLOBAL_FUNC2(multiply_numbers, int(int, int));

TEST(global_mock, my_calculate) {
  EXPECT_GLOBAL_CALL(multiply_numbers, multiply_numbers(1, 2))
      .WillOnce(Return(1));
  // 实际测试函数
  ASSERT_EQ(multiply_numbers(1, 2), 1);
  ASSERT_EQ(my_calculate(1, 2), 1);
}
