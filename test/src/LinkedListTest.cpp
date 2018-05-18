#include <gtest/gtest.h>
#include "../../List.hpp"
#include <algorithm>

TEST(List, constr1uct){
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
        EXPECT_EQ(i, x);
        ++i;
    }
}

TEST(List, removeOneByIndex){
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);
    l.push_back(3);

    l.remove(2);

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x);
        ++i;
    }
}

TEST(List, removeOneByIterator){
    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(4);
    l.push_back(3);

    l.remove(l.begin() + 2);

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x);
        ++i;
    }
}


TEST(List, removeRangeByIndex){
    List<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(3);
    l.push_back(2);

    l.remove(1, 3);

    EXPECT_EQ(2, l.getSize());

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x);
        ++i;
    }
}


TEST(List, removeRangeByIterator){
    List<int> l;
    l.push_back(1);
    l.push_back(3);
    l.push_back(3);
    l.push_back(2);

    l.remove(l.begin() + 1, l.begin() + 3);

    EXPECT_EQ(2, l.getSize());

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x);
        ++i;
    }
}


TEST(List, removeIf){
    List<int> l;
    for (int i = 0; i < 100; ++i) {
        l.push_back(i);
    }

    l.remove(std::remove_if(l.begin(), l.end(), [](int i){ return i % 2 == 0; }),
             l.end());

    EXPECT_EQ(50, l.getSize());

    int i = 1;
    for(auto const &x: l){
        EXPECT_EQ(i, x);
        i += 2;
    }
}