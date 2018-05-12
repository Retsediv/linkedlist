#include <memory>
#include <gtest/gtest.h>
#include "Node.hpp"

TEST(node, all){
    std::shared_ptr<Node<int>> n1(new Node<int>(2));
    std::shared_ptr<Node<int>> n2(new Node<int>(3));

    ASSERT_EQ(n1->getValue(), 2);
    ASSERT_EQ(n2->getValue(), 3);
    n1->setValue(5);
    ASSERT_EQ(n1->getValue(), 5);

    ASSERT_EQ(n1->getLeft(), nullptr);
    ASSERT_EQ(n1->getRight(), nullptr);

    ASSERT_EQ(n2->getLeft(), nullptr);
    ASSERT_EQ(n2->getRight(), nullptr);

    n1->setLeft(n2);
    ASSERT_EQ(&(*n1->getLeft()), &(*n2));
}

int main(int argc, char ** argv){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}