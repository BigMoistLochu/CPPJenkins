// test/test_math_operations.cpp
#include <gtest/gtest.h>
#include "../src/math_operations.h"

TEST(MathOperationsTest, AddFunction) {
EXPECT_EQ(add(1, 2), 3);
EXPECT_EQ(add(-1, -1), -2);
EXPECT_EQ(add(0, 0), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
