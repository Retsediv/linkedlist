#ifndef NODE_H_
#define NODE_H_

#include <memory>

template<class T>
class Node {
public:
    Node(
            const T &val,
            std::shared_ptr<Node<T>> left = nullptr,
            std::shared_ptr<Node<T>> right = nullptr
    ) :
            val(val),
            left(left),
            right(right) {}

    inline void setLeft(std::shared_ptr<Node<T>> left) noexcept {
        this->left = left;
    }
    inline void setRight(std::shared_ptr<Node<T>> right) noexcept {
        this->right = right;
    }

    inline std::shared_ptr<Node<T>> getLeft() noexcept {
        return left;
    }
    inline std::shared_ptr<Node<T>> getRight() noexcept{
        return right;
    }

private:
    std::shared_ptr<Node<T>>
            left{nullptr},
            right{nullptr};
    T val;
};

#endif