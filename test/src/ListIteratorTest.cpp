#include <gtest/gtest.h>
#include "../../Node.hpp"
#include "../../List.hpp"

TEST(ListIterator, simpleCase) {
    Node<int> *n1(new Node<int>(1));
    Node<int> *n2(new Node<int>(2));
    Node<int> *n3(new Node<int>(3));
    n1->setRight(n2);
    n2->setLeft(n1);
    n2->setRight(n3);
    n3->setLeft(n2);

    ListIterator<int> iter{n1};

    EXPECT_EQ(n1, iter.getPointer());
    EXPECT_EQ(n1->getValue(), *iter);

    iter++;
    EXPECT_EQ(n2->getValue(), *iter);

    ++iter;
    EXPECT_EQ(n3->getValue(), *iter);
}

TEST(ListIterator, guardNode) {
    Node<int> *n1(new Node<int>(1));
    Node<int> *n2(new Node<int>(2));
    Node<int> *n3(new Node<int>(3));
    Node<int> *guard(new GuardNode<int>());
    n1->setRight(n2);
    n2->setLeft(n1);
    n2->setRight(n3);
    n3->setLeft(n2);
    n3->setRight(guard);

    ListIterator<int> iter{std::move(n1)};

    EXPECT_EQ(n1, iter.getPointer());
    EXPECT_EQ(n1->getValue(), *iter);

    iter++;
    EXPECT_EQ(n2->getValue(), *iter);

    ++iter;
    EXPECT_EQ(n3->getValue(), *iter);
}
