#include "example.h"

#include "cmock/cmock.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace ::testing;

// class MathMocker : public CMockMocker<MathMocker> {
// public:
//   MOCK_METHOD2(multiply_numbers, int(int, int));
// };

// CMOCK_MOCK_FUNCTION2(MathMocker, multiply_numbers, int(int, int));

// TEST(c_mock, my_calculate) {
//   {
//     {
//       MathMocker mock;

//       EXPECT_CALL(mock, multiply_numbers(1, 2)).WillOnce(Return(1));
//       ASSERT_EQ(multiply_numbers(1, 2), 1);

//       EXPECT_CALL(mock, multiply_numbers(2, 2)).WillOnce(Return(2));
//       ASSERT_EQ(my_calculate(1, 2), 2);
//     }

//     // MathMocker mock;
//     // EXPECT_FUNCTION_CALL(mock, (1, 2))
//     //     .WillOnce(::testing::Invoke(MathMocker::real));
//     // ASSERT_EQ(my_calculate(1, 2), 4);
//   }
// }

DECLARE_FUNCTION_MOCK2(MultipleFunctionMock, multiply_numbers, int(int, int));
IMPLEMENT_FUNCTION_MOCK2(MultipleFunctionMock, multiply_numbers, int(int, int));

TEST(c_mock, my_calculate) {
  {
    {
      MultipleFunctionMock mock;

      EXPECT_FUNCTION_CALL(mock, (1, 2)).WillOnce(Return(1));
      ASSERT_EQ(multiply_numbers(1, 2), 1);

      EXPECT_FUNCTION_CALL(mock, (2, 2)).WillOnce(Return(2));
      ASSERT_EQ(my_calculate(1, 2), 2);
    }

    MultipleFunctionMock mock;
    // EXPECT_FUNCTION_CALL(mock, (2, 2)).WillRepeatedly(Return(4));

    EXPECT_FUNCTION_CALL(mock, (2, 2))
        .WillRepeatedly(::testing::Invoke(MultipleFunctionMock::real));
    ASSERT_EQ(multiply_numbers(2, 2), 4);
    ASSERT_EQ(my_calculate(1, 2), 4);
  }
}
