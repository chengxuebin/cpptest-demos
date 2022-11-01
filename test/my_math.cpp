#include "my_math.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using ::testing::_;
using ::testing::NiceMock;
using ::testing::Return;

class MyMathMock : public MyMath {
public:
  MOCK_METHOD(int, multiply_numbers, (const int f1, const int f2));
};

TEST(math, add) {
  MyMath math;
  int res = math.add_numbers(1, 2);
  ASSERT_EQ(res, 3);
}

TEST(math, subtract) {
  MyMath math;
  int res = math.subtract_numbers(1, 2);
  ASSERT_EQ(res, -1);
}

TEST(math, my_calculate) {
  NiceMock<MyMathMock> myMathMock;

  ON_CALL(myMathMock, multiply_numbers(_, _)).WillByDefault(Return(1));

  // EXPECT_CALL(myMathMock, multiply_numbers(_, _))
  //     .Times(1)
  //     .WillOnce(Return(1));

  int res = myMathMock.my_calculate(1, 2);
  ASSERT_EQ(res, 1);
}
