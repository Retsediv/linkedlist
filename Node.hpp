#ifndef NODE_H_
#define NODE_H_

#include <memory>

template<class T>
class Node {
public:
    explicit Node(const T &value, Node<T>* left = nullptr, Node<T>* right = nullptr ) : value(value), left(left), right(right) {}

    inline void setLeft(Node<T>* l) noexcept { left = l; }
    inline void setRight(Node<T>* r) noexcept { right = r; }

    inline Node<T>* getLeft() {return left;}
    inline Node<T>* getRight() {return right;}

    virtual bool is_guard(){
        return false;
    }

    const T& getValue() const noexcept {return value;}
    void setValue(const T& value){this->value = value;}
private:
    T value;
    Node<T>* left{nullptr};
    Node<T>* right{nullptr};
};

template <class T>
class GuardNode : public Node<T> {
public:
    GuardNode() : Node<T>(T(), nullptr, nullptr) {}

    bool is_guard() override { return true; }
};

#endif