#include "array.h"
#include <gtest/gtest.h>

TEST(Array, create) {
    Array<int> array;
    const size_t expectedZeroSize = 0;

    EXPECT_EQ(array.size(), expectedZeroSize);
}

TEST(Array, push_back) {
    Array<int> array;
    array.push_back(1);
    const size_t expectedSize = 1;

    EXPECT_EQ(array.size(), expectedSize);
}

TEST(Array, push_forward) {
    Array<int> array;
    array.makeTestArray(10);
    array.insert(0, 0);

    EXPECT_EQ(array[0], 0);
}

TEST(Array, push_middle) {
    Array<int> array;
    array.makeTestArray(10);
    array.insert(4, 10);

    EXPECT_EQ(array[4], 10);
}

TEST(Array, erase_begin) {
    Array<int> array;
    array.makeTestArray(10);
    array.erase(0);
    EXPECT_EQ(array.size(), 8);
    EXPECT_EQ(array[0], 2);
}

TEST(Array, erase_end) {
    Array<int> array;
    array.makeTestArray(10);
    array.erase(9);

    EXPECT_EQ(array.size(), 8);
    EXPECT_EQ(array[7], 8);
}

TEST(Array, erase_middle) {
    Array<int> array;
    array.makeTestArray(10);
    array.erase(3);

    EXPECT_EQ(array.size(), 8);
    EXPECT_EQ(array[3], 5);
}

TEST(Array, get_el) {
    Array<int> array;
    array.makeTestArray(10);

    EXPECT_EQ(array[3], 4);
}

TEST(Array, get_size) {
    Array<int> array;
    array.makeTestArray(10);

    EXPECT_EQ(array.size(), 9);
}

TEST(Array, copy) {
    Array<int> array;
    array.makeTestArray(10);
    Array<int> arrayCopy = array;
    for (int i = 1; i < 10; i++) {
        EXPECT_EQ(array[i], arrayCopy[i]);
    }
    EXPECT_EQ(array.size(), arrayCopy.size());
}

TEST(Array, deleting) {
    Array<int> array;
    array.makeTestArray(10);
    //Как тогда проверить, что после вызова деструктора объект удален из памяти?
    EXPECT_EQ(array.size(), 0);
}

TEST(Array, moving) {
    Array<int> array;
    array.makeTestArray(10);
    Array<int> arrayCopy = std::move(array);
    for (int i = 1; i < 10; i++) {
        EXPECT_EQ(array[i], arrayCopy[i]);
    }
    //Как тогда проверить, что после перемещения перемещаемый объект удален из памяти?
    EXPECT_EQ(array.size(), 0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}