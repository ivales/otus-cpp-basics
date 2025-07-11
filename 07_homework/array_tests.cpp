#include "array.h"
#include "list.h"
#include <gtest/gtest.h>

TEST(List, Success) {
    // Arrange
    Array<int> array;
    const size_t expectedZeroSize = 0;
    //Act
    const auto curSize = array.size();
    // Assert
    EXPECT_EQ(curSize, expectedZeroSize);
    EXPECT_EQ(expectedZeroSize, curSize);

    array.push_back(1);
    const size_t expectedSize = 1;

    EXPECT_NE(array.size(), expectedZeroSize);
    EXPECT_EQ(array.size(), expectedSize);

    EXPECT_LE(array.size(), expectedSize);
    EXPECT_GE(array.size(), expectedSize);
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
