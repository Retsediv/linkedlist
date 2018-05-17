#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node {
public:
    explicit Node(T *value, Node<T> *left = nullptr, Node<T> *right = nullptr) :
            value(value), left(left), right(right) {}

    explicit Node(const T &value, Node<T> *left = nullptr, Node<T> *right = nullptr) :
            Node(new T(value), left, right) {}


    ~Node() { delete value; }

    inline void setLeft(Node<T> *l) noexcept { left = l; }

    inline void setRight(Node<T> *r) noexcept { right = r; }

    inline Node<T> *getLeft() const noexcept { return left; }

    inline Node<T> *getRight() const noexcept { return right; }

    virtual bool is_guard() {
        return false;
    }

    T &getValue() noexcept { return *value; }
    const T &getValue() const noexcept { return *value; }

    void setValue(const T &value) { setValue(new T(value)); }
    void setValue(T *v) { value = v; }

private:
    T* value;
    Node<T> *left;
    Node<T> *right;
};

template<class T>
class GuardNode : public Node<T> {
public:
    GuardNode() : Node<T>(T(), nullptr, nullptr) {}

    bool is_guard() override { return true; }
};

#endif