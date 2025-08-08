#include "list.h"
#include <gtest/gtest.h>

TEST(ForwardList, create) {
    ForwardList<int> forwardList;
    const int expectedZeroSize = 0;

    EXPECT_EQ(forwardList.size(), expectedZeroSize);
}

TEST(ForwardList, push_back) {
    ForwardList<int> forwardList;
    forwardList.push_back(1);
    const int expectedSize = 1;

    EXPECT_EQ(forwardList.size(), expectedSize);
}

TEST(ForwardList, push_forward) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }
    forwardList.insert(0, 0);

    EXPECT_EQ(forwardList[0], 0);
}

TEST(ForwardList, push_middle) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }
    forwardList.insert(4, 10);

    EXPECT_EQ(forwardList[4], 10);
}

TEST(ForwardList, erase_begin) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }
    forwardList.erase(0);

    EXPECT_EQ(forwardList.size(), 8);
    EXPECT_EQ(forwardList[0], 2);
}

TEST(forwardList, erase_end) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }
    forwardList.erase(9);

    EXPECT_EQ(forwardList.size(), 8);
    EXPECT_EQ(forwardList[7], 8);
}

TEST(ForwardList, erase_middle) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }
    forwardList.erase(3);

    EXPECT_EQ(forwardList.size(), 8);
    EXPECT_EQ(forwardList[3], 5);
}

TEST(ForwardList, get_el) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }

    EXPECT_EQ(forwardList[3], 4);
}

TEST(ForwardList, get_size) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }

    EXPECT_EQ(forwardList.size(), 9);
}

TEST(ForwardList, copy) {
    ForwardList<int> forwardList;
    for (int i = 1; i < 10; i++) {
        forwardList.push_back(i);
    }
    ForwardList<int> forwardListCopy = forwardList;
    for (int i = 1; i < 10; i++) {
        EXPECT_EQ(forwardList[i], forwardListCopy[i]);
    }
    EXPECT_EQ(forwardList.size(), forwardListCopy.size());
}

// TEST(ForwardList, deleting) {
//     ForwardList<int> forwardList;
//     for (int i = 1; i < 10; i++) {
//         forwardList.push_back(i);
//     }
//     EXPECT_EQ(forwardList.size(), 0);
// }

// TEST(ForwardList, moving) {
//     ForwardList<int> forwardList;
//     for (int i = 1; i < 10; i++) {
//         forwardList.push_back(i);
//     }
//     ForwardList<int> forwardListCopy = std::move(forwardList);
//     for (int i = 1; i < 10; i++) {
//         EXPECT_EQ(forwardList[i], forwardListCopy[i]);
//     }
//     EXPECT_EQ(forwardList.size(), 0);
// }

// int main(int argc, char** argv) {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }