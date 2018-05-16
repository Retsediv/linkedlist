#include <gtest/gtest.h>
#include "../../Node.hpp"

TEST(node, construct) {
    Node<int> n1{1};
    Node<int> n2{2};

    EXPECT_EQ(n1.getValue(), 1);
    EXPECT_EQ(n1.getLeft(), nullptr);
    EXPECT_EQ(n1.getRight(), nullptr);
    EXPECT_EQ(n2.getValue(), 2);
    EXPECT_EQ(n2.getLeft(), nullptr);
    EXPECT_EQ(n2.getRight(), nullptr);
}

TEST(node, linkToOtherNode) {
    Node<int> n1{1};
    Node<int> n2{2};

    n1.setRight(&n2);
    n2.setLeft(&n1);

    EXPECT_EQ(n1.getRight(), &n2);
    EXPECT_EQ(n2.getLeft(), &n1);

    EXPECT_EQ(n1.getRight()->getValue(), 2);
    EXPECT_EQ(n2.getLeft()->getValue(), 1);
}

TEST(node, links) {
    Node<int> *n1(new Node<int>(2));
    Node<int> *n2(new Node<int>(3));

    ASSERT_EQ(n1->getValue(), 2);
    ASSERT_EQ(n2->getValue(), 3);
    n1->setValue(5);
    ASSERT_EQ(n1->getValue(), 5);

    ASSERT_EQ(n1->getLeft(), nullptr);
    ASSERT_EQ(n1->getRight(), nullptr);

    ASSERT_EQ(n2->getLeft(), nullptr);
    ASSERT_EQ(n2->getRight(), nullptr);

    n1->setLeft(n2);
    ASSERT_EQ(&(*n1->getLeft()), n2);
}