#ifndef NODE_H_
#define NODE_H_

#include <memory>

template<class T>
class Node {
public:
    Node(
            const T &value,
            std::shared_ptr<const Node<T>> left = nullptr,
            std::shared_ptr<const Node<T>> right = nullptr
    ) :
            value(value),
            left(left),
            right(right) {}

    inline void setLeft(std::shared_ptr<const Node<T>> left) noexcept {this->left = left;}
    inline void setRight(std::shared_ptr<const Node<T>> right) noexcept {this->right = right;}

    inline std::shared_ptr<const Node<T>> getLeft() const noexcept {return left;}
    inline std::shared_ptr<const Node<T>> getRight() const noexcept{return right;}

    const T& getValue() const noexcept {return value;}
    void setValue(const T& value){this->value = value;}
    
private:
    T value;
    std::shared_ptr<const Node<T>>
            left{nullptr},
            right{nullptr};
};

#endif