#ifndef NODE_H_
#define NODE_H_

#include <memory>

template<class T>
class Node{
public:
    Node(const T& val):
        val(val){}
    
    Node(const T& val, std::shared_ptr<Node<T>> left):
        val(val),
        left(left){}
    
    Node(const T& val, std::shared_ptr<Node<T>> right):
        val(val),
        right(right){}
    
    Node(
        const T& val,
        std::shared_ptr<Node<T>> left,
        std::shared_ptr<Node<T>> right
    ):
        val(val),
        left(left),
        right(right){}
private:
    std::shared_ptr<Node<T>>
        left{nullptr},
        right{nullptr};
    T val;

    inline void setLeft(std::shared_ptr<Node<T>> left) noexcept{
        this->left = left;
    }
    inline void setRight(std::shared_ptr<Node<T>> right) noexcept{
        this->right = right;
    }
};

#endif