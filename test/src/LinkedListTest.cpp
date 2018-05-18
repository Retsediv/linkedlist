#include <gtest/gtest.h>
#include "../../List.hpp"

TEST(List, construct){
    List<int> l;

    EXPECT_EQ(0, l.getSize());
}

TEST(List, basicPush) {
    List<int> l;

    EXPECT_EQ(nullptr, l.getHead());
    EXPECT_EQ(0, l.getSize());

    l.push_back(9);
    EXPECT_EQ(1, l.getSize());

    l.push_back(5);
    EXPECT_EQ(2, l.getSize());

    l.push_back(11);
    EXPECT_EQ(3, l.getSize());
}

TEST(List, push_front) {
    List<int> l;

    EXPECT_EQ(nullptr, l.getHead());
    EXPECT_EQ(0, l.getSize());

    l.push_front(1);

    EXPECT_EQ(1, l.getHead()->getValue());
    EXPECT_EQ(1, l.getSize());

    l.push_front(2);

    EXPECT_EQ(2, l.getHead()->getValue());
    EXPECT_EQ(1, l.getHead()->getRight()->getValue());
    EXPECT_EQ(2, l.getSize());

    l.push_front(3);

    EXPECT_EQ(3, l.getHead()->getValue());
    EXPECT_EQ(2, l.getHead()->getRight()->getValue());
    EXPECT_EQ(1, l.getHead()->getRight()->getRight()->getValue());
    EXPECT_EQ(3, l.getSize());
}


TEST(List, insert){
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);

    l.insert(1, 3);

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x->getValue());
        ++i;
    }
}

TEST(List, removeByIndex){
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);
    l.push_back(3);

    l.remove(2);

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x->getValue());
        ++i;
    }
}

TEST(List, removeByIterator){
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);
    l.push_back(3);

    l.remove(l.begin() + 2);

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x->getValue());
        ++i;
    }
}