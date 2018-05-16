#include <gtest/gtest.h>
#include "../../List.hpp"

TEST(List, basicPush) {
    List<int> l;

    EXPECT_EQ(nullptr, l.getTail());
    EXPECT_EQ(0, l.getSize());

    l.push_back(9);
    EXPECT_EQ(1, l.getSize());

    l.push_back(5);
    EXPECT_EQ(2, l.getSize());

    l.push_back(11);
    EXPECT_EQ(3, l.getSize());
}
